package centro_commerciale;

@SuppressWarnings("serial")
public class AttivitaGiaPresenteException extends Exception {
	public AttivitaGiaPresenteException() {
		super("Attenzione, attivita già presente!");
	}
}
