/**
 * DSA Simulation Layer for CampusVoice
 * Utilizing localStorage to persist state across pages.
 */

// Helper Data Structures as required
class Queue {
    constructor(items = []) {
        this.items = [...items];
    }
    enqueue(item) {
        this.items.push(item);
    }
    dequeue() {
        return this.items.shift();
    }
    peek() {
        return this.items[0];
    }
    isEmpty() {
        return this.items.length === 0;
    }
    toArray() {
        return this.items;
    }
}

class PriorityQueue {
    constructor(items = []) {
        this.items = [...items];
        this.sort();
    }
    enqueue(item) {
        this.items.push(item);
        this.sort();
    }
    dequeue() {
        return this.items.shift();
    }
    peek() {
        return this.items[0];
    }
    isEmpty() {
        return this.items.length === 0;
    }
    sort() {
        // High priority (isUrgent) first. If same priority, oldest first.
        this.items.sort((a, b) => {
            const pA = a.isUrgent ? 2 : 1;
            const pB = b.isUrgent ? 2 : 1;
            if (pA !== pB) return pB - pA;
            return new Date(a.timestamp) - new Date(b.timestamp);
        });
    }
    toArray() {
        return this.items;
    }
}

class Stack {
    constructor(items = []) {
        this.items = [...items];
    }
    push(item) {
        this.items.push(item);
    }
    pop() {
        return this.items.pop();
    }
    peek() {
        return this.items[this.items.length - 1];
    }
    isEmpty() {
        return this.items.length === 0;
    }
    toArray() {
        return this.items;
    }
}

class LinkedListNode {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    constructor(items = []) {
        this.head = null;
        this.tail = null;
        this.length = 0;
        for (const item of items) {
            this.append(item);
        }
    }
    append(value) {
        const node = new LinkedListNode(value);
        if (!this.head) {
            this.head = node;
            this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = node;
        }
        this.length++;
    }
    remove(id) {
        if (!this.head) return null;
        if (this.head.value.id === id) {
            const val = this.head.value;
            this.head = this.head.next;
            if (!this.head) this.tail = null;
            this.length--;
            return val;
        }
        let current = this.head;
        while (current.next) {
            if (current.next.value.id === id) {
                const val = current.next.value;
                if (current.next === this.tail) {
                    this.tail = current;
                }
                current.next = current.next.next;
                this.length--;
                return val;
            }
            current = current.next;
        }
        return null;
    }
    toArray() {
        const arr = [];
        let current = this.head;
        while (current) {
            arr.push(current.value);
            current = current.next;
        }
        return arr;
    }
}

// SortingManager
class SortingManager {
    static bubbleSort(arr) {
        const list = [...arr];
        const n = list.length;
        const parseId = (c) => parseInt(c.id.replace('CMP-', '')) || 0;
        for (let i = 0; i < n - 1; i++) {
            for (let j = 0; j < n - i - 1; j++) {
                if (parseId(list[j]) > parseId(list[j + 1])) {
                    const temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
        return list;
    }

    static selectionSort(arr) {
        const list = [...arr];
        const n = list.length;
        for (let i = 0; i < n - 1; i++) {
            let minIdx = i;
            for (let j = i + 1; j < n; j++) {
                if (list[j].category.localeCompare(list[minIdx].category) < 0) {
                    minIdx = j;
                }
            }
            if (minIdx !== i) {
                const temp = list[i];
                list[i] = list[minIdx];
                list[minIdx] = temp;
            }
        }
        return list;
    }

    static insertionSort(arr) {
        const list = [...arr];
        const n = list.length;
        const statusWeight = { 'pending': 1, 'in-progress': 2, 'resolved': 3 };
        for (let i = 1; i < n; i++) {
            const key = list[i];
            let j = i - 1;
            while (j >= 0 && statusWeight[list[j].status] > statusWeight[key.status]) {
                list[j + 1] = list[j];
                j = j - 1;
            }
            list[j + 1] = key;
        }
        return list;
    }

    static mergeSort(arr) {
        const parseId = (c) => parseInt(c.id.replace('CMP-', '')) || 0;
        
        function merge(left, right) {
            const result = [];
            let l = 0, r = 0;
            while (l < left.length && r < right.length) {
                if (parseId(left[l]) <= parseId(right[r])) {
                    result.push(left[l]);
                    l++;
                } else {
                    result.push(right[r]);
                    r++;
                }
            }
            return result.concat(left.slice(l)).concat(right.slice(r));
        }

        function sort(m) {
            if (m.length <= 1) return m;
            const middle = Math.floor(m.length / 2);
            const left = m.slice(0, middle);
            const right = m.slice(middle);
            return merge(sort(left), sort(right));
        }

        return sort([...arr]);
    }
}

// BSTManager
class BSTNode {
    constructor(complaint) {
        this.complaint = complaint;
        this.id = parseInt(complaint.id.replace('CMP-', '')) || 0;
        this.left = null;
        this.right = null;
    }
}

class BSTManager {
    constructor() {
        this.root = null;
    }

    insert(complaint) {
        const newNode = new BSTNode(complaint);
        if (!this.root) {
            this.root = newNode;
            return;
        }
        this._insertNode(this.root, newNode);
    }

    _insertNode(node, newNode) {
        if (newNode.id < node.id) {
            if (!node.left) {
                node.left = newNode;
            } else {
                this._insertNode(node.left, newNode);
            }
        } else {
            if (!node.right) {
                node.right = newNode;
            } else {
                this._insertNode(node.right, newNode);
            }
        }
    }

    search(id) {
        const numericId = parseInt(id.replace('CMP-', '')) || 0;
        return this._searchNode(this.root, numericId);
    }

    _searchNode(node, numericId) {
        if (!node) return null;
        if (numericId === node.id) return node.complaint;
        if (numericId < node.id) return this._searchNode(node.left, numericId);
        return this._searchNode(node.right, numericId);
    }

    delete(id) {
        const numericId = parseInt(id.replace('CMP-', '')) || 0;
        this.root = this._deleteNode(this.root, numericId);
    }

    _deleteNode(node, numericId) {
        if (!node) return null;
        if (numericId < node.id) {
            node.left = this._deleteNode(node.left, numericId);
            return node;
        } else if (numericId > node.id) {
            node.right = this._deleteNode(node.right, numericId);
            return node;
        } else {
            // Found node to delete
            if (!node.left && !node.right) {
                return null;
            }
            if (!node.left) return node.right;
            if (!node.right) return node.left;

            // Two children
            const temp = this._findMinNode(node.right);
            node.complaint = temp.complaint;
            node.id = temp.id;
            node.right = this._deleteNode(node.right, temp.id);
            return node;
        }
    }

    _findMinNode(node) {
        let current = node;
        while (current.left) {
            current = current.left;
        }
        return current;
    }

    inorder() {
        const result = [];
        this._inorderHelper(this.root, result);
        return result;
    }

    _inorderHelper(node, result) {
        if (node) {
            this._inorderHelper(node.left, result);
            result.push(node.complaint);
            this._inorderHelper(node.right, result);
        }
    }

    preorder() {
        const result = [];
        this._preorderHelper(this.root, result);
        return result;
    }

    _preorderHelper(node, result) {
        if (node) {
            result.push(node.complaint);
            this._preorderHelper(node.left, result);
            this._preorderHelper(node.right, result);
        }
    }

    postorder() {
        const result = [];
        this._postorderHelper(this.root, result);
        return result;
    }

    _postorderHelper(node, result) {
        if (node) {
            this._postorderHelper(node.left, result);
            this._postorderHelper(node.right, result);
            result.push(node.complaint);
        }
    }
}

// AVLManager
class AVLNode {
    constructor(complaint) {
        this.complaint = complaint;
        this.id = parseInt(complaint.id.replace('CMP-', '')) || 0;
        this.left = null;
        this.right = null;
        this.height = 1;
    }
}

class AVLManager {
    constructor() {
        this.root = null;
    }

    getHeight(node) {
        return node ? node.height : 0;
    }

    getBalanceFactor(node) {
        return node ? this.getHeight(node.left) - this.getHeight(node.right) : 0;
    }

    updateHeight(node) {
        if (node) {
            node.height = 1 + Math.max(this.getHeight(node.left), this.getHeight(node.right));
        }
    }

    rightRotate(y) {
        const x = y.left;
        const T2 = x.right;
        x.right = y;
        y.left = T2;
        this.updateHeight(y);
        this.updateHeight(x);
        return x;
    }

    leftRotate(x) {
        const y = x.right;
        const T2 = y.left;
        y.left = x;
        x.right = T2;
        this.updateHeight(x);
        this.updateHeight(y);
        return y;
    }

    insert(complaint) {
        this.root = this._insertNode(this.root, complaint);
    }

    _insertNode(node, complaint) {
        const id = parseInt(complaint.id.replace('CMP-', '')) || 0;
        if (!node) return new AVLNode(complaint);

        if (id < node.id) {
            node.left = this._insertNode(node.left, complaint);
        } else if (id > node.id) {
            node.right = this._insertNode(node.right, complaint);
        } else {
            return node; // Duplicates not allowed
        }

        this.updateHeight(node);
        const balance = this.getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && id < node.left.id) {
            return this.rightRotate(node);
        }
        // Right Right Case
        if (balance < -1 && id > node.right.id) {
            return this.leftRotate(node);
        }
        // Left Right Case
        if (balance > 1 && id > node.left.id) {
            node.left = this.leftRotate(node.left);
            return this.rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && id < node.right.id) {
            node.right = this.rightRotate(node.right);
            return this.leftRotate(node);
        }

        return node;
    }

    search(id) {
        const numericId = parseInt(id.replace('CMP-', '')) || 0;
        return this._searchNode(this.root, numericId);
    }

    _searchNode(node, numericId) {
        if (!node) return null;
        if (numericId === node.id) return node.complaint;
        if (numericId < node.id) return this._searchNode(node.left, numericId);
        return this._searchNode(node.right, numericId);
    }

    inorder() {
        const result = [];
        this._inorderHelper(this.root, result);
        return result;
    }

    _inorderHelper(node, result) {
        if (node) {
            this._inorderHelper(node.left, result);
            result.push(node.complaint);
            this._inorderHelper(node.right, result);
        }
    }

    preorder() {
        const result = [];
        this._preorderHelper(this.root, result);
        return result;
    }

    _preorderHelper(node, result) {
        if (node) {
            result.push(node.complaint);
            this._preorderHelper(node.left, result);
            this._preorderHelper(node.right, result);
        }
    }

    postorder() {
        const result = [];
        this._postorderHelper(this.root, result);
        return result;
    }

    _postorderHelper(node, result) {
        if (node) {
            this._postorderHelper(node.left, result);
            this._postorderHelper(node.right, result);
            result.push(node.complaint);
        }
    }
}

// GraphManager
class GraphManager {
    constructor() {
        this.nodes = ['Student Affairs', 'Lab', 'Hostel', 'Cafe', 'IT Dept', 'Admin Office'];
        this.adjacencyList = {};
        for (const node of this.nodes) {
            this.adjacencyList[node] = [];
        }
        this.initEdges();
    }

    initEdges() {
        this.addEdge('Student Affairs', 'Lab', 2);
        this.addEdge('Student Affairs', 'Hostel', 4);
        this.addEdge('Student Affairs', 'Admin Office', 1);
        this.addEdge('Lab', 'IT Dept', 3);
        this.addEdge('Hostel', 'Cafe', 2);
        this.addEdge('Cafe', 'Admin Office', 5);
        this.addEdge('IT Dept', 'Admin Office', 2);
    }

    addEdge(u, v, weight) {
        this.adjacencyList[u].push({ node: v, weight });
        this.adjacencyList[v].push({ node: u, weight });
    }

    bfs(start) {
        const visited = {};
        const queue = [start];
        const result = [];
        visited[start] = true;

        while (queue.length > 0) {
            const current = queue.shift();
            result.push(current);

            // Alphabetical sorting of neighbor node names for deterministic outcomes
            const neighbors = this.adjacencyList[current]
                .map(edge => edge.node)
                .sort();

            for (const neighbor of neighbors) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
        return result;
    }

    dfs(start) {
        const visited = {};
        const result = [];

        const dfsHelper = (node) => {
            visited[node] = true;
            result.push(node);

            const neighbors = this.adjacencyList[node]
                .map(edge => edge.node)
                .sort();

            for (const neighbor of neighbors) {
                if (!visited[neighbor]) {
                    dfsHelper(neighbor);
                }
            }
        };

        dfsHelper(start);
        return result;
    }

    dijkstra(src) {
        const distances = {};
        const previous = {};
        const unvisited = new Set();

        for (const node of this.nodes) {
            distances[node] = Infinity;
            previous[node] = null;
            unvisited.add(node);
        }
        distances[src] = 0;

        while (unvisited.size > 0) {
            let current = null;
            let minDistance = Infinity;
            for (const node of unvisited) {
                if (distances[node] < minDistance) {
                    minDistance = distances[node];
                    current = node;
                }
            }

            if (current === null || minDistance === Infinity) {
                break;
            }

            unvisited.delete(current);

            for (const edge of this.adjacencyList[current]) {
                const neighbor = edge.node;
                if (!unvisited.has(neighbor)) continue;

                const alt = distances[current] + edge.weight;
                if (alt < distances[neighbor]) {
                    distances[neighbor] = alt;
                    previous[neighbor] = current;
                }
            }
        }

        const paths = {};
        for (const dest of this.nodes) {
            if (dest === src) {
                paths[dest] = [src];
                continue;
            }
            const path = [];
            let curr = dest;
            while (curr !== null) {
                path.unshift(curr);
                curr = previous[curr];
            }
            paths[dest] = path[0] === src ? path : [];
        }

        return { distances, paths };
    }
}

// Extended dsaManager
class dsaManager {
    constructor() {
        this.storageKey = 'campusVoiceDSA';
        this.initStorage();
    }

    initStorage() {
        if (!localStorage.getItem(this.storageKey)) {
            const data = {
                allComplaints: [], // Array
                normalQueue: [],   // Queue (FIFO)
                priorityQueue: [], // Priority Queue 
                resolvedStack: [], // Stack (LIFO)
                nextId: 1
            };
            this.saveData(data);
        }
    }

    getData() {
        return JSON.parse(localStorage.getItem(this.storageKey));
    }

    saveData(data) {
        localStorage.setItem(this.storageKey, JSON.stringify(data));
    }

    submitComplaint(studentName, category, description, isUrgent) {
        const data = this.getData();
        const newComplaint = {
            id: `CMP-${data.nextId++}`,
            studentName,
            category,
            description,
            isUrgent,
            status: 'pending',
            timestamp: new Date().toISOString()
        };

        data.allComplaints.push(newComplaint);

        if (isUrgent) {
            data.priorityQueue.push(newComplaint);
        } else {
            data.normalQueue.push(newComplaint);
        }

        this.saveData(data);
        return newComplaint;
    }

    getQueues() {
        const data = this.getData();
        return {
            priorityQueue: data.priorityQueue,
            normalQueue: data.normalQueue
        };
    }

    markInProgress(complaintId) {
        const data = this.getData();

        data.priorityQueue = data.priorityQueue.filter(c => c.id !== complaintId);
        data.normalQueue = data.normalQueue.filter(c => c.id !== complaintId);

        const complaint = data.allComplaints.find(c => c.id === complaintId);
        if (complaint && complaint.status === 'pending') {
            complaint.status = 'in-progress';
        }

        this.saveData(data);
    }

    resolveComplaint(complaintId) {
        const data = this.getData();

        data.priorityQueue = data.priorityQueue.filter(c => c.id !== complaintId);
        data.normalQueue = data.normalQueue.filter(c => c.id !== complaintId);

        let resolvedItem = null;
        for (let i = 0; i < data.allComplaints.length; i++) {
            if (data.allComplaints[i].id === complaintId) {
                data.allComplaints[i].status = 'resolved';
                resolvedItem = data.allComplaints[i];
                break;
            }
        }

        if (resolvedItem) {
            data.resolvedStack.push({
                ...resolvedItem,
                resolvedAt: new Date().toISOString()
            });
        }

        this.saveData(data);
    }

    undoResolve() {
        const data = this.getData();
        if (data.resolvedStack.length === 0) return null;

        const restored = data.resolvedStack.pop();
        restored.status = 'in-progress';
        delete restored.resolvedAt;

        for (let i = 0; i < data.allComplaints.length; i++) {
            if (data.allComplaints[i].id === restored.id) {
                data.allComplaints[i].status = 'in-progress';
                break;
            }
        }

        this.saveData(data);
        return restored;
    }

    clearAll() {
        localStorage.removeItem(this.storageKey);
        this.initStorage();
    }

    getAllComplaints() {
        return this.getData().allComplaints;
    }

    getResolvedStack() {
        return this.getData().resolvedStack;
    }

    // Factory methods to build and return structures based on current state
    getBST() {
        const bst = new BSTManager();
        const complaints = this.getAllComplaints();
        for (const c of complaints) {
            bst.insert(c);
        }
        return bst;
    }

    getAVL() {
        const avl = new AVLManager();
        const complaints = this.getAllComplaints();
        for (const c of complaints) {
            avl.insert(c);
        }
        return avl;
    }

    getGraph() {
        return new GraphManager();
    }
}

const DSA = new dsaManager();
