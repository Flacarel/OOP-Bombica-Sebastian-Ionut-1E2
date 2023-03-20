#pragma once
class Number
{
	char* value;
	int base;
public:
	Number(const char* value, int base); 
	Number(const Number& n);
	Number( Number&& n)noexcept;
	Number(const int n);
	Number(const char* c);
	~Number();
	friend Number operator+(const Number& n, const Number& m);
	friend Number operator-(const Number& n, const Number& m);
	Number operator-- ();
	Number operator-- (int);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); 
	int  GetBase(); 
	bool operator<(Number ex);
	bool operator>(Number ex);
	bool operator<=(Number ex);
	bool operator>=(Number ex);
	bool operator==(Number ex);
	int operator[](int index);
	Number& operator=( Number n);
	Number& operator=(int n);
	Number& operator=(const char* c);
};
