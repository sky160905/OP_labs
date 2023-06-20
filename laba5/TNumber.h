#pragma once
#include <cmath>
class TNumber{ //визначення класу

public:
    virtual int getLastDgt() = 0; //віртуальна функція для отримання останньої цифри числа
    virtual int getFirstDgt() = 0; //віртуальна функція для отримання першої цифри числа
    virtual int getSumOfDgts() = 0; //віртуальна функція для отримання суми цифр числа
};