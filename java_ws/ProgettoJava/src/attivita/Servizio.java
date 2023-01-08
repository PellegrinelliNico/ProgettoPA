package attivita;

import java.time.LocalTime;

public class Servizio extends Attivita{
	final TipoServizio tipo;	
	boolean suPrenotazione;
	
	//Costruttori
	public Servizio(String nome, LocalTime orarioApertura, LocalTime orarioChiusura,
			int valutazione, int affollamento, TipoServizio tipo, boolean suPrenotazione)
			throws ValutazioneOutOfRangeException, AffolamentoOutOfRangeException {
		super(nome, orarioApertura, orarioChiusura, valutazione, affollamento);
		this.tipo = tipo;
		this.suPrenotazione = suPrenotazione;
	}
	public Servizio(String nome, LocalTime orarioApertura, LocalTime orarioChiusura,
			TipoServizio tipo, boolean suPrenotazione)
			throws ValutazioneOutOfRangeException, AffolamentoOutOfRangeException {
		this(nome, orarioApertura, orarioChiusura, 0, 0,  tipo, suPrenotazione);
	}
	
	//Metodi
	@Override
	public String toString() {
		return "Servizio " + tipo + ": " + super.toString() +
			   " 	-> Richiesta prenotazione: " + (suPrenotazione? "SI\n" : "NO\n");
	}
	
	public boolean isSuPrenotazione() {
		return suPrenotazione;
	}
	
	public TipoServizio getTipo() {
		return tipo;
	}
}
