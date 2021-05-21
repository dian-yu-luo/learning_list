import java.util.Scanner;

public class ScannerDemo {
    public static void main(String[] args) {
        son s = new son();
        System.out.println(s.aa);
        System.out.println(s.bb);
        s.PrintAA();
        s.PrintBB();
    }
}

class father {
    int aa = 2;

    void PrintAA() {
        System.out.println(aa);
    }
}

class son extends father {
    int bb = 5;

    void PrintBB() {
        System.out.println(bb);
    }
}