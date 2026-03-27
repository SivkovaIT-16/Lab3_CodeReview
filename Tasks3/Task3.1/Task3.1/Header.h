#include<string>
#include <vector>

// FIX_ME: добавлены комментарии к классу и его методам
// Класс для работы с графом.
class Graph
{
public:
    // Конструктор с параметром - именем файла.
    Graph(const std::string& FileName);

    // Метод для вычисления степеней вершин.
    void CalculateDegrees();

    // Метод для вывода степеней вершин.
    void PrintDegrees() const;

private:
    // Количество вершин графа.
    int NumberOfVertices;
    // Матрица смежности.
    std::vector<std::vector<int>> AdjacencyMatrix;
    // Вектор для хранения степеней вершин.
    std::vector<int> Degrees;

    // Метод для чтения графа из файла.
    void ReadGraphFromFile(const std::string& FileName);
};

