#include <stdio.h>
#include <stdlib.h>
 #define MAX 30
 #define MAX_ID 6
#define MAX_EMPLOYEE 10 

typedef struct{
    
    char employeeName[MAX];
    int employeeID;
    double wage;
    double net_salary;
    
} Employee;

    //number of employees

Employee employees[MAX_EMPLOYEE] = =
{
  {"Francine Dela-Cruz", 1234, 50, 50000},
  {"Halle Derry", 2345, 50, 50000},
  {"Sienna Nguyen", 3456, 80, 80000} 
}


void main_menu(); 
void manage_input(char); 
void addEmployee(); 
void viewEmployees(); 
void welcomeMessage(); 
void showEmplo
 
int main()
{
    welcomeMessage();
    main_menu(); 
    return 0; 
}

void welcomeMessage()
{
    //headMessage("www.aticleworld.com");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               Employee Record             =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
}

void main_menu()
{

    system("cls");

    printf("\n=================================\n");
    printf("--------------MENU---------------");
    printf("\n=================================");
    printf("\n\n\n\t\t\t1.Add employee");
    printf("\n\t\t\t2.View Employees");
    printf("\n\t\t\t3.Search employee");
    printf("\n\t\t\t0.Exit");
    printf("\n\n\n\t\t\tEnter choice => ");
    
    char input;

    while ((input = getchar()) != EOF)
    {
        manage_input(input);
    }

}

void manage_input(char input) 
{
    switch(input)
    {
        case '1':
            addEmployee();
            break;
        case '2':
            viewEmployees();
            break;
        //case 3:
            //searchEmployee();
            //break;
        case '0':
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
    }                                           //Switch Ended
}

void addEmployee()
{
    //number of employees
    int n=2;

    //array to store structure values of all employees
    Employee employees[n];
 
    //Taking each employee detail as input
    printf("Enter %d Employee Details \n \n",n);
    for(int i=0; i<n; i++){
        printf("Employee %d:- \n",i+1);

        //Name
        //printf("Employee Name: ");
        //fflush(stdin); 
        //fgets(employees[i].name, MAX, stdin);
        //scanf("%s",employees[i].name);
        
        //ID
        printf("Employee Id: ");
        fflush(stdin);
        //fgets(employees[i].id, 6, stdin);
        scanf("%d",&employees[i].id);
        
        //Salary
        printf("Basic Salary: ");
        fflush(stdin); 
        //fgets(employees[i].basic_salary, sizeof(employees[i].basic_salary), stdin ); 
        scanf("%lf",&employees[i].basic_salary);
        

        //to consume extra '\n' input
        char ch = getchar();
 
        printf("\n");
    }
    main_menu();
}
void viewEmployees()
{
    int n=2;
    
    //array to store structure values of all employees

    Employee employees[n];      
    //Displaying Employee details
    printf("-------------- All Employees Details ---------------\n");
    for(int i=0; i<n; i++){
 
        printf("Name \t: ");
        printf("%s \n",employees[i].name);
 
        printf("Id \t: ");
        printf("%d \n",employees[i].id);
 
        printf("Salary \t: ");
        printf("%.2lf \n",employees[i].net_salary);
 
        printf("\n");
    }
    main_menu();
 
    

}
   
