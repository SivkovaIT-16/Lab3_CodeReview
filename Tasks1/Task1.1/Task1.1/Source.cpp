#include "Header.h"
#include <algorithm>
#include <random>
#include <ctime>

// FIX_ME: фигурная скобка должна открываться в новой строке
//PasswordGenerator() {
PasswordGenerator::PasswordGenerator()
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы и быть информативным
    // FIX_ME: исправлены комментарии
    //std::random_device rd;
    //rng.seed(rd());
    // Инициализация генератора случайных чисел.
    std::random_device RandomDevice;
    RandomGenerator.seed(RandomDevice());
}

// FIX_ME: фигурная скобка должна открываться в новой строке
//void setCharacterSets(int level) {
void PasswordGenerator::SetCharacterSets(int Level)
{
    // FIX_ME: имена переменных должны начинаться с заглавной буквы 
    // FIX_ME: исправлены комментарии
    //// Уровни: 1 - лёгкий, 2 - средний, 3 - сильный
    //// Общий набор: lowercase, uppercase, digits, symbols
    //static const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    //static const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //static const string digits = "0123456789";
    //static const string symbols = "!@#$%^&*()-_=+[]{};:,.?/";
    // Статические строки для символов.
    static const std::string Lowercase = "abcdefghijklmnopqrstuvwxyz";
    static const std::string Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const std::string Digits = "0123456789";
    static const std::string Symbols = "!@#$%^&*()-_=+[]{};:,.?/";

    // FIX_ME: изменена логика, не используем базовый набор, использована одна переменная для выбора
    // FIX_ME: имя переменной должно начинаться с заглавной буквы 
    // FIX_ME: исправлены комментарии

    //// Базовый набор всегда включаем
    //string pool = lowercase + uppercase + digits + symbols;

    //// Можно адаптировать набор под уровень
    //// Уровень 1: ограничимся только латинскими буквами
    //// Уровень 2: добавим цифры
    //// Уровень 3: всё сочетание
    //switch (level) {
    //case 1:
    //    pool = lowercase + uppercase; // только буквы
    //    break;
    //case 2:
    //    pool = lowercase + uppercase + digits; // буквы и цифры
    //    break;
    //case 3:
    //default:
    //    pool = lowercase + uppercase + digits + symbols; // всё
    //    break;
    //}

    //charPool = pool;
    //// Разрешим не менее одного из каждого класса (для повышенной надежности)
    //// Но по желанию можно сделать равномерное распределение позже

    // Выбор набора символов в зависимости от уровня сложности пароля.
    switch (Level)
    {
    case 1:
        // Уровень 1.
        CharacterPool = Lowercase + Uppercase; // Включаем только буквы.
        break;
    case 2:
        // Уровень 2.
        CharacterPool = Lowercase + Uppercase + Digits; // Включаем буквы и цифры.
        break;
    case 3:
        // Уровень 3.
        CharacterPool = Lowercase + Uppercase + Digits + Symbols; // Используем буквы, цифры и символы.
        break;
    default:
        // Уровень неизвестен.
        CharacterPool = Lowercase + Uppercase + Digits + Symbols; // Используем буквы, цифры и символы.
        break;
    }
}

// FIX_ME: фигурная скобка должна открываться в новой строке
// FIX_ME: добавлен std::
//static string levelDescription(int level) {
std::string PasswordGenerator::GetLevelDescription(int Level)
{
    // FIX_ME: фигурная скобка должна открываться в новой строке
    // FIX_ME: добавлен комментарий
    //switch (level) {
    //case 1: return "Лёгкий";
    //case 2: return "Средний";
    //case 3: return "Сильный";
    //default: return "Неизвестный";
    //}
    // Возврат описания уровня.
    switch (Level)
    {
    case 1:
        return "Лёгкий";
    case 2:
        return "Средний";
    case 3:
        return "Сильный";
    default:
        return "Неизвестный";
    }
}

// FIX_ME: фигурная скобка должна открываться в новой строке
// FIX_ME: добавлен std::
//string generate(int length) {
std::string PasswordGenerator::Generate(int Length)
{
    // FIX_ME: добавлены фигурные скобки для оператора if
    // FIX_ME: добавлен комментарий
    //if (length <= 0) return "";
    // Проверка на корректность длины.
    if (Length <= 0)
    {
        return "";
    }

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: исправлены комментарии
    //// Ensure at least one character from each required class if possible
    //// Опционально: гарантирую по одному из каждого класса (если длинна позволяет)
    //vector<char> result;
    //result.reserve(length);
    // Гарантируем наличие символов из каждого класса.
    std::vector<char> Result;
    Result.reserve(Length);

    // FIX_ME: добавлен std::
    // FIX_ME: исправлены комментарии
    //// Определим набор классов
    //// Мы заранее разделяем pool на 4 класса
    //string lower = "abcdefghijklmnopqrstuvwxyz";
    //string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //string digits = "0123456789";
    //string symbols = "!@#$%^&*()-_=+[]{};:,.?/";
    // Наборы символов.
    static const std::string Lowercase = "abcdefghijklmnopqrstuvwxyz";
    static const std::string Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const std::string Digits = "0123456789";
    static const std::string Symbols = "!@#$%^&*()-_=+[]{};:,.?/";

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: исправлен комментарий
    // Гарантируем хотя бы один символ каждого класса, если длина позволяет
    //int remaining = length;
    // Гарантируем наличие символов каждого класса.
    int Remaining = Length;

    // FIX_ME: заменён постфиксный дикремент на префиксный
    // FIX_ME: изменена логика - добавляем символы только из тех классов, которые входят в CharacterPool 
    // FIX_ME: исправлен комментарий
    //if (length >= 4) {
    //    // добавим по одному из каждого класса
    //    result.push_back(randomChar(lower));
    //    remaining--;
    //    if (remaining == 0) return charVectorToString(result);

    //    result.push_back(randomChar(upper));
    //    remaining--;
    //    if (remaining == 0) return charVectorToString(result);

    //    result.push_back(randomChar(digits));
    //    remaining--;
    //    if (remaining == 0) return charVectorToString(result);

    //    result.push_back(randomChar(symbols));
    //    remaining--;
    //    if (remaining == 0) return charVectorToString(result);
    //}
    // Проверка, какие классы символов входят в CharacterPool.
    bool HasLowercase = (CharacterPool.find_first_of(Lowercase) != std::string::npos);
    bool HasUppercase = (CharacterPool.find_first_of(Uppercase) != std::string::npos);
    bool HasDigits = (CharacterPool.find_first_of(Digits) != std::string::npos);
    bool HasSymbols = (CharacterPool.find_first_of(Symbols) != std::string::npos);

    int RequiredClasses = 0;
    if (HasLowercase) RequiredClasses++;
    if (HasUppercase) RequiredClasses++;
    if (HasDigits) RequiredClasses++;
    if (HasSymbols) RequiredClasses++;

    // Добавляем по одному символу из каждого доступного класса.
    if (Length >= RequiredClasses && RequiredClasses > 0)
    {
        if (HasLowercase)
        {
            Result.push_back(GetRandomChar(Lowercase));
            --Remaining;
        }
        if (HasUppercase)
        {
            Result.push_back(GetRandomChar(Uppercase));
            --Remaining;
        }
        if (HasDigits)
        {
            Result.push_back(GetRandomChar(Digits));
            --Remaining;
        }
        if (HasSymbols)
        {
            Result.push_back(GetRandomChar(Symbols));
            --Remaining;
        }
    }

    // FIX_ME: фигурная скобка должна открываться в новой строке
    // FIX_ME: исправлен комментарий
    //// Остальное дополняем из charPool
    //for (int i = 0; i < remaining; ++i) {
    //    result.push_back(randomChar(charPool));
    //}
    // Дополняем остальными символами из общего набора.
    for (int i = 0; i < Remaining; ++i)
    {
        Result.push_back(GetRandomChar(CharacterPool));
    }

    // FIX_ME: добавлен std::
    // FIX_ME: исправлен комментарий
    // Перемешаем результат, чтобы позиции первых chars не всегда были одни и те же
    //shuffle(result.begin(), result.end(), rng);
    // Перемешиваем результат.
    std::shuffle(Result.begin(), Result.end(), RandomGenerator);

    //return charVectorToString(result);
    return VectorToString(Result);
}

int PasswordGenerator::GetLengthByLevel(int Level)
{
    // FIX_ME: изменена логика, использован современный генератор случайных чисел
    // switch (level) {
    // case 1: length = 8 + rand() % 5; break;       // 8-12
    // case 2: length = 12 + rand() % 5; break;      // 12-16
    // case 3: length = 16 + rand() % 9; break;      // 16-24
    // default: length = 12;
    // }
    static std::mt19937 Generator(static_cast<unsigned>(std::time(nullptr)));

    switch (Level)
    {
    case 1:
    {
        std::uniform_int_distribution<int> Distribution(8, 12);
        return Distribution(Generator);
    }
    case 2:
    {
        std::uniform_int_distribution<int> Distribution(12, 16);
        return Distribution(Generator);
    }
    case 3:
    {
        std::uniform_int_distribution<int> Distribution(16, 24);
        return Distribution(Generator);
    }
    default:
        return 12;
    }
}

// FIX_ME: фигурная скобка должна открываться в новой строке
//char randomChar(const string& pool) {
char PasswordGenerator::GetRandomChar(const std::string& Pool)
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы и быть информативным
    //std::uniform_int_distribution<size_t> dist(0, pool.size() - 1);
    //return pool[dist(rng)];
    std::uniform_int_distribution<size_t> Distribution(0, Pool.size() - 1);
    return Pool[Distribution(RandomGenerator)];
}

// FIX_ME: фигурная скобка должна открываться в новой строке
// FIX_ME: добавлен std::
//string charVectorToString(const vector<char>& v) {
std::string PasswordGenerator::VectorToString(const std::vector<char>& Vector)
{
    // FIX_ME: добавлен std::
    // FIX_ME: добавлен комментарий
    //return string(v.begin(), v.end());
    // Создание строки из вектора.
    return std::string(Vector.begin(), Vector.end());
}