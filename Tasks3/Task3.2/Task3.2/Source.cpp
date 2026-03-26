#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>

Graph::Graph(const std::string& FileName)
    // FIX_ME: фигурная скобка перенесена на следующую строку
    //: vertexCount_(0) {
    : VertexCount(0)
{
    //LoadFromFile(filename);
    LoadFromFile(FileName);
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//void Graph::LoadFromFile(const std::string& filename) {
void Graph::LoadFromFile(const std::string& FileName)
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы 
    //std::ifstream file(filename);
    //if (!file.is_open()) {
    //    std::cerr << "Ошибка открытия файла: " << filename << std::endl;
    //    std::exit(EXIT_FAILURE);
    //}
    std::ifstream File(FileName);
    if (!File.is_open())
    {
        std::cerr << "Ошибка открытия файла: " << FileName << std::endl;
        std::exit(EXIT_FAILURE);
    }

    //file >> vertexCount_;
    File >> VertexCount;

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //if (file.fail() || vertexCount_ <= 0) {
    if (File.fail() || VertexCount <= 0)
    {
        std::cerr << "Некорректное количество вершин в файле." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    //adjacencyMatrix_.resize(vertexCount_);
    AdjacencyMatrix.resize(VertexCount);

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //for (int i = 0; i < vertexCount_; ++i) {
    for (int i = 0; i < VertexCount; ++i)
    {
        //adjacencyMatrix_[i].resize(vertexCount_);
        AdjacencyMatrix[i].resize(VertexCount);

        // FIX_ME: фигурная скобка перенесена на следующую строку
        //for (int j = 0; j < vertexCount_; ++j) {
        for (int j = 0; j < VertexCount; ++j)
        {
            // FIX_ME: имя переменной должно начинаться с заглавной буквы
            // FIX_ME: переменная должна быть инициализирована при создании
            //int value;
            int Value = 0;

            // FIX_ME: фигурная скобка перенесена на следующую строку
            //if (!(file >> value)) {
            if (!(File >> Value))
            {
                std::cerr << "Недостаточно данных в матрице смежности." << std::endl;
                std::exit(EXIT_FAILURE);
            }
            //adjacencyMatrix_[i][j] = value;
            AdjacencyMatrix[i][j] = Value;
        }
    }
    //ValidateMatrix(adjacencyMatrix_);
    ValidateMatrix(AdjacencyMatrix);
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//void Graph::ValidateMatrix(const std::vector<std::vector<int>>& matrix) const {
void Graph::ValidateMatrix(const std::vector<std::vector<int>>& Matrix) const
{
    // FIX_ME: фигурная скобка перенесена на следующую строку
    // FIX_ME: имя параметра должно начинаться с заглавной буквы 
    // FIX_ME: комментарий должен заканчиваться точкой
    //for (const auto& row : matrix) {
    // Проверка, что матрица квадратная.
    for (const auto& Row : Matrix) 
    {
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //if (row.size() != static_cast<size_t>(vertexCount_)) {
        if (Row.size() != static_cast<size_t>(VertexCount))
        {
            std::cerr << "Некорректная матрица: несоответствующая размерность." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//int Graph::GetDegree(const std::vector<std::vector<int>>& matrix, int vertex) const {
int Graph::GetDegree(const std::vector<std::vector<int>>& Matrix, int Vertex) const
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    //int degree = 0;
    int Degree = 0;

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //for (int j = 0; j < vertexCount_; ++j) {
    for (int j = 0; j < VertexCount; ++j)
    {
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //if (matrix[vertex][j] != 0) {
        if (Matrix[Vertex][j] != 0)
        {
            // FIX_ME: фигурная скобка перенесена на следующую строку
            //if (vertex == j) {
            if (Vertex == j)
            {
                // FIX_ME: комментарий должен заканчиваться точкой
                //degree += 2;
                // Петля: учитывается дважды.
                Degree += 2;
            }
            // FIX_ME: фигурная скобка перенесена на следующую строку
            else 
            {
                //degree += matrix[vertex][j];
                Degree += Matrix[Vertex][j];
            }
        }
    }
    //return degree;
    return Degree;
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//void Graph::CalculateAndPrintDegrees() const {
void Graph::CalculateAndPrintDegrees() const
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    //std::vector<int> degrees(vertexCount_);
    std::vector<int> Degrees(VertexCount);

    // FIX_ME: фигурная скобка перенесена на следующую строку
    // Вычисляем степень для каждой вершины
    //for (int i = 0; i < vertexCount_; ++i) {
    for (int i = 0; i < VertexCount; ++i)
    {
        //degrees[i] = GetDegree(adjacencyMatrix_, i);
        Degrees[i] = GetDegree(AdjacencyMatrix, i);
    }

    // FIX_ME: комментарий должен заканчиваться точкой
    // Выводим степени в порядке номеров вершин.
    std::cout << "Степени вершин:" << std::endl;

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //for (int i = 0; i < vertexCount_; ++i) {
    for (int i = 0; i < VertexCount; ++i)
    {
        //std::cout << "Вершина " << i + 1 << ": " << degrees[i] << std::endl;
        std::cout << "Вершина " << i + 1 << ": " << Degrees[i] << std::endl;
    }
}