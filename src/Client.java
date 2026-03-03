import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws InterruptedException, IOException {

        Socket socket = new Socket("localhost",8888);
        System.out.println("Connected to server");
        ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

        Scanner sc = new Scanner(System.in);
        System.out.println("enter first number");
        int a=sc.nextInt();
        System.out.println("enter second number");
        int b=sc.nextInt();

        out.writeInt(a);
        out.writeInt(b);
        out.flush();

        int result=in.readInt();
        System.out.println("number of primes is: "+ result);
        in.close();
        out.close();
        socket.close();
    }
}
