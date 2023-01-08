package attivita;

import java.time.LocalTime;

public abstract class Attivita implements Comparable<Attivita>{
	protected String nome;
	protected LocalTime orarioApertura;
	protected LocalTime orarioChiusura;
	protected int valutazione;
	protected int affollamento;
	
	//Costruttori
	public Attivita(String nome, LocalTime orarioApertura, LocalTime orarioChiusura,
			int valutazione, int affollamento)
				throws ValutazioneOutOfRangeException, AffolamentoOutOfRangeException {
		this.nome = nome;
		this.orarioApertura = orarioApertura;
		this.orarioChiusura = orarioChiusura;
		if (valutazione<0 || valutazione>5)
			throw new ValutazioneOutOfRangeException();
		this.valutazione = valutazione;
		if (affollamento<0 || affollamento>100)
			throw new AffolamentoOutOfRangeException();
		this.affollamento = affollamento;
	}
	
	public Attivita(String nome, LocalTime orarioApertura, LocalTime orarioChiusura) 
			throws ValutazioneOutOfRangeException, AffolamentoOutOfRangeException {
		this(nome, orarioApertura, orarioChiusura, 0, 0);
	}

	//Metodi
	@Override
	public String toString() {
		return  "\"" + nome + "\"" +
				"\n 	-> Orario apertura: " + orarioApertura + ", Orario chiusura: " + orarioChiusura +
				"\n 	-> Valutazione: " + valutazione + "*" +
				"\n 	-> Affollamento: " + affollamento + "%\n";
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public LocalTime getOrarioApertura() {
		return orarioApertura;
	}

	public void setOrarioApertura(LocalTime orarioApertura) {
		this.orarioApertura = orarioApertura;
	}

	public LocalTime getOrarioChiusura() {
		return orarioChiusura;
	}

	public void setOrarioChiusura(LocalTime orarioChiusura) {
		this.orarioChiusura = orarioChiusura;
	}

	public int getValutazione() {
		return valutazione;
	}

	public void setValutazione(int valutazione) throws ValutazioneOutOfRangeException {
		if (valutazione<0 || valutazione>5)
			throw new ValutazioneOutOfRangeException();
		this.valutazione = valutazione;
	}

	public int getAffollamento() {
		return affollamento;
	}

	public void setAffollamento(int affollamento) throws AffolamentoOutOfRangeException {
		if (affollamento<0 || affollamento>100)
			throw new AffolamentoOutOfRangeException();
		this.affollamento = affollamento;
	}
	
	@Override
	public int compareTo(Attivita a) {
		return this.nome.compareTo(a.nome);
	}
	
	@Override
	public boolean equals(Object o) {
        if (o == this) {
            return true;
        }
        if (!(o instanceof Attivita)) {
            return false;
        }
        Attivita a = (Attivita) o;
		return this.nome.equalsIgnoreCase(a.getNome());
	}
	
}
