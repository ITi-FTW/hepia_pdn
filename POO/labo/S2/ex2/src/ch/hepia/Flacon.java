package ch.hepia;

public class Flacon {
    // VARS
    private final float capacite;
    private float volume;
    private float concentration;
    public String etiquette;

    // CONSTRUCTOR
    public Flacon(String etiquette, float capacite)
    {
        this.capacite = capacite;
        this.etiquette = etiquette;
    }

    // METHODS
    public void verser(float volumeSirop, float volumeEau)
    {
        boolean EnoughSpace = (this.volume + volumeEau + volumeSirop) <= this.capacite;
        if (EnoughSpace) {
            this.volume += (volumeEau + volumeSirop);
            this.concentration = (volumeSirop / (volumeSirop + volumeEau));
        } else {
            // EXIT
            System.out.println("Le volume du flacon est insuffisant !");
            System.exit(1);
        }
    }

    public void transvaser(Flacon autreFlacon, float volume)
    {
        boolean EnoughSpace = (volume <= this.capacite);
        if (EnoughSpace)
        {
            // Get the volume of sirup and water of the first recipient
            float volumeSirop1 = this.concentration * 100 / this.volume ;
            float volumeEau1 = this.volume - volumeSirop1;

            // Get the volume of sirup and water of the second recipient
            float volumeSirop2 = autreFlacon.concentration * 100 / autreFlacon.volume;
            float volumeEau2 = autreFlacon.volume - volumeSirop2;

            // Get the total volume of sirup and water of both recipient
            float volumeSiropTotal = volumeSirop1 + volumeSirop2;
            float volumeEauTotal = volumeEau1 + volumeEau2;

            // Calculate the volume of the mix of both recipient
            this.volume = volumeEau1 + volumeEau2 + volumeSirop1 + volumeSirop2;
            this.concentration += (volumeSiropTotal / (volumeSiropTotal + volumeEauTotal));
        } else {
            // EXIT
            System.out.println("Le volume du flacon est insuffisant !");
            System.exit(1);
        }
    }

    @Override
    public String toString() {
        return String.format("%s \n Volume : %.2f ml \n Concentration : %.2f",
                this.etiquette, this.volume, this.concentration * 100) + " %";
    }
}
