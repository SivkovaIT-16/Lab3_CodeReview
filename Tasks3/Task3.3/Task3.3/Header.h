#include <string>
#include <vector>

// FIX_ME: фигурная скобка перенесена на следующую строку
// FIX_ME: комментарий должен заканчиваться точкой
//struct VertexInfo {
// Структура для хранения информации о вершине и ее степени.
struct VertexInfo 
{
    // FIX_ME: имена полей должны начинаться с заглавной буквы 
    //int vertexId;
    //int degree;
    int VertexId;
    int Degree;

    // FIX_ME: фигурная скобка перенесена на следующую строку
    // FIX_ME: имя параметра должно начинаться с заглавной буквы 
    // FIX_ME: комментарий должен заканчиваться точкой
    //bool operator<(const VertexInfo& other) const {
    // Оператор для сортировки по возрастанию номера вершины.
    bool operator<(const VertexInfo& Other) const 
    {
        //return vertexId < other.vertexId;
        return VertexId < Other.VertexId;
    }
};

// FIX_ME: создан класс С методами для работы с графом
// Класс для работы с графом.
class Graph
{
public:
    // Конструктор с параметром - именем файла.
    explicit Graph(const std::string& FileName);

    // Метод для вычисления и вывода степеней вершин.
    void CalculateAndPrintDegrees() const;

private:
    // Метод для загрузки графа из файла.
    void LoadFromFile(const std::string& FileName);

    // Метод для проверки корректности матрицы смежности.
    bool IsValidMatrixValue(int Value) const;

    // Количество вершин графа.
    int NumVertices;

    // Вектор для хранения степеней вершин.
    std::vector<int> Degrees;
};