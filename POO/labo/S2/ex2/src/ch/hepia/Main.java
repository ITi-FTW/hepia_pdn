package ch.hepia;

public class Main {

    public static void main(String[] args) {
        // INIT
        Flacon f1 = new Flacon("Flacon 1", 200);
        Flacon f2 = new Flacon("Flacon 2", 200);

        f1.verser(100,0);
        System.out.println("\nOn verse 100ml de sirop dans le flacon 1 !");
        System.out.println(f1.toString());
        System.out.println("\nOn verse 100ml d'eau dans le flacon 1 !");

        f1.verser(0,100);
        System.out.println(f1.toString());
        System.out.println("\nOn verse 100ml d'eau et 100ml de sirop dans le flacon 2 !");

        f2.verser(100,100);
        System.out.println(f2.toString());
        System.out.println("\nOn transverse le flacon 1 dans le flacon 2");

        f2.transvaser(f1,200);
        System.out.println(f2.toString());
    }
}
