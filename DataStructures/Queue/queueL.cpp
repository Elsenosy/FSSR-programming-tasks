/**
* Queue based linkedList implementation file
* Name: Taha Elsenosy Mohamed <tahaelsenosy@gmail.com>
* Date: Dec, 16 2019
* Course: CS505
* File: queueL.cpp
*/
#include "queueL.h"
#include <iostream>
using namespace std;

// Constructor
template <class Type> QueueL<Type>::QueueL(){
	front=NULL; rear=NULL; count=0;
};


template <class Type> int QueueL<Type>::qLength(){
	return count;
};

template <class Type> void QueueL<Type>::enQueue(const Type &item){

	NodePointer newItem = new Node;
	newItem->data = item;
	newItem->next = NULL;
	
	if(isListEmpty()){
		front = rear = newItem;
	}else{
		rear->next = newItem;		
		rear = newItem;	
	}
	count++;
}

template <class Type> void QueueL<Type>::deQueue(){
	if(isListEmpty()){
		cout << "Queue is empty"<<endl;	
		return;
	}
	
	if(!isListEmpty()){
		NodePointer tmp = new Node;
		tmp = front->next;
		delete front;
		front = tmp;
		count--;
	}
}
template <class Type> void QueueL<Type>::qFront(Type &item){
	if(isListEmpty()){
		cout << "Queue is empty"<<endl;	
		return;
	}
	
	item = front->data;
};

template <class Type> bool QueueL<Type>::isListEmpty(){
	return front == NULL ? true : false;
};

template <class Type> void QueueL<Type>::printQ(){
	if(isListEmpty()){
		cout << "Queue is empty";
		return;
	}
	
	NodePointer tmp = front;
	while(tmp != NULL){
		cout << tmp->data << ", ";
		tmp = tmp->next;
	}
	cout << endl;
};

// Destructor
template <class Type> QueueL<Type>::~QueueL(){
	front=NULL; rear=NULL;
};


