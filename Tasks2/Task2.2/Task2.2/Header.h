#include <memory>
#include <string>

// FIX_ME: структура должна быть классом с приватными полями
// FIX_ME: добавлен комментарий к классу
// FIX_ME: фигурная скобка перенесена на следующую строку
//struct Node {
class Node
{
public:
    // FIX_ME: перечисление должно быть public, чтобы к нему был доступ
    enum Type { VAL, VAR, OP };
private:
    // FIX_ME: имена полей должны начинаться с заглавной буквы и быть информативными
    // FIX_ME: добавлен std::
    // FIX_ME: исправлены комментарии
    //enum Type { VAL, VAR, OP } type;
    //int val;          // если тип VAL — число
    //char op;          // если тип OP — оператор
    //shared_ptr<Node> left;
    //shared_ptr<Node> right;
    Type NodeType;
    int Value;  // Если тип Type = VAL (число).
    char Operator; // Если тип Type = OP (оператор).
    std::shared_ptr<Node> Left;
    std::shared_ptr<Node> Right;
public:
    // FIX_ME: имена полей должны начинаться с заглавной буквы 
    // FIX_ME: добавлен комментарий 
    // FIX_ME: добавлен std::
    //Node(int v);
    //Node(char o, shared_ptr<Node> l = nullptr, shared_ptr<Node> r = nullptr);
    //Node();
    // Конструктор Node для числа.
    Node(int Val);
    // Конструктор Node для оператора.
    Node(char Op, std::shared_ptr<Node> LeftChild, std::shared_ptr<Node> RightChild);
    // Конструктор Node для переменной x.
    Node();

    // FIX_ME: добавлены геттеры для доступа к полям
    Type GetNodeType() const { return NodeType; }
    int GetValue() const { return Value; }
    char GetOperator() const { return Operator; }
    std::shared_ptr<Node> GetLeft() const { return Left; }
    std::shared_ptr<Node> GetRight() const { return Right; }

    // FIX_ME: добавлены сеттеры для преобразования дерева
    void SetLeft(std::shared_ptr<Node> NewLeft) { Left = NewLeft; }
    void SetRight(std::shared_ptr<Node> NewRight) { Right = NewRight; }
    void SetOperator(char Op) { Operator = Op; }
    void SetNodeType(Type Type) { NodeType = Type; }
    void SetValue(int Val) { Value = Val; }
};

// FIX_ME: создан класс для работы с деревом выражения
class ExpressionTree
{
private:
    std::shared_ptr<Node> Root;
    std::string Expression;
    size_t Position;
    int XValue;

    // FIX_ME: имена методов должны начинаться с заглавной буквы и быть информативными
    // FIX_ME: исправлены комментарии 
    // FIX_ME: добавлен std::
    //void skipSpaces();
    //// Чтение числа или переменной x
    //shared_ptr<Node> parseFactor();
    //// Парсинг с учётом приоритетов: функция для каждого приоритета
    // 
    //// Парсим степень (^) — правая ассоциативность
    //shared_ptr<Node> parsePower();
    //// Парсим операции *, /, %
    //shared_ptr<Node> parseTerm();
    //// Парсим операции +, -
    //shared_ptr<Node> parseExpr();

    // Пропуск пробелов.
    void SkipSpaces();

    // Парсинг числа, переменной или выражения в скобках.
    std::shared_ptr<Node> ParseFactor();

    // Парсинг степени (правая ассоциативность).
    std::shared_ptr<Node> ParsePower();

    // Парсинг умножения, деления, остатка.
    std::shared_ptr<Node> ParseTerm();

    // Парсинг сложения и вычитания.
    std::shared_ptr<Node> ParseExpression();

    // FIX_ME: имена методов и параметров должны начинаться с заглавной буквы и быть информативными
    // FIX_ME: исправлен комментарий
    // FIX_ME: добавлен const, так как метод не изменяет объект
    // FIX_ME: добавлен std::
    //// Вычисление значения дерева с учетом x_value
    //int eval(const shared_ptr<Node>& node);
    // Рекурсивный метод для вычисления значения узла.
    int EvaluateNode(const std::shared_ptr<Node>& Node) const;

    // FIX_ME: имена методов и параметров должны начинаться с заглавной буквы
    // FIX_ME: добавлен std::
    // FIX_ME: комментарии должны заканчиваться точкой
    //// Преобразование поддеревьев x*A в A*x
    //shared_ptr<Node> transform(const shared_ptr<Node>& node);
    // Рекурсивный метод для преобразования дерева (x*A -> A*x).
    std::shared_ptr<Node> TransformNode(const std::shared_ptr<Node>& Current);

    // FIX_ME: имена методов и параметров должны начинаться с заглавной буквы
    // FIX_ME: добавлен std::
    // FIX_ME: добавлен const, так как метод не изменяет объект
    // FIX_ME: исправлены комментарии 
    //// Вспомогательные функции для вывода с отступами и выравниванием

    //// Мы будем рисовать дерево "на бок":
    //// Формат: правое поддерево — сверху, корень — посередине, левое поддерево — снизу

    //// Вывод дерева в поток ostream, с текущим уровнем для отступа (в количестве 4 позиций)
    //// Выравнивание по правому краю (используем std::setw и ios::right)
    //void printTree(const shared_ptr<Node>& node, ostream& out, int level = 0);
    // Рекурсивный метод для вывода дерева боком.
    void PrintTreeNode(const std::shared_ptr<Node>& Node, std::ostream& Out, int Level) const;

public:
    // Конструктор с инициализацией полей.
    ExpressionTree();

    // FIX_ME: чтение выражения из файла вынесена в отдельный метод
    bool LoadFromFile(const std::string& FileName);

    // FIX_ME: установка значения переменной x вынесена в отдельный метод
    void SetXValue(int Value);

    // FIX_ME: добавлены публичные методы для вызова приватных рекурсивных
    // Возвращает результат вычисления.
    int Evaluate() const;

    // Преобразование дерева (замена x*A на A*x).
    void Transform();

    // Дерево выводится "на бок" с отступами по 4 позиции на уровень.
    void PrintTree(std::ostream& Out) const;

    // FIX_ME: добавлен геттер для корня дерева
    std::shared_ptr<Node> GetRoot() const { return Root; }
};
