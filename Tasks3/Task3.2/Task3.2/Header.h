#include <vector>
#include <string>

// FIX_ME: фигурная скобка перенесена на следующую строку
// FIX_ME: добавлены комментарии к классу и его методам
//class Graph {
// Класс для работы с графом.
class Graph 
{
public:
    // FIX_ME: имя параметра должно начинаться с заглавной буквы 
    //explicit Graph(const std::string& filename);
    // Конструктор с параметром - именем файла.
    explicit Graph(const std::string& FileName);

    // Метод для вычисления и вывода степеней вершин.
    void CalculateAndPrintDegrees() const;

private:
    // FIX_ME: имена параметров должны начинаться с заглавной буквы 
    //void LoadFromFile(const std::string& filename);
    //void ValidateMatrix(const std::vector<std::vector<int>>& matrix) const;
    //int GetDegree(const std::vector<std::vector<int>>& matrix, int vertex) const;
    
    // Метод для загрузки графа из файла.
    void LoadFromFile(const std::string& FileName);

    // Метод для проверки корректности матрицы смежности.
    void ValidateMatrix(const std::vector<std::vector<int>>& Matrix) const;

    // Метод для получения степени вершины.
    int GetDegree(const std::vector<std::vector<int>>& Matrix, int Vertex) const;

    // FIX_ME: имена полей должны начинаться с заглавной буквы и не могут содержать '_'
    //int vertexCount_;
    //std::vector<std::vector<int>> adjacencyMatrix_;

    // Количество вершин графа.
    int VertexCount;

    // Матрица смежности.
    std::vector<std::vector<int>> AdjacencyMatrix;
};

