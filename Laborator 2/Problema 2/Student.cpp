#include "Student.h"
#include <stdio.h>
#include <cstring>
using namespace std;
void Student::SetName(char my_name[])
{
	strcpy_s(name, my_name);
}
char* Student::GetName()
{
	return this->name;
}
void Student::Set_mathGrade(float grade)
{
    if (grade < 1 || grade > 10)
        return;
    mathGrade= grade;
}
float Student::Get_mathGrade()
{
    return mathGrade;
}
void Student::Set_englishGrade(float grade)
{
    if (grade < 1 || grade > 10)
        return;
    englishGrade = grade;
}
float Student::Get_englishGrade()
{
    return englishGrade;
}
void Student::Set_historyGrade(float grade)
{
    if (grade < 1 || grade > 10)
        return;
    historyGrade = grade;
}
float Student::Get_historyGrade()
{
    return historyGrade;
}
float Student::Get_averageGrade()
{
    return 1.0f * (mathGrade + englishGrade + historyGrade) / 3;
}