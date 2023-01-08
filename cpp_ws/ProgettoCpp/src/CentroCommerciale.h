#ifndef CENTROCOMMERCIALE_H_
#define CENTROCOMMERCIALE_H_

#include <vector>
#include <memory>
#include "Bar.h"

namespace centro_commerciale {

class CentroCommerciale {
private:
	//Singleton
	static CentroCommerciale* istanzaCentro;
	vector<attivita::Attivita*>* listaAttivita;
	CentroCommerciale();
public:
	//Singleton
	static CentroCommerciale* getIstanza();
	bool addAttivita(attivita::Attivita* a);
	void setValutazione(string nome, int valutazione = 0);
	void setAffollamento(string nome, int affollamento = 0);
	shared_ptr<vector<attivita::Attivita*>> getAttivitaAperte(const attivita::Time& ora);
	shared_ptr<vector<attivita::Attivita*>> getNegoziPerTipo(attivita::TipoNegozio tipo);
	shared_ptr<vector<attivita::Attivita*>> getMiglioriRistoranti();
	float getAffollamentoMedio();
	virtual ~CentroCommerciale();
};

} /* namespace centro_commerciale */

#endif /* CENTROCOMMERCIALE_H_ */
