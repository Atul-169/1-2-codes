import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws InterruptedException, IOException {
        ServerSocket serverSocket = new ServerSocket(8888);
        System.out.println("Server Started");
        while(true){
            Socket socket = serverSocket.accept();
            System.out.println("Client Connected");
            ClientHandler clientHandler=new ClientHandler(socket);
            Thread t=new Thread(clientHandler);
            t.start();
        }
    }
    public static int primeCount(int a, int b) {
        int count = 0;

        for (int i = a; i <= b; i++) {
            if (i < 2) continue;  // skip numbers less than 2

            boolean isPrime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;   // no need to check further
                }
            }

            if (isPrime) {
                count++;
            }
        }

        return count;
    }
}
class ClientHandler implements Runnable{
    private Socket socket;
    ClientHandler(Socket socket) {
        this.socket = socket;
    }
    public void run(){
        try {
            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

            int a=in.readInt();
            int b=in.readInt();
            int result= Server.primeCount(a,b);

            out.writeInt(result);
            out.flush();
            in.close();
            out.close();

            socket.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}

