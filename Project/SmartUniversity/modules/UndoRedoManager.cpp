#include "UndoRedoManager.h"
#include <iostream>
using namespace std;

void UndoRedoManager::doAction(Student s) {
    undoStack.push(s);
    cout << "Action done for: " << s.name << endl;
}

void UndoRedoManager::undo() {
    if (!undoStack.isEmpty()) {
        Student s = undoStack.pop();
        redoStack.push(s);
        cout << "Undo: " << s.name << endl;
    } else {
        cout << "Nothing to undo" << endl;
    }
}

void UndoRedoManager::redo() {
    if (!redoStack.isEmpty()) {
        Student s = redoStack.pop();
        undoStack.push(s);
        cout << "Redo: " << s.name << endl;
    } else {
        cout << "Nothing to redo" << endl;
    }
}

void UndoRedoManager::displayStacks() {
    cout << "Undo stack size: " << undoStack.getSize() << endl;
    cout << "Redo stack size: " << redoStack.getSize() << endl;
}