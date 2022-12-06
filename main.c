
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
#include<string.h> 



//replace all fatherName and employeeName variables with LastName and FirstName
//replace macrodefinitions 
//replace isValidDate with isDateValid --> addEmployee 
//replace sFileHeader with s_FileData
//replace fileHeaderInfo with fileContent 

//macro definitions 
//allows for constant values to be declared throughout code, used globally  
//macro deefinitions are not variables and cannot be changed 
//#define CNAME (expression)  
#define MAX_YEAR 9999 
//numeric constant called MAX_YR contains value 9999 
#define MIN_YEAR 1900 
//constant called MIN_YR contains value 1900 
#define MAX_USER_NAME 30 
//constant called MAX_USER_NAME contains value 30 
#define MAX_PASSWORD 20 
//constant called MAX_PASSWORRD contains value 20 
#define FILE_NAME "EmployeeRecordSystem.bin"
//string consant called FILE_NAME contains value "EmployeeRecordSystem.bin"
#define MAX_LAST_NAME 50 
//constant called MAX_LAST_NAME contains value 50 
#define MAX_FIRST_NAME 50 
//constant MAX_FIRST_NAME contains value 50 
#define MAX_EMPLOYEE_ADDRESS 300
//constant MAX_EMPLOYEE_ADDRESS contains value 300  
#define FILE_HEADER_SIZE sizeof(sFileHeader)




//adds a new name for some existing data type but does not create a new type 



// we have declared an struct type variable Date with the typedef keyword. Now we can create struct type variables with Date 
//define an anonymous struct and give it an alias Date. 
typedef struct 
{
    int mm; 
    int dd; 
    int yyyy; 

} Date;

//typedef <existing data type or keyword> <user given name for the datatype or keyword>
//define anonymous struct and give it an alias sFileHeader
typedef struct 
{
    char username[MAX_USER_NAME]; 
    char password[MAX_PASSWORD]; 

}s_FileData;


//define anonymous struct and give it alias sEmployeeData
typedef struct 
{
    char LastName[MAX_LAST_NAME]; 
    char FirstName[MAX_FIRST_NAME];
    char employeeAddr[MAX_EMPLOYEE_ADDRESS]; 
    Date employeeJoiningDate; 
    unsigned int employee_id; 
    float employeeSalary;  

}s_EmployeesInfo;




============================


//----------IS_FILE_EXISTS

//Check file exist or not
//path is pointer to a chr 
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}



//----------init()



//----------LOGIN()




//----------MAIN()




//----------HEAD MESSAGE
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


//-----------DISPLAY MESSAGE 
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





//----------MENU()
//Displays the menu and shows the options that you'd like to do with the file
void menu()
{
    int option = 0;
    do
    {
        ///changes the headmessage from the head message function whenever a new "page" is being called
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add employee");
        printf("\n\t\t\t2.Search employee");
        printf("\n\t\t\t3.View employee");
        printf("\n\t\t\t4.Delete employee");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter option: ");
     
        scanf("%d", &option); 

        if(option == 1){
            addEmployeeInDataBase(); /// calls the addEmployeeinDataBase() function
            break;
        }
        else if(option == 2){ ///calls the searchEmployee() function
            searchEmployee();
            break;
        }
        else if(option == 3){ ///calls the viewEmployee() function
            viewEmployee();
            break;
        }
        else if(option == 4){ ///calls the deleteEmployee() function
            deleteEmployee();
            break;
        }
        else if(option == 5){
            updateCredential(); ///calls the updateCredential() function
            break;
        }
        else if(option == 0){ ///leaces the main menu
            printf("\n\n\n\t\t\t\tExiting Main Menu:\n\n\n\n\n");
            break;
        }
        default:
            printf("\n\n\n\t\t\tInvalid Input. Enter one of the valid options listed: "); ///prints out message when an invalid option number was put in
    }                                                       ///if-else statement ended
    
    while(option!=0);                                      //Loop Ended
                                     
}




//----------UPDATE_CREDENTIAL 



//----------ADD EMPLOYEE




//-----------VIEW EMPLOYEE DETAILS



//-----------SEARCH EMPLOYEE
// search employee
void searchEmployee()
{
    int found = 0;
    int employeeId =0;
    s_EmployeesInfo addEmployeeInfoInDataBase = {0};
    FILE *fp = NULL;
    ///rb: opens an existing file and reading it in binary mode
    ///
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        ///terminates the file as it cannot perform any other tasks
        exit(1); 
    }
    ///displays that we are in the search Employee option now
    headMessage("SEARCH EMPLOYEE");

    ///fseek sets the file position of the stream to the give offset
    ///fp is the pointer to the file object that idetifies the stream
    ///FILE_HEADER_SIZE refers to the size defined in the global definition
    ///SEEK_SET refers to the position in which the fp is being added to
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter employee ID NO to search:");
    ///reads the ID number input for the Employee into the file
    scanf("%u",&employeeId);

    ///fread reads data from a given file that it is poointed to
    ///&addEmployeeInfoInDataBase is a block in memory it refers to
    ///sizeof(), refers to the size in bytes of each element to be read
    ///1, reads the elements one at a time
    ///fp is the pointer to a FILE object that specifies an input stream 
    while (fread (&addEmployeeInfoInDataBase, sizeof(addEmployeeInfoInDataBase), 1, fp))
    {
        ///compares to the employee added into the file to the id that is being searched for
        if(addEmployeeInfoInDataBase.employee_id == employeeId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        ///prints out the employee ID from when it was added to the dtabase
        ///prints out the employeeName from when it was added into the database
        ///prints out the salary from the database 
        ///prints out the lastname of the employee
        ///prints out the address of the employee
        ///prints out the date of when the employee was hired
        printf("\n\t\t\tEmployee id = %d\n",addEmployeeInfoInDataBase.employee_id);    
        printf("\n\t\t\tEmployee name = %s",addEmployeeInfoInDataBase.employeeName);
        printf("\t\t\tEmployee Salary = %f\n",addEmployeeInfoInDataBase.employeeSalary);
        printf("\t\t\tFather Name = %s",addEmployeeInfoInDataBase.lastName);
        printf("\n\t\t\tEmployee Address = %s",addEmployeeInfoInDataBase.employeeAddr);
        printf("\t\t\tEmployee Admission Date(day/month/year) =  (%d/%d/%d)",addEmployeeInfoInDataBase.employeeJoiningDate.dd,
               addEmployeeInfoInDataBase.employeeJoiningDate.mm, addEmployeeInfoInDataBase.employeeJoiningDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}


//-----------DELETE EMPLOYEE 
void deleteEmployee()
{
    //initialize found variable = false, employee id is not located yet 
    //changed
    int exists = 0;
    //intialize variable for employee ID, the program will read in an integer value that the user enters 
    //change deleteID
    int employeeDelete = 0;
    //struct sFileData = fileDataInfo
    s_FileHead fileHeaderInfo = {0};

    s_EmployeesInfo addEmployeeInfoInDataBase = {0};
    //declare pointers for both files, reg and temporary
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    //display head message for this scenario of deleting an employee
    //calls headMessage function and inputs message
    headMessage("Delete employee Details");
    //open file, read
    fp = fopen(FILE_NAME,"rb");
    //if file is NULL, it does not exist 
    if(fp == NULL)
    {
        printf("Error: File does not exist\n");
        exit(1);
    }
    //open temporary file, write to 
    tmpFp = fopen("tmp.bin","wb");
    //if file is NULL, does not exist 
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("Error: File does not exist\n");
        exit(1);
    }
    //fread reads data from a file and stores it in a buffer
    //fread takes in parameters 
    //Buffer: Pointer to the buffer where data will be stored. A buffer is a region of memory used to temporarily store data
    //Size: The size of each element to be read in bytes
    //Count: Number of elements to be read
    //Stream: Pointer to the FILE object from where data is to be read
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);

    //fwrite() function writes binary and text data from an array to a given data stream.
    //buffer: points to the first object in the array to be written
    //size: the item size in bytes
    //count: the number of the objects to be written
    //stream: points to a FILE object that specifies an output stream

    fwrite(&fileHeaderInfo, FILE_HEADER_SIZE, 1, tmpFp);
  
    printf("\n\t\t\tEnter employee ID NO. for delete:");
    // the program will read in an integer value that the user enters
    //When the user enters an integer, it is stored in the employeeDelete variable.
    // &employeeDelete gets the address of employeeDelete, and the value entered by the user is stored in that address.
    scanf("%d",&employeeDelete);
   


    // fread reads data from a file and stores it in a buffer
    // fread takes in parameters 
    //Buffer: Pointer to the buffer where data will be stored. A buffer is a region of memory used to temporarily store data
    //Size: The size of each element to be read in bytes
    //Count: Number of elements to be read
    //Stream: Pointer to the FILE object from where data is to be read

    while (fread (&addEmployeeInfoInDataBase, sizeof(addEmployeeInfoInDataBase), 1, fp))
    {
        //if employeeDelete does not match an employee ID from the database
        if(addEmployeeInfoInDataBase.employee_id != employeeDelete)
        {
            fwrite(&addEmployeeInfoInDataBase,sizeof(addEmployeeInfoInDataBase), 1, tmpFp);
        }
        else
        //employee ID does already exist, exist variable = 1 or true
        {
            exists = 1;
        }
    }
    ////if exists is true then print Record deleted
    //otherwise record not found 
    //? operator, if condition is true then x(Record deleted successfully): otherwise y(Record not found)
    (exists)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");

    //close all files 
    fclose(fp);
    fclose(tmpFp);
    //delete the file Employee_Records 
    remove(FILE_NAME);
    //rename the temporary file to Employee_Records to keep an updated record 
    rename("tmp.bin",FILE_NAME);
}


//----------IS_NAME_VALID
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
//------------IS_LEAP_YEAR
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.


//-------------IS_VALID_DATE 
int isDateValid(Date *validDate)
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

