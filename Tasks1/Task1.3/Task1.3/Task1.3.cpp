// https://geekbot.ru/write-code-ai
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
        std::cout << "Выберите уровень сложности пароля:\n";
        std::cout << "1. Простой (8 символов, только строчные буквы)\n";
        std::cout << "2. Средний (12 символов, строчные и прописные буквы, цифры)\n";
        std::cout << "3. Сложный (16 символов, строчные, прописные буквы, цифры и символы)\n";
        std::cout << "Ваш выбор (1-3): ";
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
// int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // FIX_ME: инициализация генератора случайных чисел вынесена в конструктор класса
    //// Инициализация генератора случайных чисел
    //srand(time(0));

    // FIX_ME: использована функция для получения уровня сложности
    // FIX_ME: название переменной должно начинаться с заглавной буквы и быть информативным
    // FIX_ME: переменная должна быть инициализирована при объявлении
    //int choice;
    //std::cout << "Выберите уровень сложности пароля:\n";
    //std::cout << "1. Простой (8 символов, только строчные буквы)\n";
    //std::cout << "2. Средний (12 символов, строчные и прописные буквы, цифры)\n";
    //std::cout << "3. Сложный (16 символов, строчные, прописные буквы, цифры и символы)\n";
    //std::cout << "Ваш выбор (1-3): ";
    //std::cin >> choice;
    int Level = GetValidLevel();

    // FIX_ME: определение параметров генерации
    bool UseUpper = false;
    bool UseLower = false;
    bool UseDigits = false;
    bool UseSymbols = false;
    int Length = 0;

    // FIX_ME: название переменной должно начинаться с заглавной буквы
    // FIX_ME: переменная должна быть инициализирована при объявлении
    //std::string password;
    std::string Password = "";

    // FIX_ME: устанавливаем параметры для каждого уровня, генерируем пароль, используя конструктор
    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: добавлены фигурные скобки для case и default
    // FIX_ME: комментарий должен заканчиваться точкой
    //switch (choice) {
    //case 1:
    //    password = generatePassword(8, false, true, false, false);
    //    break;
    //case 2:
    //    password = generatePassword(12, true, true, true, false);
    //    break;
    //case 3:
    //    password = generatePassword(16, true, true, true, true);
    //    break;
    //default:
    //    std::cout << "Неверный выбор. Пожалуйста, выберите 1, 2 или 3.\n";
    //    return 1; // Выход с ошибкой
    //}
    switch (Level)
    {
    case 1:
    {
        UseUpper = false;
        UseLower = true;
        UseDigits = false;
        UseSymbols = false;
        Length = 8;
        break;
    }
    case 2:
    {
        UseUpper = true;
        UseLower = true;
        UseDigits = true;
        UseSymbols = false;
        Length = 12;
        break;
    }
    case 3:
    {
        UseUpper = true;
        UseLower = true;
        UseDigits = true;
        UseSymbols = true;
        Length = 16;
        break;
    }
    default:
    {
        std::cout << "Неверный выбор. Пожалуйста, выберите 1, 2 или 3.\n";
        return 1; // Выход с ошибкой.
    }
    }
    PasswordGenerator Generator;
    Password = Generator.GeneratePassword(Length, UseUpper, UseLower, UseDigits, UseSymbols);

    // FIX_ME: проверка вынесена в отдельный метод
    // FIX_ME: проверка реализована через рекурсивный вызов метода GeneratePassword
    //// Дополнительная проверка для обеспечения разнообразия символов в сложных паролях
    //if (choice == 3 && password.length() >= 4) {
    //    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;
    //    for (char c : password) {
    //        if (isupper(c)) hasUpper = true;
    //        else if (islower(c)) hasLower = true;
    //        else if (isdigit(c)) hasDigit = true;
    //        else if (std::string("!@#$%^&*()_+-=[]{}|;:,.<>?").find(c) != std::string::npos) hasSymbol = true;
    //    }

    //    // Если какой-то из типов символов отсутствует, генерируем заново
    //    if (!hasUpper || !hasLower || !hasDigit || !hasSymbol) {
    //        password = generatePassword(16, true, true, true, true);
    //    }
    //}

    // FIX_ME: добавлена проверка на корректность пароля
    if (Password == "Please select at least one character type.")
    {
        std::cout << Password << std::endl;
        return 1;
    }

    //std::cout << "Ваш сгенерированный пароль: " << password << std::endl;
    std::cout << "Ваш сгенерированный пароль: " << Password << std::endl;

    return 0;
}
