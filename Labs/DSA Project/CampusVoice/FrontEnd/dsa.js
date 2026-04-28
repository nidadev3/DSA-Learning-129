/**
 * DSA Simulation Layer for CampusVoice
 * Utilizing localStorage to persist state across pages.
 */

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

    // Submit a new complaint, matching the C++ Object fields
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

        // Add to Array (All Complaints)
        data.allComplaints.push(newComplaint);

        // Queue logic
        if (isUrgent) {
            // Priority Queue
            data.priorityQueue.push(newComplaint);
        } else {
            // Normal Queue
            data.normalQueue.push(newComplaint);
        }

        this.saveData(data);
        return newComplaint;
    }

    // Admin function: Get next complaints
    getQueues() {
        const data = this.getData();
        return {
            priorityQueue: data.priorityQueue,
            normalQueue: data.normalQueue
        };
    }

    // Set complaint as In-Progress
    markInProgress(complaintId) {
        const data = this.getData();

        // Remove from whichever queue it is in
        data.priorityQueue = data.priorityQueue.filter(c => c.id !== complaintId);
        data.normalQueue = data.normalQueue.filter(c => c.id !== complaintId);

        // Update in All Complaints array
        const complaint = data.allComplaints.find(c => c.id === complaintId);
        if (complaint && complaint.status === 'pending') {
            complaint.status = 'in-progress';
        }

        this.saveData(data);
    }

    // Set complaint as Resolved
    resolveComplaint(complaintId) {
        const data = this.getData();

        // Ensure it's out of queues
        data.priorityQueue = data.priorityQueue.filter(c => c.id !== complaintId);
        data.normalQueue = data.normalQueue.filter(c => c.id !== complaintId);

        // Update in All Complaints array
        let resolvedItem = null;
        for (let i = 0; i < data.allComplaints.length; i++) {
            if (data.allComplaints[i].id === complaintId) {
                data.allComplaints[i].status = 'resolved';
                resolvedItem = data.allComplaints[i];
                break;
            }
        }

        // Push to Stack
        if (resolvedItem) {
            data.resolvedStack.push({
                ...resolvedItem,
                resolvedAt: new Date().toISOString()
            });
        }

        this.saveData(data);
    }

    // Delete complaint totally (Clear)
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
}

const DSA = new dsaManager();
