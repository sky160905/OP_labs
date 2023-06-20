#pragma once
#include "TNumber.h"
class TRealNumber : public TNumber{  //похідний клас TRealNumber

private:
    int integral; // Змінна для зберігання цілої частини числа
    int fraction; // Змінна для зберігання дробової частини числа
public:
    TRealNumber(int integral, int fraction); // Конструктор класу з параметрами

    int getLastDgt() override; // Перевизначена функція для отримання останньої цифри числа

    int getFirstDgt() override; // Перевизначена функція для отримання першої цифри числа

    int getSumOfDgts() override; // Перевизначена функція для отримання суми цифр числа
};
