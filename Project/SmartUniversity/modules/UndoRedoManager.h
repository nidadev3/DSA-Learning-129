#ifndef UNDOREDOMANAGER_H
#define UNDOREDOMANAGER_H

#include "../include/Stack.h"

class UndoRedoManager {
private:
    Stack undoStack;
    Stack redoStack;
public:
    void doAction(Student s);
    void undo();
    void redo();
    void displayStacks();
};

#endif