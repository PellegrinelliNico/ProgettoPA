#ifndef SERVIZIO_H_
#define SERVIZIO_H_
#define stringify(name) #name

#include "Attivita.h"

namespace attivita {

enum class TipoServizio {PARRUCCHIERE=0, LAVANDERIA, RISTORANTE};

class Servizio: public virtual Attivita {
private:
	const TipoServizio tipo;
	bool suPrenotazione;
	//Necessario per stampare gli enumerativi, corrispondenza 1 a 1 tra enum e stringa
	const string enumToString[3] = {stringify(PARRUCCHIERE),stringify(LAVANDERIA),stringify(RISTORANTE)};
public:
	Servizio(string m, Time oA, Time oC, int v, int a, TipoServizio tS, bool sP);
	Servizio(string m, Time oA, Time oC, TipoServizio tS, bool sP);
	string toString();
	TipoServizio getTipoServizio() const;
	virtual ~Servizio();
};

inline TipoServizio Servizio::getTipoServizio() const{
	return tipo;
}

} /* namespace attivita */

#endif /* SERVIZIO_H_ */
