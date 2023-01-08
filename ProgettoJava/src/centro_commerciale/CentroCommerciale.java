package centro_commerciale;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import attivita.*;

public final class CentroCommerciale implements CentroCommercialeIF{
	private static CentroCommerciale istanzaCentro;
	private List<Attivita> listAttivita;
	private List<Parcheggio> listParcheggi;
	
	//Costruttore
	private CentroCommerciale(){
		listAttivita = new ArrayList<>();
		listParcheggi = new ArrayList<>();
	}
	
	//Metodi
	public static CentroCommerciale getIstanza() {
		if (istanzaCentro == null)
			istanzaCentro = new CentroCommerciale();
		return istanzaCentro;
	}

	@Override
	public void addAttivita(final Attivita... la) throws AttivitaGiaPresenteException {
		for(Attivita a : la)
			if (!listAttivita.contains(a))
				listAttivita.add(a);
			else
				throw new AttivitaGiaPresenteException();
	}

	@Override
	public boolean setValutazione(String nome, int valutazione) throws ValutazioneOutOfRangeException {
		var val = getAttivitaPerNome(nome);
		if(val.isPresent()) {
			val.get().setValutazione(valutazione);
			return true;
		}
		return false;
	}

	@Override
	public boolean setAffollamento(String nome, int affollamento) throws AffolamentoOutOfRangeException {
		var val = getAttivitaPerNome(nome);
		if(val.isPresent()) {
			val.get().setAffollamento(affollamento);
			return true;
		}
		return false;
	}

	@Override
	public List<Attivita> getAttivitaAperte(LocalTime ora) {
		var attivitaAperte = new ArrayList<Attivita>();
		for(Attivita a: listAttivita) {
			if(ora.isAfter(a.getOrarioApertura()) && ora.isBefore(a.getOrarioChiusura()))
				attivitaAperte.add(a);
		}
		Collections.sort(attivitaAperte);
		return attivitaAperte;
	}

	@Override
	public List<Attivita> getNegoziPerTipo(TipoNegozio tipo) {
		var negozi = listAttivita
				  .stream()
				  .filter(c -> c instanceof Negozio)
				  .filter(c -> ((Negozio) c).getTipo() == tipo)
				  .sorted()
				  .collect(Collectors.toList());
		return negozi;
	}

	@Override
	public List<Attivita> getMiglioriRistoranti() {
		var ristorantiMigliori = listAttivita
				  .stream()
				  .filter(c -> c instanceof Servizio)
				  .filter(c -> ((Servizio) c).getTipo() == TipoServizio.RISTORANTE)
				  .sorted(new ValutazioneComparator().reversed())
				  .limit(5)
				  .collect(Collectors.toList());
		return ristorantiMigliori;
	}

	@Override
	public Optional<Float> getAffollamentoMedio() {
		if(listAttivita.isEmpty())
			return Optional.empty();
		int somma = 0;
		for(Attivita a: listAttivita)
			somma += a.getAffollamento();
		return Optional.of((float)somma/listAttivita.size());
	}
	
	private Optional<Attivita> getAttivitaPerNome(String nome) {
		for(int i = 0; i < listAttivita.size(); i++){
			if (nome.equalsIgnoreCase(listAttivita.get(i).getNome()))
				return Optional.of(listAttivita.get(i));
		}
		return Optional.empty();
	}
	
	@Override
	public void addParcheggio(final Parcheggio... lp) {
		for(Parcheggio p : lp)
			listParcheggi.add(p);
	}

	@Override
	public void stampaParcheggi() {
		System.out.println("PARCHEGGI:");
		int n = 0;
		for (Parcheggio p : listParcheggi)
			System.out.println("P" + n++ + " -> " + p.toString());
		
	}
	
}
