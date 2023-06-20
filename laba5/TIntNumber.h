#pragma once
#include "TNumber.h"

class TIntNumber : public TNumber //похідний клас TIntNumber
{
private:
    int number;

public:
    TIntNumber();

    TIntNumber(int number);

    int getLastDgt() override; //перевизначення функції для знаходження останньої цифри числа

    int getFirstDgt() override; //перевизначення функції для знаходження першої цифри числа

    int getSumOfDgts() override; //перевизначення функції для знаходження суми
};