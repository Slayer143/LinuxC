#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

class Student{
    private:
        string _lastName, _name, _secondName;
        char _gender;
        int _age, _id;
    public:
        void SetLastName(const string& lastName) { _lastName = lastName; }

        void SetName(const string& name) { _name = name; }

        void SetSecondName(const string& secondName) { _secondName = secondName; }

        void SetGender(const char& gender) { _gender = gender; }

        void SetAge(const int& age) { _age = age; }

        string GetLastName() { return _lastName; }

        string GetName() { return _name; }

        string GetSecondName() { return _secondName; }

        char GetGender() { return _gender; }

        int GetAge() { return _age; }

        int GetId() { return _id; }

        void PrintOutStudent()
        {
            cout 
            << "ID: " << _id << "\n" 
            << "Last name: " << _lastName << "\n" 
            << "Name: " << _name << "\n" 
            << "Second name: " << _secondName << "\n" 
            << "Gender: " << _gender << "\n" 
            << "Age: " << _age 
            << endl; 
        }

        bool Exists()
        {
            return _id >= 0;
        }

        string ConvertToFileWriteFormat()
        {
            stringstream result;

            result << _lastName << ";" << _name << ";" << _secondName << ";" << _gender << ";" << _age << ";" << _id << ";" << endl;

            return result.str();
        }

        Student ConverFromFileWriteFormat(char student[NAME_MAX])
        {
            string stringStudent = student;

            string lastName, name, secondName, gender, age, id;

            int pointer = 0;

            for (size_t i = 0; i < stringStudent.length(); i++)
            {
                if (stringStudent[i] != ';' && pointer == 0)
                    lastName +=stringStudent[i];
                
                if (stringStudent[i] != ';' && pointer == 1)
                    name +=stringStudent[i];

                if (stringStudent[i] != ';' && pointer == 2)
                    secondName +=stringStudent[i];

                if (stringStudent[i] != ';' && pointer == 3)
                    gender +=stringStudent[i];

                if (stringStudent[i] != ';' && pointer == 4)
                    age +=stringStudent[i];

                if (stringStudent[i] != ';' && pointer == 5)
                    id +=stringStudent[i];

                if (stringStudent[i] == ';')
                    pointer++;
            }
            
            Student formedStudent(lastName, name, secondName, gender[0], stoi(age), stoi(id));

            return formedStudent;
        }


        Student(const string& lastName, const string& name, const string& secondName, const char& gender, const int& age, const int& id)
        :
            _lastName(lastName),
            _name(name),
            _secondName(secondName),
            _gender(gender),
            _age(age),
            _id(id)
        {}
        
        Student(){};
};
