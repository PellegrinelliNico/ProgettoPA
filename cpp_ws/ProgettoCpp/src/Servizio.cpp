#include "Servizio.h"

namespace attivita {

Servizio::Servizio(string m, Time oA, Time oC, int v, int a, TipoServizio tS, bool sP)
		:Attivita::Attivita(m, oA, oC, v, a), tipo(tS), suPrenotazione(sP){}

Servizio::Servizio(string m, Time oA, Time oC, TipoServizio tN, bool sP)
		:Servizio::Servizio(m, oA, oC, 0, 0, tN, sP){}

string Servizio::toString(){
	return "Servizio di "  + enumToString[static_cast<int>(tipo)] + ": " + Attivita::toString() +
			" 	-> Richiesta prenotazione: " + (suPrenotazione? "SI\n" : "NO\n");
}

Servizio::~Servizio() {}

} /* namespace attivita */
