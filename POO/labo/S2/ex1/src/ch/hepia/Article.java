package ch.hepia;

/**
 * Created by samuel on 03.10.16.
 */
public class Article {
    //CONSTANT
    private static float TVA = 8;

    // VARS
    private long reference;
    private String intitule;
    private float prixHT;
    private int quantiteEnStock;

    // GET-SET
    public long getReference() {
        return this.reference;
    }

    public float getPrixHT() {
        return this.prixHT;
    }

    public String getIntitule() {
        return this.intitule;
    }

    public int getQuantiteEnStock() {
        return this.quantiteEnStock;
    }

    // CONSTRUCTOR
    public Article(long reference, String intitule, float prixHT, int quantiteEnStock) {
        this.reference = reference;
        this.intitule = intitule;
        this.prixHT = prixHT;
        this.quantiteEnStock = quantiteEnStock;
    }

    //METHODS
    public void approvisionner(int nombreUnites) {
        this.quantiteEnStock += nombreUnites;
    }

    public boolean vendre(int nombreUnites) {
        boolean EnoughStock = this.quantiteEnStock >= nombreUnites;
        if (EnoughStock) {
            this.quantiteEnStock -= nombreUnites;
        }
        return EnoughStock;
    }

    public float prixTTC() {
        return this.getPrixHT() * (1 + (TVA / 100));
    }

    public String toString() {
        return String.format("Article : %d \n Intitulé : %s \n Prix : %f\n",
                this.reference, this.intitule, this.prixTTC());
    }

    public boolean equals(Article article) {
        return this.reference == article.reference;
    }
}
