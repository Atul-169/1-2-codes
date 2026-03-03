import java.util.Random;

class ParalielMin implements Runnable {

    private static int[] numbers;
    private static int minAns = Integer.MAX_VALUE;

    private int start;
    private int end;

    public ParalielMin(int[] numbers, int start, int end) {
        ParalielMin.numbers = numbers;
        this.start = start;
        this.end = end;
    }

    @Override
    public void run() {
        int partialMin = Integer.MAX_VALUE;

        for (int i = start; i < end; i++) {
            if (numbers[i] < partialMin) {
                partialMin = numbers[i];
            }
        }

        synchronized (ParalielMin.class) {
            if (partialMin < minAns) {
                minAns = partialMin;
            }
        }
    }

    public static int getMin() {
        return minAns;
    }
}

public class multipleThread {

    public static void main(String[] args) throws InterruptedException {

        Random random = new Random();
        int[] numbers = new int[1000];

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt(100,10000);
        }

        int S = 5;   // number of threads
        Thread[] threads = new Thread[S];
        ParalielMin[] paralielMin = new ParalielMin[S];

        int size = numbers.length / S;

        for (int i = 0; i < S; i++) {
            int start = i * size;
            int end = (i == S - 1) ? numbers.length : (i + 1) * size;

            paralielMin[i] = new ParalielMin(numbers, start, end);
            threads[i] = new Thread(paralielMin[i]);
            threads[i].start();
        }

        // Wait for all threads
        for (int i = 0; i < S; i++) {
            threads[i].join();
        }

        System.out.println("Minimum value: " + ParalielMin.getMin());
    }
}