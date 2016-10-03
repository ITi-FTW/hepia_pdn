package ch.hepia;

public class Main {

    public static void main(String[] args) {

        // Création des articles
        Article a1 = new Article(180654001, "Lentille", 2.50f, 10);
        Article a2 = new Article(180654002, "Quinoa", 1.20f, 2);
        Article a3 = new Article(180654003, "Riz", 0.50f, 25);

        // Affichage de tous les articles
        System.out.println("Articles =====================\n");

        System.out.println(a1.toString());
        System.out.println(a2.toString());
        System.out.println(a3.toString());

        // Vente (égale au stock)
        System.out.println("Vente égale au stock");
        System.out.println(" Vente possible : " + a1.vendre(10)  + "\n");
        a1.approvisionner(10);

        // Vente (plus grand que stock)
        System.out.println("Vente plus grand que stock");
        System.out.println(" Vente possible : " + a1.vendre(20) + "\n");
        a1.approvisionner(10);

        // Vente (plus petit que stock)
        System.out.println("Vente plus petit que stock");
        System.out.println(" Vente possible : " + a1.vendre(5) + "\n");

        // Réception
        System.out.println("Info Lentille");
        a1.approvisionner(20);
        System.out.println(" Vente possible : " + a1.vendre(10));
        System.out.println(" Intitulé : " + a1.getIntitule());
        System.out.println(" Prix HT : " + a1.getPrixHT());
        System.out.println(" Prix TTC : " + a1.prixTTC() + "\n");

        // Entrée d'un nouvelle article !! doublon !!
        System.out.println("Ajout article, référence déjà présente !");
        Article a4 = new Article(180654001, "Pâtes", 9.50f, 10);
        System.out.println(" Doublon ? " + a1.equals(a4));
    }
}
