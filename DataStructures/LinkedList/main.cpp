/**
    CS505 sheet
    main.cpp
    Purpose: Linked list main program

    @author Taha Elseosy <tahaelseosy@gmail.com>
*/
#include "linkedList.cpp"
#include<iostream>
#include<string.h>
using namespace std;

struct Student{
	int id;
	string name;
	int phone;
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	LinkedList <int, int>ls;
	
	int myData = 0;
	
	ls.insertFirst(1, 10);
	ls.insertFirst(2, 20);
	ls.insertFirst(3, 30);
	ls.insertFirst(4, 40);
	ls.insertFirst(5, 50);
	cout << "--------------------------------"<<endl;
	ls.displayAllInt();
	ls.evenOddOrder();
	cout << "--------------------------------"<<endl;
	ls.displayAllInt();
	cout<<ls.listSize();
	
	return 0;
}
