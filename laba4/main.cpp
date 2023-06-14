#include <iostream> //підключення бібліотек
#include "vector.h"
using namespace std;

int main() {
    double x, y, x2;
    char count;
    do { //цикл для введення користувачем координат вектора, поки буде вибрано "+"
        cout << "Enter x coordinate of first vector: ";
        x = Datainput();
        cout << "Enter y coordinate of first vector: ";
        y = Datainput();
        cout << "Enter x coordinate of second vector: ";
        x2 = Datainput();

        Vector Vect1(x, y); // Створення об'єктів векторів з введеними користувачем значеннями
        Vector Vect2(x2);
        Vector Vect3;

        cout << "V1 = (" << Vect1.getCoordX() << ", " << Vect1.getCoordY() << ")" << endl; // Виведення координат першого вектора
        Vect1 = Vect1 * 2; // Множення першого вектора на 2
        Vect3 = Vect1 - Vect2;   // Обчислення різниці між першим і другим векторами

        cout << "V2 = (" << Vect2.getCoordX() << ", " << Vect2.getCoordY() << ")" << endl;   // Виведення координат другого вектора
        cout << "V1_doubled = (" << Vect1.getCoordX() << ", " << Vect1.getCoordY() << ")" << endl; // Виведення координат першого вектора після множення на 2
        cout << "V3 = (" << Vect3.getCoordX() << ", " << Vect3.getCoordY() << ")" << endl;     // Виведення координат третього вектора та його довжини
        cout << "Length of V3 = " << Vect3.getLen() << endl;
        cout << "Press '+' to retry: ";  // Запит користувачеві на повторення циклу
        cin >> count;
    } while (count == '+');

    return 0;
}
