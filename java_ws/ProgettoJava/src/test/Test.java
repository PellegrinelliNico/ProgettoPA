package test;

import java.time.LocalTime;
import java.util.Optional;

import attivita.AffolamentoOutOfRangeException;
import attivita.Attivita;
import attivita.Negozio;
import attivita.Servizio;
import attivita.TipoNegozio;
import attivita.TipoServizio;
import attivita.ValutazioneOutOfRangeException;
import centro_commerciale.AttivitaGiaPresenteException;
import centro_commerciale.CentroCommerciale;
import centro_commerciale.CentroCommercialeIF;
import centro_commerciale.Parcheggio;

public class Test {
	
	public static void main(String[] args) {
		CentroCommercialeIF centro = CentroCommerciale.getIstanza();
		
		//Stampa affollamento medio
		Optional<Float> val = centro.getAffollamentoMedio();
		if(val.isPresent())
			System.out.printf("Affollamento medio: %.2f%%", val.get());
		else
			System.out.println("Centro commerciale senza attività");
		//Inserimento negozi senza eccezzioni
		try {
			Attivita a1 = new Negozio("Zara", LocalTime.of(8, 0), LocalTime.of(17, 0), 4, 50, TipoNegozio.ABBIGLIAMENTO);
			Attivita a2 = new Negozio("Unieuro", LocalTime.of(10, 0), LocalTime.of(20, 0), 3, 90, TipoNegozio.ELETTRONICA);
			Attivita a3 = new Negozio("Giunti al Punto", LocalTime.of(8, 0), LocalTime.of(17, 0), TipoNegozio.LIBRERIA);
			Attivita a4 = new Negozio("LaFeltrinelli", LocalTime.of(8, 0), LocalTime.of(17, 0), TipoNegozio.LIBRERIA);
			Attivita a5 = new Servizio("Old Wild West", LocalTime.of(18, 0), LocalTime.of(22, 0), 4, 50, TipoServizio.RISTORANTE, false);
			Attivita a6 = new Servizio("McDonalds", LocalTime.of(8, 0), LocalTime.of(22, 0), 2, 20, TipoServizio.RISTORANTE, false);
			Attivita a7 = new Servizio("Dispensa Emilia", LocalTime.of(18, 0), LocalTime.of(22, 0), 5, 70, TipoServizio.RISTORANTE, true);
			Attivita a8 = new Servizio("Da30Polenta", LocalTime.of(12, 0), LocalTime.of(20, 0), 5, 90, TipoServizio.RISTORANTE, true);
			Attivita a9 = new Servizio("KFC", LocalTime.of(12, 0), LocalTime.of(22, 0), 3, 100, TipoServizio.RISTORANTE, false);
			Attivita a10 = new Servizio("Road House", LocalTime.of(12, 0), LocalTime.of(22, 0), 4, 5, TipoServizio.RISTORANTE, false);
			centro.addAttivita(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
			centro.setValutazione("LaFeltrinelli", 5);
			centro.setAffollamento("LaFeltrinelli", 10);
		} catch (ValutazioneOutOfRangeException | AffolamentoOutOfRangeException | AttivitaGiaPresenteException e) {
			e.printStackTrace();
		}
		
		//Stampa affollamento medio
		val = centro.getAffollamentoMedio();
		if(val.isPresent())
				System.out.printf("Affollamento medio: %.2f%%", val.get());
		else
				System.out.println("Centro commerciale senza attività");
		System.out.println(); System.out.println();
		
		//Stampa attivita aperte alle 11:30
		System.out.println("ATTIVITA' APERTE ALLE 11:30");
		for(Attivita a : centro.getAttivitaAperte(LocalTime.of(11, 30)))
			System.out.println(a);
		
		//Stampa negozi di tipo LIBRERIA
		System.out.println("LIBRERIE");
		for(Attivita a : centro.getNegoziPerTipo(TipoNegozio.LIBRERIA))
			System.out.println(a);
		
		//Stampa ristoranti migliori
		System.out.println("MIGLIORI 5 RISTORANTI");
		for(Attivita a : centro.getMiglioriRistoranti())
			System.out.println(a);
		
		//Utilizzo dei parcheggi
		centro.addParcheggio(new Parcheggio(100, 10, true), new Parcheggio(500, 20, false), new Parcheggio(20, 1, true));
		centro.stampaParcheggi();
		System.out.println();
		
		//Test delle eccezioni
		try {
			@SuppressWarnings("unused")
			Attivita a11 = new Negozio("OVS", LocalTime.of(8, 0), LocalTime.of(17, 0), 10, 50, TipoNegozio.ABBIGLIAMENTO);
		} catch (ValutazioneOutOfRangeException | AffolamentoOutOfRangeException e) {
			e.printStackTrace();
		}
		try {
			@SuppressWarnings("unused")
			Attivita a12 = new Negozio("Conbipel", LocalTime.of(8, 0), LocalTime.of(17, 0), 3, -10, TipoNegozio.ABBIGLIAMENTO);
		} catch (ValutazioneOutOfRangeException | AffolamentoOutOfRangeException e) {
			e.printStackTrace();
		}
		try {
			Attivita a13 = new Negozio("LaFeltrinelli", LocalTime.of(8, 0), LocalTime.of(17, 0), 1, 45, TipoNegozio.ABBIGLIAMENTO);
			centro.addAttivita(a13);
		} catch (ValutazioneOutOfRangeException | AffolamentoOutOfRangeException | AttivitaGiaPresenteException e) {
			e.printStackTrace();
		}
	}

}
