class newThread2 extends Thread {
    newThread2() {
        super("Thread 2");
        start();

    }
     synchronized public void run() {

        for(int i=0;i<10;i++) {
            System.out.println(this.getName() +" is running");
            System.out.println("counting from "+this.getName()+" "+ i);
        }
    }
}
class newThread4 implements Runnable {
    Thread t;
    newThread4(){
        t=new Thread(this);
        t.setName("Thread 4");
        t.start();

    }

    synchronized public void run() {

        for (int i = 0; i < 10; i++) {
            System.out.println(t.getName() + " is running");
            System.out.println("counting from "+t.getName()+" "+ i);
        }
    }


}

public class Thread2 {
    public static void main(String[] args) throws InterruptedException {
        newThread2 t1 = new newThread2();
       newThread4 t2= new newThread4();



    }
}
