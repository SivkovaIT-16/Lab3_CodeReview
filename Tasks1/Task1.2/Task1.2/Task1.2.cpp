// https://trychatgpt.ru/chat
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

// FIX_ME: добавлена функция для очистки ввода
void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// FIX_ME: получение уровня пароля вынесено в отдельную функцию 
// FIX_ME: добавлен цикл для повторного ввода при неверном выборе
int GetValidLevel()
{
    int Level = 0;
    while (true)
    {
        std::cout << "Выберите уровень сложности:\n";
        std::cout << "1. Простая (длина 8): только строчные буквы\n";
        std::cout << "2. Средняя (длина 12): строчные + заглавные + цифры\n";
        std::cout << "3. Надежная (длина 16): все символы\n";
        std::cout << "Ваш выбор (1, 2, 3): ";

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

// FIX_ME: фигурная скобка перенесена на следующую строку
//int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // FIX_ME: использован конструктор класса
    // FIX_ME: исправлен комментарий
    //// Инициализация генератора случайных чисел с учетом времени
    //std::random_device rd;
    //std::mt19937 rng(rd());
    // Создание объекта генератора паролей.
    PasswordGenerator Generator;

    // FIX_ME: названия переменных должны начинаться с заглавной буквы
    // FIX_ME: комментарий должен заканчиваться точкой
    //const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    //const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //const std::string digits = "0123456789";
    //const std::string symbols = "!@#$%^&*()-_=+[]{}|;:',.<>/?";
    // Наборы символов для разных уровней.
    const std::string Lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string Digits = "0123456789";
    const std::string Symbols = "!@#$%^&*()-_=+[]{}|;:',.<>/?";

    // FIX_ME: названия переменных должны начинаться с заглавной буквы
    // FIX_ME: комментарий должен заканчиваться точкой
    //const std::string all_chars = lowercase + uppercase + digits + symbols;
    // Все символы.
    const std::string AllChars = Lowercase + Uppercase + Digits + Symbols;

    // FIX_ME: использована функция для получения уровня сложности
    // FIX_ME: название переменной должно начинаться с заглавной буквы и быть информативным
    // FIX_ME: переменная должна быть инициализирована при объявлении
    //int choice;
    //std::cout << "Выберите уровень сложности:\n";
    //std::cout << "1. Простая (длина 8): только строчные буквы\n";
    //std::cout << "2. Средняя (длина 12): строчные + заглавные + цифры\n";
    //std::cout << "3. Надежная (длина 16): все символы\n";
    //std::cout << "Ваш выбор (1,2,3): ";
    //std::cin >> choice;
    int Level = GetValidLevel();

    // FIX_ME: названия переменных должны начинаться с заглавной буквы и быть информативными
    // FIX_ME: переменные должны быть инициализированы при объявлении
    //int password_length;
    //std::string charset;
    int PasswordLength = 0;
    std::string CharacterSet = "";

    // FIX_ME: фигурная скобка перенесена на следующую строку
    // FIX_ME: добавлены фигурные скобки для case и default
    //switch (choice) {
    switch (Level)
    {
    case 1:
    {
        // FIX_ME: исправлен комментарий
        //password_length = 8;
        //charset = lowercase; // только строчные
        PasswordLength = 8;
        CharacterSet = Lowercase; // Используем только строчные буквы.
        break;
    }
    case 2:
    {
        // FIX_ME: исправлен комментарий
        //password_length = 12;
        //charset = lowercase + uppercase + digits; // строчные, заглавные, цифры
        PasswordLength = 12;
        CharacterSet = Lowercase + Uppercase + Digits; // Используем строчные и заглавные буквы и цифры.
        break;
    }
    case 3:
    {
        // FIX_ME: исправлен комментарий
        //password_length = 16;
        //charset = all_chars; // все символы
        PasswordLength = 16;
        CharacterSet = AllChars; // Используем все символы.
        break;
    }
    default:
    {
        std::cout << "Неправильный выбор. По умолчанию уровень 1.\n";
        //password_length = 8;
        //charset = lowercase;
        PasswordLength = 8;
        CharacterSet = Lowercase;
        // FIX_ME: добавлен break
        break;
    }
    }
    // FIX_ME: комментарий должен заканчиваться точкой
    //std::string password = generatePassword(password_length, charset, rng);
    // Генерация пароля.
    std::string Password = Generator.GeneratePassword(PasswordLength, CharacterSet);

    //std::cout << "Сгенерированный пароль:\n" << password << "\n";
    std::cout << "Сгенерированный пароль:\n" << Password << "\n";

    return 0;
}