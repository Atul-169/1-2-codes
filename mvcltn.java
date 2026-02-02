import java.util.Scanner;

public class mvcltn {
    Scanner sc=new Scanner(System.in);
    static Movie []movie;
    mvcltn(int mnum){
        movie=new Movie [mnum];
        for(int i=0;i<mnum;i++){
            movie[i]=new Movie();
            System.out.println("input title,genre,rating,tcp,inital rcp for movie"+ (i+1));
            movie[i].title=sc.nextLine();
            movie[i].genre=sc.nextLine();

            while(true){
                movie[i].rating=sc.nextFloat();
                if(movie[i].rating>=0 && movie[i].rating<=10){
                    break;
                }
                else{
                    System.out.println("enter a valid rating");
                }
            }
            int chk1;
            while(true) {
                chk1 = sc.nextInt(); //total
                if(chk1>=0){
                    movie[i].tcp = chk1;
                    break;

                }
                else{
                    System.out.println("tcp cant be negative");
                }

            }

            int chk2=sc.nextInt(); //rented

                while(chk2<0){
                    System.out.println("rcp cant be negative");
                    chk2 = sc.nextInt();
                }

            while(chk2>chk1){
                System.out.println("error. try again. rcp should be less than or equal tcp ");
                chk2=sc.nextInt();
            }
            movie[i].ircp=chk2;
            movie[i].remain=chk1-chk2;
            sc.nextLine();

        }
    }
    static void search(String name, int mnum){
        for(int i=0;i<mnum;i++){
            if(name.equals(movie[i].title)){
                System.out.println("movie details");
                System.out.println(movie[i].title);
                System.out.println(movie[i].genre);
                System.out.println(movie[i].rating);
                System.out.println(movie[i].remain);
                return;
            }

        }
        System.out.println("movie not found");

    }
    static void rent(String name, int mnum){
        for(int i=0;i<mnum;i++){
            if(name.equals(movie[i].title)){
                if(movie[i].remain==0){
                    System.out.println("no copy available for rent");
                }

                else{
                    movie[i].remain--;
                    movie[i].ircp++;
                    System.out.println("rent successful");
                    System.out.println("available"+movie[i].remain);
                }
            }
            else {
                System.out.println("movie not found");
            }
        }
    }

}
