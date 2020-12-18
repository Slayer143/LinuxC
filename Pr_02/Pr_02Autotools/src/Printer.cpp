#include <iostream>

using namespace std;

class Printer
{
public:
    void FileMenuPrint()
    {
        cout << "Please, select action:" << endl;
        cout << "1 - add student" << endl;
        cout << "2 - show students" << endl;
        cout << "3 - select student" << endl;
        cout << "4 - back to main menu" << endl; 
    }

    void MainMenuPrint()
    {
        cout << "Chose action" << endl;
        cout << "1 - select file" << endl;
        cout << "2 - create new file" << endl;
        cout << "3 - exit" << endl;
    }

    void SelectedStudentPrint()
    {
        cout << "Chose action" << endl;
        cout << "1 - delete student" << endl;
        cout << "2 - edit student" << endl;
        cout << "3 - back" << endl;
    }

    void PrintError()
    {
        cout << "Something went wrong..." << endl;
    }

    void PrintWarning()
    {
        cout << "!WARNING!\n!IF YOU ENTER EXISTING FILENAME FILE WILL BE CLEANED AND ALL DATA WILL BE GONE!" << endl;
    }
};

