#include "Attivita.h"
#include<string>
using namespace std;

namespace attivita {

//Se valutazione o affollamento fuori range = 0, non si fan controlli sui Time
Attivita::Attivita(string n, Time oA, Time oC, int v, int a)
		:nome(n), orarioApertura(oA), orarioChiusura(oC){
	valutazione = (v<0 || v>5)? 0: v;
	affollamento = (a<0 || a>100)? 0: a;
}

Attivita::Attivita(string n, Time oA, Time oC)
	:Attivita(n, oA, oC, 0, 0){
}

string Attivita::toString(){
	return  "\"" + nome + "\"" +
			"\n 	-> Orario apertura: " + to_string(orarioApertura.ora) + ":" +
			(orarioApertura.minuti < 10? "0":"") + to_string(orarioApertura.minuti) +
			", Orario chiusura: " + to_string(orarioChiusura.ora) + ":" +
			(orarioChiusura.minuti < 10? "0":"") + to_string(orarioChiusura.minuti) +
			"\n 	-> Valutazione: " + to_string(valutazione) + "*" +
			"\n 	-> Affollamento: " + to_string(affollamento) + "%\n";
}

Attivita::~Attivita() {}

} /* namespace attivita */
