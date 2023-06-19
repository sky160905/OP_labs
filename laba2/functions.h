using namespace std;

void CreateFile(string filename); //функція створення файла
void ReadFile(string filename); //функція зчитування з бінарного файла
bool CheckDate(string date); //функція для перевірки коректності вводу дати
bool DateComparison(string date1,string date2); //функця порівняння дат
char LeapYear(int year); //функція для визначення високосності року
void AddProducts(string filename); //функція додавання продуктів до файлу
int Expiry(string dateOfManufacture, string expirationDate); //функція розрахунку строку придатності
void PriceChange(string filename); //функція для зміни ціни
void ResultFile(const string& input_filename, const string& output_filename); //функція для виведення результату у файлі
