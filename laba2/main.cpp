#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include "functions.h"

using namespace std;

int main(){
    char ch, check;
    string filename;

    do{
        cout << "Enter filename: "; // Введення назви файлу від користувача
        cin >> filename;

        string fullname = filename + ".bin"; // Формування повних назв файлів
        string new_fullname = filename + "_new" + ".bin";

        if (!ifstream(fullname, ios::binary)) {
            CreateFile(fullname); // Створення файлу, якщо він не існує
            cout << "\nFile " << filename << " created." << endl;

            AddProducts(fullname); // Додавання товарів до файлу
            cout << "\nOutput of this file: \n";
            ReadFile(fullname);

            PriceChange(fullname); // Зміна цін товарів
            cout << "\nOutput with changed prices: \n";
            ReadFile(fullname);

            ResultFile(fullname, new_fullname); // Створення нового файлу з товарами, виготовленими до поточного місяця
            cout << "\nItems produced before current month: \n";
            ReadFile(new_fullname);
        } else {
            cout << "\nFile with name '" << filename << "' already exists.\n" << endl;
            cout << "\nOutput of this file: \n";

            do{
                ReadFile(fullname); // Показ вмісту файлу
                cout << "\nPress + for showing content, another key to append file: ";
                cin >> check;

                if(check != '+'){
                    AddProducts(fullname); // Додавання товарів до існуючого файлу
                }
            }while(check != '+');

            PriceChange(fullname); // Зміна цін товарів
            cout << "\nOutput with changed prices: \n";
            ReadFile(fullname);

            ResultFile(fullname, new_fullname); // Створення нового файлу з товарами, виготовленими до поточного місяця
            cout << "\nItems produced before current month: \n";
            ReadFile(new_fullname);
        }

        cout << "\nPress + to retry: ";
        cin >> ch; // Перевірка на бажання повторити процес
    }while (ch == '+');
}
