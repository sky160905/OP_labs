#include <iostream>
#include "classes.h"

using namespace std;

TLine::TLine(float _a, float _b, float _c) { //конструктор класу лінія, що ініціалізує коефіцієнти
    a = _a;
    b = _b;
    c = _c;
}

bool TLine::IsPointOnLine(TPoint m) { //функція, яка повертає значення в залежності від того, чи належить точка прямій
    return (a * m.getx() + b * m.gety() + c == 0);
}

void TLine::LineOutput(TLine array[], const int n) { //функція, яка реалізує вивід всіх рівнянь прямої
    cout << "\nLines output: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << array[i].a << "x + " << array[i].b << "y + " << array[i].c << " = 0." << endl;
    }
}

void TLine::FindLine(TLine array[], const int n, TPoint m) { //функція, яка шукає пряму, якій належить точка
    bool search = false;
    cout << "\nPoint(" << m.getx() << ";" << m.gety() << ") refers to : " << endl;
    for (int i = 0; i < n; i++) {
        if (array[i].IsPointOnLine(m)) {
            cout << i+1 << "th line.\n ";
            search = true;
        }
    }
    if (!search) { //вивід помилки, якщо точка не належить жодній прямій
        cout << "Any of lines owns this point. ";
    }
}

TPoint::TPoint(float _x, float _y) { //конструктор класу точка, який присвоює х і у передані значення у змінні
    x = _x;
    y = _y;
}

float TPoint::getx() { //метод класу точка, що повертає значення координати x
    return x;
}

float TPoint::gety() { //метод класу точка, що повертає значення координати y
    return y;
}