#include <string>
#include <fstream>

// FIX_ME: структура должна быть классом с приватными полями
// FIX_ME: фигурная скобка перенесена на следующую строку
//struct Node {
class Node
{
private:
    // FIX_ME: имена полей должны начинаться с заглавной буквы
    // FIX_ME: комментарии должны заканчиваться точкой
    //char op; // Операция или 'x' для переменной, '#' для числа
    //int value; // Значение числа, если op == '#'
    //Node* left, * right;
    char Op; // Операция или 'x' для переменной, '#' для числа.
    int Value; // Значение числа, если op == '#'.
    Node* Left;
    Node* Right;

public:
    // FIX_ME: имена параметров должны начинаться с заглавной буквы и быть информативными
    // FIX_ME: добавлен комментарий 
    //Node(char o = '\0', int v = 0, Node* l = nullptr, Node* r = nullptr);
    // Конструктор с списком инициализации.
    Node(char Operation = '\0', int Val = 0, Node* LeftChild = nullptr, Node* RightChild = nullptr);

    // FIX_ME: добавлен комментарий 
    // Деструктор для освобождения памяти.
    ~Node();

    // FIX_ME: добавлены геттеры для доступа к полям
    char GetOp() const { return Op; }
    int GetValue() const { return Value; }
    Node* GetLeft() const { return Left; }
    Node* GetRight() const { return Right; }
    void SetLeft(Node* NewLeft) { Left = NewLeft; }
    void SetRight(Node* NewRight) { Right = NewRight; }
};

// FIX_ME: добавлен класс для работы с деревом выражения
class ExpressionTree
{
public:
    // FIX_ME: добавлен конструктор
    ExpressionTree();

    // FIX_ME: добавлен деструктор
    ~ExpressionTree();

    // FIX_ME: загрузка выражения из файла вынесена в отдельный метод класса
    bool LoadFromFile(const std::string& FileName);

    // FIX_ME: добавлен метод для установки значения x
    void SetXValue(int X);

    // FIX_ME: вычисление значения выражения вынесено в отдельный метод класса
    int Evaluate() const;

    // FIX_ME: преобразование дерева (x * A -> A * x) вынесено в отдельный метод класса
    void Transform();

    // FIX_ME: вывод дерева в файл вынесено в отдельный метод класса
    void PrintTree(std::ofstream& Out) const;
   
private:
    // FIX_ME: имена параметров должны начинаться с заглавной буквы 
    // FIX_ME: имена методов должны начинаться с заглавной буквы 
    // FIX_ME: методы, не изменяющие объект сделаны константными
    // FIX_ME: комментарии должны заканчиваться точкой
    //int getPriority(char op);
    //bool isOperator(char c);
    //Node* buildExpressionTree(const std::string& expression);
    //int evaluateExpressionTree(Node* root, int x);
    //void transformTree(Node* root);
    //void printTree(std::ofstream& ofs, Node* root, int indent = 0);
    
    // Определение приоритетов операций.
    int GetPriority(char Op) const;

    // Проверка, является ли символ оператором.
    bool IsOperator(char C) const;

    // Преобразование инфиксного выражения в дерево.
    Node* BuildExpressionTree(const std::string& Expression);

    // Вычисление значения дерева выражения.
    int EvaluateExpressionTree(Node* Root, int X) const;

    // Преобразование дерева: x*A -> A*x.
    void TransformTree(Node* Root);

    // Печать дерева в файл (многострочный формат)
    void PrintTree(std::ofstream& Ofs, Node* Root, int Indent = 0) const;

    // FIX_ME: добавлены поля класса
    Node* Root;     // Корень дерева выражения.
    int XValue;     // Значение переменной x.
};

