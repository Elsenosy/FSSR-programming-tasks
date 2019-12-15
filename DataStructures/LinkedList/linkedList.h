/**
    CS505 sheet
    linkedList.h
    Purpose: Linked list header file

    @author Taha Elseosy <tahaelseosy@gmail.com>
*/
#ifndef LIST_H
#define LIST_H
template <class keyType, class dataType> class LinkedList{
	public:
		LinkedList();
		~LinkedList();
		
		bool listIsEmpty() const;
		bool curIsEmpty() const;
		
		void toFirst();
		bool atFirst() const;
		
		void advance();
		
		void toEnd();
		bool atEnd() const;
		
		int listSize() const;
		
		void updateData(const dataType &);
		void retrieveData(const dataType &) const;
		
		void insertFirst(const keyType&, const dataType&);
		void insertAfter(const keyType&, const dataType&);
		void insertBefore(const keyType&, const dataType&);
		void insertEnd(const keyType&, const dataType&);
		
		void display() const;
		void displayAll();
		void displayAllInt();
		void deleteNode();
		void deleteFirst();
		void deleteEnd();
		void makeListEmpty();
		
		bool search(const keyType &);
		void orderInsert(const keyType &, const dataType &);
		
		void traverse();
		void evenOddOrder();
		
		private:
			class Node{
				public:
					keyType key;
					dataType data;
					Node *next;
			};
			
			Node * head;
			Node * cursor;
			Node * prev;
			
			typedef Node * NodePointer;
};
#endif
