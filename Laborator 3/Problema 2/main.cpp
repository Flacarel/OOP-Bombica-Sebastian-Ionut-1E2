#include "Canvas.h"
#include <cstring>
int main() {
	Canvas a(40, 40);
	a.DrawLine(1, 1, 40, 40, '@');
	a.DrawLine(1, 40, 40, 1, '+');
	a.DrawCircle(20, 30, 4, '@');
	a.DrawCircle(25, 10, 4, '@');
	a.FillCircle(10, 25, 5, '$');
	a.SetPoint(39, 39, '!');
	a.DrawRect(1, 1, 38, 38, '&');
	a.FillRect(5, 30, 35, 35, '*');
	a.Print();
}