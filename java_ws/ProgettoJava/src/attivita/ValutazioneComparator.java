package attivita;

import java.util.Comparator;

public class ValutazioneComparator implements Comparator<Attivita> {

	@Override
	public int compare(Attivita a1, Attivita a2) {
		return Integer.compare(a1.valutazione, a2.valutazione);
	}
	
}
