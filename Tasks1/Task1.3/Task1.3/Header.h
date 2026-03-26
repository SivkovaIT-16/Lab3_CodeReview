#include <string>

// FIX_ME: создан класс - генератор случайных паролей
// FIX_ME: добавлен комментарий к классу
// Класс для генерации случайных паролей.
class PasswordGenerator
{
private:
    // FIX_ME: наборы символов вынесены в статические константы
    static const std::string LowercaseLetters;
    static const std::string UppercaseLetters;
    static const std::string Digits;
    static const std::string Symbols;

    // FIX_ME: проверка для обеспечения разнообразия символов в сложных паролях вынесена в отдельный метод
    // Метод для проверки наличия всех типов символов.
    bool HasAllCharTypes(const std::string& Password, bool UseUpper, bool UseLower, bool UseDigits, bool UseSymbols) const;

public:
    // FIX_ME: добавлен конструктор 
    // Конструктор для инициализации генератора.
    PasswordGenerator();

    // FIX_ME: названия метода и параметров должны начинаться с заглавной буквы
    // FIX_ME: комментарий должен заканчиваться точкой
    //std::string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSymbols);
    // Функция для генерации случайного пароля.
    std::string GeneratePassword(int Length, bool UseUpper, bool UseLower, bool UseDigits, bool UseSymbols);
};