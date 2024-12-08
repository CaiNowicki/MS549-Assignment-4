#include <cstddef>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "functions.h"

//https://www.geeksforgeeks.org/implementation-deque-using-doubly-linked-list/#
//(modified to fit assignment)

using namespace std;


//create Node of doubly linked list
Node* Node::getnode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		cout << "Memory allocation failed" << endl;
		return NULL;
	}
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	return newNode;
}


// Constructor for the Queue class
Queue::Queue() {
	front = rear = NULL;
	Size = 0;
}
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
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
	return Size;
}
Stack::Stack() {
	start = top = NULL;
	Size = 0;
}
//Start GeeksForGeeks code snippet
// https://www.geeksforgeeks.org/implementation-of-stack-using-doubly-linked-list/#

	bool Stack::isEmpty() {
		if (start == NULL)
			return true;
		return false;
	}
void Stack::insert(int data) {
	struct Node* node;
	node = new Node();
	node->data = data;
	if (isEmpty()) {
		node->prev = NULL;
		node->next = NULL;
		//empty stack means new node is first node
		start = node;
		top = node;
	}
	else {
		top->next = node;
		node->next = NULL;
		node->prev = top;
		top = node;
	}
}

void Stack::remove() {
	struct Node* node;
	node = top;
	if (isEmpty())
		cout << "Cannot remove, stack is empty" << endl;
	else if (top == start) {
		top = NULL;
		start = NULL;
		free(node);
	}
	else {
		top->prev->next = NULL;
		top = node->prev;
		free(node);
	}

}



int Stack::printAll() {
	if (isEmpty())
		cout << "Stack is empty" << endl;
	else {
		struct Node* ptr = start;
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	return Size;
}

int Stack::size() {
	int counter = 0;
	if (isEmpty()) cout << "Stack is empty";
	else {
		struct Node* ptr = start;
		while (ptr != NULL) {
			counter++;
			ptr = ptr->next;
		}
	}
	cout << "Size of stack is " << counter;
	return counter;
}
//end GeeksForGeeks code snippet

void Stack::erase() {
	while (top != NULL) {
		Node* temp = top;
		top = top->prev;
		free(temp);
	}
	start = NULL;
	Size = 0;
}
void measureInsertionTime() {
	Queue q;
	Stack s;

	ofstream outFile("Assignment4_Insert.csv");
	if (!outFile.is_open()) {
		cerr << "Error: Cannot open output file" << endl;
		return;
	}
	//create outfile header
	outFile << "Test size, Queue Time Taken, Stack Time Taken" << endl;

	for (int size = 100; size <= 100000; size += 1000) {
		cout << "Testing for queue size " << size << endl;
		//Measure for Queue
		//start timer
		auto start = chrono::high_resolution_clock::now();
		//insert random integers into queue
		for (int i = 0; i < size; i++) {
			int randomValue = rand() % 1000; //picks random integers between 0 and 999
			q.insert(randomValue);
		}
		//end timer
		auto end = chrono::high_resolution_clock::now();
		auto queueDuration = chrono::duration_cast<chrono::microseconds>(end - start).count();

		//Measure for Stack
		cout << "Testing for stack size " << size << endl;
		// start time
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < size; i++) {
			s.insert(rand() % 1000);
		}
		end = chrono::high_resolution_clock::now();
		auto stackDuration = chrono::duration_cast<chrono::microseconds>(end - start).count();
		//record results in CSV file
		outFile << size << "," << queueDuration << "," << stackDuration << endl;
		//clear queue/stack for next test
		q.erase();
		s.erase();
	}
	outFile.close();
	cout << "Results saved to Assignment4_Insert.csv" << endl;
}


// Measure delete time for Queue and Stack
void measureDeleteTime() {
	Queue q;
	Stack s;

	ofstream outFile("Assignment4_Delete.csv");
	if (!outFile.is_open()) {
		cerr << "Error: Cannot open output file" << endl;
		return;
	}
	outFile << "Test size, Queue Time (ms), Stack Time (ms)" << endl;

	for (int size = 100; size <= 100000; size += 1000) {
		// Fill Queue and Stack
		for (int i = 0; i < size; i++) {
			q.insert(rand() % 1000);
			s.insert(rand() % 1000);
		}

		// Measure for Queue
		cout << "Testing queue for size " << size << endl;
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i < size; i++) {
			q.remove();
		}
		auto end = chrono::high_resolution_clock::now();
		auto queueDuration = chrono::duration_cast<chrono::microseconds>(end - start).count();

		// Measure for Stack
		cout << "Testing stack for size " << size << endl;
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < size; i++) {
			s.remove();
		}
		end = chrono::high_resolution_clock::now();
		auto stackDuration = chrono::duration_cast<chrono::microseconds>(end - start).count();

		outFile << size << "," << queueDuration << "," << stackDuration << endl;

		q.erase();
		s.erase();
	}
	outFile.close();
	cout << "Deletion results saved to Assignment4_Delete.csv" << endl;
}

