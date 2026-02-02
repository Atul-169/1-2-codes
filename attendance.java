import java.util.Scanner;

public class Department {
    int no_dept;
    int no_employee;
    int dept_id;
    Employee []employee;
    Department []department;
    Scanner sc = new Scanner(System.in);
    void input(int a) {
        no_dept = a;
        department = new Department [no_dept];
        for(int i=0;i<no_dept;i++){
            department[i] = new Department ();
            System.out.println("enter no of employee for department "+(i+1));
            int emp_no= sc.nextInt();
            sc.nextLine();
            department[i].no_employee =emp_no;
           department[i].employee = new Employee [emp_no];
            for(int j=0;j<emp_no;j++){
                department[i].employee[j] = new Employee();

                System.out.println("employee id : ");
                department[i].employee[j].id = sc.nextInt();
                sc.nextLine();
                System.out.println("employee name : ");
                department[i].employee[j].name = sc.nextLine();
                System.out.println("employee days present : ");
                while(true) {
                    department[i].employee[j].present = sc.nextInt();
                    sc.nextLine();
                    if(department[i].employee[j].present>=0) break;
                    else System.out.println("invalid input");

                }
            }
        }
    }
    void display() {
        for(int i=0;i<no_dept;i++){
            System.out.println("dept id: "+ (i+1));
            if(department[i].no_employee==0){
                System.out.println("no employee for department "+(i+1));
            }
            else {
                for (int j = 0; j < department[i].no_employee; j++) {
                    Employee emp = department[i].employee[j];
                    System.out.println("id: " + emp.id + " name: " + emp.name + " days present " + emp.present);

                }
            }
        }
    }
    void mark(){
        System.out.println("enter dept id: ");
        int did = sc.nextInt()-1;
        sc.nextLine();
        System.out.println("enter employee id: ");
        int eid = sc.nextInt();
        sc.nextLine();
        for(int i=0;i<department[did].no_employee;i++){
            if(department[did].employee[i].id==eid){
                department[did].employee[i].present++;
                System.out.println("days increased successfully");
            }
        }

    }
    void correct(){
        System.out.println("enter dept id: ");
        int did = sc.nextInt()-1;
        sc.nextLine();
        System.out.println("enter employee id: ");
        int eid = sc.nextInt();
        sc.nextLine();
        for(int i=0;i<department[did].no_employee;i++){
            if(department[did].employee[i].id==eid) {
                if (department[did].employee[i].present > 0) {
                    department[did].employee[i].present--;
                    System.out.println("days decreased successfully");
                }
                else if(department[did].employee[i].present == 0) {
                    System.out.println("already zero, cant decrease");
                }

            }
        }

    }
}

public class Employee {
    int id;
    String name;
    int present;

    public void storeEmployee(int id, String name, int present) {
        this.id = id;
        this.name = name;
        this.present = present;
    }

}

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int deptno;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of departments : ");
        deptno = sc.nextInt();
        Department dept = new Department();
        dept.input(deptno);
        int choice;
        while (true) {
            System.out.println("Menu :");
            System.out.println("1.Mark attendance");
            System.out.println("2.Correct attendance");
            System.out.println("3.Display all");
            System.out.println("4.Exit");
            choice = sc.nextInt();
            sc.nextLine();
            if(choice==1){
                dept.mark();
            }
            else if(choice==2){
                dept.correct();
            }
            else if(choice==3){
                dept.display();
            }
            else if(choice==4){
                break;
            }
            else{
                System.out.println("Invalid choice");
            }
        }
    }
}
