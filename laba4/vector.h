#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
class Vector { // Клас Vector представляє вектор у двовимірному просторі
        private:
        double coordX, coordY;
        friend ostream& operator<<(ostream& os, const Vector& vec); // Перевантажений оператор виводу для вектора
        friend istream& operator>>(istream& is, Vector& vec); // Перевантажений оператор вводу для вектора

public:
        Vector(); // Конструктор за замовчуванням
        Vector(double _coordX); // Конструктор з однією координатою (x)
        Vector(double _coordX, double _coordY); // Конструктор з двома координатами (x і y)

        Vector operator-(const Vector& other);  // Перевантажений оператор віднімання для векторів
        Vector operator*(int factor); // Перевантажений оператор множення на скаляр для вектора

        double getLen(); // Метод для отримання довжини вектора
        double getCoordX(); // Метод для отримання координати x вектора
        double getCoordY(); // Метод для отримання координати y вектора

        void setCoordX(double coordX); // Метод для встановлення нового значення координати x вектора
        void setCoordY(double coordY);  // Метод для встановлення нового значення координати y вектора
};

 double Datainput(); // Функція Datainput для введення дійсних чисел з консолі
