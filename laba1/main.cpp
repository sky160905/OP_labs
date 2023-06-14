#include <iostream> //підключення бібліотек
#include "cppstyle.h"
#include "cstyle.h"
#include "common_func.h"
#include <limits>

using namespace std;

int main() { //основна функція для реалізації програми
    int modechoice;
    while (true){  //цикл для перевірки правильності вводу змінної для вибору режиму
        cout << "Enter 0 for FileStream mode, 1 for FilePointer:";
        if (!(cin >> modechoice)) { //умова для перевірки вводу цілого числа
            cout << "Enter correct choice!\n" << std::endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (modechoice != 0 && modechoice != 1) { //умова для перевірки вводу числа 0 чи 1
            cout << "Enter correct choice!\n" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    if (modechoice==0){ // виклик функці] для роботи програми в  режимі FileStream
        filestream_func(modechoice);
    }
    else{ // виклик функції для роботи програми в  режимі FilePointer
        pointer_func(modechoice);
    }
}