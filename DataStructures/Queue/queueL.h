/**
* Queue based linkedList header file
* Name: Taha Elsenosy Mohamed <tahaelsenosy@gmail.com>
* Date: Dec, 16 2019
* Course: CS505
* File: queueL.h
*/
#ifndef QUEUEL_H
#define QUEUE_H
template <class Type> class QueueL{
	public: 
		QueueL();
		~QueueL();
		
		void toFirst();
		void toEnd();
		void advance();
		
		bool isCursorEmpty() const;
		bool isListEmpty();
		
		
		void enQueue(const Type&);
		void deQueue();
		
		void qFront(Type &);
		void printQ();
		int qLength();
	
	private:
		class Node{
			public:
				Type data;
				Node *next;
		};
		int count;
		typedef Node* NodePointer ;
		
		NodePointer front, rear;
};
#endif
