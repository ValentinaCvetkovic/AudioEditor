#include "AudioEditor.h"
#include "SymbolMap.h"
#include <fstream>
#include "List.h"


using namespace std;

AudioEditor::AudioEditor(){
}

AudioEditor::~AudioEditor(){

}



//string firstRow = table.substr(0, end);

int AudioEditor::importAudio(string audio){
	
	size_t end = audio.find('/n');

	SymbolMap* sm = new SymbolMap();
	string tek1 = "";
	char txt;
	List* l = new List();
	
	for (int i = 0; i < audio.length(); i++) {
		//while (audio[i] != '/' && audio[i + 1] != 'n') {
			txt = audio[i];
			tek1 = audio[i];
			int a = sm->isItTxt(txt);
			size_t end = audio.find('/n');
			if ((a == -1) || (txt == '|') || (txt == ' ') || (txt == '[') || (txt == ']')) {
				l->addElement(tek1);
				tek1 = "";
			}
			else if (i == end-1 ) {
				for (int j = 0; j < end; j++){	
					l->deleteElement(j-1);
				 }
			}
			else {
				cout << "Karakter na " << i << "." << "mjestu je nevalidan!" << endl;
				return 0;

			}

	}
	return -1; 
}







