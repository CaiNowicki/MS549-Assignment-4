#include <cstddef>
#include <stdlib.h>
#include <iostream>
#include "functions.h"

//https://www.geeksforgeeks.org/implementation-deque-using-doubly-linked-list/#
//(modified to fit assignment)

using namespace std;

//create Node of doubly linked list
struct Node {
	int data;
	Node* prev, * next;
	static Node* getnode(int data) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->prev = newNode->next = NULL;
		return newNode;
	}

};

//Queue structure
class Queue {
	Node* front;
	Node* rear;
	int Size;
public:
	Queue() {
		front = rear = NULL;
		Size = 0;
	}
	//operations on Queue - FIFO
	void insert(int data);
	void remove();
	int printAll();
	int size();
	bool isEmpty();
	void erase();
};

//Check if queue is empty
bool Queue::isEmpty() {
	return (front == NULL);
}

//Return number of elements in Queue
int Queue::size() {
	return Size;
}

//Insert an element at front of Queue
void Queue::insert(int data) {
	Node* newNode = Node::getnode(data);
	if (newNode == NULL)
		cout << "Cannot add new node - overflow" << endl;
	else {
		if (front == NULL) //queue is empty
			rear = front = newNode;
		else {
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}
		Size++;
	}
}

//Remove an element from the front of the Queue
void Queue::remove() {
	if (isEmpty())
		cout << "Empty queue, cannot delete" << endl;
	else {
		Node* temp = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		else
			front->prev = NULL;
		free(temp);
		Size--;
	}
}

//Delete all elements in the queue
void Queue::erase() {
	rear = NULL;
	while (front != NULL) {
		Node* temp = front;
		front = front->next;
		free(temp);
	}
	Size = 0;
}

//end GeeksForGeeks code snippet

int Queue::printAll() {
	if (isEmpty()) {
		cout << "Queue is empty." << endl;
		return 0;
	}
	Node* current = front;
	cout << "Elements: ";
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
	return Size;
}