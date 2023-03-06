#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
int Math::Add(int x, int y) {
	return x + y;
}

int Math::Add(int x, int y, int z) {
	return x + y + z;
}

int Math::Add(double x, double y) {
	return x + y;
}

int Math::Add(double x, double y, double z) {
	return x + y + z;
}

int Math::Mul(int x, int y) {
	return x * y;
}

int Math::Mul(int x, int y, int z) {
	return x * y * z;
}

int Math::Mul(double x, double y) {
	return x * y;
}

int Math::Mul(double x, double y, double z) {
	return x * y * z;
}
int Math::Add(int count, ...) {
	va_list list;
	va_start(list, count);
	int s = 0;
	for (int i = 0;i < count;i++)
		s = s + va_arg(list, int);
	return s;
}
char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;
	int a1 = strlen(a);
	int b1 = strlen(b);
	int max = (a1 > b1) ? a1 : b1;
	char* sir = new char[max];
	sir[0] = '\0';
	strcat(sir, a);
	strcat(sir, b);
}

  


