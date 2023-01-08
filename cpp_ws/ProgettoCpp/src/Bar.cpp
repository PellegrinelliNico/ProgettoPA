#include "Bar.h"

namespace attivita {

Bar::Bar(string m, Time oA, Time oC, int v, int a):
	Attivita::Attivita(m, oA, oC, v, a),
	Negozio::Negozio(m, oA, oC, v, a, attivita::TipoNegozio::TABACCHI),
	Servizio::Servizio(m, oA, oC, v, a, attivita::TipoServizio::RISTORANTE, false){}

Bar::~Bar() {}

string Bar::toString(){
	return "Servizio di BAR-TABACCHI: " + Attivita::toString() +
			" 	-> Richiesta prenotazione: NO\n";
}

} /* namespace attivita */
