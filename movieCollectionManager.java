import java.util.Scanner;

public class movieCollectionManager {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int mnum;
        System.out.println("Enter number of movies");
        mnum=sc.nextInt();
        mvcltn mv1=new mvcltn(mnum);
        while(true){
            System.out.println("command");
            String command=sc.next();
            if(command.equals("search")){
                System.out.println("Enter movie name");
                String name= sc.next();
                mvcltn.search(name,mnum);

            }
            else if(command.equals("rent")){
                System.out.println("Enter movie name");
                String name= sc.next();
                mvcltn.rent(name,mnum);
            }
            else if(command.equals("exit")){
                System.out.println("program closed");
                break;
            }
            else{
                System.out.println("Invalid command");
            }
        }



    }

}
