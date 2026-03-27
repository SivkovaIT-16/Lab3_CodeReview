#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

Graph::Graph(const std::string& FileName)
{
    ReadGraphFromFile(FileName);
    Degrees.resize(NumberOfVertices, 0);
}

void Graph::ReadGraphFromFile(const std::string& FileName)
{
    std::ifstream InputFile(FileName);
    if (!InputFile.is_open())
    {
        // FIX_ME: сообщение переведено на русский
        //throw std::runtime_error("Unable to open file: " + FileName);
        throw std::runtime_error("Не удалось открыть файл: " + FileName);
    }

    InputFile >> NumberOfVertices;

    // Комментарий должен заканчиваться точкой
    // Проверка на корректность количества вершин.
    if (NumberOfVertices <= 0)
    {
        // FIX_ME: сообщение переведено на русский
        //throw std::invalid_argument("Number of vertices must be positive.");
        throw std::invalid_argument("Количество вершин должно быть положительным.");
    }

    AdjacencyMatrix.resize(NumberOfVertices, std::vector<int>(NumberOfVertices, 0));

    for (int i = 0; i < NumberOfVertices; ++i)
    {
        for (int j = 0; j < NumberOfVertices; ++j)
        {
            InputFile >> AdjacencyMatrix[i][j];

            // Комментарий должен заканчиваться точкой
            // Проверка на корректность значений в матрице смежности.
            if (AdjacencyMatrix[i][j] < 0)
            {
                // FIX_ME: сообщение переведено на русский
                //throw std::invalid_argument("Invalid value in adjacency matrix.");
                throw std::invalid_argument("Недопустимое значение в матрице смежности.");
            }
        }
    }

    InputFile.close();
}

void Graph::CalculateDegrees()
{
    for (int i = 0; i < NumberOfVertices; ++i)
    {
        for (int j = 0; j < NumberOfVertices; ++j)
        {
            Degrees[i] += AdjacencyMatrix[i][j];
        }
    }
}

void Graph::PrintDegrees() const
{
    for (int i = 0; i < NumberOfVertices; ++i)
    {
        // FIX_ME: сообщение переведено на русский
        //std::cout << "Degree of vertex " << i << ": " << Degrees[i] << std::endl;
        std::cout << "Степень вершины " << i << ": " << Degrees[i] << std::endl;
    }
}
