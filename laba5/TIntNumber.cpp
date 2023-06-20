#include "TIntNumber.h"

TIntNumber::TIntNumber()
{
    this->number = 0; // Конструктор за замовчуванням ініціалізує число нулем
}

TIntNumber::TIntNumber(int number)
{
    this->number = number; // Конструктор з параметром встановлює число вказаним значенням
}

int TIntNumber::getLastDgt()
{
    return abs(this->number) % 10; // Повертає останню цифру числа, використовуючи оператор модуля
}

int TIntNumber::getFirstDgt()
{
    int temp_num = abs(this->number); // Зберігаємо абсолютне значення числа у тимчасову зміннус
    while (temp_num >= 10) {
        temp_num /= 10; // Ділимо на 10 до тих пір, поки число не стане однозначним (першою цифрою)
    }
    return temp_num; // Повертає першу цифру числа
}

int TIntNumber::getSumOfDgts()
{
    int temp_num = abs(this->number); // Зберігаємо абсолютне значення числа у тимчасову змінну
    int sum = 0; // Ініціалізуємо суму нулем
    while (temp_num) {
        sum += temp_num % 10; // Додаємо останню цифру числа до суми
        temp_num /= 10; // Видаляємо останню цифру, ділячи на 10
    }
    return sum; // Повертає суму всіх цифр у числі
}