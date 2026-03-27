// https://pr-cy.ru/chat-gpt
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
#include <stdexcept>

// FIX_ME: добавлен метод для получения имени файла
std::string GetFileName()
{
    std::string FileName;
    std::cout << "Введите имя файла: ";
    std::cin >> FileName;
    return FileName;
}

int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // FIX_ME: ввод имени файла с консоли
    std::string FileName = GetFileName();

    try
    {
        //Graph MyGraph("FileName.txt");
        Graph MyGraph(FileName);
        MyGraph.CalculateDegrees();
        MyGraph.PrintDegrees();
    }
    // FIX_ME: имя переменной должно начинаться с заглавной буквы и быть информативным
    //catch (const std::exception& e)
    catch (const std::exception& Error)
    {
        // FIX_ME: сообщение переведено на русский
        //std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Ошибка: " << Error.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
