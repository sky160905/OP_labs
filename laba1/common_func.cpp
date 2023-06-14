#include "cppstyle.h"
#include "cstyle.h"
#include "common_func.h"
#include <iostream>
#include <fstream>
#include <string>

void filestream_func(int modechoice){ //функція для роботи програми в  режимі FileStream
         cout<<"Stream mode is activated.\n"<<endl;
         char  cont;
         char ch;
         string filename;
         do {
             cout << "Enter filename: "; //введення імені файлу
             cin >> filename;
             string fullname = filename + ".txt"; //створення повного імені файлу з розширенням
             string new_fullname = filename + "_new" + ".txt";
             if (!ifstream(fullname)) { //перевірка умови неіснування файлу
                 CreateFile(fullname); //створення файлу з заданою назвою
                 do{
                     AddToFile(fullname); // доповнення файлу
                     cout << "\nYour file " << fullname << ":\n";
                     NewFile(fullname); //виведення файлу
                     cout << "\nPress +  to continue or press any other key to add to this file : "; //вибір "продовжити роботу з даним файлом або доповнити його"
                     cin >> cont;
                 }while (cont != '+');//цикл буде виконуватись, доки користувач вибирає "продвожити роботу з файлом"
                 SortText(fullname, new_fullname); //сортування вмісту файлу
                 cout << "\nResult file " << new_fullname << ": \n"<<endl;
                 NewFile(new_fullname); //виведення результуючого файлу
             }
             else{ //якщо файл існує
                 cout << "\nThis file '" << filename <<"' exists.\n" << endl; //виведення інформації про існування файлу та його зміст
                 cout << "Output of this file: \n";
                 do{
                     NewFile(fullname); //виведення файлу
                     cout << "\nPress + to continue or press any other key to add to this file: "; //вибір "продовжити роботу з даним файлом або доповнити його"
                     cin >> cont;
                     if(cont != '+'){
                         AddToFile(fullname); //додавання даних до файлу за відповідного вибору користувача
                     }
                 }while (cont != '+'); //цикл буде виконуватись, доки користувач вибирає "продвожити роботу з файлом"
                 SortText(fullname, new_fullname); //сортування вмісту файлу
                 cout << "\nNew file " << new_fullname << ": \n\n";
                 NewFile(new_fullname); //виведення результуючого файлу
             }
             cout << "\nEnter + to try again or any other key to exit: "; //вибір "продовжити виконання програми або вийти"
             cin >> ch;
             if (ch!= '+')
                 break; //вихід з програми
         }while(ch == '+');

};

void pointer_func(int modechoice) { //функція для роботи програми в  режимі FilePointer
    cout << "Pointer mode is activated." << endl;
    char cont;
    char ch;
    string filename; //створюємо змінну для роботи з файлом
    do {
        cout << "\nEnter filename: "; //записуємо введене ім'я файлу у спеціальну змінну
        cin >> filename;
        string fullname = filename + ".txt"; //отримуємо повне ім'я файлу з розширенням
        string new_fullname = filename + "_new" + ".txt";
        if (!ifstream(fullname)) { //якщо файл існує, то виводимо повідомлення про це
            CreateFile(fullname);
            cout << "File '" << fullname << "' created.\n";
            do {
                AddToFile(fullname); //доповнюємо файл
                cout << "\nYour file " << fullname << ":\n";
                NewFile(fullname);
                cout << "\nPress + to continue or press any other key to add to this file: "; //вибір "продовжити роботу з даним файлом або доповнити його"
                cin >> cont;
            } while (cont != '+');
            SortText(fullname, new_fullname); //сортуємо вміст
            cout << "\nResult file " << new_fullname << ": \n" << endl;
            NewFile(new_fullname); //виводимо результуючий файл
        }
        else {
            cout << "\nThis file '" << filename << "' exists.\n" << endl; //виведення повідомлення про існування файлу та його вмісту
            cout << "Output of this file: \n";
            do {
                NewFile(fullname);
                cout << "\nPress + to continue or press any other key to add to this file: "; //вибір "продовжити роботу з даним файлом або доповнити його"
                cin >> cont;
                if (cont != '+') {
                    AddToFile(fullname); //доповнюємо існуючий файл
                }
            } while (cont != '+');
            SortText(fullname, new_fullname); //сортуємо рядки та записуємо їх у новий файл
            cout << "\nNew file " << new_fullname << ": \n\n";
            NewFile(new_fullname); //вивід результуючого файлу
        }
        cout << "\nEnter + to try again or any other key to exit: ";  //вибір "продовжити виконання програми або вийти"
        cin >> ch;
        cin.ignore(); // ігнорування символу нової строки
    } while (ch == '+');
}
