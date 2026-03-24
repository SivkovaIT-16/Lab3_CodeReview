// https://chatgpt.org/chat
// Задание 1
// Напишите генератор паролей.Составьте три уровня сложности генерации 
// паролей(вместе с их длиной) и спрашивайте у пользователя, какой уровень 
// сложности ему нужен.Проявите свою изобретательность : надёжные пароли 
// должны состоять из сочетания строчных букв, прописных букв, цифр и символов.
// Пароли должны генерироваться случайным образом каждый раз, когда пользователь 
// запрашивает новый пароль.

// FIX_ME: программа разделена на модули
#include "Header.h"
#include <iostream>

// FIX_ME: using namespace std в глобальной области видимости
// using namespace std;

// FIX_ME: добавлена функция для очистки ввода
void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// FIX_ME: добавлена функция для получения корректного уровня
int GetValidLevel()
{
    int Level = 0;
    while (true)
    {
        std::cout << "Выберите уровень сложности:\n";
        std::cout << "1) Лёгкий: длина пароля 8-12 символов, буквы (a-z, A-Z)\n";
        std::cout << "2) Средний: длина 12-16 символов, буквы + цифры\n";
        std::cout << "3) Сильный: длина 16-24 символа, буквы + цифры + символы\n";
        std::cout << "Введите номер уровня (1..3): ";

        std::cin >> Level;

        if (std::cin.fail())
        {
            std::cout << "Ошибка: введите число!" << std::endl;
            ClearInput();
        }
        else if (Level < 1 || Level > 3)
        {
            std::cout << "Ошибка: уровень должен быть 1, 2 или 3!" << std::endl;
        }
        else
        {
            ClearInput();
            return Level;
        }
    }
}

// FIX_ME: фигурная скобка должна быть на новой строке
//int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // FIX_ME: добавлен std::
    //cout << "Генератор паролей\n";
    std::cout << "Генератор паролей\n";

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: использование функции для получения уровня сложности
    //cout << "Выберите уровень сложности:\n";
    //cout << "1) Лёгкий: длинна пароля 8-12 символов, буквы (a-z, A-Z)\n";
    //cout << "2) Средний: длинна 12-16 символов, буквы + цифры\n";
    //cout << "3) Сильный: длинна 16-24 символа, буквы + цифры + символы\n";
    //cout << "Введите номер уровня (1..3): ";
    //int level = 0;
    //if (!(cin >> level)) {
    //    cerr << "Неверный ввод.\n";
    //    return 1;
    //}
    //if (level < 1 || level > 3) {
    //    cerr << "Неправильный уровень. Нужно выбрать 1, 2 или 3.\n";
    //    return 1;
    //}
    int Level = GetValidLevel();

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: получение длины пароля через статический метод
    //int length = 0;
    //switch (level) {
    //case 1: length = 8 + rand() % 5; break;       // 8-12
    //case 2: length = 12 + rand() % 5; break;      // 12-16
    //case 3: length = 16 + rand() % 9; break;      // 16-24
    //default: length = 12;
    //}
    int Length = PasswordGenerator::GetLengthByLevel(Level);

    // FIX_ME: имена переменных должны начинаться с заглавной буквы и быть информативными
    // FIX_ME: добавлен std::
    // FIX_ME: добавлен комментарий
    //PasswordGenerator pg;
    //pg.setCharacterSets(level);
    //string password = pg.generate(length);
    // Cоздание генератора и генерация пароля.
    PasswordGenerator Generator;
    Generator.SetCharacterSets(Level);
    std::string Password = Generator.Generate(Length);

    // FIX_ME: добавлен std::
    // FIX_ME: в строке должно быть не более 100 символов
    //cout << "Сгенерированный пароль (" << PasswordGenerator::levelDescription(level) << ", длина " << length << "):\n";
    //cout << password << "\n";
    std::cout << "Сгенерированный пароль (" << PasswordGenerator::GetLevelDescription(Level)
        << ", длина " << Length << "):\n";
    std::cout << Password << "\n";

    return 0;
}