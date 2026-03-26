// https://trychatgpt.ru/chat
//Graf1.
//Дано описание неориентированного графа в текстовом файле с именем FileName.в виде
//матрицы смежности.Первая строка файла содержит количество вершин графа(n), а следующие
//n строк содержат матрицу смежности(m), m[i][j] = 0, если ребра между вершинами i и j не существует.
//Определить степень для каждой вершины графа.Вывести степени вершин, перечисляя их
//в порядке возрастания номеров вершин.Если в графе имеются петли, то каждая петля в степени
//вершины учитывается дважды.

// FIX_ME: программа разделена на модули
#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// FIX_ME: добавлена функция для получения имени файла
std::string GetFileName()
{
    std::string FileName;
    std::cout << "Введите имя файла: ";
    std::cin >> FileName;
    return FileName;
}

// FIX_ME: фигурная скобка должна быть на новой строке
// int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: ввод имени файла с консоли
    //std::string filename = "FileName.txt";
    std::string FileName = GetFileName();

    //Graph graph(filename);
    //graph.CalculateAndPrintDegrees();
    Graph Graph(FileName);
    Graph.CalculateAndPrintDegrees();

    return 0;
}