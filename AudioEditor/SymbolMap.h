#ifndef SYMBOLMAP_H
#define SYMBOLMAP_H

#include <iostream>
#include <string>
using namespace std;

class SymbolMap {
	char txtRepresentation[60] = { '1', '!', '2', '@', '3', '4', '$', '5', '%', '6', '^', '7', '8', '*', '9', '(', '0', 'q', 'Q', 'w', 'W', 'e', 'E', 'r', 't', 'T', 'y', 'Y', 'u', 'i', 'I', 'o', 'O', 'p', 'P', 'a', 's', 'S', 'd', 'D', 'f', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'l', 'L', 'z', 'Z', 'x', 'c', 'C', 'v', 'V', 'b', 'B', 'n' };
	std::string symbol[60] = { "C2", "C#2", "D2", "D#2", "E2", "F2", "F#2", "G2", "G#2", "A2", "A#2", "B2", "C3", "C#3", "D3", "D#3", "E3", "F3", "F#3", "G3", "G#3", "A3", "A#3", "B3", "C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4", "C5", "C#5", "D5", "D#5", "E5", "F5", "F#5", "G5", "G#5", "A5", "A#5", "B5", "C6", "C#6", "D6", "D#6", "E6", "F6", "F#6", "G6", "G#6", "A6", "A#6", "B6" };

public:
	SymbolMap();

	string getSymbol(char txtRep);
	char getTxtRep(string symbol);
	int  isItTxt(char txtRep);

};
#endif