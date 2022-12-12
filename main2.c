#include <stdio.h>
#include <stdlib.h>
 #define MAX 30
 #define MAX_ID 6
#define MAX_EMPLOYEE 10 

typedef struct{
    
    char employeeName[MAX];
    int employeeID;
    float wage;
    float net_salary;
    
} Employee;

    //number of employees

Employee employees[MAX_EMPLOYEE] = =
{
  {"Francine Dela-Cruz", 1234, 50, 50000},
  {"Halle Derry", 2345, 50, 50000},
  {"Sienna Nguyen", 3456, 80, 80000}, 
  { "John Smith", 3921, 50, 80000}, 
  {"Jane Doe", 3422, 20, 60000}, 
  {"James Davis", 4555, 30, 90000},  
  {"Kaitlyn Johnson, 0191, 20, 30000}, 
  {"James Madison", 5115, 20, 30000}, 
 
}


void main_menu(); 
void manage_input(char); 
void addEmployee(); 
void viewEmployees(); 
void searchEmployee();
void welcomeMessage(); 
void showEmployee(); 


 
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
    int add = 0; 
    printf("Enter the number of employees you wish to add: "); 
    scanf("%d", &add); 
 
    //number of employees
    //int n=2;

    //array to store structure values of all employees
    //Employee employees[n];
 
    //Taking each employee detail as input
    printf("Enter %d Employee Details \n \n",n);
    for(int i=0; i < add ; i++){
        printf("Employee %d:- \n",i+1);

        //Name
        //printf("Employee Name: ");
        //fflush(stdin); 
        //fgets(employees[i].name, MAX, stdin);
        //scanf("%s",employees[i].name);
     
        //Name
        printf("Employee Name: ");
        fflush(stdin); 
        fgets(employees[i].name, MAX, stdin);
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
 
 void searchEmployee(){
    int employeeID;
    
    //array to store structure values of all employees
    Employee employees[n]; 
  
    //Searching employee details by ID
    printf("-------------- Employees Search ---------------\n");
    printf("Enter ID to Search Employee: ");
    for (int i = 0; i < 10; ++i){
        if (employees[i].id == employeeID){
            printf("%d %s :%f ", employees[i].id, employees[i].name, employees[i].net_salary);       
        }else{
            printf("Employee can't be found with that ID.");
        }
    main_menu();
    

}

void showEmployee
{
    File *fptr = fopen("Employees.txt", "w");

    if(file == NULL)
    {
        printf("File does not exist");
        exit(1); 

    }

    puts(" "); 

    for(int i = 0; i < MAX_EMPLOYEE; i++)
    {
        fprintf(fptr, "Employee:  %-32s  %d %.2f %.2f \n", i + 1, employees[i].name, employees[i].employeeID, employees[i].wage, employees[i].net_salary); 
    }

    fclose(fptr); 

    
}
   
