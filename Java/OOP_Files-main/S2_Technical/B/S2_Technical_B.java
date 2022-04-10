class Arithmetic {
    public int add(int a, int b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return a + b + c;
    }

    public int add(int a, int b, int c, int d) {
        return a + b + c + d;
    }

    public double multiply(int a, int b) {
        return a * b;

    }

    public double multiply(int a, int b, int c) {
        return a * b * c;
    }

    public double multiply(int a, int b, int c, int d) {
        return a * b * c * d;
    }

    public int subtract(int a, int b) {
        return a - b;
    }

    public double divide(int a, int b) {
        return a / b;
    }
}

public class S2_Technical_B {

    public static void main(String args[]) {

        Arithmetic compute = new Arithmetic();
        System.out.println("add(5, 5) : " + compute.add(5, 5));
        System.out.println("add(5, 5, 5) : " + compute.add(5, 5, 5));
        System.out.println("add(5, 5, 5, 5) : " + compute.add(5, 5, 5, 5));
        System.out.println("multiply(5, 5) : " + compute.multiply(5, 5));
        System.out.println("multiply(5, 5, 5) : " + compute.multiply(5, 5, 5));
        System.out.println("multiply(5, 5, 5, 5) : " + compute.multiply(5, 5, 5, 5));
        System.out.println("subtract(5, 5): " + compute.subtract(5, 5));
        System.out.println("divide(5, 5): " + compute.divide(5, 5));
    }
}
