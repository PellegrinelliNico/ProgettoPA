#include "CentroCommerciale.h"
#include <iostream>
#include <string.h>
#include <algorithm>
#include <typeinfo>
#include <memory>

//Funzioni per ordinare le lista
bool pointerCompare(const attivita::Attivita* a, const attivita::Attivita* b){
	return *a < *b;
}
bool pointerCompareValutazione(const attivita::Attivita* a, const attivita::Attivita* b){
	return (*a).getValutazione() > (*b).getValutazione();
}

namespace centro_commerciale {

//Necessario per il Singleton
CentroCommerciale* CentroCommerciale::istanzaCentro = nullptr;

CentroCommerciale::CentroCommerciale() {
	listaAttivita = new vector<attivita::Attivita*>();
}

CentroCommerciale* CentroCommerciale::getIstanza() {
	if (istanzaCentro == nullptr)
		istanzaCentro = new CentroCommerciale();
	return istanzaCentro;
}

bool CentroCommerciale::addAttivita(attivita::Attivita* a){
	for(auto i = listaAttivita->begin(); i != listaAttivita->end(); ++i){
		if ((*i)->getNome().compare(a->getNome()) == 0)
			return false;
	}
	listaAttivita->push_back(a);
	return true;
}

//Se valutazione fuori range o non specificata = 0
void CentroCommerciale::setValutazione(string nome, int valutazione){
	int val = (valutazione < 0 || valutazione > 5)? 0 : valutazione;
	for(auto i = listaAttivita->begin(); i != listaAttivita->end(); ++i){
		if ((*i)->getNome().compare(nome) == 0){
			(*i)->setValutazione(val);
			return;
		}
	}
}

//Se affollamento fuori range o non specificata = 0
void CentroCommerciale::setAffollamento(string nome, int affollamento){
	int aff = (affollamento < 0 || affollamento > 100)? 0 : affollamento;
	for(auto i = listaAttivita->begin(); i != listaAttivita->end(); ++i){
		if ((*i)->getNome().compare(nome) == 0){
			(*i)->setAffollamento(aff);
			return;
		}
	}
}

shared_ptr<vector<attivita::Attivita*>> CentroCommerciale::getAttivitaAperte(const attivita::Time& ora){
	shared_ptr<vector<attivita::Attivita*>> listaAperti(new vector<attivita::Attivita*>());
	for(auto i = listaAttivita->begin(); i != listaAttivita->end(); ++i){
		if ((*i)->orarioApertura < ora && (*i)->orarioChiusura > ora)
			listaAperti->push_back(*i);
	}
	sort(listaAperti->begin(), listaAperti->end(), pointerCompare);
	return listaAperti;
}

shared_ptr<vector<attivita::Attivita*>> CentroCommerciale::getNegoziPerTipo(attivita::TipoNegozio tipo){
	shared_ptr<vector<attivita::Attivita*>> listaNegozi(new vector<attivita::Attivita*>());

	//Serve solo per avere un elemento con cui controllare il typeid
	attivita::Attivita* a = new attivita::Negozio("", {0,0}, {0,0}, tipo);
	attivita::Attivita* b = new attivita::Bar("", {0,0}, {0,0});

	for(auto i = listaAttivita->begin(); i != listaAttivita->end(); ++i){
		if (typeid(**i) == typeid(*a) || typeid(**i) == typeid(*b)){
			auto temp = dynamic_cast<attivita::Negozio*>(*i);
			if (temp->getTipoNegozio() == tipo)
				listaNegozi->push_back(*i);
		}
	}
	delete a;
	delete b;

	sort(listaNegozi->begin(), listaNegozi->end(), pointerCompare);
	return listaNegozi;
}

shared_ptr<vector<attivita::Attivita*>> CentroCommerciale::getMiglioriRistoranti(){
	shared_ptr<vector<attivita::Attivita*>> listaRistoranti(new vector<attivita::Attivita*>());

	//Servono solo per avere un elemento con cui controllare il typeid
	attivita::Attivita* a = new attivita::Servizio("", {0,0}, {0,0}, attivita::TipoServizio::RISTORANTE, true);
	attivita::Attivita* b = new attivita::Bar("", {0,0}, {0,0});

	for(auto i = listaAttivita->begin(); i != listaAttivita->end(); ++i){
		if (typeid(**i) == typeid(*a) || typeid(**i) == typeid(*b)){
			auto temp = dynamic_cast<attivita::Servizio*>(*i);
			if (temp->getTipoServizio() == attivita::TipoServizio::RISTORANTE)
				listaRistoranti->push_back(*i);
		}
	}
	delete a;
	delete b;

	sort(listaRistoranti->begin(), listaRistoranti->end(), pointerCompareValutazione);
	for(int i = listaRistoranti->size(); i > 5; i--)
		listaRistoranti->pop_back();
	return listaRistoranti;
}

float CentroCommerciale::getAffollamentoMedio(){
	int somma = 0;
	for(auto i = listaAttivita->begin(); i != listaAttivita->end(); ++i)
		somma += (*i)->getAffollamento();
	return (float)somma/listaAttivita->size();
}

CentroCommerciale::~CentroCommerciale() {
	for(auto i = listaAttivita->begin(); i != listaAttivita->end(); ++i){
		delete *i;
	}
	delete listaAttivita;
}

} /* namespace centro_commerciale */
