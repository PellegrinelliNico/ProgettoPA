#ifndef ATTIVITA_H_
#define ATTIVITA_H_

#include<string>
using namespace std;

//Necessario per indicare friend CentroCommerciale
namespace centro_commerciale{class CentroCommerciale;}

namespace attivita {

struct Time {
	int ora;
	int minuti;
    bool operator > (Time const& t) {
    	return (ora > t.ora) || (ora == t.ora && minuti > t.minuti);
    }
    bool operator < (Time const& t) {
    	return (ora < t.ora) || (ora == t.ora && minuti < t.minuti);
    }
};

class Attivita {
private:
	string nome;
	Time orarioApertura;
	Time orarioChiusura;
	int valutazione;
	int affollamento;
	friend class centro_commerciale::CentroCommerciale;
protected:
	Attivita(string m, Time oA, Time oC, int v, int a);
	Attivita(string m, Time oA, Time oC);
public:
	virtual string toString();
	virtual ~Attivita();
	int getValutazione() const;
	void setValutazione(int v);
	int getAffollamento() const;
	void setAffollamento(int a);
	const string& getNome() const;
	Time getOApertura() const;
	Time getOChiusura() const;
    bool operator < (const Attivita& a) const {
        return (nome.compare(a.nome) < 0);
    }
};

inline int Attivita::getValutazione() const{
	return valutazione;
}
inline void Attivita::setValutazione(int v){
	valutazione = v;
}
inline int Attivita::getAffollamento() const{
	return affollamento;
}
inline void Attivita::setAffollamento(int a){
	affollamento = a;
}
inline const string& Attivita::getNome() const{
	return nome;
}
inline Time Attivita::getOApertura() const{
	return orarioApertura;
}
inline Time Attivita::getOChiusura() const{
	return orarioChiusura;
}

} /* namespace attivita */

#endif /* ATTIVITA_H_ */

