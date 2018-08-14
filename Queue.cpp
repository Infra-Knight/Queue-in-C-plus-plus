
#include "Queue.h"

Queue::Queue () {
	count = 0;
	frontPtr = NULL;
	rearPtr = NULL;
}

Queue::Queue(int _data) {
	count++;
	frontPtr = new QueueNode;
	frontPtr->next = NULL;
	frontPtr->data = _data;
	rearPtr = frontPtr;
}

bool Queue::enqueue(int _dataIn) {
	if (count == MAX_SIZE) return false;
	QueueNode* newNode = new QueueNode;
	newNode->next = NULL;
	newNode->data = _dataIn;
	if (count == 0) {
		frontPtr = newNode;
	}
	else {
		rearPtr->next = newNode;
	}
	rearPtr = newNode;
	count++;

	return true;
}

bool Queue::dequeue(int &_dataOut) {
	if (count == 0) return false;
	_dataOut = frontPtr->data;
	QueueNode* delPtr = frontPtr;
	if (count == 1) {
		frontPtr = NULL;
		rearPtr = NULL;
	}
	else {
		frontPtr = frontPtr->next;
	}
	delete delPtr;
	count--;
	return true;
}

bool Queue::front(int &_dataOut) {
	if (count == 0) return false;
	_dataOut = frontPtr->data;
}

bool Queue::rear(int &_dataOut) {
	if (count == 0) return false;
	_dataOut = rearPtr->data;
}

bool Queue::isEmpty() {
	if (count == 0) return true;
	return false;
}

bool Queue::isFull() {
	if (count == MAX_SIZE) return true;
	return false;
}

int Queue::size() {
	return count;
}

void Queue::print() {
	if (count == 0) {
		cout << "Queue is empty..." << endl;
		return;
	}

	QueueNode* pTemp = frontPtr;
	cout << "front -> ";
	while (pTemp != NULL) {
		cout << pTemp->data;
		if (pTemp->next != NULL) {
			cout << " -> ";
		}
		pTemp = pTemp->next;
	}
	cout << " -> rear " << endl;
}

void Queue::arrayToQueue(int *arr, int N) {
	for (int i = 0; i < N; i++) {
		enqueue(arr[i]);
	}
}