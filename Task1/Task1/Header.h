#include <string>
#include <random>
#include <vector>

// FIX_ME: исправлен комментарий к классу
// FIX_ME: фигурная скобка перенесена на следующую строку
// Генератор случайного пароля
//class PasswordGenerator {
//
class PasswordGenerator
{
public:
    // FIX_ME: добавлен комментарий
    // Конструктор для инициализации генератора.
    PasswordGenerator();

    // FIX_ME: названия метода и параметра должны начинаться с заглавной буквы
    // FIX_ME: исправлен комментарий к методу
    // Подготовить набор символов для каждого класса сложности
    //void setCharacterSets(int level);
    // Метод для установки набора символов.
    void SetCharacterSets(int Level);

    // FIX_ME: названия метода и параметра должны начинаться с заглавной буквы
    // FIX_ME: название метода должно быть информативным
    // FIX_ME: добавлен комментарий к методу
    // FIX_ME: добавлен std::
    //static string levelDescription(int level);
    // Cтатический метод для описания уровня.
    static std::string GetLevelDescription(int Level);

    // FIX_ME: названия метода и параметра должны начинаться с заглавной буквы
    // FIX_ME: добавлен комментарий к методу
    // FIX_ME: добавлен std::
    //string generate(int length);
    // Метод для генерации пароля.
    std::string Generate(int Length);

    // FIX_ME: получение длины пароля вынесено в отдельный статический метод
    // FIX_ME: добавлен комментарий к методу
    // Метод для получения длины пароля по уровню.
    static int GetLengthByLevel(int Level);

private:
    // FIX_ME: название параметра должно быть информативным и начинаться с заглавной буквы
    // FIX_ME: добавлен комментарий к параметру
    //std::mt19937 rng; 
    std::mt19937 RandomGenerator; // Генератор случайных чисел.

    // FIX_ME: название параметра должно быть информативным и начинаться с заглавной буквы
    // FIX_ME: добавлен std::
    // FIX_ME: добавлен комментарий к параметру
    //string charPool;
    std::string CharacterPool; // Набор символов для генерации.

    // FIX_ME: названия метода и параметра должны начинаться с заглавной буквы
    // FIX_ME: название метода должно быть информативным
    // FIX_ME: добавлен комментарий к методу
    //char randomChar(const string& pool);
    // Метод для получения случайного символа из строки.
    char GetRandomChar(const std::string& Pool);

    // FIX_ME: названия метода и параметра должны начинаться с заглавной буквы
    // FIX_ME: названия метода и параметра должны быть информативными
    // FIX_ME: добавлен std::
    // FIX_ME: добавлен комментарий к методу
    //string charVectorToString(const vector<char>& v);
    // Метод для преобразования вектора в строку.
    std::string VectorToString(const std::vector<char>& Vector);
};
