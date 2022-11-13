#include <iostream>
#include <fstream>
#include "List.h"
#include "SymbolMap.h"
#include "AudioEditor.h"

using namespace std;


int main() {
	/*	List* l = new List();

		l->addElement("A", 1);
		l->addElement("C", 2);
		l->addElement("A", 3);
		l->addElement("B", 4);

		l->insertElementAtIndex("H", 0, 6);
		l->print();
		cout << endl;
		l->deleteElement(3);
		l->print();
		cout << endl;
		l->replaceElement("G", 6, 0);
		//cout << l->getLength() << endl;

		l->print();*/

	string myText;
	SymbolMap* sm = new SymbolMap();

	ifstream MyReadFile("note.txt");
	getline(MyReadFile, myText);
	MyReadFile.close();

	AudioEditor* a = new AudioEditor(); 
	 int n = a->importAudio(myText);
	

	cout << n << endl;

	List* l = new List();

	//string glumi_listu = "";

/*	string tek1 = "";
	char txt;


	List* prviTest = new List();


	for (int i = 0; i < myText.length(); i++) {
		txt = myText[i]; 
		tek1 = myText[i];
		int a = sm->isItTxt(txt);
		if ((a == -1) || (txt == '|') || (txt == ' ') || (txt == '[') || (txt == ']')) {
			prviTest->addElement(tek1); 
			tek1 = ""; 
		}
		else {
			cout << "Greska!" << endl;

		}
	}

	prviTest->print();
	cout << endl;*/


	string tek = "";
	for (int i = 0; i < myText.length(); i++) {
		int duration;

		if (myText[i] == '[') {
			if (tek != "") {
				// glumi listu koristim samo za ispis
				// gde god imas ovo glumi listu ti treba da ubacis element na kraj liste
				// odnosno da koristis funkciju za ubacivanje u listu
				//glumi_listu += tek;
				l->addElement(tek);
				tek = "";
			}

			tek += myText[i++];
			while (myText[i] != ']') {
				tek += sm->getSymbol(myText[i++]);
			}
			tek += ']';
		}

		else if (myText[i] == ' ') {
			// add to list one time tek
			// add to list one time blanko
			//glumi_listu += tek;
			l->addElement(tek);
			//glumi_listu += "_";
			l->addElement("_");
			tek = "";
		}

		else if (myText[i] == '|') {
			duration = 2;

			if (myText[i + 1] == '|') {
				duration = 4;
				i++;
			}

			for (int j = 0; j < duration; j++) {
				//add to list tek
				//glumi_listu += tek;
				l->addElement(tek);

			}
			for (int j = 0; j < duration; j++) {
				//add to list blanko
				//glumi_listu += "_";
				l->addElement("_");

			}

			tek = "";
		}

		else {
			if (tek != "") {
				// add to list tek
				//glumi_listu += tek;
				l->addElement(tek);
				tek = "";
			}
			tek = sm->getSymbol(myText[i]);
		}

		if (i == myText.length() - 1) {
			// add tek to list
			//glumi_listu += tek;
			l->addElement(tek);

		}
	}

	//cout << endl << glumi_listu << endl; 
	l->print(); 
	cout << endl;
	int j = sm->isItTxt('M');
	cout << j << endl;

	






}