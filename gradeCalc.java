import java.util.Scanner;

public class Student {
    String name;
    float grade;
    static Scanner sc = new Scanner(System.in);
    static void input(int a,int b) {

        Course[] courses = new Course[a];
        for (int i = 0; i < a; i++) {
            courses[i] = new Course();
            System.out.print("course name: ");
            courses[i].name = sc.nextLine();
            System.out.print("course credit: ");
            courses[i].credit = sc.nextFloat();
            sc.nextLine();

        }
        Student[] students = new Student[b];
        for (int i = 0; i < b; i++) {
            System.out.print("student name: ");
            students[i] = new Student();
            students[i].name = sc.nextLine();
            for(int j=0;j<a;j++) {
                System.out.println("student marks for course " + courses[j].name);
                courses[j].marks = sc.nextFloat();
                sc.nextLine();
            }
            int sum=0,tcredit=0;
            for(int j=0;j<a;j++) {
                sum+=(courses[j].marks)*(courses[j].credit);
                tcredit+=courses[j].credit;

            }
            students[i].

        }
    }



}



public class Course {
    String name;
    float credit,marks;

    }


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnum = sc.nextInt();
        int snum = sc.nextInt();
        Student std=new Student();
        Student.input(cnum,snum);







    }
}
