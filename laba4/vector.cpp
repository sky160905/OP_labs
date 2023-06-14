#include "vector.h"

Vector::Vector() {
    coordX = 0;
    coordY = 0;
}

Vector::Vector(double _coordX) {
    coordX = _coordX;
    coordY = 2;
}

Vector::Vector(double _coordX, double _coordY) {
    coordX = _coordX;
    coordY = _coordY;
}

Vector Vector::operator-(const Vector& other) { // Перевантажений оператор "-" для векторів
    return Vector(coordX - other.coordX, coordY - other.coordY); // Віднімає координати вектора other від поточного вектора
}

Vector Vector::operator*(int factor) { // Перевантажений оператор "*" для вектора та множника
    return Vector(coordX * factor, coordY * factor); // Повертає новий вектор, який отриманий множенням координат поточного вектора на множник factor
}

double Vector::getLen() {  // Повертає довжину вектора, обчислену за формулою |v| = sqrt(x^2 + y^2)
    return sqrt(coordX * coordX + coordY * coordY);
}

double Vector::getCoordX() { // Повертає координату x поточного вектора
    return coordX;
}

double Vector::getCoordY() { // Повертає координату y поточного вектора
    return coordY;
}

void Vector::setCoordX(double coordX) { // Встановлює нове значення координати x для поточного вектора
    this->coordX = coordX;
}

void Vector::setCoordY(double coordY) { // Встановлює нове значення координати y для поточного вектора
    this->coordY = coordY;
}

double Datainput() { // Функція  введення дійсних чисел з консолі
    double input;
    string str;
    while (true) {
        cin >> str;
        bool valid_input = true;
        for (int i = 0; i < str.length(); i++) {
            if (!(isdigit(str[i]) || str[i] == '.' || (i == 0 && str[i] == '-'))) {
                valid_input = false;
                break;
            }
        }
        if (valid_input) {
            input = stod(str);
            break;
        } else {
            cout << "Input error. Enter a valid number: ";
        }
    }
    return input;
}