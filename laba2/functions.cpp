#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>

using namespace std;

struct Product{  //створюємо структуру продукту з чотирма полями
    char name[100];
    char dateOfManufacture[11];
    char expirationDate[11];
    char price[10];
};

void CreateFile(string filename){ //функція для створення файлу та відкриття його в бінарному режимі
    ofstream created_file(filename, ios::binary);
    created_file.close();
}

void ReadFile(string filename){ //функція для зчитування вмісту бінарного файлу
    ifstream file(filename, ios::binary);

    Product product;

    while (file.read((char*)&product, sizeof(Product))){
        cout << "Name: " << product.name << ", " //виведення імені
             << "Date of manufacture: " << product.dateOfManufacture << ", " //виведення дати виготовлення
             << "Expiration date: " << product.expirationDate << ", " //виведення строку придатності
             << "Price: " << product.price << "$" << endl; //виведення ціни
    }
    file.close(); //закриття файлу
}

char LeapYear(int year){ //функція для перевірки року на високосність
    return ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0); //рік високосний, якщо остача від його ділення на 100 не =0 і остача від ділення на 4 дорівнює 0, або остача від ділення на 400 дорівнює 0
}

bool CheckDate(string date){ //функція для перевірки коректності вводу дати
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
    if (month == 2){ // Перевірка для лютого
        if (day <= 28 + LeapYear(year)){ // Перевірка, чи день не перевищує 28 (або 29 у високосному році)
            return true; // Дата є коректною
        }
        else{
            cout << "February has only 28 days!\n\n"; // Вивід повідомлення про помилку
            return false; // Дата є некоректною
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11){ // Перевірка для місяців з 30 днями
        if (day > 30){ // Перевірка, чи день не перевищує 30
            cout << "This month has only 30 days!\n\n"; // Вивід повідомлення про помилку
            return false; // Дата є некоректною
        }
        else{
            return true; // Дата є коректною
        }
    }
    return true; // Дата є коректною для інших місяців
}

bool DateComparison(string date1, string date2){
    int day, month, year, day2, month2, year2;
    sscanf(date1.c_str(), "%d/%d/%d", &day, &month, &year);
    sscanf(date2.c_str(), "%d/%d/%d", &day2, &month2, &year2);

    // Порівняння дат
    if (day <= day2 && month <= month2 && year <= year2 || // Дата1 менша або рівна Даті2 за всіма складовими
        day >= day2 && month <= month2 && year <= year2 || // Дата1 більша або рівна Даті2 за днями, але менша або рівна за місяцями та роками
        day >= day2 && month >= month2 && year <= year2 || // Дата1 більша або рівна Даті2 за днями та місяцями, але менша або рівна за роками
        day <= day2 && month >= month2 && year <= year2)   // Дата1 менша або рівна Даті2 за днями, але більша або рівна за місяцями та роками
    {
        return true; // Дата1 є раніше або рівною Даті2
    }
    else{
        cout << "Date error!"; // Вивід повідомлення про помилку
        return false; // Дата1 є пізніше за Дату2
    }
}

void AddProducts(string filename){
    ifstream file(filename, ios::binary); // Відкриття файлу для читання
    Product product;
    vector<Product> existing_products;
    // Зчитування наявних продуктів з файлу
    while (file.read((char*)&product, sizeof(Product))){
        existing_products.push_back(product);
    }
    file.close(); // Закриття файлу
    ofstream append_file(filename, ios::app | ios::binary); // Відкриття файлу для додавання нових записів
    char ch;
    do{
        cin.ignore(); // Пропуск символу нового рядка
        cout << "\nEnter item name: ";
        cin.getline(product.name, sizeof(product.name)); // Зчитування назви товару

        bool product_exists = false;
        for (const Product& existing_product : existing_products){
            if (strcmp(existing_product.name, product.name) == 0){ // Перевірка, чи товар вже існує у файлі
                product_exists = true;
                break;
            }
        }
        if (product_exists){
            cout << "Item already exists. Price won't be updated.\n";
        }
        else{
            do{
                do{
                    cout << "\nEnter date of manufacture (DD/MM/XXXX): ";
                    cin.getline(product.dateOfManufacture, sizeof(product.dateOfManufacture)); // Зчитування дати виробництва
                } while (!CheckDate(product.dateOfManufacture)); // Перевірка правильності формату дати

                do{
                    cout << "\nEnter expiring date (DD/MM/XXXX): ";
                    cin.getline(product.expirationDate, sizeof(product.expirationDate)); // Зчитування дати закінчення терміну придатності
                } while (!CheckDate(product.expirationDate)); // Перевірка правильності формату дати

            } while (!DateComparison(product.dateOfManufacture, product.expirationDate)); // Перевірка правильності порядку дат

            cout << "\nEnter price(in UAH): ";
            cin.getline(product.price, sizeof(product.price)); // Зчитування ціни товару
            append_file.write((char*)&product, sizeof(Product)); // Запис товару у файл
        }
        cout << "If you want to add item press '+': ";
        cin >> ch;
    } while (ch == '+');

    append_file.close(); // Закриття файлу
}

int Expiry(string dateOfManufacture, string expirationDate){
    struct tm t1 = {0}; // Структура для першої дати (дати виробництва)
    struct tm t2 = {0}; // Структура для другої дати (дати закінчення терміну придатності)
    int year, month, day;

    sscanf(dateOfManufacture.c_str(), "%d/%d/%d", &day, &month, &year);
    t1.tm_year = year - 1900; // Заповнення року (віднімаємо 1900)
    t1.tm_mon = month - 1; // Заповнення місяця (віднімаємо 1, так як місяці нумеруються з 0)
    t1.tm_mday = day; // Заповнення дня

    sscanf(expirationDate.c_str(), "%d/%d/%d", &day, &month, &year);
    t2.tm_year = year - 1900; // Заповнення року (віднімаємо 1900)
    t2.tm_mon = month - 1; // Заповнення місяця (віднімаємо 1, так як місяці нумеруються з 0)
    t2.tm_mday = day; // Заповнення дня

    time_t expiration_time = mktime(&t2); // Конвертуємо структуру у часовий тип для дати закінчення терміну придатності
    time_t now = mktime(&t1); // Конвертуємо структуру у часовий тип для поточної дати
    double seconds_left = difftime(expiration_time, now); // Розраховуємо різницю в секундах між датами

    int days_left = static_cast<int>(seconds_left / 86400); // Розраховуємо кількість днів, розділивши секунди на 86400 (кількість секунд у дні)
    return days_left; // Повертаємо кількість днів
}

void PriceChange(string filename){

    ifstream read_file(filename, ios::binary); // Відкриття файлу для читання
    ofstream write_file("temp.bin", ios::binary); // Відкриття тимчасового файлу для запису

    Product product;

    while(read_file.read((char*)&product, sizeof(Product))){

        int days_till_expiration = Expiry(product.dateOfManufacture, product.expirationDate); // Отримання кількості днів до закінчення терміну придатності

        double price = atof(product.price); // Конвертація ціни з рядка в число з плаваючою точкою

        if(days_till_expiration <= 14){
            price *= 0.95; // Зниження ціни на 5% для товарів, у яких залишилось 14 днів або менше до закінчення терміну придатності
        } else if(days_till_expiration >= 365){
            price *= 1.03; // Збільшення ціни на 3% для товарів, у яких залишилось 365 днів або більше до закінчення терміну придатності
        }

        snprintf(product.price, sizeof(product.price), "%.2lf", price); // Форматування ціни у рядок з двома знаками після коми

        write_file.write((char*)&product, sizeof(Product)); // Запис товару зі зміненою ціною в тимчасовий файл
    }

    read_file.close(); // Закриття файлу для читання
    write_file.close(); // Закриття тимчасового файлу
    remove(filename.c_str()); // Видалення початкового файлу
    rename("temp.bin", filename.c_str()); // Перейменування тимчасового файлу на початкове ім'я
}

void ResultFile(const string& input_filename, const string& output_filename){
    ifstream input_file(input_filename, ios::binary); // Відкриття вхідного файлу для читання
    ofstream output_file(output_filename, ios::binary); // Відкриття вихідного файлу для запису

    time_t now = time(nullptr); // Отримання поточного часу
    tm local_time = *localtime(&now); // Конвертація поточного часу в локальний час
    int current_month = local_time.tm_mon + 1; // Отримання поточного місяця (додаємо 1, так як місяці нумеруються з 0)
    int current_year = local_time.tm_year + 1900; // Отримання поточного року (додаємо 1900, так як роки підраховуються з 1900)

    Product product;
    while (input_file.read(reinterpret_cast<char*>(&product), sizeof(Product))){
        int product_day, product_month, product_year;
        sscanf(product.dateOfManufacture, "%d/%d/%d", &product_day, &product_month, &product_year);

        if (product_year < current_year || (product_year == current_year && product_month < current_month)){
            output_file.write(reinterpret_cast<char*>(&product), sizeof(Product)); // Запис товару в вихідний файл, якщо його дата виробництва є меншою за поточну дату
        }
    }

    input_file.close(); // Закриття вхідного файлу
    output_file.close(); // Закриття вихідного файлу
}

