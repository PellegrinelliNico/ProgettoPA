#ifndef NEGOZIO_H_
#define NEGOZIO_H_
#define stringify(name) #name

#include "Attivita.h"

namespace attivita {

enum class TipoNegozio {ABBIGLIAMENTO=0, LIBRERIA, ALIMENTARI, ELETTRONICA, TABACCHI};

class Negozio: public virtual Attivita {
private:
	const TipoNegozio tipo;
	//Necessario per stampare gli enumerativi, corrispondenza 1 a 1 tra enum e stringa
	const string enumToString[5] = {stringify(ABBIGLIAMENTO),stringify(LIBRERIA),stringify(ALIMENTARI),
											stringify(ELETTRONICA),stringify(TABACCHI)};
public:
	Negozio(string m, Time oA, Time oC, int v, int a, TipoNegozio tN);
	Negozio(string m, Time oA, Time oC, TipoNegozio tN);
	string toString();
	TipoNegozio getTipoNegozio() const;
	virtual ~Negozio();
};

inline TipoNegozio Negozio::getTipoNegozio() const{
	return tipo;
}

} /* namespace attivita */

#endif /* NEGOZIO_H_ */
