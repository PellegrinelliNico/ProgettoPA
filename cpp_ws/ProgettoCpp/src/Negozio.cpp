#include "Negozio.h"

namespace attivita {

Negozio::Negozio(string m, Time oA, Time oC, int v, int a, TipoNegozio tN)
		:Attivita::Attivita(m, oA, oC, v, a), tipo(tN){}

Negozio::Negozio(string m, Time oA, Time oC, TipoNegozio tN)
		:Negozio::Negozio(m, oA, oC, 0, 0, tN){}

string Negozio::toString(){
	return "Negozio di "  + enumToString[static_cast<int>(tipo)] + ": " + Attivita::toString();
}

Negozio::~Negozio() {}

} /* namespace attivita */
