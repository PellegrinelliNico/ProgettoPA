package attivita;

import java.time.LocalTime;

public class Negozio extends Attivita{
	final TipoNegozio tipo;
	
	//Costruttori
	public Negozio(String nome, LocalTime orarioApertura, LocalTime orarioChiusura,
			int valutazione, int affollamento, TipoNegozio tipo)
			throws ValutazioneOutOfRangeException, AffolamentoOutOfRangeException {
		super(nome, orarioApertura, orarioChiusura, valutazione, affollamento);
		this.tipo = tipo;
	}
	
	public Negozio(String nome, LocalTime orarioApertura, LocalTime orarioChiusura, TipoNegozio tipo)
			throws ValutazioneOutOfRangeException, AffolamentoOutOfRangeException {
		this(nome, orarioApertura, orarioChiusura, 0, 0, tipo);
	}
	
	//Metodi
	@Override
	public String toString() {
		return "Negozio " + tipo + ": " + super.toString();
	}
	
	public TipoNegozio getTipo() {
		return tipo;
	}
}
