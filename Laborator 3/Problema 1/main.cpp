#include "Math.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    Math m;
    cout << m.Add(69, 31) << endl;
    cout << m.Add(69, 420, 0) << endl;
    cout << m.Add(1.69, 4.20) << endl;
    cout << m.Add(100.69, 5.11, 15.22) << endl;
    cout << m.Mul(10, 35) << endl;
    cout << m.Mul(15, 9, 1) << endl;
    cout << m.Mul(0.5, 19.5) << endl;
    cout << m.Mul(3.14, 3.15, 3.16) << endl;
    cout << m.Add(6, 1, 3, 5, 7, 9, 11) << endl;
    cout << m.Add("5", "6") << endl;

    return 0;
}