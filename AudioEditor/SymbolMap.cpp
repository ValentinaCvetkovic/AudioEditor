#include <fstream>
#include "SymbolMap.h"

using namespace std; 

SymbolMap::SymbolMap(){
}

string SymbolMap::getSymbol(char txtRep){
	for (int i = 0; i < 60; i++) {
		if (this->txtRepresentation[i] == txtRep) {
			return this->symbol[i]; 
		}
	}
	return "Ne postoji simbol za datu tekstualnu reprezentaciju!";
}

char SymbolMap::getTxtRep(string symbol){
	for (int i = 0; i < 60; i++) {
		if (this->symbol[i] == symbol) {
			return this->txtRepresentation[i];
		}
	}
	return -1 ;
}

int SymbolMap::isItTxt(char txtRep){
	for (int i = 0; i < 60; i++) {
		if (this->txtRepresentation[i] == txtRep) {
			return -1;
		}
	}
	return 0;
}
