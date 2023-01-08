package attivita;

@SuppressWarnings("serial")
public class AffolamentoOutOfRangeException extends Exception {
	public AffolamentoOutOfRangeException() {
		super("Attenzione, affollamento fuori dal range 0-100!");
	}
}
