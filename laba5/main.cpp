#include <iostream> //підключення бібліотек
#include "TIntNumber.h"
#include "TRealNumber.h"
#include <cstdlib>
#include <ctime>

using namespace std;

TIntNumber** generate_TIntNumber_arr(int m) { //генерується масив вказівників розмірністю m
    const int LOWER_BOUND = -1000; //межі діапазону
    const int UPPER_BOUND = 1000;

    TIntNumber** arr = new TIntNumber*[m]; //створюється динамічний масив вказівників розміром m
    for (int i = 0; i < m; i++) { //створюється m показників типу TIntNumber
        arr[i] = new TIntNumber(LOWER_BOUND + rand() % (2 * UPPER_BOUND));
    }
    return arr; //повертається масив вказівників
}

TRealNumber** generate_TRealNumber_arr(int n) { //генерується масив вказівників розмірністю n
    const int LOWER_BOUND = -1000; //межі діапазону
    const int UPPER_BOUND = 1000;

    TRealNumber** arr = new TRealNumber*[n]; //створюється динамічний масив вказівників розміром n
    for (int i = 0; i < n; i++) { //створюється m показників типу TRealNumber
        arr[i] = new TRealNumber(LOWER_BOUND + rand() % (2 * UPPER_BOUND), rand() % UPPER_BOUND);
    }
    return arr; //повертається масив показників
}

int get_first_dgts_sum(TIntNumber** arr, int m) { //обчислюється сума перших цифр чисел, представлених у масиві вказівників
    int sum = 0;
    for (int i = 0; i < m; i++) { //отримане значення додається до суми
        sum += arr[i]->getFirstDgt();
    }
    return sum; //отримана сума повертається
}

int get_last_dgts_sum(TRealNumber** arr, int n) { //обчислюється сума останніх цифр чисел, представлених у масиві вказівників
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]->getLastDgt();
    }
    return sum; //отримана сума повертається
}

int main() {
    srand(time(NULL)); //ініціалізація генератора випадкових чисел
    int m;
    cout << "Enter m: "; //зчитування взіжних даних
    cin >> m;

    int n;
    cout << "Enter n: ";
    cin >> n;

    TIntNumber** int_numbers_arr = generate_TIntNumber_arr(m); //Створення двовимірного масиву
    TRealNumber** real_numbers_arr = generate_TRealNumber_arr(n);

    int first_dgts_sum = get_first_dgts_sum(int_numbers_arr, m); //Обчислення суми перших цифр цілих чисел шляхом виклику функції get_first_dgts_sum(int_numbers_arr, m) і збереження результату у змінну first_dgts_sum
    int last_dgts_sum = get_last_dgts_sum(real_numbers_arr, n); //Обчислення суми останніх цифр дійсних чисел шляхом виклику функції get_last_dgts_sum(real_numbers_arr, n) і збереження результату у змінну last_dgts_sum

    cout << "First digits sum of integer numbers: " << first_dgts_sum << endl; //виведення результатів
    cout << "Last digits sum of real numbers: " << last_dgts_sum << endl;

    for (int i = 0; i < m; i++) { //звільнення виділеної під масив пам'яті
        delete int_numbers_arr[i];
    }
    delete[] int_numbers_arr;

    for (int i = 0; i < n; i++) {
        delete real_numbers_arr[i];
    }
    delete[] real_numbers_arr;

    return 0;
}
