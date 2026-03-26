#include "Header.h"
#include <cstdlib>
#include <ctime>
#include <cctype>

// FIX_ME: инициализация статических констант
const std::string PasswordGenerator::LowercaseLetters = "abcdefghijklmnopqrstuvwxyz";
const std::string PasswordGenerator::UppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string PasswordGenerator::Digits = "0123456789";
const std::string PasswordGenerator::Symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

// FIX_ME: инициализация генератора случайных чисел вынесена в конструктор
PasswordGenerator::PasswordGenerator()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//std::string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSymbols) {
std::string PasswordGenerator::GeneratePassword(int Length, bool UseUpper, bool UseLower, bool UseDigits, bool UseSymbols)
{
    // FIX_ME: название переменной должно начинаться с заглавной буквы и быть информативным
    //std::string chars = "";
    std::string CharacterSet = "";

    // FIX_ME: добавлены фигурные скобки для однострочных операторов if
    // FIX_ME: использованы статические константы для определения наборов символов
    //if (useLower) chars += "abcdefghijklmnopqrstuvwxyz";
    //if (useUpper) chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //if (useDigits) chars += "0123456789";
    //if (useSymbols) chars += "!@#$%^&*()_+-=[]{}|;:,.<>?";
    if (UseLower)
    {
        CharacterSet += LowercaseLetters;
    }
    if (UseUpper)
    {
        CharacterSet += UppercaseLetters;
    }
    if (UseDigits)
    {
        CharacterSet += Digits;
    }
    if (UseSymbols)
    {
        CharacterSet += Symbols;
    }

    // FIX_ME: название переменной должно начинаться с заглавной буквы
    //std::string password = "";
    std::string Password = "";

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //if (chars.empty()) {
    if (CharacterSet.empty())
    {
        // FIX_ME: сообщение об ошибке переведено на русский
        //return "Please select at least one character type.";
        return "Ошибка: не выбран ни один тип символов.";
    }

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //for (int i = 0; i < length; ++i) {
    for (int i = 0; i < Length; ++i)
    {
        // FIX_ME: добавлен std::
        //password += chars[rand() % chars.length()];
        Password += CharacterSet[std::rand() % CharacterSet.length()];
    }

    // FIX_ME: добавлена дополнительная проверка для сложных паролей
    if (UseUpper && UseLower && UseDigits && UseSymbols && Length >= 4)
    {
        if (!HasAllCharTypes(Password, UseUpper, UseLower, UseDigits, UseSymbols))
        {
            return GeneratePassword(Length, UseUpper, UseLower, UseDigits, UseSymbols);
        }
    }
    //return password;
    return Password;
}

bool PasswordGenerator::HasAllCharTypes(const std::string& Password, bool UseUpper, bool UseLower, bool UseDigits, bool UseSymbols) const
{
    bool HasUpper = false;
    bool HasLower = false;
    bool HasDigit = false;
    bool HasSymbol = false;

    for (char Char : Password)
    {
        // FIX_ME: добавлен static_cast для безопасного преобразования
        if (UseUpper && std::isupper(static_cast<unsigned char>(Char)))
        {
            HasUpper = true;
        }
        if (UseLower && std::islower(static_cast<unsigned char>(Char)))
        {
            HasLower = true;
        }
        if (UseDigits && std::isdigit(static_cast<unsigned char>(Char)))
        {
            HasDigit = true;
        }
        if (UseSymbols && Symbols.find(Char) != std::string::npos)
        {
            HasSymbol = true;
        }
    }

    return (!UseUpper || HasUpper) &&
        (!UseLower || HasLower) &&
        (!UseDigits || HasDigit) &&
        (!UseSymbols || HasSymbol);
}
