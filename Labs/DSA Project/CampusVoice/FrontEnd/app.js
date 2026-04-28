/**
 * app.js - DOM interaction and bindings to dsa.js structures
 */

document.addEventListener('DOMContentLoaded', () => {
    // Determine which page we're on by checking elements
    if (document.getElementById('complaintForm')) {
        initStudentPortal();
    }

    if (document.getElementById('priorityQueueList')) {
        initAdminDashboard();
    }
});

/* =========================================================
   STUDENT PORTAL
   ========================================================= */
function initStudentPortal() {
    renderStudentHistory();

    document.getElementById('complaintForm').addEventListener('submit', function (e) {
        e.preventDefault();

        const studentName = document.getElementById('cStudentName').value;
        const category = document.getElementById('cCategory').value;
        const desc = document.getElementById('cDesc').value;
        const priority = document.getElementById('cPriority').value;
        const isUrgent = priority === 'urgent';

        // Add to data structures
        DSA.submitComplaint(studentName, category, desc, isUrgent);

        // Reset form
        this.reset();

        // Visual confirm & re-render
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

    // Since array maintains all complaints, we'll reverse it to show newest on top in UI
    const html = complaints.slice().reverse().map(c => {
        let badgeClass = 'badge-pending';
        if (c.status === 'in-progress') badgeClass = 'badge-progress';
        if (c.status === 'resolved') badgeClass = 'badge-resolved';

        let prioBadge = c.isUrgent ? `<span class="badge badge-urgent">Urgent</span>` : `<span class="badge badge-default">Normal</span>`;

        return `
        <div class="complaint-item">
            <div class="complaint-header">
                <span class="complaint-student">${c.studentName}</span>
                <div>${prioBadge} <span class="badge ${badgeClass}">${c.status}</span></div>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default" style="font-size: 0.7rem; background: #e2e8f0;">${c.category}</span>
                <span class="complaint-meta">ID: ${c.id}</span>
            </div>
            <div class="complaint-meta">${c.description}</div>
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
}

function renderAdminViews() {
    const queues = DSA.getQueues();
    renderQueue('priorityQueueList', queues.priorityQueue);
    renderQueue('normalQueueList', queues.normalQueue);

    renderInProgress();
    renderStack();
}

function renderQueue(elementId, items) {
    const list = document.getElementById(elementId);
    if (!list) return;

    if (items.length === 0) {
        list.innerHTML = '<div class="empty-state">Queue is empty</div>';
        return;
    }

    const html = items.map(c => `
        <div class="complaint-item">
            <div class="complaint-header">
                <div>
                    <span class="complaint-student">${c.studentName}</span>
                    <span class="complaint-meta" style="margin-left:8px;">${c.id}</span>
                </div>
                <span class="badge badge-pending">Waiting</span>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default" style="font-size: 0.7rem; background: #e2e8f0;">${c.category}</span>
            </div>
            <div class="complaint-meta">${c.description}</div>
            <div class="complaint-actions">
                <button onclick="adminMarkInProgress('${c.id}')" class="btn btn-warning" style="font-size:0.8rem; padding:0.4rem 0.8rem;">Mark In Progress</button>
                <button onclick="adminResolve('${c.id}')" class="btn btn-success" style="font-size:0.8rem; padding:0.4rem 0.8rem;">Resolve Now</button>
            </div>
        </div>
    `).join("");

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

    const html = complaints.map(c => `
        <div class="complaint-item" style="border-left: 4px solid #f59e0b;">
            <div class="complaint-header">
                <div>
                    <span class="complaint-student">${c.studentName}</span>
                    <span class="complaint-meta" style="margin-left:8px;">${c.id}</span>
                </div>
                <span class="badge badge-progress">In Progress</span>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default" style="font-size: 0.7rem; background: #e2e8f0;">${c.category}</span>
            </div>
            <div class="complaint-meta">${c.description}</div>
            <div class="complaint-actions">
                <button onclick="adminResolve('${c.id}')" class="btn btn-success" style="font-size:0.8rem; padding:0.4rem 0.8rem;">Mark as Resolved</button>
            </div>
        </div>
    `).join("");

    list.innerHTML = html;
}

// Stack view (LIFO - Top of stack first)
function renderStack() {
    const list = document.getElementById('resolvedStackList');
    if (!list) return;

    const stack = DSA.getResolvedStack();

    if (stack.length === 0) {
        list.innerHTML = '<div class="empty-state">Stack is empty</div>';
        return;
    }

    // Stack is visualized by mapping it from top to bottom (reverse array)
    const html = stack.slice().reverse().map(c => `
        <div class="complaint-item" style="border-left: 4px solid #10b981; background-color: #f8fafc;">
            <div class="complaint-header">
                <div>
                    <span class="complaint-student"><del>${c.studentName}</del></span>
                    <span class="complaint-meta" style="margin-left:8px;">${c.id}</span>
                </div>
                <span class="badge badge-resolved">Resolved</span>
            </div>
            <div class="complaint-info-row">
                <span class="badge badge-default" style="font-size: 0.7rem; background: #e2e8f0;">${c.category}</span>
            </div>
            <div class="complaint-meta">Popped from Stack &bull; ${new Date(c.resolvedAt).toLocaleTimeString()}</div>
        </div>
    `).join("");

    list.innerHTML = html;
}

// Global scope actions for inline onclick attributes
window.adminMarkInProgress = function (id) {
    DSA.markInProgress(id);
    renderAdminViews();
}

window.adminResolve = function (id) {
    DSA.resolveComplaint(id);
    renderAdminViews();
}

window.clearSystem = function () {
    if (confirm("Are you sure you want to reset all data?")) {
        DSA.clearAll();
        renderAdminViews();
    }
}
