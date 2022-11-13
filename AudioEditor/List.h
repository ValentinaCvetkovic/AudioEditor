#ifndef LIST_H
#define LIST_H

#include <iostream> 
#include <string>
using namespace std;


struct Elem{
	string note;
	Elem* next;
};

class List {
private: 
	Elem* first, * last; 
	int lenght; 

public: 
	List();

	void addElement(string note); 
	void insertElementAtIndex(string note, int index); 
	void deleteElement(int position);
	void replaceElement(string note, int position); 

	inline int getLenght() const { return this->lenght; }





	void print() {
		Elem* tek = this->first;

		while (tek != nullptr) {
			std::cout << tek->note ;
			tek = tek->next;
		}
	}




};


#endif 
