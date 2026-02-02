public class Book {
    String title;
    int id;
    boolean available;
    Book(String t,int id,boolean b){
        this.title=t;
        this.id=id;
        this.available=b;
    }
}
import java.util.Scanner;

public class Branch {
    String name;
    int no_books;
    int no_branch;
    Scanner sc=new Scanner(System.in);
    Book[] books;
    static Branch[] branches;



    void store(int a){
        this.no_branch=a;
        branches = new Branch[no_branch];
        for(int i=0;i<no_branch;i++){
            System.out.println("enter no of books for branch "+ (i+1));
            branches[i]=new Branch();
            branches[i].no_books=sc.nextInt();
            branches[i].books =new Book[branches[i].no_books];
            for(int j=0;j<branches[i].no_books;j++){
                System.out.println("enter book id ");
                int id=sc.nextInt();
                sc.nextLine();
                System.out.println("enter book title ");
                String name=sc.nextLine();
                System.out.println("enter book availability ");
                boolean av=sc.nextBoolean();

                branches[i].books[j]= new Book(name,id,av);


            }
        }
    }
    void show(){
        for(int i=0;i<no_branch;i++){
            System.out.println("branch no "+ (i+1));
            if(branches[i].no_books==0){
                System.out.println("no books in this branch");
            }
            for(int j=0;j<branches[i].no_books;j++){
                Book b=branches[i].books[j];
                System.out.print("book id "+ b.id + " title:" + b.title);
                System.out.println(",available:" + b.available);

            }
        }
    }
    boolean borrow() {
        System.out.println("Enter branch no:");
        int brid = sc.nextInt() - 1;
        sc.nextLine();

        if (brid < 0 || brid >= branches.length) {
            System.out.println("Invalid branch number");
            return false;
        }

        System.out.println("Enter book id to borrow:");
        int boid = sc.nextInt();
        sc.nextLine();

        for (Book b : branches[brid].books) {
            if (b.id == boid) {
                if (b.available) {
                    b.available = false;
                    System.out.println("Borrowed successfully");
                    return true;
                } else {
                    System.out.println("Book is not available");
                    return false;
                }
            }
        }

        System.out.println("Book ID not found in this branch");
        return false;
    }

    boolean rtrn() {
        System.out.println("Enter branch no:");
        int brid = sc.nextInt() - 1;
        sc.nextLine();

        if (brid < 0 || brid >= branches.length) {
            System.out.println("Invalid branch number");
            return false;
        }

        System.out.println("Enter book id to return:");
        int boid = sc.nextInt();
        sc.nextLine();

        for (Book b : branches[brid].books) {
            if (b.id == boid) {
                if (!b.available) {
                    b.available = true;
                    System.out.println("Returned successfully");
                    return true;
                } else {
                    System.out.println("Book was already available");
                    return false;
                }
            }
        }

        System.out.println("Book ID not found in this branch");
        return false;
    }

}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter number of branch");
        int no_branch= sc.nextInt();
        Branch branch=new Branch();

        branch.store(no_branch);
        boolean state=true;
        while(state){
            System.out.println("menu");
            System.out.println("1. Borrow");
            System.out.println("2. Return");
            System.out.println("3. Display all");
            System.out.println("4. Exit");
            int choice=sc.nextInt();
            sc.nextLine();
            if(choice==1){
                branch.borrow();

            }
            else if(choice==2){
                branch.rtrn();
            }
            else if(choice==4){
                state=false;
            }
            else if(choice==3){
               branch.show();
            }
            else {
                System.out.println("invalid choice");
            }
        }


    }
}

