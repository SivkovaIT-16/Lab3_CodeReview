// https://geekbot.ru/write-code-ai
// Задание 1
// Напишите генератор паролей.Составьте три уровня сложности генерации 
// паролей(вместе с их длиной) и спрашивайте у пользователя, какой уровень 
// сложности ему нужен.Проявите свою изобретательность : надёжные пароли 
// должны состоять из сочетания строчных букв, прописных букв, цифр и символов.
// Пароли должны генерироваться случайным образом каждый раз, когда пользователь 
// запрашивает новый пароль.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Функция для генерации случайного пароля
std::string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSymbols) {
    std::string chars = "";
    if (useLower) chars += "abcdefghijklmnopqrstuvwxyz";
    if (useUpper) chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (useDigits) chars += "0123456789";
    if (useSymbols) chars += "!@#$%^&*()_+-=[]{}|;:,.<>?";

    std::string password = "";
    if (chars.empty()) {
        return "Please select at least one character type.";
    }
    for (int i = 0; i < length; ++i) {
        password += chars[rand() % chars.length()];
    }
    return password;
}

// FIX_ME: фигурная скобка должна быть на новой строке
// int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // Инициализация генератора случайных чисел
    srand(time(0));

    int choice;
    std::cout << "Выберите уровень сложности пароля:\n";
    std::cout << "1. Простой (8 символов, только строчные буквы)\n";
    std::cout << "2. Средний (12 символов, строчные и прописные буквы, цифры)\n";
    std::cout << "3. Сложный (16 символов, строчные, прописные буквы, цифры и символы)\n";
    std::cout << "Ваш выбор (1-3): ";
    std::cin >> choice;

    std::string password;
    switch (choice) {
    case 1:
        password = generatePassword(8, false, true, false, false);
        break;
    case 2:
        password = generatePassword(12, true, true, true, false);
        break;
    case 3:
        password = generatePassword(16, true, true, true, true);
        break;
    default:
        std::cout << "Неверный выбор. Пожалуйста, выберите 1, 2 или 3.\n";
        return 1; // Выход с ошибкой
    }

    // Дополнительная проверка для обеспечения разнообразия символов в сложных паролях
    if (choice == 3 && password.length() >= 4) {
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;
        for (char c : password) {
            if (isupper(c)) hasUpper = true;
            else if (islower(c)) hasLower = true;
            else if (isdigit(c)) hasDigit = true;
            else if (std::string("!@#$%^&*()_+-=[]{}|;:,.<>?").find(c) != std::string::npos) hasSymbol = true;
        }

        // Если какой-то из типов символов отсутствует, генерируем заново
        if (!hasUpper || !hasLower || !hasDigit || !hasSymbol) {
            password = generatePassword(16, true, true, true, true);
        }
    }


    std::cout << "Ваш сгенерированный пароль: " << password << std::endl;

    return 0;
}
