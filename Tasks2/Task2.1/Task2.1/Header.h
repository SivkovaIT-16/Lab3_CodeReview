#include <fstream>
#include <string>
#include <memory>
#include <vector>

// FIX_ME: добавлен комментарий к классу
// Класс узла дерева.
class Node
{
public:
    // FIX_ME: добавлены комментарии к методам

    // Виртуальный деструктор для корректного удаления производных классов.
    virtual ~Node() = default;

    // Метод для вычисления значения узла.
    virtual int Evaluate(int x) const = 0;

    // FIX_ME: имена параметров должны начинаться с заглавной буквы 
    //virtual void Print(std::ofstream& out, int level) const = 0;
    // Метод для вывода дерева в файл.
    virtual void Print(std::ofstream& Out, int Level) const = 0;
};

// FIX_ME: добавлен комментарий к классу
// Класс узла для числа.
class ValueNode : public Node
{
public:
    // FIX_ME: имена параметров должны начинаться с заглавной буквы
    // FIX_ME: добавлены комментарии к методам
    //explicit ValueNode(int value);
    //int Evaluate(int x) const override;
    //void Print(std::ofstream& out, int level) const override;

    // Конструктор ValueNode.
    explicit ValueNode(int Val);

    // Метод для вычисления для Value Node. 
    int Evaluate(int X) const override;

    // Метод вывода для ValueNode.
    void Print(std::ofstream& Out, int Level) const override;

private:
    int Value;
};

// FIX_ME: добавлен комментарий к классу
// Класс узла для переменной x.
class VariableNode : public Node
{
public:
    // FIX_ME: имена параметров должны начинаться с заглавной буквы 
    // FIX_ME: добавлены комментарии к методам
    //int Evaluate(int x) const override;
    //void Print(std::ofstream& out, int level) const override;

    // Метод вычисления для VariableNode.
    int Evaluate(int X) const override;

    // Метод вывода для VariableNode.
    void Print(std::ofstream& Out, int Level) const override;
};

// FIX_ME: добавлен комментарий к классу
// Класс узла для операции.
class OperationNode : public Node
{
public:
    // FIX_ME: имена параметров должны начинаться с заглавной буквы 
    // FIX_ME: добавлены комментарии к методам
    //OperationNode(char op, std::shared_ptr<Node> left, std::shared_ptr<Node> right);
    //int Evaluate(int x) const override;
    //void Print(std::ofstream& out, int level) const override;

    // Конструктор OperationNode.
    OperationNode(char Op, std::shared_ptr<Node> Left, std::shared_ptr<Node> Right);

    // Метод вычисления для OperationNode.
    int Evaluate(int X) const override;

    // Метод вывода для OperationNode
    void Print(std::ofstream& Out, int Level) const override;

    // FIX_ME: добавлены геттеры и сеттеры для доступа к полям
    std::shared_ptr<Node> GetLeft() const { return Left; }
    std::shared_ptr<Node> GetRight() const { return Right; }
    std::shared_ptr<Node>& GetLeftRef() { return Left; }
    std::shared_ptr<Node>& GetRightRef() { return Right; }
    const std::shared_ptr<Node>& GetLeftRef() const { return Left; }
    const std::shared_ptr<Node>& GetRightRef() const { return Right; }
    void SetLeft(std::shared_ptr<Node> NewLeft) { Left = NewLeft; }
    void SetRight(std::shared_ptr<Node> NewRight) { Right = NewRight; }
    char GetOperator() const { return Op; }
   
private:
    char Op;
    std::shared_ptr<Node> Left;
    std::shared_ptr<Node> Right;
};

// FIX_ME: добавлен класс для инкапсуляции логики работы с деревом
// Класс для работы с деревом выражения.
class ExpressionTree
{
public:
    ExpressionTree();

    // FIX_ME: загрузка выражения из файла вынесена в отдельный метод класса
    bool LoadFromFile(const std::string& FileName);

    // FIX_ME: установка значения X вынесена в отдельный метод класса
    void SetXValue(int X);

    // FIX_ME: вычисление значения выражения вынесено в отдельный метод класса
    int Evaluate() const;

    // FIX_ME: преобразование дерева (x * A -> A * x) вынесено в отдельный метод класса
    void Transform();

    // FIX_ME: вывод дерева в файл вынесено в отдельный метод класса
    void PrintTree(std::ofstream& Out) const;

private:
    // FIX_ME: имена параметров должны начинаться с заглавной буквы 
    // FIX_ME: добавлены комментарии к методам
    // FIX_ME: возвращаемое значение метода ParseExpression изменено с std::shared_ptr<Node> на void,
    // тк результат сохраняется в член класса Root (в исходном коде возвращался)
    //std::shared_ptr<Node> ParseExpression(const std::string& expression);
    //int GetPrecedence(char op);
    //std::shared_ptr<Node> CreateTree(const std::vector<std::shared_ptr<Node>>& values, const std::vector<char>& ops);
    //void TransformTree(std::shared_ptr<Node>& node);
    //bool IsVariable(const std::shared_ptr<Node>& node);

    // Парсинг выражения.
    void ParseExpression(const std::string& Expression);

    // Определение приоритета операции.
    int GetPrecedence(char Op) const;

    // Создание дерева из значений и операторов.
    std::shared_ptr<Node> CreateTree(const std::vector<std::shared_ptr<Node>>& Values, const std::vector<char>& Ops);

    // Преобразование узла.
    void TransformNode(std::shared_ptr<Node>& Node);

    // Проверка, является ли узел переменной.
    bool IsVariableNode(const std::shared_ptr<Node>& Node) const;

    std::shared_ptr<Node> Root;  // Корень дерева выражения.
    int XValue;                   // Значение переменной x.
};
