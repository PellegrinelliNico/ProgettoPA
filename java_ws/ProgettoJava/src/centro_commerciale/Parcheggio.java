package centro_commerciale;

public record Parcheggio(int nPosti, int nPostiDisabili, boolean coperto) {

	@Override
	public String toString() {
		return  (coperto? "Coperto" : "Non coperto") +
				". " + nPosti + " parcheggi, di cui " + nPostiDisabili + " per disabili.";
	}
}
