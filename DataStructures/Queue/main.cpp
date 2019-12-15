/**
* Queue implementation using dynamic arrays and linkedLists
* Name: Taha Elsenosy Mohamed <tahaelsenosy@gmail.com>
* Date: Dec, 16 2019
* Course: CS505
* File: main.cpp
*/

#include <iostream>
#include "queueArr.cpp"
#include "queueL.cpp"
using namespace std;


int main(int argc, char** argv) {
	/**
	* Calling Queue based array implementation
	*/
	int returnQt, returnQl;
	QueueT<int> qt; // Queue based array 
	QueueL<int> ql; // Queue based linkedlist
	
	cout<< "+-------------------------------------------+"<<endl;
	cout<< "\t Implementation using dynamic array"<<endl;
	cout<< "+-------------------------------------------+"<<endl;
	cout<<endl;
	
 	//Enqueue
	qt.enQueue(10);
	qt.enQueue(11);
	qt.enQueue(12);
	// Retrieve the first item
	qt.qFront(returnQt);
	
	// Print the queue
	cout << "Queue items: "<<endl;
	qt.printQ();
	cout<< "-------------------------"<<endl;
	cout << "Front value: "<< returnQt <<endl;
	
	cout<< "-------------------------"<<endl;
	cout << "Dequeue once.... "<<endl; qt.deQueue();
	cout<< "-------------------------"<<endl;
	cout << "Queue items: "<<endl;
	qt.printQ();
	
	// Printing the queue length 
	cout<< "-------------------------"<<endl;
	cout << "Queue length: "<< qt.qLength() << endl;
	cout<< "-------------------------"<<endl;
	
	cout << endl<<endl;
	
	/**
	* Implementation using LinkedList
	*/
	cout<< "+-------------------------------------------+"<<endl;
	cout<< "\t Implementation using LinkedList"<<endl;
	cout<< "+-------------------------------------------+"<<endl;
	cout << endl;
	
	ql.enQueue(1);
	ql.enQueue(2);
	ql.enQueue(3);
	ql.qFront(returnQl);
	
	cout << "Queue items: "<<endl;
	ql.printQ();
	
	cout<< "-------------------------"<<endl;
	cout << "Front value: "<< returnQl <<endl;
	
	cout<< "-------------------------"<<endl;
	cout << "Dequeue once.... "<<endl; ql.deQueue();
	cout<< "-------------------------"<<endl;
	cout << "Queue items: "<<endl;
	ql.printQ();
	
	
	return 0;
}
