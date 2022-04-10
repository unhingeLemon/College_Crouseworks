public class MachineProblem7 {

    public interface Comparison {
        public boolean isGreater(int a, int b);

        public boolean isLess(int a, int b);

        public boolean isEqual(int a, int b);
    }

    public static class Time {

        // Private Variables
        private int hrs;
        private int sec;
        private int min;

        // setter
        public int setter(int h, int m, int s) {
            this.hrs = h;
            this.min = m;
            this.sec = s;
            // convert time into sec
            return (((this.hrs * 60)*60) + (this.min * 60) + this.sec);
        }

    }

    public static class Methods implements Comparison {

        // METHODS
        public boolean isGreater(int a, int b) {
            return (a > b);
        }

        public boolean isLess(int a, int b) {
            return (a < b);
        }

        public boolean isEqual(int a, int b) {
            return (a == b);
        }
    }

    public static void main(String args[]) {

        // I just created a new time object
        // just to call the methods
        Methods time = new Methods();

        // 2 time object
        Time time1 = new Time();
        Time time2 = new Time();

        int time1_in_sec = time1.setter(1, 20, 20);
        int time2_in_sec = time2.setter(1, 30, 10);

        System.out.println("isGreater:");
        System.out.println(time.isGreater(time1_in_sec, time2_in_sec));
        System.out.println("isLess:");
        System.out.println(time.isLess(time1_in_sec, time2_in_sec));
        System.out.println("isEqual:");
        System.out.println(time.isEqual(time1_in_sec, time2_in_sec));

    }
}