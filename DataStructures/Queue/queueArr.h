/**
* Queue based array implementation header file
* Name: Taha Elsenosy Mohamed <tahaelsenosy@gmail.com>
* Date: Dec, 16 2019
* Course: CS505
* File: queueArr.h
*/
#ifndef QUEUEARR_H
#define QUEUEARR_H
template <class Type> class QueueT{
	public:
		// Constructor, Destrucor
		QueueT(int maxSize=128);
		~QueueT();
		
		bool qIsEmpty();
		bool qIsFull();
		
		bool enQueue(const Type&);
		bool deQueue();
		
		void qFront(Type &);
		int qLength();
		
		
		void printQ();
	
	private:
		int front, rear, count, maxSize;
		Type* queue;
	
};
#endif
