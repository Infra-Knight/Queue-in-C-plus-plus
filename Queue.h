
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MAX_SIZE 256

struct QueueNode {
	int data;
	QueueNode* next;
};

class Queue {
public:
	Queue();
	Queue(int _data);

	bool dequeue(int &_dataOut);
	bool enqueue(int dataIn);

	bool front(int &_dataOut);
	bool rear(int &_dataOut);

	bool isEmpty();
	bool isFull();

	int size();
	void print();

	void arrayToQueue(int *arr, int N);

private:
	QueueNode *frontPtr;
	QueueNode *rearPtr;
	int count;
};

#endif