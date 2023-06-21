#include <iostream>
#include <string>
#include "binary.h"

int main() {
    int choice;

    std::cout << "Choose data type:\n";
    std::cout << "1. Integers (int)\n";                 // Вибір типу даних: цілі числа (int)
    std::cout << "2. Real numbers (float)\n";             // Вибір типу даних: дійсні числа (float)
    std::cout << "3. Symbols (char)\n";                   // Вибір типу даних: символи (char)
    std::cout << "4. Strings (string)\n";                   // Вибір типу даних: рядки (string)
    std::cout << "Your choice: ";
    std::cin >> choice;                                   // Зчитування вибору користувача

    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice.\n";                  // Перевірка на недійсний вибір
    }

    if (choice == 1) {
        BinaryTree<int> tree;                             // Створення бінарного дерева для цілих чисел
        tree.processBinaryTree();                         // Обробка бінарного дерева
    }
    else if (choice == 2) {
        BinaryTree<float> tree;                           // Створення бінарного дерева для дійсних чисел
        tree.processBinaryTree();                         // Обробка бінарного дерева
    }
    else if (choice == 3) {
        BinaryTree<char> tree;                            // Створення бінарного дерева для символів
        tree.processBinaryTree();                         // Обробка бінарного дерева
    }
    else if (choice == 4) {
        BinaryTree<std::string> tree;                     // Створення бінарного дерева для рядків
        tree.processBinaryTree();                         // Обробка бінарного дерева
    }
    return 0;
}
