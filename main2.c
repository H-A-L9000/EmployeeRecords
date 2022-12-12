#include <stdio.h>
#include <stdlib.h>


#define MAX 30
#define MAX_ID 6
#define MAX_EMPLOYEE 10 

typedef struct{
    
    char FirstName[MAX];
    char LastName[MAX];
    int employeeID;
    float salary;
    float net_salary;
    
} Employee;

void main_menu(); 
void manage_input(char); 
void addEmployee(); 
void searchEmployee();
//void viewEmployees(); 
void welcomeMessage(); 
void showEmployee(); 

Employee employees[MAX_EMPLOYEE] =
{
  {"Francine Dela-Cruz", 1234, 50, 50000},
  {"Halle Derry", 2345, 50, 50000},
  {"Sienna Nguyen", 3456, 80, 80000}, 
  { "John Smith", 3921, 50, 80000}, 
  {"Jane Doe", 3422, 20, 60000}, 
  {"James Davis", 4555, 30, 90000},  
  {"Kaitlyn Johnson", 1191, 20, 30000}, 
  {"James Madison", 5115, 20, 30000}, 
 
};

 
int main()
{
    showEmployee();
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
    printf("\n\t\t\t2.Search employee");
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
            searchEmployee();
            break;
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
    FILE *fp = NULL;
    int status = 0; 
    fp = fopen("Employees.txt", "a+");
    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }

    int add = 0; 
    int i;
    printf("Enter the number of employees you wish to add: "); 
    scanf("%d", &add); 
 
    //number of employees
    //int n=2;
    //array to store structure values of all employees
    //Employee employees[n];
 
    //Taking each employee detail as input
    printf("Enter %d Employee Details \n \n",add);
    for(i=0; i < add ; i++){
        printf("Employee %d:- \n",i+1);
        
     
        //Name
        printf("Last Name: ");
        fflush(stdin); 
        //fgets(&employees[i].LastName, MAX, stdin);
        scanf("%s", employees[i].LastName);

        printf("First Name: ");
        fflush(stdin); 
        //fgets(&employees[i].employeeName, MAX, stdin);
        scanf("%s", employees[i].FirstName);
        
        //ID
        printf("Employee Id: ");
        fflush(stdin);
        //fgets(employees[i].id, 6, stdin);
        scanf("%d",&employees[i].employeeID);
        
        //Salary
        printf("Gross Salary: ");
        fflush(stdin); 
        //fgets(employees[i].basic_salary, sizeof(employees[i].basic_salary), stdin ); 
        scanf("%f",&employees[i].salary);
        
        //to consume extra '\n' input
        char ch = getchar();
 
        printf("\n");

        printf("\nHRA is 10%% of gross salary.\n\n");
        printf("DA is 5%% of gross salary.\n\n");
        printf("PF is 8%% of gross salary."); 


        employees[i].net_salary = employees[i].salary - (employees[i].salary*0.10 + employees[i].salary*0.05 + employees[i].salary*0.08);

        printf("\n\nCalculating Net Salary... \n");
        printf("Net Salary: %.2f ", employees[i].net_salary); 

        

        
    }
    fprintf(fp, "Employee:  %-d %-32s %s %d %.2f %.2f \n", i + 1, employees[i].FirstName, employees[i].LastName, employees[i].employeeID, employees[i].salary, employees[i].net_salary);
    fclose(fp);
    main_menu();
}

void searchEmployee()
{
    int employeeID;
    
    //array to store structure values of all employees
    //Employee employees[n]; 
  
    //Searching employee details by ID
    printf("-------------- Employee Search ---------------\n");
    printf("Enter ID to Search Employee: ");
    for (int i = 0; i < 10; ++i){
        if (employees[i].employeeID == employeeID){
            printf("%d %s :%.2f ", employees[i].employeeID, employees[i].employeeName, employees[i].net_salary);       
        }
    }
    main_menu();
    
}

// void viewEmployees()
// {
//     //int n=2;
    
//     //array to store structure values of all employees
//     //Employee employees[n];      
//     //Displaying Employee details
//     printf("-------------- All Employees Details ---------------\n");
//     for(int i=0; i<MAX_EMPLOYEE; i++){
 
//         printf("Name \t: ");
//         printf("%s \n",employees[i].employeeName);
 
//         printf("Id \t: ");
//         printf("%d \n",employees[i].employeeID);
 
//         printf("Salary \t: ");
//         printf("%.2lf \n",employees[i].net_salary);
 
//         printf("\n");
//     }
//     main_menu();
 
    
// }

void showEmployee()
{
    FILE *fptr = fopen("Employees.txt", "w");
    if(fptr == NULL)
    {
        printf("File does not exist");
        exit(1); 
    }
    puts(" "); 
    for(int i = 0; i < MAX_EMPLOYEE; i++)
    {
        fprintf(fptr, "Employee:  %-d %-32s %d %.2f %.2f \n", i + 1, employees[i].employeeName, employees[i].employeeID, employees[i].wage, employees[i].net_salary); 
    }
    fclose(fptr); 
    
}
   
