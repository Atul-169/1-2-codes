class newThread1 implements Runnable {
    Thread t;
    newThread1(){
        t=new Thread(this);
        t.setName("Thread 1");
        t.start();

    }
    @Override
    public void run() {
        System.out.println(t.getName() + " is running");
        for (int i = 0; i < 10; i++) {
            System.out.println("counting = " + i);
        }
    }

}
public class Thread1 {
    static void main(String[] args) {
           new newThread1();
    }
}
