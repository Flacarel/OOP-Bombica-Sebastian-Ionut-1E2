#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>


int main()
{
	//1
	Sort x1(10, 0, 15);
	x1.Print();
	x1.BubbleSort(true);
	printf("\n");
	x1.Print();
	printf("\n------------------\n");
	//2
	int v[5] = { 1,2,3,4,5 };
	Sort x2(v, 5);
	x2.Print();
	x2.BubbleSort(true);
	printf("\n");
	x2.Print();
	printf("\n------------------\n");
	//3
	Sort x3(4, 1, 420, 699, 5);
	x3.Print();
	x3.QuickSort(true);
	printf("\n");
	x3.Print();
	printf("\n------------------\n");
	//4
	char c[] = "12,34,56,78";
	Sort x4(c);
	x4.Print();
	x4.InsertSort(true);
	printf("\n");
	x4.Print();
	printf("\n------------------\n");
	//5
	Sort x5;
	x5.Print();
	x5.InsertSort(false);
	printf("\n");
	x5.Print();
	printf("\n------------------\n");

}
