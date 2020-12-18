#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Printer.h"

using namespace std;

char Filename[NAME_MAX];
vector <Student> students;
Printer printer;

void OpenFileForWrite()
{
    FILE *file;

    if ((file = fopen(Filename, "w")) != NULL)
    {
        for (size_t i = 0; i < students.size(); i++)
        {
            char convertedStudent[NAME_MAX];
            strcpy(convertedStudent, students[i].ConvertToFileWriteFormat().c_str());
            
            fputs(convertedStudent, file);
        }
        
        fclose(file);   
    }
    else
        printer.PrintError();
}

bool OpenFileForRead()
{
    FILE *file;

    if ((file = fopen(Filename, "r")) != NULL)
    {
        while (!feof(file))
        {
            char fileString[NAME_MAX];

            if (fgets(fileString, 500, file) != NULL)
            {
                Student student;

                students.push_back(student.ConverFromFileWriteFormat(fileString));

                strcpy(fileString, "");
            }
        }

        fclose(file);   

        return true;
    }
    
    printer.PrintError();
    return false;
}

void AddStudent()
{
    cout << "Enter user data" << endl;

    bool isCorrectData = true;

    string lastName, name, secondName, gender, age;

    do
    {
        isCorrectData = true;

        cout << "Enter student`s last name" << endl;
        cin >> lastName;

        if (lastName == "")
        {
            cout << "Input error" << endl;
            isCorrectData = false;
        }

        cout << "Enter student`s name" << endl;
        cin >> name;

        if (name == "")
        {
            cout << "Input error" << endl;
            isCorrectData = false;
        }

        cout << "Enter student`s second name" << endl;
        cin >> secondName;

        if (secondName == "")
        {
            cout << "Input error" << endl;
            isCorrectData = false;
        }

        cout << "Enter student`s gender M/F" << endl;
        cin >> gender;
        cout << gender[0] << endl;
            
        if (gender != "M" && gender != "F")
        {
            cout << "Input error" << endl;
            isCorrectData = false;
        }

        cout << "Enter student`s age" << endl;
        cin >> age;

        if(age == "" || !isdigit(age[0]) || !isdigit(age[1]) && age.length() == 0 || age.length() > 2)
        {
            cout << "Input error" << endl;
            isCorrectData = false;
        }

        if(isCorrectData == false)
            cout << "Incorrect input, try again..." << endl;

    } while (!isCorrectData);

    Student student(
        lastName,
        name,
        secondName,
        gender[0],
        stoi(age),
        students.size());
    
    students.push_back(student);

    OpenFileForWrite();
}

void ShowStudents()
{
    for (size_t i = 0; i < students.size(); i++)
        students[i].PrintOutStudent();

    printer.FileMenuPrint();
}

void DeleteStudent(int id)
{
    if (students[id].Exists())
        students.erase(students.begin() + id);

    OpenFileForWrite();
}

void EditStudent(int id)
{
    if (students[id].Exists())
    {
        string lastName, name, secondName, gender, age;

        cout << "Enter new data. If input is incorrect or empty data won`t be changed" << endl;

        cout << "Enter new last name" << endl;
        cin >> lastName;

        cout << "Enter new name" << endl;
        cin >> name;

        cout << "Enter new second name" << endl;
        cin >> secondName;

        cout << "Enter new gender" << endl;
        cin >> gender;

        cout << "Enter new age" << endl;
        cin >> age;

        if (lastName != "")
            students[id].SetLastName(lastName);

        if (name != "")
            students[id].SetName(name);

        if (secondName != "")
            students[id].SetSecondName(secondName);

        if (gender == "M" || gender == "F")
            students[id].SetGender(gender[0]);
        
        if (age != "" && isdigit(age[0]) && isdigit(age[1]) && age.length() > 0 && age.length() < 3)
            students[id].SetAge(stoi(age));
    }

    OpenFileForWrite();
}

void SelectedStudentActions(int id)
{
    printer.SelectedStudentPrint();

    bool isBack = false;

    do
    {
        string chose;
        cin >> chose;

        if (chose[0] == '1' || chose[0] == '2' || chose[0] == '3')
        {
            int numChose = (int)chose[0] - 48; 
            cout << numChose << endl;

            switch (numChose)
            {
                case 1:
                {
                    DeleteStudent(id);
                    isBack = true;
                }               
                    break;
                case 2:
                {
                    EditStudent(id);
                    isBack = true;
                }
                    break;
                case 3: isBack = true;
                    break;
            }
        }
        else
            cout << "Wrong input, try again..." << endl;
    } while (!isBack);
    
}

void SelectStudent()
{
    bool isDigit = false;

    cout << "Enter student`s number" << endl;

    do
    {
        string chose;
        cin >> chose;

        if (isdigit(chose[0]) || (isdigit(chose[0]) && isdigit(chose[1])) && chose.length() > 0 && chose.length() < 3)
        {
            isDigit = true;

            students[stoi(chose)].PrintOutStudent();

            SelectedStudentActions(stoi(chose));
        }

    } while (!isDigit);
    
}

void ShowFileMenu()
{
    printer.FileMenuPrint();

    bool isExit = false;
    do
    {
        string mainChose;
        cin >> mainChose;
        if (mainChose[0] == '1' 
        || mainChose[0] == '2' 
        || mainChose[0] == '3'
        || mainChose[0] == '4')
        {
            int numChose = (int)mainChose[0] - 48; 
            
            switch (numChose)
            {
            case 1:
                {
                    AddStudent();
                    printer.FileMenuPrint();    
                } 
                break;
            case 2: ShowStudents();
                break;
            case 3:
                {
                    SelectStudent();
                    printer.FileMenuPrint();
                } 
                break;
            case 4:
                {
                    isExit = true;
                    printer.MainMenuPrint();
                }
                break;
            }
        }
        else
            cout << "Wrong input, try again..." << endl;  
    } while (!isExit); 
}

void SelectFileFocused()
{
    cout << "Input filename" << endl;
    cin >> Filename;

    if(OpenFileForRead())
        ShowFileMenu();
    else
        printer.MainMenuPrint();
}

void CreateFileFocused()
{
    int result;

    do
    {
        cout << "Input filename" << endl;
        printer.PrintWarning();
        cin >> Filename;

        result = creat(Filename, S_IREAD|S_IWRITE);

        if (result == -1)
            printer.PrintError();

    } while (result == -1);
                
    cout << result << endl;
    ShowFileMenu();
}

void ShowMainMenu()
{
    printer.MainMenuPrint();

    bool isExit = false;

    do
    {
        string mainChose;
        cin >> mainChose;

        if (mainChose[0] == '1' || mainChose[0] == '2' || mainChose[0] == '3')
        {
            int numChose = (int)mainChose[0] - 48; 

            switch (numChose)
            {
            case 1: SelectFileFocused();
                break;
            case 2: CreateFileFocused();
                break;
            case 3:
                {
                    isExit = true;
                    cout << "1000-7" << endl;
                }
                break;
            }
        }
        else
            cout << "Wrong input, try again..." << endl;
    } while (!isExit);
}

int main()
{
    ShowMainMenu();
}