package attivita;

@SuppressWarnings("serial")
public class ValutazioneOutOfRangeException extends Exception {
	public ValutazioneOutOfRangeException() {
		super("Attenzione, valutazione fuori dal range 0-5!");
	}
}
