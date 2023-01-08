#ifndef BAR_H_
#define BAR_H_

#include "Negozio.h"
#include "Servizio.h"

namespace attivita {

class Bar: private Negozio, public Servizio {
public:
	Bar(string m, Time oA, Time oC, int v = 0, int a = 0);
	string toString();
	using Negozio::getTipoNegozio;
	virtual ~Bar();
};

} /* namespace attivita */

#endif /* BAR_H_ */
