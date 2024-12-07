#include <windows.h>
#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define numberOfLines 8
#define numberOfLinesInSub 4
int empNumber;
int numberOfEmployeesEntered ;
int diserdLine;
int diserdLine_inSubMenu ; //SubMenu

void gotoxy(int column , int line);
void textattr(int i );


class MenuSystem
{
private:
    char** mymenuOptions;

public:
    MenuSystem(char* options[] , int numberOfMenuOptions )
    {

        this->mymenuOptions = new char*[numberOfMenuOptions];
        for (int i = 0; i < numberOfMenuOptions; ++i)
        {
            mymenuOptions[i] = new char[strlen(options[i]) + 1];
            strcpy(mymenuOptions[i], options[i]);
        }

    }

    void startSys()
    {
        cout << "Welcome to our Employee Management System :\n" ;
        cout << "PLease enter How many Employees do you want in your system ? " ;
        cin >> empNumber ;
    }

//============================Draw The Menu ======================================//

    void menuDisplay()
    {
        system("cls");  // Clear the screen for the next iteration

        for(int stageLine = 0; stageLine < numberOfLines; stageLine++)
        {
            gotoxy(20 , 10 + stageLine);
            if (stageLine == diserdLine)
                textattr(0x74);  // Change color to highlight
            cout << mymenuOptions[stageLine];  // Print the menu option
            textattr(0x07);  // Reset text color to default
        }

    }
/*    void MenuDisplay(char * submenu[4] = NULL ,int inSubMenu = 0)
    {
        system("cls");  // Clear the screen for the next iteration

        if (inSubMenu != 0 && submenu != NULL)
        {
            for (int submenu_Elementselected = 0; submenu_Elementselected < 4; submenu_Elementselected++)
            {
                gotoxy(40, 10 + submenu_Elementselected);  // Adjust position for submenu
                if (submenu_Elementselected == diserdLine_inSubMenu)
                    textattr(0x74);  // Highlight selected submenu option
                printf("%s", submenu[submenu_Elementselected]);
                textattr(0x07);  // Reset text color
            }
        }
        else
        {
            // Handle Main Menu
            for (int stageLine = 0; stageLine < numberOfLines; stageLine++)
            {
                gotoxy(20, 10 + stageLine);
                if (stageLine == diserdLine)
                    textattr(0x74);  // Highlight selected main menu option
                cout << mymenuOptions[stageLine];  // Print the main menu option
                textattr(0x07);  // Reset text color
            }
        }
    }
*/
    void clearMenu()
    {
        _getch();
        system("cls");
    }

    ~MenuSystem() {
        for (int i = 0; i < numberOfLinesInSub; ++i)
        {
            delete[] mymenuOptions[i];
        }
    }

};

#include <iostream>
using namespace std;

class person
{
public:
    static int empNumber;
    static person* arr;

/////////////////////////////// Constructor ////////////////////////////////////////////////
    person() {
        // Constructor logic for individual objects (if needed)
    }

    static void initializeArray(int number) {
        empNumber = number;
        arr = new person[empNumber];
    }

    static void cleanupArray()
    {
        delete[] arr;
        empNumber = 0;
    }

    ~person()
    {
        delete[] arr;
        empNumber = 0;
    }
};

// Define static members
int person::empNumber = 0;


class employee : protected person
{
    int ID;
    char name[30];
    int Age;

public:
    employee(int _ID = -1, char* _name = "no name yet", int _Age = 30)
    {
        cout << "employee CTOR" << endl;
        ID = _ID;
        strcpy(name, _name);
        Age = _Age;
        //numberOfEmployeesEntered ++ ;
    }

/////////////////////////////////////Setters///////////////////////////

    void setID(int _ID){ ID = _ID; }
    void setAge(int _Age) { Age = _Age ;}
    void setName(char *_name) { strcpy(name , _name ) ; }

    static void newEmployee()
    {
        cout << "New Selected --\n";
        if (numberOfEmployeesEntered < empNumber)
        {
            // Input and validate ID
            do {
                cout << "Please Enter the ID (positive integer): ";
                cin >> arr[numberOfEmployeesEntered].ID;

                if (arr[numberOfEmployeesEntered].ID <= 0)
                    cout << "Invalid ID. It must be a positive integer.\n";

            } while (arr[numberOfEmployeesEntered].ID <= 0);

            // Input and validate Age
            do {
                cout << "Please Enter the Age (must be > 18): ";
                cin >> arr[numberOfEmployeesEntered].Age;

                if (arr[numberOfEmployeesEntered].Age <= 18)
                    cout << "Invalid Age. It must be greater than 18.\n";

            } while (arr[numberOfEmployeesEntered].Age <= 18);

            // Input and validate Name
            bool isValidName;
            do {
                isValidName = true;
                cout << "Please Enter the Name (only alphabets): ";
                cin >> arr[numberOfEmployeesEntered].name;

                // Check if name contains only alphabets
                for (int i = 0; arr[numberOfEmployeesEntered].name[i] != '\0'; i++) {
                    if (!isalpha(arr[numberOfEmployeesEntered].name[i])) {
                        cout << "Invalid Name. It must contain only alphabets.\n";
                        isValidName = false;
                        break;
                    }
                }

            } while (!isValidName);

            numberOfEmployeesEntered++;
        }
        else
        {
            cout << "The array is FULL.\n";
        }

        //_getch();
    }

////////////////////////////////////Getters//////////////////////////////////////////////////

    int getID() { return ID ;}
    int getAge() { return Age ;}
    char* getName() { return name ;}

///////////////////////////////////Print//////////////////////////////////////////////////
    static void printAll()
    {
        if (numberOfEmployeesEntered == 0)
        {
            cout << "You have not entered any employees yet.\n";
            return;
        }

        for (int i = 0; i < numberOfEmployeesEntered; i++)
        {
            cout << "Employee no." << i+1 << " ID: " << arr[i].getID() << ", Name: " << arr[i].getName() << ", Age: " << arr[i].getAge() << endl;
        }
    }

    static void displayByID()
    {
        int IdToSearch;
        cout << "Display by ID Selected --\n" ;
        cout << "What is the ID you want to search about ?" ;
        cin >> IdToSearch ;
        int i;
        int found = 0 ;
        for ( int i =0 ; i< empNumber ; i++)
        {
            if(IdToSearch==arr[i].ID)
            {
                cout << "The ID is " << arr[i].getID() << endl ;
                cout << "The name is " << arr[i].getName() << endl ;
                cout << "The Age is " << arr[i].getAge() << endl ;
                found = 1;
                break;
            }
        }
            if (found == 0) {
                cout << "The ID was not found.\n";
            }
    }

    static void displayByName()
    {
        char NameToSearch[30];
        cout << "Display by Name Selected --\n" ;
        cout << "What is the ID you want to search about ?" ;
        cin >> NameToSearch ;
        int found = 0 ;
        int i;
        for ( i =0 ; i< empNumber ; i++)
        {
            if(strcmp(NameToSearch, arr[i].getName()) == 0)
            {
                cout << "The ID is " << arr[i].getID() << endl ;
                cout << "The name is " << arr[i].getName() << endl ;
                cout << "The Age is " << arr[i].getAge() << endl ;
                found = 1;
                break;
            }

        }
            if (found == 0) {
                cout << "The Name was not found.\n";
            }
    }

    static void editEmployee() {
        int IdToEdit;
        cout << "Edit Employee Selected --\n";
        cout << "Enter the ID of the employee you want to edit: ";
        cin >> IdToEdit;

        for (int i = 0; i < empNumber; i++) {
            if (arr[i].ID == IdToEdit) {
                cout << "Edit Options:\n";
                cout << "1. Edit ID\n";
                cout << "2. Edit Name\n";
                cout << "3. Edit Age\n";
                int choice;
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter new ID: ";
                        cin >> arr[i].ID;
                        break;
                    case 2:
                        cout << "Enter new Name: ";
                        cin >> arr[i].name;
                        break;
                    case 3:
                        cout << "Enter new Age: ";
                        cin >> arr[i].Age;
                        break;
                    default:
                        cout << "Invalid choice.\n";
                }
                break;
            }
        }
    }

    static void deleteEmployee() {
        int IdToDelete;
        cout << "Delete Employee Selected --\n";
        cout << "Enter the ID of the employee you want to delete: ";
        cin >> IdToDelete;

        for (int i = 0; i < empNumber; i++) {
            if (arr[i].ID == IdToDelete) {
                for (int j = i; j < empNumber - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                numberOfEmployeesEntered--;
                cout << "Employee with ID " << IdToDelete << " has been deleted.\n";
                break;
            }
        }
    }

    static void deleteAll() {
        numberOfEmployeesEntered = 0;
        cout << "All employees have been deleted.\n";
    }
/////////////////////////////Destructor/////////////////////////////////////////
    ~employee()
    {
        cout << "Employee destructor\n" ;
    }

};

employee* employee::arr = new employee[empNumber];

class HR_Emp : protected employee
{
protected:
    char position[30];
    char department[30];
public:

    HR_Emp(int _ID , char* _name , int _age , char* _position ) : employee(_ID,_name,_age)
    {
        strcpy(position , _position) ;
        strcpy(department , "HR Employee") ;
    }

};
class IT_Emp : protected employee
{
protected:
    char position[30];
    char department[30];
public:

    IT_Emp(int _ID , char* _name , int _age , char* _position ) : employee(_ID,_name,_age)
    {
        strcpy(position , _position) ;
        strcpy(department , "IT Employee") ;
    }

};
class Developer_Emp : protected employee
{
protected:
    char position[30];
    char department[30];
public:

    Developer_Emp(int _ID , char* _name , int _age , char* _position ) : employee(_ID,_name,_age)
    {
        strcpy(position , _position) ;
        strcpy(department , "Developer Employee") ;
    }

};

int main()
{

    char* mainMenuOptions[8] = {"New Employee", "Display by ID", "Display by name", "Display All","Edit Employee","Delete Employee","Delete All", "Exit"};
    char* subMenu_New[numberOfLinesInSub] = {"HR Employee", "IT employee", "Developer","Intern"};
    char* subMenu_Emp[numberOfLinesInSub] = {"HR Employee", "IT employee", "Developer","Intern"};

    //char* subMenu_Display_BY_ID[5] = {"HR Employee", "IT employee", "Developer","Intern" ,"Back to Main Menu"};
    //char* subMenu_Display_BY_Name[5] = {"HR Employee", "IT employee", "Developer","Intern" ,"Back to Main Menu"};
    //char* subMenu_Delete[5] = {"HR Employee", "IT employee", "Developer","Intern" ,"Back to Main Menu"};
    char* subMenu_Edit[numberOfLinesInSub] = {"ID", "Name", "Age","Position" };

    // Create menu systems
    MenuSystem mainMenu(mainMenuOptions , numberOfLines);
    MenuSystem subMenuNew(subMenu_New , numberOfLinesInSub);
    MenuSystem subMenuEmp(subMenu_Emp , numberOfLinesInSub);
    MenuSystem subMenuEdit(subMenu_Edit , numberOfLinesInSub);
    int inSubMenu = 0; // 0-> main menu & 1-> submenu

    mainMenu.startSys();

    char ch ;
    do{
        mainMenu.menuDisplay();

        if (inSubMenu)
        {
            char* currentSubMenu[numberOfLinesInSub];
            switch (diserdLine)
            {
                case 0:
                    for (int i = 0; i < numberOfLinesInSub; i++) {
                        currentSubMenu[i] = subMenu_New[i];  // Copy each string
                    }
                    break;
                case 3:
                    for (int i = 0; i < numberOfLinesInSub; i++) {
                        currentSubMenu[i] = subMenu_Emp[i];  // Copy each string
                    }
                    break;
                case 4:
                    for (int i = 0; i < numberOfLinesInSub; i++) {
                        currentSubMenu[i] = subMenu_Edit[i];  // Copy each string
                    }
                    break;
                case 6:
                    for (int i = 0; i < numberOfLinesInSub; i++) {
                        currentSubMenu[i] = subMenu_Emp[i];  // Copy each string
                    }
                    break;
                default :
                    currentSubMenu[0] = NULL ;
                    inSubMenu = 0;
                    break;
            }
            if (currentSubMenu[0] != NULL)
            {
                for (int submenu_Elementselected = 0; submenu_Elementselected < numberOfLinesInSub; submenu_Elementselected++)
                {
                    gotoxy(40, 10 + submenu_Elementselected);
                    if (submenu_Elementselected == diserdLine_inSubMenu)
                        textattr(0x74);
                    printf("%s", currentSubMenu[submenu_Elementselected]);
                    textattr(0x07);
                }
            }

        }

        //==================== check if extended or normal key =============================//
        ch = _getch();
        switch(ch)
        {
            case -32:
                ch = _getch();
                if (!inSubMenu)
                {
                    switch (ch)
                    {
                        case 72: //up
                            diserdLine --;
                            if (diserdLine<0)
                                diserdLine=numberOfLines-1 ;
                            break;

                        case 80: //down
                            diserdLine ++;
                            if (diserdLine>(numberOfLines-1))
                                diserdLine=0 ;
                            break;
                    }
                }
                else { // Sub-menu navigation
                    switch (ch) {
                        case 72: // Up arrow
                            diserdLine_inSubMenu--;
                            if (diserdLine_inSubMenu < 0)
                                diserdLine_inSubMenu = numberOfLinesInSub-1;
                            break;
                        case 80: // Down arrow
                            diserdLine_inSubMenu++;
                            if (diserdLine_inSubMenu > numberOfLinesInSub-1)
                                diserdLine_inSubMenu = 0;
                            break;
                        case 75: // Left arrow
                            inSubMenu = 0; // Go back to main menu
                            break;
                    }
                }
                break;

            case 13: //Enter
                if (!inSubMenu) {
                    inSubMenu = 1; // Enter the sub-menu
                    diserdLine_inSubMenu = 0; // Reset sub-menu selection
                }

                system("cls");///////////////////////////////////////////////////////
                //if(diserdLine == 0) employee::newEmployee();
                if(diserdLine == 1) employee::displayByID();
                else if(diserdLine == 2) employee::displayByName();
                //else if(diserdLine == 3) employee::printAll();
                //else if(diserdLine == 4) employee::editEmployee();
                else if(diserdLine == 5) employee::deleteEmployee();
                //else if(diserdLine == 6) employee::deleteAll();
                else if(diserdLine == 7)
                {
                    ch = 'e';
                    cout << "Exit Selected --";
                }
                break;

            case 27:  // ESC
                if (inSubMenu)
                {
                    inSubMenu = 0;  // Go back to the main menu
                }
                else
                {
                    cout << "Exiting the system.\n";
                    return 0;
                }
                break;

            default:
                system("cls");
                cout << "invalid char" ;
                _getch();
                break;

        }

    }while(ch != 'e' && ch != 27 );


    delete[] employee::arr;
    return 0;


}

void loopMenu()
{

}
void gotoxy(int column , int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}


void textattr(int i )
{
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE) , i );
}

