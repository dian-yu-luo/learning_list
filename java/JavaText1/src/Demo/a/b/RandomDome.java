package Demo.a.b;

import java.util.Random;

public class RandomDome {
    public static void main(String[] args) {
            Random ra = new Random();
        for (int i = 0; i < ra.nextInt(255); i++) {

            System.out.println(i);
        }
    }
}
