#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

Graph::Graph(const std::string& FileName)
    : NumVertices(0)
{
    LoadFromFile(FileName);
}

// FIX_ME: загрузка графа из файла вынесена в отдельный метод класса
void Graph::LoadFromFile(const std::string& FileName)
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    //std::ifstream graphFile(fileName);
    std::ifstream GraphFile(FileName);

    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: комментарии должны заканчиваться точкой
    //if (!graphFile.is_open()) {
    // Проверка на успешное открытие файла
    if (!GraphFile.is_open())
    {
        //std::cerr << "Ошибка: Не удалось открыть файл " << fileName << std::endl;
        std::cerr << "Ошибка: не удалось открыть файл " << FileName << std::endl;
        //return 1;
        std::exit(EXIT_FAILURE); // Код ошибки.
    }

    // FIX_ME: используем переменную - член класса вместо локальной
    //int numVertices;
    
    // FIX_ME: комментарий должен заканчиваться точкой
    // Чтение количества вершин.
    //graphFile >> numVertices;
    GraphFile >> NumVertices;

    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: комментарий должен заканчиваться точкой
    //if (numVertices <= 0) {
    // Проверка на корректность количества вершин.
    if (NumVertices <= 0)
    {
        //std::cerr << "Ошибка: Некорректное количество вершин в файле." << std::endl;
        std::cerr << "Ошибка: некорректное количество вершин в файле." << std::endl;
        //return 1;
        std::exit(EXIT_FAILURE);
    }

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: комментарий должен заканчиваться точкой
    //std::vector<int> degrees(numVertices, 0);
    // Инициализация вектора для хранения степеней вершин.
    Degrees.assign(NumVertices, 0);

    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: комментарий должен заканчиваться точкой
    //for (int i = 0; i < numVertices; ++i) {
    // Чтение матрицы смежности и расчет степеней.
    for (int i = 0; i < NumVertices; ++i)
    {
        // FIX_ME: фигурная скобка должна быть на новой строке
        // FIX_ME: комментарий должен заканчиваться точкой
        //if (graphFile.peek() == '\n') { 
        // Пропускаем пустые строки.
        if (GraphFile.peek() == '\n')
        {
            //graphFile.ignore();
            GraphFile.ignore();
        }

        // FIX_ME: фигурная скобка должна быть на новой строке
        //for (int j = 0; j < numVertices; ++j) {
        for (int j = 0; j < NumVertices; ++j)
        {
            // FIX_ME: имя переменной должно начинаться с заглавной буквы
            // FIX_ME: переменная должна быть инициализирована при создании
            //int adjacencyValue;
            //graphFile >> adjacencyValue;
            int AdjacencyValue = 0;
            GraphFile >> AdjacencyValue;

            // FIX_ME: фигурная скобка должна быть на новой строке
            // FIX_ME: использован отдельный метод
            // FIX_ME: комментарий должен заканчиваться точкой
            //if (adjacencyValue != 0 && adjacencyValue != 1) {
            // Проверка на корректность значения матрицы смежности.
            if (!IsValidMatrixValue(AdjacencyValue))
            {
                std::cerr << "Ошибка: Некорректное значение в матрице смежности [" << i << "][" << j << "]." << std::endl;
                //return 1;
                std::exit(EXIT_FAILURE);
            }

            // FIX_ME: фигурная скобка должна быть на новой строке
            //if (adjacencyValue == 1) {
            if (AdjacencyValue == 1)
            {
                // FIX_ME: изменена логика подсчёта, т.к. в неориентированом графе каждое ребро нужно учитывать 1 раз
                // FIX_ME: фигурные скобки должны быть на новой строке
                // FIX_ME: постфиксный инкремент заменён на префиксный
                //degrees[i]++; // Увеличиваем степень текущей вершины
                //// Если это не петля (i != j), то увеличиваем степень и смежной вершины
                //if (i != j) {
                //    degrees[j]++;
                //}
                //else {
                //    // Петля учитывается дважды, поэтому увеличиваем степень еще раз
                //    degrees[i]++;
                //}
                if (i == j)
                {
                    // Петля: учитывается дважды.
                    Degrees[i] += 2;
                }
                else if (i < j)
                {
                    // Ребро: учитываем для обеих вершин.
                    ++Degrees[i];
                    ++Degrees[j];
                }
                // Если i > j, пропускаем, так как ребро уже учтено.
            }
        }
    }
    // graphFile.close();
    GraphFile.close();
}

// FIX_ME: проверка корректности значения матрицы смежности вынесена в отдельный метод
bool Graph::IsValidMatrixValue(int Value) const
{
    return (Value == 0 || Value == 1);
}

// FIX_ME: вычисление и вывод степеней вершин вынесен в отдельный метод класса
void Graph::CalculateAndPrintDegrees() const
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: комментарий должен заканчиваться точкой
    //std::vector<VertexInfo> vertexInfos(numVertices);
    // Создание вектора структур для сортировки.
    std::vector<VertexInfo> VertexInfos(NumVertices);

    // FIX_ME: фигурная скобка должна быть на новой строке
    //for (int i = 0; i < numVertices; ++i) {
    for (int i = 0; i < NumVertices; ++i)
    {
        //vertexInfos[i] = { i, degrees[i] };
        VertexInfos[i] = { i, Degrees[i] };
    }

    // FIX_ME: комментарий должен заканчиваться точкой
    //std::sort(vertexInfos.begin(), vertexInfos.end());
    // Сортировка вершин по возрастанию их номеров.
    std::sort(VertexInfos.begin(), VertexInfos.end());

    // FIX_ME: комментарий должен заканчиваться точкой
    // Вывод степеней вершин в порядке возрастания их номеров.
    std::cout << "Степени вершин графа (в порядке возрастания номеров вершин):" << std::endl;

    // FIX_ME: фигурная скобка должна быть на новой строке
    //for (const auto& vertexInfo : vertexInfos) {
    for (const auto& VertexInfo : VertexInfos)
    {
        //std::cout << "Вершина " << vertexInfo.vertexId << ": " << vertexInfo.degree << std::endl;
        std::cout << "Вершина " << VertexInfo.VertexId << ": " << VertexInfo.Degree << std::endl;
    }
}