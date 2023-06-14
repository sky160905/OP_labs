#include "cppstyle.h"
#include <iostream>
#include <fstream>
#include <string>


int line_length(string line){ // функція для підрахунку к-к символів у рядку
    int counter = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] != ' ' && line[i] != '.' && line[i] != ',' && line[i] != '\n') { //підрахунок символів окрім ком, крапок та пробілів
            counter++;
        }
    }
    return counter; //повертаємо значення кількості символів
}

void CreateFile(string filename){ // функція для створення файлу
    ofstream created_file(filename); //створення об'єкту класу оfstream  з параметром, що вказує ім'я файлу
    created_file.close(); //закриваємо створений файл
}

void AddToFile(string filename) { // функція для доповнення файлу
    ofstream file(filename); //створення об'єкту для запису даних у файл
    string line;
    cout << "\nPlease fill in the file. To stop filling press ---." << endl;
    bool first_line = true;
    while (getline(cin, line)) { //цикл для зчитування рядків та запису їх у змінну line
        if (line == "---") {
            break;
        }
        if (!first_line) file << endl; //перехід на наступний рядок для всіх рядків, починаючи від першого
        first_line = false;
        file << line;
    }
    file.close(); //закриття файлу
    cout << "The file has been successfully added.\n"; //повідомлення про успішне доповнення
}

void SortText(const string& inputFile, const string& outputFile){ // функція для сортування строк файлу
    ifstream in(inputFile); //об'єкт для читання з файлу
    ofstream out(outputFile); //об'єкт для запису до файлу
    string line;
    string* lines = nullptr; //вказівник на масив рядків
    int count = 0; //кількість рядків у файлі
    while (getline(in, line)) { //цикл для зчитування рядків у файлі та підрахунку рядків
        count++;
    }
    lines = new string[count]; //виділення пам'яті під масив рядків розміром count
    in.clear(); //скидання позиції читання до початку файлу
    in.seekg(0, ios::beg);
    int i = 0;
    while (getline(in, line)) { //запис рядків у масив
        lines[i++] = line;
    }
    for (int i = 0; i < count - 1; i++) { //сортування рядків за довжиною
        for (int j = i + 1; j < count; j++) {
            if (line_length(lines[i]) < line_length(lines[j])) {
                swap(lines[i], lines[j]);
            }
        }
    }
    for (int i = 0; i < count; i++) { //вивід відстортованих рядків до результуючого файлу
        if(line_length(lines[i]) > 0){
            out << line_length(lines[i]) << "- " << lines[i] << endl;
        }
    }
    delete[] lines; //звільнення пам'яті, виділеної під масив
}

void NewFile(string filename){ //функція для виведення результуючого файлу
    ifstream file(filename); // відкриття файлу для читання
    string line;
    while (getline(file, line)) { //виведення рядка на екран
        cout << line << endl;
    }
}