#include <iostream>
#include "classes.h"

using namespace std;

int main() { //ініціалізуємо значення коефіцієнтів прямої, створивши масив
    bool answer;
    float x, y;
    const int n = 10;
    TLine array[n] = {
            TLine(0, 1, 6),
            TLine(4, 4, -10),
            TLine(3, 3, 3),
            TLine(-2, 8, 2.5),
            TLine(0.001, -2, 2),
            TLine(11, -5, 6),
            TLine(1, -1, -2),
            TLine(-1, -1, 4),
            TLine(2, 7, 5),
            TLine(-3, 3, -1)
    };

    while (true){ //цикл, що реалізує введення координат (х,у) з клавіатури та перевіряє точку на приналежність прямій
        array[0].LineOutput(array, n);
        cout << "\nEnter coordinates of some point:\n";
        cin >> x >> y;
        TPoint m(x, y); //створюємо об'єкт класу з отриманих значень координат
        array[0].FindLine(array, n, m); //знаходимо пряму, якій належить дана точка
        cout << "\n\nDo you want to go on? 0/1\n"; //питаємо користувача про продовження
        cin >> answer;
        if (answer == (false)) {
            break;
        }
    }
    return 0;
}