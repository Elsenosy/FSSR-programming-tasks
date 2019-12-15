/**
* Queue based array implementation file
* Name: Taha Elsenosy Mohamed <tahaelsenosy@gmail.com>
* Date: Dec, 16 2019
* Course: CS505
* File: queueArr.cpp
*/
#include "queueArr.h"
#include <iostream>
using namespace std;
// Constructor function 
template <class Type> QueueT<Type>::QueueT(int size){
	front=0; rear=-1; maxSize = size; count=0;
	queue = new Type[maxSize];
};

//Check Queue is empty 
template <class Type> QueueT<Type>::~QueueT(){
	delete queue;
};

// Checkk queue is full 
template <class Type> bool QueueT<Type>::qIsEmpty(){
	return count == 0 ? true : false;
};

// Check queue is full
template <class Type> bool QueueT<Type>::qIsFull(){
	return count == maxSize ? true : false;
};

// Enqueue function: add an item to the rear of the queue
template <class Type> bool QueueT<Type>::enQueue(const Type &item){
		if(qIsFull()){
			return false;
		}
		
		rear = (rear+1) % maxSize;
		queue[rear] = item;
		count++;
		return true;
};
// Dequeue: remove the first item.
template <class Type> bool QueueT<Type>::deQueue(){
	if(qIsEmpty())
		return false;
		
	front = (front + 1) % maxSize;
	count--;
	
	return true;
};

// qFront: retrieve the first item without removing it
template <class Type> void QueueT<Type>::qFront(Type &item){
	if(qIsEmpty()){
		cout << "Queue is empty!"<<endl;
		return;
	}
	item = queue[front];
}

// qLength: return queue actual length
template <class Type> int QueueT<Type>::qLength(){
	return count;	
};

// Printing queue values
template <class Type> void QueueT<Type>::printQ(){
	if(qIsEmpty()){
		cout << "Queue is empty!"<<endl;
		return;
	}
	
	for(int i=front; i <=rear; i++){
		cout << queue[i] << ", ";
	}
	cout << endl;
};

