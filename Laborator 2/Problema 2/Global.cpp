#include "Student.h"
#include "Global.h"
#include <cstring>
int Compare_math(Student* s1, Student* s2)
{
    float grade1 = s1->Get_mathGrade();
    float grade2 = s2->Get_mathGrade();
    if (grade1 > grade2)
        return 1;
    if (grade1 < grade2)
        return -1;
    return 0;
}
int Compare_english(Student* s1, Student* s2)
{
    float grade1 = s1->Get_englishGrade();
    float grade2 = s2->Get_englishGrade();
    if (grade1 > grade2)
        return 1;
    if (grade1 < grade2)
        return -1;
    return 0;
}
int Compare_history(Student* s1, Student* s2)
{
    float grade1 = s1->Get_historyGrade();
    float grade2 = s2->Get_historyGrade();
    if (grade1 > grade2)
        return 1;
    if (grade1 < grade2)
        return -1;
    return 0;
}
int Compare_average(Student* s1, Student* s2)
{
    float grade1 = s1->Get_averageGrade();
    float grade2 = s2->Get_averageGrade();
    if (grade1 > grade2)
        return 1;
    if (grade1 < grade2)
        return -1;
    return 0;
}
int Compare_name(Student* s1, Student* s2)
{
    char* name1 = s1->GetName();
    char* name2 = s2->GetName();
    if (strcmp(name1, name2) > 0)
        return 1;
    if (strcmp(name1, name2) < 0)
        return -1;
    return 0;
}

