#ifndef AUDIOEDITOR_H
#define AUDIOEDITOR_H

#include "List.h"
#include "SymbolMap.h"
#include <iostream> 
#include <string>
using namespace std;

class AudioEditor {
public:
	AudioEditor();
	// Destruktor klase je posebna funkcija clanica klase (kao i konstruktor) koja se poziva kada brisemo objekat neke klase (pozivom operatora delete)
	// Potrebna je u svim klasama sa pokazivackim poljima da bismo na ispravan nacin izbrisali ono na sta oni pokazuju
	// Naime pozivom operatora delete mi brisemo samo taj konkretan objekat i sva njegova polja, medjutim ukoliko u objektu postoji pokazivac koji ukazuje na neki drugi deo memorije, taj deo memorije ce ostati neizbrisan (curenje memorije)
	// Dakle potrebno je da definisemo destruktor koji brise sve iz dinamicke memorije sto je nas objekat u toku programa kreirao (u ovom slucaju, samo dinamicku matricu)
	~AudioEditor();

	int importAudio(string audio);
	string exportAudio();
	string exportNotes();

	void insertSymbol(string symbol, int position);
	void deleteSymbol(int position);
	void replaceSymbol(string symbol, int position);
	void changeOctave(int step);

private:

};

#endif