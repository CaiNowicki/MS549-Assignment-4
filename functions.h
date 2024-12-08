#pragma once

#include <cstddef>

// Node of the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Static method to create a new node
    static Node* getnode(int data);
};

// Queue class
class Queue {
    Node* front;
    Node* rear;
    int Size;

public:
    // Constructor
    Queue();

    // Queue operations
    void insert(int data);
    void remove();
    int size();
    bool isEmpty();
    void erase();
    int printAll();
};

//Stack class
class Stack {
    Node* start;
    Node* top;
    int Size;

public:
    //Constructor
    Stack();

    //Stack operations
    void insert(int data);
    void remove();
    int size();
    bool isEmpty();
    void erase();
    int printAll();
};
void measureInsertionTime();
void measureDeleteTime();