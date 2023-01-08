#include <iostream>
#include <memory>
#include "CentroCommerciale.h"

using namespace std;

//Metodo accessorio
void stampaLista(const shared_ptr<vector<attivita::Attivita*>> l){
	for(auto i = l->begin(); i != l->end(); ++i)
		cout << (*i)->toString();
}

int main() {
	//Creazione attivita
	attivita::Attivita* a1 = new attivita::Negozio("OVS", {10, 0}, {17, 0}, attivita::TipoNegozio::ABBIGLIAMENTO);
	attivita::Attivita* a2 = new attivita::Negozio("Euronics", {8, 30}, {16, 30}, 5, 75, attivita::TipoNegozio::ELETTRONICA);
	attivita::Attivita* a3 = new attivita::Servizio("Aldo Pizza", {18, 30}, {23, 0}, 5, 75, attivita::TipoServizio::RISTORANTE, true);
	attivita::Attivita* a4 = new attivita::Servizio("DaRoberto", {18, 30}, {23, 0}, 5, 80, attivita::TipoServizio::RISTORANTE, true);
	attivita::Attivita* a5 = new attivita::Servizio("McDonalds", {8, 30}, {24, 0}, 2, 75, attivita::TipoServizio::RISTORANTE, false);
	attivita::Attivita* a6 = new attivita::Servizio("Road House", {12, 00}, {22, 30}, 3, 45, attivita::TipoServizio::RISTORANTE, false);
	attivita::Attivita* a7 = new attivita::Servizio("Adess", {19, 00}, {21, 0}, 4, 20, attivita::TipoServizio::RISTORANTE, true);
	attivita::Attivita* a8 = new attivita::Servizio("iPhizza", {18, 30}, {20, 0}, 4, 50, attivita::TipoServizio::RISTORANTE, true);
	attivita::Attivita* a9 = new attivita::Servizio("Sumo", {17, 30}, {23, 0}, 4, 100, attivita::TipoServizio::RISTORANTE, true);
	attivita::Attivita* a10 = new attivita::Bar("Freedom", {11, 30}, {24, 0}, 5, 15);

	//Creazione centro commerciale e assegnazione attivita
	centro_commerciale::CentroCommerciale* centro = centro_commerciale::CentroCommerciale::getIstanza();

	centro->addAttivita(a1);
	centro->addAttivita(a2);
	centro->addAttivita(a3);
	centro->addAttivita(a4);
	centro->addAttivita(a5);
	centro->addAttivita(a6);
	centro->addAttivita(a7);
	centro->addAttivita(a8);
	centro->addAttivita(a9);
	centro->addAttivita(a10);
	centro->setAffollamento("OVS", 20);
	centro->setValutazione("OVS", 3);

	//Aggiunta attivita già inserita
	attivita::Attivita* a11 = new attivita::Bar("Freedom", {0, 0}, {0, 0}, 0, 0);
	cout << (centro->addAttivita(a11)?"Attività inserita":"Attività già presente") << endl << endl;

	//Test dei metodi di centro
	cout << "Affollamento medio: " << centro->getAffollamentoMedio()<< "%" << endl << endl;

	cout << "ATTIVITA' APERTE A MEZZOGIORNO: " << endl;
	auto l1 = centro->getAttivitaAperte({12, 0});
	stampaLista(l1);

	cout << endl << "NEGOZI DI ABBIGLIAMENTO: " << endl;
	auto l2 = centro->getNegoziPerTipo(attivita::TipoNegozio::ABBIGLIAMENTO);
	stampaLista(l2);

	cout << endl << "5 MIGLIORI RISTORANTI: " << endl;
	auto l3 = centro->getMiglioriRistoranti();
	stampaLista(l3);

	cout << endl << "TABACCHI: " << endl;
	auto l4 = centro->getNegoziPerTipo(attivita::TipoNegozio::TABACCHI);
	stampaLista(l4);

	delete centro;
}
