#include "Header.h"
#include <random>

PasswordGenerator::PasswordGenerator()
{
    std::random_device RandomDevice;
    RandomGenerator.seed(RandomDevice());
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//int getRandomInt(int min, int max) {
int PasswordGenerator::GetRandomInt(int Min, int Max)
{
    // FIX_ME: названия класса и параметров должны начинаться с заглавной буквы
    // FIX_ME: название класса должно быть информативным
    //std::uniform_int_distribution<int> dist(min, max);
    std::uniform_int_distribution<int> Distribution(Min, Max);

    //return dist(rng);
    return Distribution(RandomGenerator);
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//std::string generatePassword(int length, const std::string& chars) {
std::string PasswordGenerator::GeneratePassword(int Length, const std::string& CharacterSet)
{
    // FIX_ME: название переменной должно начинаться с заглавной буквы
    // FIX_ME: переменные должны быть инициализированы при объявлении
    //std::string password;
    std::string Password = "";

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //for (int i = 0; i < length; ++i) {
    for (int i = 0; i < Length; ++i)
    {
        // FIX_ME: название переменной должно начинаться с заглавной буквы и быть информативным
        // FIX_ME: добавлен static_cast<int> для явного преобразования size_t к int для избежания предупреждения
        //int idx = getRandomInt(0, chars.size() - 1, rng);
        int Index = GetRandomInt(0, static_cast<int>(CharacterSet.size()) - 1);

        //password += chars[idx];
        Password += CharacterSet[Index];
    }
    //return password;
    return Password;
}