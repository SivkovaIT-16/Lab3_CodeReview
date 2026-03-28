#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <map>
#include <cctype>

//explicit ValueNode(int value) : Value(value) {}
ValueNode::ValueNode(int Val) : Value(Val) {}

//int ValueNode::Evaluate(int x) const override
int ValueNode::Evaluate(int X) const
{
    return Value;
}

//void Print(std::ofstream& out, int level) const override
void ValueNode::Print(std::ofstream& Out, int Level) const
{
    // FIX_ME: вывод с отступом, выравнивание по правому краю
    //out << std::string(4 * level, ' ') << Value << "\n";
    Out.width(4 * Level);
    Out << std::right << Value << "\n";
}

//int Evaluate(int x) const override
int VariableNode::Evaluate(int X) const
{
    //return x;
    return X;
}

//void Print(std::ofstream& out, int level) const override
void VariableNode::Print(std::ofstream& Out, int Level) const
{
    // FIX_ME: вывод с отступом, выравнивание по правому краю
    //out << std::string(4 * level, ' ') << "x\n";
    Out.width(4 * Level);
    Out << std::right << 'x' << "\n";
}

//OperationNode(char op, std::shared_ptr<Node> left, std::shared_ptr<Node> right)
//    : Op(op), Left(std::move(left)), Right(std::move(right)) {}
OperationNode::OperationNode(char Op, std::shared_ptr<Node> Left, std::shared_ptr<Node> Right)
    : Op(Op), Left(std::move(Left)), Right(std::move(Right)) {}

//int Evaluate(int x) const override
int OperationNode::Evaluate(int X) const
{
    // FIX_ME: добавлены фигурные скобки для case и default
    switch (Op)
    {
    case '+':
    {
        //return Left->Evaluate(x) + Right->Evaluate(x);
        return Left->Evaluate(X) + Right->Evaluate(X);
    }
    case '-':
    {
        //return Left->Evaluate(x) - Right->Evaluate(x);
        return Left->Evaluate(X) - Right->Evaluate(X);
    }
    case '*':
    {
        //return Left->Evaluate(x) * Right->Evaluate(x);
        return Left->Evaluate(X) * Right->Evaluate(X);
    }
    case '/':
    {
        //return Left->Evaluate(x) / Right->Evaluate(x);
        return Left->Evaluate(X) / Right->Evaluate(X);
    }
    case '%':
    {
        //return Left->Evaluate(x) % Right->Evaluate(x);
        return Left->Evaluate(X) % Right->Evaluate(X);
    }
    case '^':
    {
        //return static_cast<int>(pow(Left->Evaluate(x), Right->Evaluate(x)));
        return static_cast<int>(pow(Left->Evaluate(X), Right->Evaluate(X)));
    }
    default:
    {
        // FIX_ME: сообщение переведено на русский
        //throw std::runtime_error("Unknown operation");
        throw std::runtime_error("Неизвестная операция");
    }
    }
}

//void Print(std::ofstream& out, int level) const override
void OperationNode::Print(std::ofstream& Out, int Level) const
{
    // FIX_ME: сначала выводим правое поддерево, далее оператор с отступом, затем левое поддерево
    //out << std::string(4 * level, ' ') << Op << "\n";
    //Left->Print(out, level + 1);
    //Right->Print(out, level + 1);
    Right->Print(Out, Level + 1);
    Out.width(4 * Level);
    Out << std::right << Op << "\n";
    Left->Print(Out, Level + 1);
}

ExpressionTree::ExpressionTree() : Root(nullptr), XValue(0) {}

bool ExpressionTree::LoadFromFile(const std::string& FileName)
{
    // FIX_ME: имя переменной должно начинаться с заглавной буквы 
    //std::ifstream inputFile("FN1.txt");
    std::ifstream InputFile(FileName);
    //if (!inputFile.is_open() || !outputFile.is_open())
    if (!InputFile.is_open())
    {
        // FIX_ME: сообщение переведено на русский
        //std::cerr << "Error opening files!" << std::endl;
        //return 1;
        std::cerr << "Ошибка: не удалось открыть файл " << FileName << std::endl;
        return false;
    }

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    // FIX_ME: переменная должна быть инициализирована при создании
    //std::string expression;
    std::string Expression = "";

    //std::getline(inputFile, expression);
    //inputFile.close();
    std::getline(InputFile, Expression);
    InputFile.close();

    // FIX_ME: комментарий должен заканчиваться точкой
    //expression.erase(remove_if(expression.begin(), expression.end(), isspace), expression.end());
    // Удаление пробелов из выражения.
    Expression.erase(remove_if(Expression.begin(), Expression.end(), isspace), Expression.end());

    // FIX_ME: добавлена обработка ошибки парсинга выражения
    try
    {
        // FIX_ME: комментарий должен заканчиваться точкой
        //ParseExpression(expression);
        // Парсинг выражения и построение дерева.
        ParseExpression(Expression);
    }
    catch (const std::exception& Error)
    {
        std::cerr << "Ошибка парсинга выражения: " << Error.what() << std::endl;
        return false;
    }

    return true;
}

void ExpressionTree::SetXValue(int X)
{
    XValue = X;
}

int ExpressionTree::Evaluate() const
{
    // FIX_ME: добавлена проверка построено ли дерево выражения
    if (!Root)
    {
        throw std::runtime_error("Дерево выражения не построено");
    }
    //int result = expressionTree->Evaluate(x);
    return Root->Evaluate(XValue);
}

void ExpressionTree::Transform()
{
    //TransformTree(expressionTree);
    TransformNode(Root);
}

void ExpressionTree::PrintTree(std::ofstream& Out) const
{
    // FIX_ME: добавлена проверка на пустое дерево
    if (!Root)
    {
        Out << "Дерево пусто" << std::endl;
        return;
    }
    //expressionTree->Print(outputFile, 0);
    Root->Print(Out, 0);
}

//std::shared_ptr<Node> ParseExpression(const std::string& expression)
void ExpressionTree::ParseExpression(const std::string& Expression)
{
    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    // FIX_ME: переменные должны быть инициализированы при создании
    //std::vector<std::shared_ptr<Node>> values;
    //std::vector<char> ops;
    //std::string number;
    std::vector<std::shared_ptr<Node>> Values = {};
    std::vector<char> Operators = {};
    std::string Number = "";

    //for (size_t i = 0; i < expression.length(); ++i)
    for (size_t i = 0; i < Expression.length(); ++i)
    {
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //char current = expression[i];
        char Current = Expression[i];

        // FIX_ME: комментарий должен заканчиваться точкой
        //if (isdigit(current) || (current == '-' && (i == 0 || expression[i - 1] == '('))) 
        // Обработка отрицательных чисел.
        if (std::isdigit(Current) || (Current == '-' && (i == 0 || Expression[i - 1] == '(')))
        {
            //number += current;
            Number += Current;
        }
        else
        {
            //if (!number.empty())
            if (!Number.empty())
            {
                //values.push_back(std::make_shared<ValueNode>(std::stoi(number)));
                //number.clear();
                Values.push_back(std::make_shared<ValueNode>(std::stoi(Number)));
                Number.clear();
            }

            //if (current == 'x')
            if (Current == 'x')
            {
                //values.push_back(std::make_shared<VariableNode>());
                Values.push_back(std::make_shared<VariableNode>());
            }
            //else if (current == '(')
            else if (Current == '(')
            {
                //ops.push_back(current);
                Operators.push_back(Current);
            }
            //else if (current == ')')
            else if (Current == ')')
            {
                //while (!ops.empty() && ops.back() != '(')
                while (!Operators.empty() && Operators.back() != '(')
                {
                    // FIX_ME: имя переменной должно начинаться с заглавной буквы
                    //char op = ops.back();
                    char Op = Operators.back();

                    //ops.pop_back();
                    Operators.pop_back();

                    // FIX_ME: имя переменной должно начинаться с заглавной буквы
                    //auto right = values.back();
                    auto Right = Values.back();

                    //values.pop_back();
                    Values.pop_back();

                    // FIX_ME: имя переменной должно начинаться с заглавной буквы
                    //auto left = values.back();
                    auto Left = Values.back();

                    //values.pop_back();
                    //values.push_back(std::make_shared<OperationNode>(op, left, right));
                    Values.pop_back();
                    Values.push_back(std::make_shared<OperationNode>(Op, Left, Right));
                }
                //ops.pop_back(); 
                Operators.pop_back();
            }
            //else if (GetPrecedence(current) > 0)
            else if (GetPrecedence(Current) > 0)
            {
                //while (!ops.empty() && GetPrecedence(ops.back()) >= GetPrecedence(current))
                while (!Operators.empty() && GetPrecedence(Operators.back()) >= GetPrecedence(Current))
                {
                    // FIX_ME: имя переменной должно начинаться с заглавной буквы
                         //char op = ops.back();
                    char Op = Operators.back();

                    //ops.pop_back();
                    Operators.pop_back();

                    // FIX_ME: имя переменной должно начинаться с заглавной буквы
                    //auto right = values.back();
                    auto Right = Values.back();

                    //values.pop_back();
                    Values.pop_back();

                    // FIX_ME: имя переменной должно начинаться с заглавной буквы
                    //auto left = values.back();
                    auto Left = Values.back();

                    //values.pop_back();
                    //values.push_back(std::make_shared<OperationNode>(op, left, right));
                    Values.pop_back();
                    Values.push_back(std::make_shared<OperationNode>(Op, Left, Right));
                }
                //ops.push_back(current);
                Operators.push_back(Current);
            }
        }
    }

    //if (!number.empty())
    if (!Number.empty())
    {
        //values.push_back(std::make_shared<ValueNode>(std::stoi(number)));
        Values.push_back(std::make_shared<ValueNode>(std::stoi(Number)));
    }

    //while (!ops.empty())
    while (!Operators.empty())
    {
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
                     //char op = ops.back();
        char Op = Operators.back();

        //ops.pop_back();
        Operators.pop_back();

        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //auto right = values.back();
        auto Right = Values.back();

        //values.pop_back();
        Values.pop_back();

        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //auto left = values.back();
        auto Left = Values.back();

        //values.pop_back();
        //values.push_back(std::make_shared<OperationNode>(op, left, right));
        Values.pop_back();
        Values.push_back(std::make_shared<OperationNode>(Op, Left, Right));
    }
    //return values.back();
    Root = Values.back();
}

//int GetPrecedence(char op)
int ExpressionTree::GetPrecedence(char Op) const
{
    // FIX_ME: добавлены фигурные скобки для case и default
    //switch (op)
    switch (Op)
    {
    case '+': {}
    case '-':
    {
        return 1;
    }
    case '*': {}
    case '/': {}
    case '%':
    {
        return 2;
    }
    case '^':
    {
        return 3;
    }
    default:
    {
        return 0;
    }
    }
}

//void TransformTree(std::shared_ptr<Node>& node)
void ExpressionTree::TransformNode(std::shared_ptr<Node>& Node)
{
    // FIX_ME: добавлены фигурные скобки для однострочного if
    //if (!node) 
    if (!Node)
    {
        return;
    }

    // FIX_ME: имя переменной должно начинаться с заглавной буквы
    //auto operationNode = dynamic_cast<OperationNode*>(node.get());
    auto OpNode = std::dynamic_pointer_cast<OperationNode>(Node);

    //if (operationNode)
    if (OpNode)
    {
        // FIX_ME: использованы геттеры для доступа к левому и правому поддеревьям
        //TransformTree(operationNode->Left);
        //TransformTree(operationNode->Right);
        auto& LeftRef = OpNode->GetLeftRef();
        auto& RightRef = OpNode->GetRightRef();
        TransformNode(LeftRef);
        TransformNode(RightRef);

        // FIX_ME: добавлена проверка формы (x * A) и замена на (A * x)
        if (OpNode->GetOperator() == '*' && IsVariableNode(OpNode->GetLeft()))
        {
            Node = std::make_shared<OperationNode>('*', OpNode->GetRight(), OpNode->GetLeft());
        }
    }
}

// Проверка, является ли узел переменной
//bool IsVariable(const std::shared_ptr<Node>& node)
bool ExpressionTree::IsVariableNode(const std::shared_ptr<Node>& Node) const
{
    //return dynamic_cast<VariableNode*>(node.get()) != nullptr;
    return std::dynamic_pointer_cast<VariableNode>(Node) != nullptr;
}