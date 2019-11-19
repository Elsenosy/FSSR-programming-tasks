#include<iostream>
#include<string.h>
using namespace std;
/**
* Written by: Taha Elsenosy <tahaelsenosy@gmail.com> 
*/
struct Student{
	string name;
	int id;
	int phone; 
	string address;
	Student *next;
};

class LinkedList{
	public: 
		static int count;
		Student *head;
		Student *cursor;
		Student *list;
		
	LinkedList(){
		head = NULL;
	}
	void insert(Student std){
		// Create new pointer of type Student 
		Student *new_student = new Student;
		// Assign Student data to the dynamic pointer 
		new_student->name = std.name;
		new_student->id = std.id;
		new_student->phone = std.phone;
		new_student->address = std.address;
		// Append the student to the head of the list
		new_student->next = head;
		head = new_student;
	}	
	
	void displayStudent(){
		// Make pointer to point to head of the list and iterate its items using next -- 
		Student *ptr = head;
		if(head == NULL){
			cout << "There no students to display \n";
		}
		while(ptr != NULL){
			cout << ptr->id << " \t" << ptr->name << " \t "<< ptr->address << " \t "<<ptr->phone<<endl;
			ptr = ptr->next;
		}
	}
		
};

int main(){
	/**
	* Creating dynamic object of class Person using pointers, and accessing its properties using -> 'arrow' opertator
	*/
	char stop = 'n';
	int process;
	int id, phone;
	string name, address;
	Student std; 
	LinkedList ls;
	
	cout << "Hello there, LinkedList implementation in C++"<<endl;
	while(stop != 'y'){		
		cout << "-----------------------------------------"<<endl;
		cout << "   Please select a process: "<<endl;
		cout << "\t 1) Print all students."<<endl;
		cout << "\t 2) Add new student. "<<endl;
		cout << "\t 3) Insert after a student. "<<endl;
		cout<<"Your choice: "; cin>>process;
		
		if(!cin){
			cout << "Please enter a valid choice!"<<endl;
			exit(1);
		}
		
		switch(process){
			case 1:
				// Print all students
				cout << "--------------- Prinitng students -----------------------"<<endl;
				ls.displayStudent();
			break;
			case 2:
				{
				// Get student's data
				cout <<" ---------------- Create new student ------------------"<< endl;
				cout << "Enter student name: "; cin>>name;
				cout << "Enter student address: "; cin>>address;
				cout << "Enter student id: "; cin>>id;
				cout << "Enter student phone: "; cin>>phone;
				// Create the student
				std.name = name;
				std.address = address;
				std.id = id;
				std.phone = phone;
				
				ls.insert(std);
				cout << "Student has been added."<<endl;
				}
			break;
			default:
				cout << "Out of choices!"<<endl;
				break;
			break;
		}
		
		cout << " \t \t Do you want to exit? Y/N: ";
		cin>>stop;
	}
	return 0;
}

	
