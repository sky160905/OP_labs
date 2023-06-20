#include "TRealNumber.h"

TRealNumber::TRealNumber(int integral, int fraction)
{
    this->integral = integral; // Ініціалізуємо змінну integral переданим значенням
    this->fraction = fraction; // Ініціалізуємо змінну fraction переданим значенням
}

int TRealNumber::getLastDgt()
{
    return abs(this->fraction)%10; // Повертаємо останню цифру дробової частини числа
}

int TRealNumber::getFirstDgt()
{
    int temp_num = abs(this->integral);
    while (temp_num >= 10) {
        temp_num /= 10;
    }
    return temp_num; // Повертаємо першу цифру цілої частини числа
}

int TRealNumber::getSumOfDgts()
{
    int sum = 0;
    int temp_num = abs(this->integral);

    while (temp_num) {
        sum += temp_num % 10;
        temp_num /= 10;
    }
    temp_num = this->fraction;
    while (temp_num) {
        sum += temp_num % 10;
        temp_num /= 10;
    }
    return sum; // Повертаємо суму цифр числа (інтегральної та дробової частини)
}
