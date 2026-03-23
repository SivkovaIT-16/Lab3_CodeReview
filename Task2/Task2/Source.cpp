#include "Header.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <cassert>

// FIX_ME: имена параметров должны начинаться с большой буквы и быть информативными
//Node(int v) : type(VAL), val(v), op(0), left(nullptr), right(nullptr) {}
//Node(char o, shared_ptr<Node> l = nullptr, shared_ptr<Node> r = nullptr) : type(OP), val(0), op(o), left(l), right(r) {}
//Node() : type(VAR), val(0), op(0), left(nullptr), right(nullptr) {}
Node::Node(int Val) : NodeType(VAL), Value(Val), Operator(0), Left(nullptr), Right(nullptr) {}
Node::Node(char Op, std::shared_ptr<Node> LeftChild, std::shared_ptr<Node> RightChild)
    : NodeType(OP), Value(0), Operator(Op), Left(LeftChild), Right(RightChild) {}
Node::Node() : NodeType(VAR), Value(0), Operator(0), Left(nullptr), Right(nullptr) {}


ExpressionTree::ExpressionTree() : Root(nullptr), Position(0), XValue(0) {}

// FIX_ME: фигурная скобка перенесена на следующую строку
//void skipSpaces() {
void ExpressionTree::SkipSpaces()
{
    // FIX_ME: добавлены фигурные скобки для однострочного оператора while
    // FIX_ME: заменён постфиксный инкремент на префиксный
    //while (pos < expr.size() && isspace(expr[pos])) pos++;
    while (Position < Expression.size() && std::isspace(Expression[Position]))
    {
        ++Position;
    }
}

// FIX_ME: фигурная скобка перенесена на следующую строку
// FIX_ME: добавлен std::
//shared_ptr<Node> parseFactor() {
std::shared_ptr<Node> ExpressionTree::ParseFactor()
{
    //skipSpaces();
    SkipSpaces();

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //if (pos >= expr.size()) {
    if (Position >= Expression.size())
    {
        // FIX_ME: добавлен std::
        // FIX_ME: сообщение об ошибке на русском
        //cerr << "Unexpected end of expression\n";
        std::cerr << "Ошибка: неожиданный конец выражения\n";
        exit(1);
    }

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //if (expr[pos] == '(') {
    if (Expression[Position] == '(')
    {
        // FIX_ME: заменён постфиксный инкремент на префиксный
        // FIX_ME: комментарий должен начинаться с заглавной буквы и заканчиваться точкой
        //pos++; // пропускаем '('
        ++Position; // Пропускаем '('.

        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //auto node = parseExpr();
        auto Node = ParseExpression();

        //skipSpaces();
        SkipSpaces();

        // FIX_ME: фигурная скобка перенесена на следующую строку
        //if (pos >= expr.size() || expr[pos] != ')') {
        if (Position >= Expression.size() || Expression[Position] != ')')
        {
            // FIX_ME: добавлен std::
            // FIX_ME: сообщение об ошибке на русском
            //cerr << "Expected ')' at position " << pos << "\n";
            std::cerr << "Ошибка: ожидалась ')' на позиции " << Position << "\n";
            exit(1);
        }
        // FIX_ME: заменён постфиксный инкремент на префиксный
        // FIX_ME: комментарий должен начинаться с заглавной буквы и заканчиваться точкой
        //pos++; // пропускаем ')'
        ++Position; // Пропускаем ')'.

        //return node;
        return Node;
    }

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //if (expr[pos] == 'x') {
    if (Expression[Position] == 'x')
    {
        // FIX_ME: заменён постфиксный инкремент на префиксный
        //pos++;
        ++Position;

        // FIX_ME: добавлен std::
        // FIX_ME: комментарий должен начинаться с заглавной буквы и заканчиваться точкой
        //return make_shared<Node>(); // переменная x
        return std::make_shared<Node>(); // Переменная x.
    }

    // FIX_ME: фигурная скобка перенесена на следующую строку
    // FIX_ME: исправлен комментарий
    //// Число [1..30]: читаем цифры
    //if (isdigit(expr[pos])) {
    // Обработка числа.
    if (std::isdigit(Expression[Position]))
    {
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //int val = 0;
        int Val = 0;
       
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //while (pos < expr.size() && isdigit(expr[pos])) {
        while (Position < Expression.size() && std::isdigit(Expression[Position]))
        {
            // FIX_ME: заменён постфиксный инкремент на префиксный
            //val = val * 10 + (expr[pos++] - '0');
            Val = Val * 10 + (Expression[Position] - '0');
            ++Position;
        }
        // FIX_ME: фигурная скобка перенесена на следующую строку
        // FIX_ME: добавлен комментарий
        //if (val < 1 || val > 30) {
        // Проверка длины диапазона.
        if (Val < 1 || Val > 30)
        {
            // FIX_ME: добавлен std::
            // FIX_ME: сообщение об ошибке на русском
            //cerr << "Number out of range [1..30]: " << val << "\n";
            std::cerr << "Ошибка: число " << Val << " вне диапазона [1;30]" << "\n";
            exit(1);
        }
        // FIX_ME: добавлен std::
        //return make_shared<Node>(val);
        return std::make_shared<Node>(Val);
    }
    // FIX_ME: добавлен std::
    // FIX_ME: сообщение об ошибке на русском
    //cerr << "Unexpected symbol at position " << pos << ": '" << expr[pos] << "'\n";
    std::cerr << "Ошибка: неожиданный символ на позиции " << Position
        << ": '" << Expression[Position] << "\n";
    exit(1);
}

// FIX_ME: фигурная скобка перенесена на следующую строку
// FIX_ME: добавлен std::
//shared_ptr<Node> parsePower() {
std::shared_ptr<Node> ExpressionTree::ParsePower()
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    //auto left = parseFactor();
    auto Left = ParseFactor();

    //skipSpaces();
    SkipSpaces();

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //while (pos < expr.size() && expr[pos] == '^') {
    while (Position < Expression.size() && Expression[Position] == '^')
    {
        // FIX_ME: заменён постфиксный инкремент на префиксный
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //char op = expr[pos++];
        char Op = Expression[Position];
        ++Position;

        //skipSpaces();
        SkipSpaces();

        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        // FIX_ME: исправлен комментарий
        //// При ^ правая ассоциативность, поэтому парсим справа и присоединяем иначе чем слева
        //auto right = parsePower();
        // Правая ассоциативность.
        auto Right = ParsePower();

        // FIX_ME: добавлен std::
        //left = make_shared<Node>(op, left, right);
        Left = std::make_shared<Node>(Op, Left, Right);

        //skipSpaces();
        SkipSpaces();
    }
    //return left;
    return Left;
}

// FIX_ME: фигурная скобка перенесена на следующую строку
// FIX_ME: добавлен std::
//shared_ptr<Node> parseTerm() {
std::shared_ptr<Node> ExpressionTree::ParseTerm()
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    //auto left = parsePower();
    auto Left = ParsePower();

    //skipSpaces();
    SkipSpaces();

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //while (pos < expr.size() && (expr[pos] == '*' || expr[pos] == '/' || expr[pos] == '%')) {
    while (Position < Expression.size() &&
        (Expression[Position] == '*' || Expression[Position] == '/' || Expression[Position] == '%'))
    {
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        // FIX_ME: заменён постфиксный инкремент на префиксный
        //char op = expr[pos++];
        char Op = Expression[Position];
        ++Position;

        //skipSpaces();
        SkipSpaces();

        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //auto right = parsePower();
        auto Right = ParsePower();

        // FIX_ME: добавлен std::
        //left = make_shared<Node>(op, left, right);
        Left = std::make_shared<Node>(Op, Left, Right);

        //skipSpaces();
        SkipSpaces();
    }
    //return left;
    return Left;
}

// FIX_ME: фигурная скобка перенесена на следующую строку
// FIX_ME: добавлен std::
//shared_ptr<Node> parseExpr() {
std::shared_ptr<Node> ExpressionTree::ParseExpression()
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    //auto left = parseTerm();
    auto Left = ParseTerm();

    //skipSpaces();
    SkipSpaces();

    //while (pos < expr.size() && (expr[pos] == '+' || expr[pos] == '-')) {
    while (Position < Expression.size() &&
        (Expression[Position] == '+' || Expression[Position] == '-'))
    {
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        // FIX_ME: заменён постфиксный инкремент на префиксный
        //char op = expr[pos++];
        char Op = Expression[Position];
        ++Position;

        //skipSpaces();
        SkipSpaces();

        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //auto right = parseTerm();
        auto Right = ParseTerm();

        // FIX_ME: добавлен std::
        //left = make_shared<Node>(op, left, right);
        Left = std::make_shared<Node>(Op, Left, Right);

        //skipSpaces();
        SkipSpaces();
    }
    //return left;
    return Left;
}

bool ExpressionTree::LoadFromFile(const std::string& FileName)
{
    std::ifstream File(FileName);
    if (!File.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл " << FileName << std::endl;
        return false;
    }

    std::getline(File, Expression);
    File.close();

    Position = 0;
    Root = ParseExpression();
    SkipSpaces();

    if (Position != Expression.size())
    {
        std::cerr << "Ошибка: лишние символы в конце выражения" << std::endl;
        return false;
    }

    return true;
}

void ExpressionTree::SetXValue(int Value)
{
    XValue = Value;
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//int eval(const shared_ptr<Node>& node) {
int ExpressionTree::EvaluateNode(const std::shared_ptr<Node>& Node) const
{
    // FIX_ME: используем геттеры и сеттеры
    // FIX_ME: добавлены фигурные скобки для однострочных операторов if
    //if (!node) return 0;
    //if (node->type == Node::VAL) return node->val;
    //if (node->type == Node::VAR) return x_value;
    if (!Node)
    {
        return 0;
    }

    if (Node->GetNodeType() == Node::VAL)
    {
        return Node->GetValue();
    }

    if (Node->GetNodeType() == Node::VAR)
    {
        return XValue;
    }

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: используем геттеры и сеттеры
    // // FIX_ME: исправлен комментарий
    //// OP
    //int l_val = eval(node->left);
    //int r_val = eval(node->right);
    // Оператор.
    int LeftVal = EvaluateNode(Node->GetLeft());
    int RightVal = EvaluateNode(Node->GetRight());

    // FIX_ME: используем геттеры и сеттеры
    // FIX_ME: фигурная скобка перенесена на следующую строку
    //switch (node->op) {
    switch (Node->GetOperator())
    {
    case '+':
        //return l_val + r_val;
        return LeftVal + RightVal;
    case '-': 
        //return l_val - r_val;
        return LeftVal - RightVal;
    case '*': 
        //return l_val * r_val;
        return LeftVal * RightVal;
    case '/':
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //if (r_val == 0) {
        if (RightVal == 0)
        {
            // FIX_ME: добавлен std::
            // FIX_ME: сообщение об ошибке на русском
            //cerr << "Division by zero\n";
            std::cerr << "Ошибка: деление на ноль\n";
            exit(1);
        }
        //return l_val / r_val;
        return LeftVal / RightVal;
    case '%':
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //if (r_val == 0) {
        if (RightVal == 0)
        {
            // FIX_ME: добавлен std::
            // FIX_ME: сообщение об ошибке на русском
            //cerr << "Modulo by zero\n";
            std::cerr << "Ошибка: остаток от деления на ноль\n";
            exit(1);
        }
        //return l_val % r_val;
        return LeftVal % RightVal;
    case '^': {
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //if (r_val < 0) {
        if (RightVal < 0)
        {
            // FIX_ME: добавлен std::
            // FIX_ME: сообщение об ошибке на русском
            //cerr << "Negative exponent not allowed\n";
            std::cerr << "Ошибка: отрицательная степень недопустима\n";
            exit(1);
        }
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //int res = 1;
        int Result = 1;

        // FIX_ME: добавлены фигурные скобки для однострочного оператора for
        //for (int i = 0; i < r_val; ++i) res *= l_val;
        for (int i = 0; i < RightVal; ++i)
        {
            Result *= LeftVal;
        }
        //return res;
        return Result;
    }
    default:
        // FIX_ME: используем геттеры и сеттеры
        // FIX_ME: добавлен std::
        // FIX_ME: сообщение об ошибке на русском
        //cerr << "Unknown operator: " << node->op << "\n";
        std::cerr << "Ошибка: неизвестный оператор '" << Node->GetOperator() << "'" << "\n";
        exit(1);
    }
    return 0;
}

int ExpressionTree::Evaluate() const
{
    return EvaluateNode(Root);
}

// FIX_ME: фигурная скобка перенесена на следующую строку
// FIX_ME: имя параметра изменено на Current, для избежания конфликта с именем класса
// FIX_ME: добавлен std::
//shared_ptr<Node> transform(const shared_ptr<Node>& node) {
std::shared_ptr<Node> ExpressionTree::TransformNode(const std::shared_ptr<Node>& Current)
{
    // FIX_ME: добавлены фигурные скобки для однострочного оператора if
    //if (!node) return nullptr;
    if (!Current)
    {
        return nullptr;
    }

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //if (node->type == Node::OP) {
    if (Current->GetNodeType() == Node::OP)
    {
        // FIX_ME: используем геттеры и сеттеры
        //node->left = transform(node->left);
        //node->right = transform(node->right);
        Current->SetLeft(TransformNode(Current->GetLeft()));
        Current->SetRight(TransformNode(Current->GetRight()));

        // FIX_ME: фигурная скобка перенесена на следующую строку
        // FIX_ME: комментрарий должен заканчиваться точкой
        // FIX_ME: используем геттеры и сеттеры
        //if (node->op == '*' && node->left && node->left->type == Node::VAR) {
        // Проверяем форму (x * A).
        if (Current->GetOperator() == '*' && Current->GetLeft() && Current->GetLeft()->GetNodeType() == Node::VAR)
        {
            // FIX_ME: добавлен std::
            // FIX_ME: используем геттеры и сеттеры
            // FIX_ME: исправлен комментарий
            //// swap left and right
            //return make_shared<Node>('*', node->right, node->left);
            // Меняем местами левое и правое поддеревья.
            return std::make_shared<Node>('*', Current->GetRight(), Current->GetLeft());
        }
    }
    //return node;
    return Current;
}

void ExpressionTree::Transform()
{
    Root = TransformNode(Root);
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//void printTree(const shared_ptr<Node>& node, ostream& out, int level = 0) {
void ExpressionTree::PrintTreeNode(const std::shared_ptr<Node>& Node, std::ostream& Out, int Level) const
{
    // FIX_ME: добавлены фигурные скобки для однострочного оператора if
    //if (!node) return;
    if (!Node)
    {
        return;
    }

    // FIX_ME: используем геттеры и сеттеры
    //printTree(node->right, out, level + 1);
    PrintTreeNode(Node->GetRight(), Out, Level + 1);

    // FIX_ME: добавлен std::
    //out.width(4 * level);
    //out << right;
    Out.width(4 * Level);
    Out << std::right;

    // FIX_ME: используем геттеры и сеттеры
    // FIX_ME: добавлены фигурные скобки для однострочного оператора if
    // FIX_ME: добавлен std::
    //if (node->type == Node::VAL)
    //    out << node->val << "\n";
    //else if (node->type == Node::VAR)
    //    out << 'x' << "\n";
    //else
    //    out << node->op << "\n";
    if (Node->GetNodeType() == Node::VAL)
    {
        Out << Node->GetValue() << "\n";
    }
    else if (Node->GetNodeType() == Node::VAR)
    {
        Out << 'x' << "\n";
    }
    else
    {
        Out << Node->GetOperator() << "\n";
    }
    // FIX_ME: используем геттеры и сеттеры
    //printTree(node->left, out, level + 1);
    PrintTreeNode(Node->GetLeft(), Out, Level + 1);
}

void ExpressionTree::PrintTree(std::ostream& Out) const
{
    PrintTreeNode(Root, Out, 0);
}
