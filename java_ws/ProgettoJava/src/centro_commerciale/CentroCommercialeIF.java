package centro_commerciale;

import java.time.LocalTime;
import java.util.List;
import java.util.Optional;

import attivita.*;

public interface CentroCommercialeIF {
	public void addAttivita(Attivita... la) throws AttivitaGiaPresenteException ;
	public boolean setValutazione(String nome, int valutazione) throws ValutazioneOutOfRangeException ;
	public boolean setAffollamento(String nome, int affollamento) throws AffolamentoOutOfRangeException ;
	public List<Attivita> getAttivitaAperte(LocalTime ora);
	public List<Attivita> getNegoziPerTipo(TipoNegozio tipo);
	public List<Attivita> getMiglioriRistoranti();
	public Optional<Float> getAffollamentoMedio();
	public void addParcheggio(Parcheggio... lp);
	public void stampaParcheggi();
}
