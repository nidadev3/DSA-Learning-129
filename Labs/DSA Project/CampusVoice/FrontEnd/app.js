/**
 * app.js - DOM interaction and bindings to dsa.js structures
 * Drives the premium white minimalist CampusVoice frontend.
 */

document.addEventListener('DOMContentLoaded', () => {
    // Determine page and initialize
    if (document.getElementById('complaintForm')) {
        initStudentPortal();
    }

    if (document.getElementById('priorityQueueList')) {
        initAdminDashboard();
    }
});

/* =========================================================
   COMMON UTILITIES
   ========================================================= */

// Escape HTML utility to prevent injection
function escapeHtml(str) {
    if (!str) return '';
    return str.replace(/&/g, '&amp;')
              .replace(/</g, '&lt;')
              .replace(/>/g, '&gt;')
              .replace(/"/g, '&quot;')
              .replace(/'/g, '&#039;');
}

// Custom Toast notification system (Polished light-border alert)
function showToast(message, type = 'info') {
    const container = document.getElementById('toast-container');
    if (!container) return;
    
    const toast = document.createElement('div');
    toast.className = `toast toast-${type}`;
    toast.innerHTML = `
        <span>${message}</span>
        <button class="toast-close" onclick="this.parentElement.remove()">&times;</button>
    `;
    
    container.appendChild(toast);
    
    // Smooth transition trigger
    setTimeout(() => {
        toast.classList.add('show');
    }, 10);

    // Auto delete toast after 4 seconds
    setTimeout(() => {
        toast.classList.remove('show');
        setTimeout(() => {
            toast.remove();
        }, 300);
    }, 4000);
}

/* =========================================================
   STUDENT PORTAL
   ========================================================= */
function initStudentPortal() {
    renderStudentHistory();

    document.getElementById('complaintForm').addEventListener('submit', function (e) {
        e.preventDefault();

        const studentName = document.getElementById('cStudentName').value.trim();
        const category = document.getElementById('cCategory').value;
        const desc = document.getElementById('cDesc').value.trim();
        const priority = document.querySelector('input[name="priority"]:checked').value;
        const isUrgent = priority === 'urgent';

        // Submit to local storage structures
        const complaint = DSA.submitComplaint(studentName, category, desc, isUrgent);

        showToast(`Complaint ${complaint.id} submitted successfully!`, 'success');
        
        // Reset form inputs
        this.reset();
        
        // Visual reset slider
        const normalPrioInput = document.getElementById('prio-normal');
        if (normalPrioInput) normalPrioInput.checked = true;

        renderStudentHistory();
    });
}

function renderStudentHistory() {
    const list = document.getElementById('studentHistoryList');
    if (!list) return;

    const complaints = DSA.getAllComplaints();

    if (complaints.length === 0) {
        list.innerHTML = '<div class="empty-state">No complaints submitted yet.</div>';
        return;
    }

    // Slice and reverse array to list newest complaints first
    const html = complaints.slice().reverse().map((c, index) => {
        let dotClass = 'dot-pending';
        let statusText = 'Pending';
        if (c.status === 'in-progress') {
            dotClass = 'dot-progress';
            statusText = 'In Progress';
        } else if (c.status === 'resolved') {
            dotClass = 'dot-resolved';
            statusText = 'Resolved';
        }

        const prioBadge = c.isUrgent ? `<span class="badge badge-urgent">Urgent</span>` : '';
        const date = new Date(c.timestamp).toLocaleString();

        return `
        <div class="complaint-item fade-in-item stagger-${(index % 3) + 1}">
            <div class="complaint-header">
                <span class="complaint-student">${escapeHtml(c.studentName)}</span>
                <div style="display: flex; align-items: center; gap: 8px;">
                    ${prioBadge}
                    <span class="badge-status">
                        <span class="dot ${dotClass}"></span>
                        ${statusText}
                    </span>
                </div>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default">${escapeHtml(c.category)}</span>
                <span class="complaint-meta font-mono">${c.id}</span>
                <span class="complaint-meta" style="margin-left: auto;">${date}</span>
            </div>
            <div class="complaint-meta" style="color: var(--text-primary); font-size: 0.9rem; margin-top: 2px;">
                ${escapeHtml(c.description)}
            </div>
        </div>
        `;
    }).join("");

    list.innerHTML = html;
}

/* =========================================================
   ADMIN DASHBOARD
   ========================================================= */
function initAdminDashboard() {
    renderAdminViews();
    initTabSystem();
    initGraphBindings();
}

function initTabSystem() {
    const tabs = document.querySelectorAll('.tab-btn');
    tabs.forEach(tab => {
        tab.addEventListener('click', function () {
            document.querySelectorAll('.tab-btn').forEach(btn => btn.classList.remove('active'));
            document.querySelectorAll('.tab-pane').forEach(pane => pane.classList.remove('active'));

            this.classList.add('active');
            const target = this.getAttribute('data-tab');
            const targetPane = document.getElementById(target);
            if (targetPane) targetPane.classList.add('active');

            if (target === 'tab-sort') {
                renderSortList(DSA.getAllComplaints());
            } else if (target === 'tab-search') {
                resetTraversalChain();
            } else if (target === 'tab-graph') {
                resetGraphHighlight();
            }
        });
    });

}

function renderAdminViews() {
    const queues = DSA.getQueues();
    renderQueue('priorityQueueList', queues.priorityQueue);
    renderQueue('normalQueueList', queues.normalQueue);
    renderInProgress();
    renderResolvedStack();
    updateStats();
}

function updateStats() {
    const complaints = DSA.getAllComplaints();
    const queues = DSA.getQueues();
    const resolved = DSA.getResolvedStack();

    const total = complaints.length;
    const pending = queues.priorityQueue.length + queues.normalQueue.length;
    const progress = complaints.filter(c => c.status === 'in-progress').length;
    const resCount = resolved.length;

    document.getElementById('stat-total').textContent = total;
    document.getElementById('stat-pending').textContent = pending;
    document.getElementById('stat-progress').textContent = progress;
    document.getElementById('stat-resolved').textContent = resCount;
}

function renderQueue(elementId, items) {
    const list = document.getElementById(elementId);
    if (!list) return;

    if (items.length === 0) {
        list.innerHTML = '<div class="empty-state">Queue is empty</div>';
        return;
    }

    const html = items.map((c, index) => {
        const date = new Date(c.timestamp).toLocaleTimeString();
        return `
        <div class="complaint-item fade-in-item stagger-${(index % 3) + 1}">
            <div class="complaint-header">
                <div>
                    <span class="complaint-student">${escapeHtml(c.studentName)}</span>
                    <span class="complaint-meta font-mono" style="margin-left:8px;">${c.id}</span>
                </div>
                <span class="badge-status">
                    <span class="dot dot-pending"></span>
                    Waiting
                </span>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default">${escapeHtml(c.category)}</span>
                <span class="complaint-meta">${date}</span>
            </div>
            <div class="complaint-meta" style="color: var(--text-primary); font-size: 0.85rem;">
                ${escapeHtml(c.description)}
            </div>
            <div class="complaint-actions">
                <button onclick="adminMarkInProgress('${c.id}')" class="btn btn-warning" style="font-size:0.75rem; padding:0.35rem 0.7rem;">Mark In Progress</button>
                <button onclick="adminResolve('${c.id}')" class="btn btn-success" style="font-size:0.75rem; padding:0.35rem 0.7rem;">Resolve Now</button>
            </div>
        </div>
        `;
    }).join("");

    list.innerHTML = html;
}

function renderInProgress() {
    const list = document.getElementById('inProgressList');
    if (!list) return;

    const complaints = DSA.getAllComplaints().filter(c => c.status === 'in-progress');

    if (complaints.length === 0) {
        list.innerHTML = '<div class="empty-state">No complaints in progress</div>';
        return;
    }

    const html = complaints.map((c, index) => {
        const prioBadge = c.isUrgent ? `<span class="badge badge-urgent" style="margin-right:8px;">Urgent</span>` : '';
        return `
        <div class="complaint-item fade-in-item stagger-${(index % 3) + 1}" style="border-left: 3px solid var(--warning);">
            <div class="complaint-header">
                <div>
                    <span class="complaint-student">${escapeHtml(c.studentName)}</span>
                    <span class="complaint-meta font-mono" style="margin-left:8px;">${c.id}</span>
                </div>
                <span class="badge-status">
                    <span class="dot dot-progress"></span>
                    In Progress
                </span>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default">${escapeHtml(c.category)}</span>
                ${prioBadge}
            </div>
            <div class="complaint-meta" style="color: var(--text-primary); font-size: 0.85rem;">
                ${escapeHtml(c.description)}
            </div>
            <div class="complaint-actions">
                <button onclick="adminResolve('${c.id}')" class="btn btn-success" style="font-size:0.75rem; padding:0.35rem 0.7rem; width: 100%;">Mark as Resolved</button>
            </div>
        </div>
        `;
    }).join("");

    list.innerHTML = html;
}

function renderResolvedStack() {
    const list = document.getElementById('resolvedStackList');
    if (!list) return;

    const stack = DSA.getResolvedStack();

    if (stack.length === 0) {
        list.innerHTML = '<div class="empty-state">Resolved stack is empty</div>';
        return;
    }

    const html = stack.slice().reverse().map((c, index) => `
        <div class="complaint-item fade-in-item stagger-${(index % 3) + 1}" style="border-left: 3px solid var(--success); opacity: 0.85;">
            <div class="complaint-header">
                <div>
                    <span class="complaint-student" style="text-decoration: line-through; color: var(--text-secondary);">${escapeHtml(c.studentName)}</span>
                    <span class="complaint-meta font-mono" style="margin-left:8px;">${c.id}</span>
                </div>
                <span class="badge-status">
                    <span class="dot dot-resolved"></span>
                    Resolved
                </span>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default">${escapeHtml(c.category)}</span>
                <span class="complaint-meta" style="margin-left: auto;">Resolved at ${new Date(c.resolvedAt).toLocaleTimeString()}</span>
            </div>
        </div>
    `).join("");

    list.innerHTML = html;
}

// Global scope bindings for inline action attributes
window.adminMarkInProgress = function (id) {
    DSA.markInProgress(id);
    showToast(`Complaint ${id} is now In Progress.`, 'warning');
    renderAdminViews();
}

window.adminResolve = function (id) {
    DSA.resolveComplaint(id);
    showToast(`Complaint ${id} is marked as Resolved.`, 'success');
    renderAdminViews();
}

window.adminUndoResolve = function () {
    const restored = DSA.undoResolve();
    if (!restored) {
        showToast("Resolved Stack is empty. Nothing to undo.", 'warning');
        return;
    }
    showToast(`Undo complete: restored ${restored.id} to In Progress.`, 'info');
    renderAdminViews();
}

// Double click confirm wrapper to avoid window.confirm popup
let resetClickedOnce = false;
window.clearSystem = function () {
    const btn = document.querySelector('button[onclick="clearSystem()"]');
    if (!resetClickedOnce) {
        resetClickedOnce = true;
        if (btn) btn.textContent = "Confirm Reset?";
        showToast("Click Reset again to confirm system wipe.", "warning");
        setTimeout(() => {
            resetClickedOnce = false;
            if (btn) btn.textContent = "Reset System";
        }, 3000);
    } else {
        DSA.clearAll();
        resetClickedOnce = false;
        if (btn) btn.textContent = "Reset System";
        showToast("System wipe complete. All complaints cleared.", "success");
        renderAdminViews();
        
        // Clear panel visual values
        const sortedList = document.getElementById('sortedComplaintsList');
        if (sortedList) sortedList.innerHTML = '<div class="empty-state" style="grid-column: 1 / -1;">Select a sort method above to run simulation.</div>';
        resetTraversalChain();
        const card = document.getElementById('searchResultCard');
        if (card) card.classList.remove('show');
        resetGraphHighlight();
    }
}

/* =========================================================
   TAB 1 - SORTING SIMULATION
   ========================================================= */
window.sortComplaints = function (method) {
    const complaints = DSA.getAllComplaints();
    if (complaints.length === 0) {
        showToast("No complaints inside the array database to sort.", "warning");
        return;
    }

    let sorted = [];
    let label = "";

    switch (method) {
        case 'bubble':
            sorted = SortingManager.bubbleSort(complaints);
            label = "Bubble Sort (by ID)";
            break;
        case 'selection':
            sorted = SortingManager.selectionSort(complaints);
            label = "Selection Sort (by Category)";
            break;
        case 'insertion':
            sorted = SortingManager.insertionSort(complaints);
            label = "Insertion Sort (by Status)";
            break;
        case 'merge':
            sorted = SortingManager.mergeSort(complaints);
            label = "Merge Sort (by ID)";
            break;
    }

    showToast(`Successfully sorted utilizing ${label}`, "success");
    renderSortList(sorted);
}

function renderSortList(items) {
    const list = document.getElementById('sortedComplaintsList');
    if (!list) return;

    if (items.length === 0) {
        list.innerHTML = '<div class="empty-state" style="grid-column: 1 / -1;">Select a sort method above to run simulation.</div>';
        return;
    }

    const html = items.map((c, index) => {
        let dotClass = 'dot-pending';
        let statusText = 'Pending';
        if (c.status === 'in-progress') {
            dotClass = 'dot-progress';
            statusText = 'In Progress';
        } else if (c.status === 'resolved') {
            dotClass = 'dot-resolved';
            statusText = 'Resolved';
        }

        const prioBadge = c.isUrgent ? `<span class="badge badge-urgent">Urgent</span>` : '';
        const delay = (index * 0.03).toFixed(2);

        return `
        <div class="complaint-item fade-in-item" style="animation-delay: ${delay}s;">
            <div class="complaint-header">
                <span class="complaint-student">${escapeHtml(c.studentName)}</span>
                <div style="display: flex; align-items: center; gap: 8px;">
                    ${prioBadge}
                    <span class="badge-status">
                        <span class="dot ${dotClass}"></span>
                        ${statusText}
                    </span>
                </div>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default">${escapeHtml(c.category)}</span>
                <span class="complaint-meta font-mono">${c.id}</span>
            </div>
            <div class="complaint-meta" style="color: var(--text-primary); font-size: 0.85rem;">
                ${escapeHtml(c.description)}
            </div>
        </div>
        `;
    }).join('');

    list.innerHTML = html;
}

/* =========================================================
   TAB 2 - BST / AVL SEARCH TREE
   ========================================================= */
window.searchTreeComplaint = function () {
    const input = document.getElementById('searchIdInput');
    if (!input) return;

    const id = input.value.trim().toUpperCase();
    if (!id) {
        showToast("Please input a search ID (e.g. CMP-1)", "warning");
        return;
    }

    const tree = DSA.getBST();
    
    const complaint = tree.search(id);
    const card = document.getElementById('searchResultCard');

    if (!complaint) {
        showToast(`Complaint ${id} not found inside the BST.`, "danger");
        if (card) card.classList.remove('show');
        return;
    }

    showToast(`Found Complaint ${id} inside BST Index structure!`, "success");

    let dotClass = 'dot-pending';
    let statusText = 'Pending';
    if (complaint.status === 'in-progress') {
        dotClass = 'dot-progress';
        statusText = 'In Progress';
    } else if (complaint.status === 'resolved') {
        dotClass = 'dot-resolved';
        statusText = 'Resolved';
    }

    const prioBadge = complaint.isUrgent ? `<span class="badge badge-urgent">Urgent</span>` : '';

    card.innerHTML = `
    <div class="complaint-item" style="border-left: 3px solid var(--accent); margin-bottom: 0;">
        <h3 class="stat-title" style="color: var(--accent); margin-bottom: 0.35rem; font-size: 0.75rem;">Tree Query Results</h3>
        <div class="complaint-header">
            <span class="complaint-student">${escapeHtml(complaint.studentName)}</span>
            <div style="display: flex; align-items: center; gap: 8px;">
                ${prioBadge}
                <span class="badge-status">
                    <span class="dot ${dotClass}"></span>
                    ${statusText}
                </span>
            </div>
        </div>
        <div class="complaint-info-row">
            <span class="badge badge-default">${escapeHtml(complaint.category)}</span>
            <span class="complaint-meta font-mono">${complaint.id}</span>
        </div>
        <div class="complaint-meta" style="color: var(--text-primary); font-size: 0.85rem;">
            ${escapeHtml(complaint.description)}
        </div>
    </div>
    `;

    card.classList.add('show');

    // Visually highlight corresponding item inside the chain representation if present
    document.querySelectorAll('.chain-node').forEach(node => {
        if (node.getAttribute('data-id') === id) {
            node.classList.add('active-search');
        } else {
            node.classList.remove('active-search');
        }
    });
}

window.visualizeTreeTraversal = function (order) {
    const tree = DSA.getBST();
    
    let result = [];
    if (order === 'inorder') {
        result = tree.inorder();
    } else if (order === 'preorder') {
        result = tree.preorder();
    } else if (order === 'postorder') {
        result = tree.postorder();
    }

    const chain = document.getElementById('traversalChain');
    if (!chain) return;

    if (result.length === 0) {
        chain.innerHTML = '<div class="empty-state" style="width: 100%; padding: 1.5rem;">No complaints indexed inside this tree structure.</div>';
        return;
    }

    const html = result.map((c, index) => {
        const urgentStyle = c.isUrgent ? 'border-color: var(--danger);' : '';
        return `
        <div class="chain-node" data-id="${c.id}" onclick="showChainNodeDetails('${c.id}')" style="${urgentStyle}">
            <span class="font-mono" style="font-weight:600; font-size:0.85rem;">${c.id}</span>
            <span style="font-size:0.65rem; color:var(--text-secondary); text-transform:uppercase;">${escapeHtml(c.category)}</span>
        </div>
        ${index < result.length - 1 ? '<span class="chain-arrow">&rarr;</span>' : ''}
        `;
    }).join('');

    chain.innerHTML = html;
    showToast(`Rendered ${order.toUpperCase()} Traversal sequence.`, "info");
}

window.showChainNodeDetails = function (id) {
    const input = document.getElementById('searchIdInput');
    if (input) {
        input.value = id;
        searchTreeComplaint();
    }
}

function resetTraversalChain() {
    const chain = document.getElementById('traversalChain');
    if (chain) {
        chain.innerHTML = '<div class="empty-state" style="width: 100%; padding: 1.5rem;">Click a traversal type above to display structured tree order.</div>';
    }
}

/* =========================================================
   TAB 3 - DEPARTMENT ROUTING GRAPH
   ========================================================= */
let graphAnimTimeout = null;

function initGraphBindings() {
    // Direct click handler on SVG nodes to update selector
    const svgNodes = document.querySelectorAll('.graph-node');
    svgNodes.forEach(node => {
        node.addEventListener('click', function () {
            const name = this.getAttribute('data-name');
            const select = document.getElementById('startNodeSelect');
            if (select) {
                select.value = name;
                showToast(`Starting Node set to: ${name}`, "info");
                highlightActiveStartNode(name);
            }
        });
    });
}

function getEdgeId(nodeA, nodeB) {
    const sorted = [nodeA, nodeB].sort();
    const cleanA = sorted[0].replace(/ /g, '-');
    const cleanB = sorted[1].replace(/ /g, '-');
    return `edge-${cleanA}-${cleanB}`;
}

function highlightActiveStartNode(nodeName) {
    resetGraphHighlight();
    const elementId = `node-${nodeName.replace(/ /g, '-')}`;
    const el = document.getElementById(elementId);
    if (el) el.classList.add('active');
}

function clearGraphTimeouts() {
    if (graphAnimTimeout) {
        clearTimeout(graphAnimTimeout);
        graphAnimTimeout = null;
    }
}

function resetGraphHighlight() {
    document.querySelectorAll('.graph-node').forEach(node => {
        node.classList.remove('active', 'visited');
    });
    document.querySelectorAll('.graph-edge').forEach(edge => {
        edge.classList.remove('active', 'visited');
    });
}

window.runBFS = function () {
    animateGraphTraversal('bfs');
}

window.runDFS = function () {
    animateGraphTraversal('dfs');
}

function animateGraphTraversal(type) {
    clearGraphTimeouts();
    resetGraphHighlight();

    const startNode = document.getElementById('startNodeSelect').value;
    const graph = DSA.getGraph();
    const sequence = (type === 'bfs') ? graph.bfs(startNode) : graph.dfs(startNode);

    const statusEl = document.getElementById('graphAnimationStatus');
    if (statusEl) statusEl.textContent = `Initializing ${type.toUpperCase()}...`;

    highlightActiveStartNode(startNode);

    let idx = 0;
    function walk() {
        if (idx >= sequence.length) {
            if (statusEl) statusEl.innerHTML = `<span style="color:var(--success); font-weight:bold;">${type.toUpperCase()} Sequence:</span> ${sequence.join(' ➔ ')}`;
            showToast(`${type.toUpperCase()} traversal demonstration complete.`, 'success');
            return;
        }

        const current = sequence[idx];
        const elementId = `node-${current.replace(/ /g, '-')}`;
        const nodeEl = document.getElementById(elementId);

        if (nodeEl) {
            nodeEl.classList.remove('active');
            nodeEl.classList.add('visited');
        }

        // Highlight connecting path line
        if (idx > 0) {
            const prev = sequence[idx - 1];
            const edgeId = getEdgeId(prev, current);
            const edgeEl = document.getElementById(edgeId);
            if (edgeEl) edgeEl.classList.add('visited');
        }

        if (statusEl) {
            statusEl.innerHTML = `<span style="color: var(--success); font-weight:500;">Traversing:</span> ${sequence.slice(0, idx + 1).join(' ➔ ')}`;
        }

        idx++;
        graphAnimTimeout = setTimeout(walk, 600);
    }

    graphAnimTimeout = setTimeout(walk, 600);
}

window.runDijkstra = function () {
    clearGraphTimeouts();
    resetGraphHighlight();

    const startNode = document.getElementById('startNodeSelect').value;
    const graph = DSA.getGraph();
    const { distances, paths } = graph.dijkstra(startNode);

    const resultDiv = document.getElementById('dijkstraResult');
    if (!resultDiv) return;

    showToast(`Dijkstra pathfinding completed from ${startNode}`, "success");
    highlightActiveStartNode(startNode);

    const statusEl = document.getElementById('graphAnimationStatus');
    if (statusEl) statusEl.textContent = `Shortest path calculations from root "${startNode}":`;

    const html = `
    <h3 class="stat-title" style="margin-bottom: 0.5rem; margin-top: 1rem;">Cost Adjacency Table</h3>
    <table class="dark-table">
        <thead>
            <tr>
                <th>Destination</th>
                <th>Routing Sequence</th>
                <th>Min Weight Cost</th>
            </tr>
        </thead>
        <tbody>
            ${graph.nodes.map(node => {
                const pathStr = paths[node].join(' ➔ ');
                const cost = distances[node] === Infinity ? 'Unreachable' : distances[node];
                return `
                <tr onmouseenter="highlightPath(${JSON.stringify(paths[node])})" onmouseleave="resetGraphHighlight(); highlightActiveStartNode('${startNode}');">
                    <td><strong>${node}</strong></td>
                    <td class="font-mono" style="font-size: 0.8rem; color: var(--accent);">${pathStr}</td>
                    <td class="font-mono" style="font-weight: bold; color: var(--success);">${cost}</td>
                </tr>
                `;
            }).join('')}
        </tbody>
    </table>
    `;

    resultDiv.innerHTML = html;
}

window.highlightPath = function (path) {
    resetGraphHighlight();
    if (!path || path.length === 0) return;

    path.forEach(node => {
        const elementId = `node-${node.replace(/ /g, '-')}`;
        const el = document.getElementById(elementId);
        if (el) el.classList.add('active');
    });

    for (let i = 0; i < path.length - 1; i++) {
        const edgeId = getEdgeId(path[i], path[i + 1]);
        const edgeEl = document.getElementById(edgeId);
        if (edgeEl) edgeEl.classList.add('active');
    }
}
