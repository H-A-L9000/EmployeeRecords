
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
#include<string.h> 



//replace all fatherName and employeeName variables with lastName and firstName
//replace macrodefinitions 

//macro definitions 
//allows for constant values to be declared throughout code, used globally  
//macro deefinitions are not variables and cannot be changed 
//#define CNAME (expression)  
#define MAX_YEAR 9999 
//numeric constant called MAX_YR contains value 9999 
#define MIN_YEAR 1900 
//constant called MIN_YR contains value 1900 
#define MAX_USER_NAME 30 
//constant called MAX_SIZE_USER_NAME contains value 30 
#define MAX_PASSWORD 20 
//constant called MAX_SIZE_PASSWORRD contains value 20 
#define FILE_NAME "EmployeeRecordSystem.bin"
//string consant called FILE_NAME contains value "EmployeeRecordSystem.bin"
#define MAX_LAST_NAME 50 
//constant called MAX_FATHER_NAME contains value 50 
#define MAX_EMPLOYEE_NAME 50 
//constant MAX_EMPLOYEE_NAME contains value 50 
#define MAX_EMPLOYEE_ADDRESS 300
//constant MAX_EMPLOYEE_ADDRESS contains value 300  
#define FILE_HEADER_SIZE sizeof(sFileHeader)



//adds a new name for some existing data type but does not create a new type 
//typedef <existing_name> <alias_name>


// we have declared an struct type variable Date with the typedef keyword. Now we can create struct type variables with Date 
typedef struct 
{
    int mm; 
    int dd; 
    int yyyy; 

} Date;

//typedef <existing data type or keyword> <user given name for the datatype or keyword>
typedef struct 
{
    char username[MAX_SIZE_USER_NAME]; 
    char password[MAX_SIZE_PASSWORD]; 

}sFileHeader;//sFileData

//typedef <existing data type or keyword> <user given name for the datatype or keyword>
typedef struct 
{
    char LastName[MAX_LAST_NAME]; 
    char FirstName[MAX_FIRST_NAME];
    char employeeAddr[MAX_EMPLOYEE_ADDRESS]; 
    Date employeeJoiningDate; 
    unsigned int employee_id; 
    float employeeSalary;  

}s_EmployeeInfo;



void printMessageCenter(const char* message)
{
    int len = 0; 
    int pos = 0; 

    len = (78 - strlen(message)/2); 
    printf("\t\t\t"); 
    
    for(pos = 0; pos < len; pos++)
    {
        printf(" "); 

    }
    printf("%s", message) 
}

//Head message
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Employee Record Management System Project in C  ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
//Display message
void welcomeMessage()
{
    headMessage("www.aticleworld.com");
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
    getch();
}
//Validate name
int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
// Function to check leap year.
//Function returns 1 if leap year
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YEAR ||
            validDate->yyyy < MIN_YEAR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}
// Add employee in list
void addEmployeeInDataBase()
{
    // size of addEmployeeInfoDataBase is equal to size of s_employeeInfo struct (6 data types)
    s_EmployeesInfo addEmployeeInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW EMPLOYEES");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tEmployee ID  = ");
    fflush(stdin);
    scanf("%u",&addEmployeeInfoInDataBase.employee_id);
    do
    {
        printf("\n\t\t\tFather Name  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.lastName,MAX_LAST_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.lastName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tEmployee Name  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.FirstName,MAX_FIRST_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.firstName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tEmployee Address  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.employeeAddr,MAX_LAST_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.employeeAddr);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    printf("\n\t\t\tEmployee Salary  = ");
    fflush(stdin);
    scanf("%f",&addEmployeeInfoInDataBase.employeeSalary);
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        scanf("%d/%d/%d",&addEmployeeInfoInDataBase.employeeJoiningDate.dd,&addEmployeeInfoInDataBase.employeeJoiningDate.mm,&addEmployeeInfoInDataBase.employeeJoiningDate.yyyy);
        //check date validity
        status = isValidDate(&addEmployeeInfoInDataBase.employeeJoiningDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addEmployeeInfoInDataBase,sizeof(addEmployeeInfoInDataBase), 1, fp);
    fclose(fp);
}

