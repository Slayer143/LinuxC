#include "/home/slayer143/Documents/Unity/src/unity.h"
#include "Student.h"
#include <string.h>

using namespace std;

void CtorTest()
{
    Student student("lname", "name", "sname", 'M', 29, 0);

    TEST_ASSERT_EQUAL_INT(0, student.GetId());
    TEST_ASSERT_EQUAL_STRING("lname", student.GetLastName().c_str());
    TEST_ASSERT_EQUAL_STRING("name", student.GetName().c_str());
    TEST_ASSERT_EQUAL_STRING("sname", student.GetSecondName().c_str());
    TEST_ASSERT_EQUAL_CHAR('M', student.GetGender());
    TEST_ASSERT_EQUAL_INT(29, student.GetAge());
}

void SettersTest()
{
    Student student("lname", "name", "sname", 'M', 29, 0);

    student.SetLastName("newLastName");
    TEST_ASSERT_EQUAL_STRING("newLastName", student.GetLastName().c_str());

    student.SetName("newName");
    TEST_ASSERT_EQUAL_STRING("newName", student.GetName().c_str());
    
    student.SetSecondName("newSecondName");
    TEST_ASSERT_EQUAL_STRING("newSecondName", student.GetSecondName().c_str());
    
    student.SetGender('L');
    TEST_ASSERT_EQUAL_CHAR('L', student.GetGender());
    
    student.SetAge(20);
    TEST_ASSERT_EQUAL_INT(20, student.GetAge());
}

void ConvertToFileWriteFormatTest()
{
    Student student("lname", "name", "sname", 'M', 29, 0);

    TEST_ASSERT_EQUAL_STRING("lname;name;sname;M;29;0;\n", student.ConvertToFileWriteFormat().c_str());
}

void setUp(){}

void tearDown(){}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(CtorTest);
    RUN_TEST(SettersTest);
    RUN_TEST(ConvertToFileWriteFormatTest);

    return UNITY_END();
}