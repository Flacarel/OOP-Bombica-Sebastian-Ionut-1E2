#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;
char* conv_base(int number, int newBase);
int digitint(int n);
int conv_int(char c);
char conv_char(int c);
int conv_base10(char* number, int base);
//Constructori
Number::Number(const char* value, int base)
{
	this->value = new char[strlen(value) + 1];
	strcpy(this->value,value);
	this->base = base;
}

Number::Number(const Number& n) //copy constructor
{
	this->base = n.base;
	this->value = new char[strlen(n.value) + 1];
	strcpy(this->value, n.value);
}

Number::Number(Number&& n)noexcept //move constructor
{
	this->base = n.base;
	this->value = n.value;
	n.value = nullptr;
}

Number::Number(const int n)
{
	this->value = new char[100];
	int aux = n;
	int i = 0;
	while (aux > 0) {
		this->value[i++] = conv_char(aux % 10);
		aux = aux / 10;
	}
	this->value[i] = '\0';
	_strrev(value);
	this->base = 10;
}

Number::Number(const char* c)
{
	this->value = new char[strlen(c) + 1];
	strcpy(this->value,c);
	this->base = 10;
}
Number::~Number() {
	if(this->value!=nullptr)
	this->value = nullptr;
}

//methods
void Number::SwitchBase(int newBase) {
	char aux[255];
	int x = conv_base10(this->value, this->base);
	strcpy(aux, conv_base(x, newBase));
	aux[strlen(aux)] = '\0';
	delete[] this->value;
	this->value = new char[strlen(aux)+1];
	strcpy(this->value, aux);
	this->base = newBase;
}

int Number::GetBase() {
	return this->base;
}

int Number::GetDigitsCount() {
	return strlen(this->value);
}

void Number::Print()
{
	for (int i = 0; i < GetDigitsCount(); i++)
		cout << this->value[i];
	cout << '\n';

}

bool Number::operator<(Number ex) {
	conv_base10(this->value, this->base);
	conv_base10(ex.value, ex.base);
	return (this->value<ex.value);
}

bool Number::operator>(Number ex) {
	conv_base10(this->value, this->base);
	conv_base10(ex.value, ex.base);
	return (this->value > ex.value);
}

bool Number::operator<=(Number ex) {
	conv_base10(this->value, this->base);
	conv_base10(ex.value, ex.base);
	return (this->value <= ex.value);
}

bool Number::operator>=(Number ex) {
	conv_base10(this->value, this->base);
	conv_base10(ex.value, ex.base);
	return (this->value >= ex.value);
}

bool Number::operator==(Number ex) {
	conv_base10(this->value, this->base);
	conv_base10(ex.value, ex.base);
	return (this->value == ex.value);
}

int Number::operator[](int index) {
	return this->value[index];
}

Number operator+(const Number& n, const Number& m) {
	int maxbase = std::max(n.base, m.base);
	int s = conv_base10(n.value, n.base) + conv_base10(m.value, m.base);
	Number result(conv_base(s,maxbase), maxbase);
	return result;
}

Number operator-(const Number& n, const Number& m) {
	int maxbase = std::max(n.base, m.base);
	int s = conv_base10(n.value, n.base) - conv_base10(m.value, m.base);
	Number result(conv_base(s, maxbase), maxbase);
	return result;
}

Number& Number::operator = (int n) {
	if (this->value != nullptr)
		delete[] this->value;
	this->value = new char[digitint(n)+1];
	int aux = n;
	int i = 0;
	while (aux > 0) {
		this->value[i++] = conv_char(aux % 10);
		aux = aux / 10;
	}
	this->value[i] = '\0';
	_strrev(value);
	this->base = 10;
	return (*this);
}

Number&Number:: operator=(const char* c) {
	delete[] this->value;
	this->value = new char[strlen(c) + 1];
		strcpy(this->value, c);
	return(*this);
}

Number&Number:: operator=(Number  n) {
	//delete[] this->value;
	this->value = new char[strlen(n.value) + 1];
	strcpy(this->value, n.value);
	this->base = n.base;
	return (*this);
}

Number Number:: operator-- () {
	strcpy(this->value, this->value + 1);
	return (*this);
}

Number Number:: operator-- (int) {
	this->value[strlen(this->value) - 1] = '\0';
	return (*this);
}

//functii pe langa methods
int conv_base10(char* number, int base) {
	int nr = 0;
	int p = 1;
	int count = strlen(number) - 1;
	for (int i = count; i >= 0; i--) {
		nr += p * conv_int(number[i]);
		p *= base;
	}
	return nr;
}

char* conv_base(int number, int newBase) {
	char* nr = new char[255];
	int i = 0;
	while (number > 0) {
		nr[i++] = conv_char(number % newBase);
		number /= newBase;
	}

	nr[i] ='\0';
	std::reverse(nr, nr + i);
	
	return nr;
}

int conv_int(char c) {
	if (c >= '0' && c <= '9')
		return (int)(c - '0');
	else
		return (int)(c - 'A' + 10);
}

char conv_char(int c) {
	if (c >= 0 && c <= 9)
		return (char)(c + '0');
	else
		return (char)(c - 10 + 'A');
}

int digitint(int n) {
	int i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return i;
}

