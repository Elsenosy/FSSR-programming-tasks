/**
    CS505 sheet
    linkedList.cpp
    Purpose: Linked list implementation

    @author Taha Elseosy <tahaelseosy@gmail.com>
*/
#include "linkedList.h"
#include <iostream>
using namespace std;

// Constructor
template <class keyType, class dataType> LinkedList<keyType, dataType>::LinkedList(){
	head = NULL; cursor = NULL; prev = NULL;	
}

// Check if list is empty!
template <class keyType, class dataType> bool LinkedList<keyType, dataType>::listIsEmpty() const{
	return head == NULL ? true : false;
}

// Insert at the first
template <class keyType, class dataType> void LinkedList<keyType, dataType>::insertFirst(const keyType &key, const dataType &data){
	Node *node = new Node;
	node->key = key;
	node->data = data;
	node->next = head;
	
	head = node;
	cursor = head;
	prev = NULL;
}
// Insert before a node
template <class keyType, class dataType> void LinkedList<keyType, dataType>::insertAfter(const keyType &key, const dataType &data){
	toFirst();
	Node *q = new Node;
	Node *tmp = new Node;
	if(!listIsEmpty()){
		while(cursor != NULL){
			if(cursor->key == key){
				q->key = cursor->key;
				q->data = data;

				prev = cursor;
				q->next = cursor->next;
				cursor->next = q;
				cursor = q;
				break;
			}
			advance();
		}
	}
}

template <class keyType, class dataType> void LinkedList<keyType, dataType>::insertEnd(const keyType &key, const dataType &data){
	NodePointer p = new Node;
	
	toFirst();
	while(!curIsEmpty()){
		if(cursor->next == NULL){
			p->key = key;
			p->data = data;
			
			cursor->next = p;
			p->next = NULL;
			prev = cursor;
			cursor = p;
			break;
		}
		advance();
	}
}

// Check if list is empty or not
template <class keyType, class dataType> bool LinkedList<keyType, dataType>::curIsEmpty() const{
	return cursor == NULL ? true : false;
}
// Move the cursor to the front of the list
template <class keyType, class dataType> void LinkedList<keyType, dataType>::toFirst(){
	cursor = head; prev = NULL;
}

// Check if the cursro at the first
template <class keyType, class dataType> bool LinkedList<keyType, dataType>::atFirst() const{
	return cursor == head ? true : false;
}

// Move the cursor one move forward
template <class keyType, class dataType> void LinkedList<keyType, dataType>::advance(){
	prev = cursor; cursor = cursor->next;
}

// Move the cursor to the last element in the list
template <class keyType, class dataType> void LinkedList<keyType, dataType>::toEnd(){
	toFirst();
	if(!listIsEmpty()){
		while(!curIsEmpty())
			advance();
	}
}

template <class keyType, class dataType> void LinkedList<keyType, dataType>::display() const{
	if(!curIsEmpty()){
		cout << "Student id: "<< cursor->data.id << endl;
		cout << "Student name: "<< cursor->data.name<<endl;
		cout << "Student phone: "<< cursor->data.phone<<endl;
		cout << " --- "<<endl;
	}
}

template <class keyType, class dataType> void LinkedList<keyType, dataType>::displayAll(){
	toFirst();
	while(!curIsEmpty()){
		cout << "Student id: "<< cursor->data.id << endl;
		cout << "Student name: "<< cursor->data.name<<endl;
		cout << "Student phone: "<< cursor->data.phone<<endl;
		cout << " --- "<<endl;
		advance();
	}
}


template <class keyType, class dataType> void LinkedList<keyType, dataType>::displayAllInt(){
	toFirst();
	while(!curIsEmpty()){
		cout << "key: "<< cursor->key<<endl;
		cout << "Data: "<< cursor->data << endl;
		cout << " --- "<<endl;
		advance();
	}
}

// Check if the cursor at the last element or not
template <class keyType, class dataType> bool LinkedList<keyType, dataType>::atEnd() const{
	return cursor->next == NULL ? true : false;
}

// Return the list size
template <class keyType, class dataType> int LinkedList<keyType, dataType>::listSize() const{
	int counter = 0;
	Node *p = new Node;
	p = head;
		while(p != NULL){
			counter++;
			p = p->next;	
		}
	
	return counter;
}

// Delete the cursor node
template <class keyType, class dataType> void LinkedList<keyType, dataType>::deleteNode(){
	Node *q = new Node;
	
	if(!curIsEmpty()){
		q = cursor->next;
		delete cursor;
		cursor = q;
	}
	
}

// Empty the whole list
template <class keyType, class dataType> void LinkedList<keyType, dataType>::makeListEmpty(){
	if(!listIsEmpty()){
		while(cursor != NULL){
			delete cursor;
			advance();
		}
	}
}

template <class keyType, class dataType> LinkedList<keyType, dataType>::~LinkedList(){
	makeListEmpty();
}


// Even, odd nodes
template <class keyType, class dataType> void LinkedList<keyType, dataType>::evenOddOrder(){

    /* Get pointer to the last node */
    toEnd();  
    Node *new_end = cursor;  
    Node *end = cursor;
  
    /* Consider all odd nodes before the first  
     even node and move then after end */
    toFirst();
    while (cursor->data % 2 != 0 && cursor != end)  
    {  
        new_end->next = cursor;  
        cursor = cursor->next;  
        new_end->next->next = NULL;  
        new_end = new_end->next;  
    }  
  
    // 10->8->17->17->15  
    /* Do following steps only if  
    there is any even node */
    if (cursor->data%2 == 0)  
    {  
        /* Change the head pointer to  
        point to first even node */
        head = cursor;  
  
        /* now current points to 
        the first even node */
        while (cursor != new_end)  
        {  
            if ( (cursor->data) % 2 == 0 )  
            {  
                prev = cursor;  
                cursor = cursor->next;  
            }  
            else
            {  
                /* break the link between 
                prev and current */
                prev->next = cursor->next;  
//  
                /* Make next of curr as NULL */
                cursor->next = NULL;  
  
                /* Move curr to end */
                new_end->next = cursor;  
  
                /* make curr as new end of list */
                new_end = cursor;  
  
                /* Update current pointer to 
                next of the moved node */
                cursor = prev->next;  
            }  
        }  
    }  
  
    /* We must have prev set before executing  
    lines following this statement */
    else prev = cursor;  
  
    /* If there are more than 1 odd nodes  
    and end of original list is odd then  
    move this node to end to maintain  
    same order of odd numbers in modified list */
//    if (new_end != end && (end->data) % 2 != 0)  
//    {  
//        prev->next = end->next;  
//        end->next = NULL;  
//        new_end->next = end;  
//    }  
    return;  
}

