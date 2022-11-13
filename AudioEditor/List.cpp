#include "List.h"


List::List(){
	this->first = nullptr;
	this->last = nullptr; 
	this->lenght = 0; 
}

void List::addElement(string note){
	if (this->first == nullptr) {
		this->first = new Elem(); 
		this->first->note = note;
		this->first->next = nullptr; 
		this->last = this->first; 
		this->lenght++; 
		return; 
	}

	Elem* newElement = new Elem(); 
	newElement->note = note; 
	newElement->next = nullptr; 
	this->last->next = newElement; 
	this->last = newElement;
	newElement = nullptr; 
	delete newElement; 
	this->lenght++; 
}

void List::insertElementAtIndex(string note, int index){
	if (index > this->lenght || index < 0) {
		cout << "Index out of range!" << endl; 
		return; 
	}
	if (index == 0) {
		Elem* newElement = new Elem();
		newElement->note = note;
		newElement->next = first;
		this->first = newElement;
		newElement = nullptr;
		delete newElement;
		return;
	}
	Elem* curr = this->first; 
	for (int i = 0; i < index - 1; i++) {
		curr = curr->next;
	}
	Elem* newElement = new Elem();
	newElement->note = note;
	newElement->next = nullptr;
	newElement->next = curr->next;
	curr->next = newElement; 
	newElement = nullptr;
	delete newElement; 
}

void List::deleteElement(int position){
	if (position > this->lenght || position < 0 ) {
		cout << "Position out of range!" << endl;
		return;
	}
	if (position == 0) {
		Elem* curr = this->first; 
		this->first = first->next; 
		delete curr;
		return;
	}
	Elem* curr = this->first;
	for (int i = 0; i < position - 1; i++) {
		curr = curr->next; 
	}
	Elem* nextCurr = curr->next; 
	curr->next = nextCurr->next;
	nextCurr->next = nullptr;
	delete nextCurr; 

}

void List::replaceElement(string note, int position){
	if (position > this->lenght || position < 0) {
		cout << "Position out of range!" << endl;
		return;
	}
	Elem* curr = this->first;
	for (int i = 0; i < position; i++) {
		curr = curr->next;
	}
	curr->note = note; 
	curr = nullptr;
	delete curr; 
}

