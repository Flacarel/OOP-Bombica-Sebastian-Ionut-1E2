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
    int carry = 0;
    char* sum = (char*)malloc(1);
    sum[0] = '\n';
    long a_size = strlen(a) - 1;
    long b_size = strlen(b) - 1;
    long max_size = -1;
    max_size = (a_size > b_size) ? a_size : b_size;
    int current_position = 0;
    while (a_size >= 0 && b_size >= 0)
    {
        auto addition = a[a_size--] + b[b_size--] - 2 * '0';
        sum = (char*)realloc(sum, ++current_position * sizeof(char));
        memmove(sum + 1, sum, current_position);
        if (carry != 0)
            sum[0] = 1;
        else
            sum[0] = 0;
        carry = 0;
        sum[0] += addition % 10 + '0';
        if (addition > 9)
            carry++;
    }

    while (a_size >= 0)
    {
        memmove(sum + 1, sum, current_position++);
        if (carry != 0)
        {
            if (a[a_size] == '9')
            {
                a_size--;
                sum[0] = '0';
            }
            else
            {
                sum[0] = a[a_size--] + 1;
                carry = 0;
            }
        }
        sum[0] = a[a_size--];


    }

    while (b_size >= 0)
    {
        memmove(sum + 1, sum, current_position++);
        if (carry != 0)
        {
            if (b[b_size] == '9')
            {
                b_size--;
                sum[0] = '0';
            }
            else
            {
                sum[0] = a[b_size--] + 1;
                carry = 0;
            }
        }
        sum[0] = b[b_size--];
    }

    if (carry != 0)
    {
        memmove(sum + 1, sum, current_position);
        sum[0] = '1';
        sum[max_size + 2] = '\0';
    }
    else
        sum[max_size + 1] = '\0';

    return sum;
}

