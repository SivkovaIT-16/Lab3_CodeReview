#include <string>
#include <random>

// FIX_ME: создан класс - генератор случайных паролей
// FIX_ME: добавлен комментарий к классу
// Класс для генерации случайных паролей.
class PasswordGenerator
{
public:
	// FIX_ME: добавлен конструктор 
	// Конструктор для инициализации генератора.
	PasswordGenerator();

	// FIX_ME: названия метода и параметров должны начинаться с заглавной буквы
	// FIX_ME: удалён параметр std::mt19937& rng, так как генератор стал членом класса
	// FIX_ME: исправлен комментарий
	//// Функция для генерации случайного числа в диапазоне
	//int getRandomInt(int min, int max, std::mt19937& rng);
	// Функция для получения случайного числа.
	int GetRandomInt(int Min, int Max);

	// FIX_ME: названия метода и параметров должны начинаться с заглавной буквы
	// FIX_ME: удалён параметр std::mt19937& rng, так как генератор стал членом класса
	// FIX_ME: комментарий должен заканчиваться точкой
	//std::string generatePassword(int length, const std::string& chars, std::mt19937& rng);
	// Функция для генерации пароля.
	std::string GeneratePassword(int Length, const std::string& CharacterSet);

private:
	// FIX_ME: название поля должно начинаться с заглавной буквы и быть информативным
	// FIX_ME: генератор случайных чисел перенесён в поле класса
	//std::mt19937 rng;
	std::mt19937 RandomGenerator;
};
