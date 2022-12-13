#include <stdio.h>
#include <stdlib.h>

//macro definitions 
//allows for constant values to be declared throughout code, used globally  
//macro definitions are not variables and cannot be changed 

#define MAX_FIRST 30
//numeric constant called MAX_FIRST contains value 30
#define MAX_LAST 30
//numeric constant called MAX_LAST contains value 30
#define FILE_NAME "EmployeeDatabase.txt"
//string consant called FILE_NAME contains value "EmployeeDatabase.txt"
#define OUTPUT_FILE "EmployeeDatabaseRead.txt"

//define anonymous struct and give it alias Employee
struct Employee{
    
    char FirstName[MAX_FIRST];
    char LastName[MAX_LAST];
    int employeeID;
    float salary;
    float net_salary;
    
};




void main_menu(); 
void showAllEmployees();
void manage_input(char); 
void addEmployee(); 
void searchEmployee(); 
void welcomeMessage(); 
void BinaryToText();

//new_Employee n_employees[MAX_EMPLOYEE];

struct Employee employees;

 
int main()
{ 
    //calls welcomeMessage function 
    welcomeMessage();
    BinaryToText(); 
    //calls main_menu function
    main_menu(); 
    return 0; 
}
void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               Employee Record             =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....\n\n");
    getchar();
}

void main_menu()
{
    printf("\n\t\t\t--------------MENU---------------");
    printf("\n\t\t\t=================================");
   printf("\n\n\n\t\t\t1.Add Employee");
   printf("\n\t\t\t2.Search Employee");
   printf("\n\t\t\t3.Show Current Employees");
   printf("\n\t\t\t4.Exit");
   printf("\n\n\n\t\t\tEnter choice => ");
   
   char input;
   while ((input = getchar()) != EOF)
   {
       manage_input(input);

   }
       manage_input(input);
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
        case '3':
            showAllEmployees();
            break;
        case '4':
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        case '\n':
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Enter Choice =>");
    }                                           //Switch Ended
}

void addEmployee()
{
    
    FILE *fp = NULL;
    int status = 0; 
    //Open file for writing in binary mode. 
    //If the file exists, its contents are overwritten. If the file does not exist, it will be created.
    fp = fopen(FILE_NAME, "wb");

    // //Check file exist or not
    // if(fp == NULL)
    // {
    //     printf("File cannot be opened\n");
    //     exit(1);
    // }

    printf("-------------- Add Employee(s) to System ---------------\n");

    int add = 0; 
    int i;
    //user inputs the number of employees to be added 
    printf("How many employees would you like to add?  "); 
    scanf("%d", &add); 
 
    //use for loop to add each employee until max number is reached 
    printf("Enter %d Employee Details \n \n",add);
    for(i=0; i < add ; i++){
        printf("\nEmployee %d:- \n",i+1);
        
     
        //Prompts user to enter last name
        printf("Enter Last Name: ");
        fflush(stdin); 
        //fgets(&employees[i].LastName, 30, stdin);
        scanf("%s", employees.LastName);

        //prompts user to enter first name
        printf("Enter First Name: ");
        fflush(stdin); 
        //fgets(&employees[i].FirstName, 30, stdin);
        scanf("%s", employees.FirstName);
        
        //prompts user to enter the employee ID
        printf("Enter Employee ID: ");
        fflush(stdin);
        //fgets(employees[i].id, 6, stdin);
        scanf("%d",&employees.employeeID);
        
        //prompts user to enter the gross salary
        printf("Enter Gross Salary: ");
        fflush(stdin); 
        //fgets(employees[i].basic_salary, sizeof(employees[i].basic_salary), stdin ); 
        scanf("%f",&employees.salary);

        
        //to consume extra '\n' input
        char ch = getchar();
 
        printf("\n");

        //Display Deductions and taxes to user
        printf("\nHRA is 10%% of gross salary.");
        printf("\nDA is 5%% of gross salary.");
        printf("\nPF is 8%% of gross salary."); 

        //calculate net salary from gross salary by using deductions and taxes
        employees.net_salary = employees.salary - (employees.salary*0.10 + employees.salary*0.05 + employees.salary*0.08);

        printf("\n\nCalculating Net Salary... \n");
        printf("\nNet Salary: %.2f \n", employees.net_salary);

        //fwrite() function writes binary and text data from an array to a given data stream.
        //buffer: points to the first object in the array to be written
        //size: the item size in bytes
        //count: the number of the objects to be written
        //stream: points to a FILE object that specifies an output stream 

        fwrite(&employees, sizeof(employees), 1, fp);


        
    }
    //fprintf(fp, "Employee: %d %-32s %s %d %.2f %.2f \n",  employees[i].FirstName, employees[i].LastName, employees[i].employeeID, employees[i].salary, employees[i].net_salary);
    fclose(fp);
    puts("\n\nAddition to System Successful");

    // go back to main menu when done
    main_menu();
}

void searchEmployee()
{
    FILE*fp;
    //Open file for reading in binary mode. 
    //If the file does not exist, fopen( ) returns NULL.
	fp=fopen(FILE_NAME,"rb");
	if(fp==NULL){
		printf("The file cannot be opened!");
		exit(1);
	}


    printf("-------------- Search for an Employee ---------------\n");
    int id;
    //Ask user to enter employee ID in order to find specifc employee
    printf("Enter Employee ID: ");
    scanf("%d", &id);


    //fread reads data from a file and stores it in a buffer
    //fread takes in parameters 
    //Buffer: Pointer to the buffer where data will be stored. A buffer is a region of memory used to temporarily store data
    //Size: The size of each element to be read in bytes
    //Count: Number of elements to be read
    //Stream: Pointer to the FILE object from where data is to be read

    while(fread(&employees,sizeof(employees),1,fp)==1)
    {
        //if the employee ID entered by the user matches an employee ID in the struct
        if(id==employees.employeeID)
        {
            //proceed to print out all of the employee information that matches the employee ID 
            printf("Name:  ");
            printf("%s %s \n",employees.FirstName, employees.LastName);
            
            printf("Employee Id:  ");
            printf("%d \n",employees.employeeID);
 
            printf("Salary: ");
            printf("$%.2f \n",employees.salary);

            printf("Net Salary: ");
            printf("$%.2f \n",employees.net_salary);
            //printf("%s\t\t%s\t\t%d\t\t%f\n",employees.FirstName, employees.LastName,employees.employeeID,employees.net_salary);
        }
    
 
    }
    fclose(fp);
    main_menu();

}



void showAllEmployees()
{
    FILE*fp;
    //Open file for reading in binary mode. 
    //If the file does not exist, fopen( ) returns NULL.
	fp=fopen(FILE_NAME,"rb");
	if(fp==NULL){
		printf("The file cannot be opened!");
		exit(1);
	}
    //printf("-------------- All Employees Details ---------------\n");
    printf("============================================================================================\n");
    printf("Employee First Name\t Employee Last Name\t Employee ID\t    Net Salary\n\n"); 
    printf("============================================================================================\n");

    //fread reads data from a file and stores it in a buffer
    //fread takes in parameters 
    //Buffer: Pointer to the buffer where data will be stored. A buffer is a region of memory used to temporarily store data
    //Size: The size of each element to be read in bytes
    //Count: Number of elements to be read
    //Stream: Pointer to the FILE object from where data is to be read

     while(fread(&employees,sizeof(employees),1,fp)==1)
    {
        printf("%-s %28s %28d $%28.2f\n",employees.FirstName, employees.LastName,employees.employeeID,employees.net_salary);
    }
    puts("\n\nRecords Updated"); 

    main_menu();

    // go back to main menu when done
    

}

void BinaryToText() {
    unsigned char str[256];
    unsigned int num;  // assuming 32 bit ints
    int i, len;

    FILE *finp = fopen(FILE_NAME, "rb");
    FILE *fout = fopen(OUTPUT_FILE, "w+");

    while ((len = fgetc(finp)) != EOF) {
        fread(str, len, 1, finp);
        str[len] = '\0';
        num  = (unsigned int)fgetc(finp) << 24;
        num |= fgetc(finp) << 16;
        num |= fgetc(finp) << 8;
        num |= fgetc(finp);
        fprintf(fout, "%s %d\n", (char*)str, num);
    }
    fclose(finp);
    fclose(fout);
}


