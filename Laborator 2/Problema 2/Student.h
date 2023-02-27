#pragma once
//#include <cstring>
class Student {
private:
	char name[55];
	float mathGrade;
	float englishGrade;
	float historyGrade;
	float averageGrade;
public:
	void SetName(char my_name[]);
	char* GetName();
	void Set_mathGrade(float grade);
	float Get_mathGrade();
	void Set_englishGrade(float grade);
	float Get_englishGrade();
	void Set_historyGrade(float grade);
	float Get_historyGrade();
	float Get_averageGrade();
};

