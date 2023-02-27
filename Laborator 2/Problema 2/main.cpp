#include <iostream>
#include "Student.h"
#include "Global.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;
Student student[100];
int main()
{
	char nume1[55] = "Bombel\0";
	student[0].SetName(nume1);
	student[0].Set_mathGrade(9.5f);
	student[0].Set_englishGrade(3.9f);
	student[0].Set_historyGrade(5.0f);

	char nume2[55] = "Bombescu\0";
	student[1].SetName(nume2);
	student[1].Set_mathGrade(4.5f);
	student[1].Set_englishGrade(2.8f);
	student[1].Set_historyGrade(9.9f);
	cout << Compare_average(&student[0], &student[1]); cout << endl;
	cout << Compare_math(&student[0],& student[1]); cout << endl;
	cout << Compare_english(&student[0], &student[1]); cout << endl;
	cout << Compare_history(&student[0], &student[1]); cout << endl;
	cout << Compare_name(&student[0], &student[1]);




}