#include "cstyle.h"
#include <cstring>
#include <string>

int line_length(const char* line) { // функція для підрахунку к-к символів у рядку
    int counter = 0;
    for(int i = 0; line[i] != '\0'; i++) {
        if (line[i] != '.' && line[i] != ',' && line[i] != ' ' && line[i] != '\n') { //підрахунок символів окрім ком, крапок та пробілів
            counter++;
        }
    }
    return counter;
}

int length(const char* line) {
    for(int i = 0; ; i++) if (line[i] == '\0') return i; //функція для підрахунку к-к символів у рядку за допомогою нуль-термінованих строк
}

void CreateFile(const char* filename) { //функція для створення файла
    FILE* created_file = fopen(filename, "w"); //викликається функція fopen в режимі для запису
    fclose(created_file); //викликається функція fclose для закриття файлу
}

void AddToFile(const char* filename) { //функція для доповнення файла
    FILE* file = fopen(filename, "a"); //викликається функція  fopen в режимі додавання
    char line[1024]; //оголошлення масиву символів розміром 1024
    int counter = 0; //змінна для відслідковування позиції символа в рядку
    bool first_line = true;
    printf("Fill in file. To stop filling press ---.");
    while (fgets(line, sizeof(line), stdin)) { //цикл для зчитування і запису строк в змінну line
        if (strcmp(line, "---\n") == 0) { //вихід із циклу, якщо строка дорівнює "---"
            break;
        }
        if (!first_line) fputc('\n', file); //додавання переходу на нову строку перед кожною строкою
        while (line[counter] != '\n') fputc(line[counter++], file); //цикл додавання строк у файл посимвольно
        counter = 0;
        first_line = false; //показуємо, що всі наступні строки не будуть першою
    }
    fclose(file); //закриваємо файл
    printf("The file has been successfully added.\n"); //виведення повідослення про успішну створення файлу
}

void SortText(const char* inputFile, const char* outputFile) { //функція для сортування строк файлу, яка приймає вказівники на вхідний та вихідний файли
    FILE *in = fopen(inputFile, "r"); //відкриття файлу в режимі читання та збереження показника на нього в змінній in
    FILE *out = fopen(outputFile, "w"); //відкриття файлу в режимі читання та збереження показника на нього в змінній out
    char line[1024]; //створення масиву символів розмірністю 1024
    char **lines = nullptr; //показник на показник символів
    int count = 0;
    while (fgets(line, sizeof(line), in)) { //зчитування строк із вхідного файлу
        count++;
    }
    lines = new char*[count];
    fseek(in, 0, SEEK_SET);
    int i = 0;
    while (fgets(line, sizeof(line), in)) { //копіювання строки в елемент масиву
        lines[i] = new char[strlen(line) + 1];
        strcpy(lines[i++], line);
    }
    for (int i = 0; i < count - 1; i++) { //перебирання елементів масиву для сортування строк
        for (int j = i + 1; j < count; j++) { //перебирання елементів і порівнювання довжин строк
            if (line_length(lines[i]) < line_length(lines[j])) {
                char *temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++) { //записує відсортовані строки в вихідний файл
        if (line_length(lines[i]) > 0) {
            fprintf(out, "%d %s", line_length(lines[i]), lines[i]);
            if (lines[i][length(lines[i]) - 1] != '\n') fputc('\n', out);
        }
        delete[] lines[i]; //очистка пам'яті масиву
    }
    delete[] lines;
    fclose(in);//закриття вхідного файлу
    fclose(out); //закриття вихідного файлу
}

void NewFile(const char* filename) { //функція для відкриття файлу з заданим іменем
    FILE* file = fopen(filename, "r"); //відкриваємо файл в режимі запису
    char line[1024]; //створюємо масив символів розміром 1024
    while (fgets(line, 1024, file) != NULL) { //цикл для зчитування строк і запису їх в змінну line
        printf("%s", line);
    }
    fclose(file); //закриваємо файл
}

