#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

//Node(char o = '\0', int v = 0, Node* l = nullptr, Node* r = nullptr)
Node::Node(char Operation, int Val, Node* LeftChild, Node* RightChild)
    //: op(o), value(v), left(l), right(r) {}
    : Op(Operation), Value(Val), Left(LeftChild), Right(RightChild) {}

// FIX_ME: фигурная скобка перенесена на следующую строку
//~Node() {
Node::~Node()
{
    //delete left;
    //delete right;
    delete Left;
    delete Right;
}

ExpressionTree::ExpressionTree() : Root(nullptr), XValue(0) {}

ExpressionTree::~ExpressionTree()
{
    delete Root;
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//int getPriority(char op) {
int ExpressionTree::GetPriority(char Op) const
{
    // FIX_ME: добавлены фигурные скобки для однострочных if
    //if (op == '^') return 4;
    //if (op == '*' || op == '/' || op == '%') return 3;
    //if (op == '+' || op == '-') return 2;
    if (Op == '^')
    {
        return 4;
    }
    if (Op == '*' || Op == '/' || Op == '%')
    {
        return 3;
    }
    if (Op == '+' || Op == '-')
    {
        return 2;
    }
    return 1;
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//bool isOperator(char c) {
bool ExpressionTree::IsOperator(char C) const
{
    //return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
    return C == '+' || C == '-' || C == '*' || C == '/' || C == '%' || C == '^';
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//Node* buildExpressionTree(const std::string& expression) {
Node* ExpressionTree::BuildExpressionTree(const std::string& Expression)
{
    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    //std::stack<Node*> operandStack;
    //std::stack<char> operatorStack;
    std::stack<Node*> OperandStack;
    std::stack<char> OperatorStack;

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //for (int i = 0; i < expression.length(); ++i) {
    for (size_t i = 0; i < Expression.length(); ++i)
    {
        // FIX_ME: использована переменная для хранения текущего символа
        char Current = Expression[i];

        // FIX_ME: добавлены фигурные скобки для однострочного if
        //if (expression[i] == ' ') continue;
        if (Current == ' ')
        {
            continue;
        }

        // FIX_ME: фигурная скобка перенесена на следующую строку
        //if (expression[i] == '(') {
        if (Current == '(')
        {
            //operatorStack.push('(');
            OperatorStack.push('(');
        }
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //else if (expression[i] == ')') {
        else if (Current == ')')
        {
            // FIX_ME: фигурная скобка перенесена на следующую строку
            //while (!operatorStack.empty() && operatorStack.top() != '(') {
            while (!OperatorStack.empty() && OperatorStack.top() != '(')
            {
                // FIX_ME: имя переменной должно начинаться с заглавной буквы
                //char op = operatorStack.top();
                char Op = OperatorStack.top();

                //operatorStack.pop();
                OperatorStack.pop();

                // FIX_ME: имя переменной должно начинаться с заглавной буквы
                //Node* right = operandStack.top();
                Node* Right = OperandStack.top();

                //operandStack.pop();
                OperandStack.pop();

                // FIX_ME: имя переменной должно начинаться с заглавной буквы
                //Node* left = operandStack.top();
                Node* Left = OperandStack.top();

                //operandStack.pop();
                //operandStack.push(new Node(op, 0, left, right));
                OperandStack.pop();
                OperandStack.push(new Node(Op, 0, Left, Right));
            }
            // FIX_ME: добавлены фигурные скобки для однострочного if
            // FIX_ME: комментарий должен заканчиваться точкой
            //if (!operatorStack.empty()) operatorStack.pop(); // Удаляем '('
            if (!OperatorStack.empty())
            {
                OperatorStack.pop(); // Удаляем '('.
            }
        }
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //else if (isdigit(expression[i])) {
        else if (std::isdigit(Current))
        {
            // FIX_ME: имя переменной должно начинаться с заглавной буквы
            //int num = 0;
            int Num = 0;

            // FIX_ME: фигурная скобка перенесена на следующую строку
            //while (i < expression.length() && isdigit(expression[i])) {
            while (i < Expression.length() && std::isdigit(Expression[i]))
            {
                //num = num * 10 + (expression[i] - '0');
                Num = Num * 10 + (Expression[i] - '0');

                // FIX_ME: префиксный инкремент заменён на постфиксный
                //i++;
                ++i;
            }
            // FIX_ME: префиксный инкремент заменён на постфиксный
            // FIX_ME: комментарий должен заканчиваться точкой
            //i--; // Возвращаемся на один символ назад
            --i; // Возвращаемся на один символ назад.

            //operandStack.push(new Node('#', num));
            OperandStack.push(new Node('#', Num));
        }
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //else if (expression[i] == 'x') {
        else if (Current == 'x')
        {
            //operandStack.push(new Node('x'));
            OperandStack.push(new Node('x'));
        }
        // FIX_ME: фигурная скобка перенесена на следующую строку
        //else if (isOperator(expression[i])) {
        else if (IsOperator(Current))
        {
            // FIX_ME: фигурная скобка перенесена на следующую строку
            // FIX_ME: в строке не должно быть больше 100 символов - добавлен перенос строки
            //while (!operatorStack.empty() && operatorStack.top() != '(' && getPriority(operatorStack.top()) >= getPriority(expression[i])) {
            while (!OperatorStack.empty() && OperatorStack.top() != '(' &&
                GetPriority(OperatorStack.top()) >= GetPriority(Current))
            {
                // FIX_ME: имя переменной должно начинаться с заглавной буквы
                //char op = operatorStack.top();
                char Op = OperatorStack.top();

                //operatorStack.pop();
                OperatorStack.pop();

                // FIX_ME: имя переменной должно начинаться с заглавной буквы
                //Node* right = operandStack.top();
                Node* Right = OperandStack.top();

                //operandStack.pop();
                OperandStack.pop();

                // FIX_ME: имя переменной должно начинаться с заглавной буквы
                //Node* left = operandStack.top();
                Node* Left = OperandStack.top();

                //operandStack.pop();
                //operandStack.push(new Node(op, 0, left, right));
                OperandStack.pop();
                OperandStack.push(new Node(Op, 0, Left, Right));
            }
            //operatorStack.push(expression[i]);
            OperatorStack.push(Current);
        }
    }

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //while (!operatorStack.empty()) {
    while (!OperatorStack.empty())
    {
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
                //char op = operatorStack.top();
        char Op = OperatorStack.top();

        //operatorStack.pop();
        OperatorStack.pop();

        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //Node* right = operandStack.top();
        Node* Right = OperandStack.top();

        //operandStack.pop();
        OperandStack.pop();

        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        //Node* left = operandStack.top();
        Node* Left = OperandStack.top();

        //operandStack.pop();
        //operandStack.push(new Node(op, 0, left, right));
        OperandStack.pop();
        OperandStack.push(new Node(Op, 0, Left, Right));
    }
    //return operandStack.top();
    return OperandStack.top();
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//int evaluateExpressionTree(Node* root, int x) {
int ExpressionTree::EvaluateExpressionTree(Node* RootNode, int X) const
{
    // FIX_ME: добавлены фигурные скобки для однострочных if
    // FIX_ME: использованы геттеры для обращения к узлам
    //if (!root) return 0;
    //if (root->op == '#') return root->value;
    //if (root->op == 'x') return x;
    if (!RootNode)
    {
        return 0;
    }
    if (RootNode->GetOp() == '#')
    {
        return RootNode->GetValue();
    }
    if (RootNode->GetOp() == 'x')
    {
        return X;
    }

    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    //long long leftVal = evaluateExpressionTree(root->left, x);
    //long long rightVal = evaluateExpressionTree(root->right, x);
    long long LeftVal = EvaluateExpressionTree(RootNode->GetLeft(), X);
    long long RightVal = EvaluateExpressionTree(RootNode->GetRight(), X);

    // FIX_ME: фигурная скобка перенесена на следующую строку
    // FIX_ME: использован геттер для обращения к узлe
    //switch (root->op) {
    switch (RootNode->GetOp())
    {
        // FIX_ME: использован static_cast<int> для явного преобразования из long long в int
        // FIX_ME: добавлен default для обработки неизвестных операторов
        // FIX_ME: добавлены фигурные скобки для case и default
        //case '+': return leftVal + rightVal;
        //case '-': return leftVal - rightVal;
        //case '*': return leftVal * rightVal;
        //case '/': return leftVal / rightVal;
        //case '%': return leftVal % rightVal;
        //case '^': return std::pow(leftVal, rightVal);
    case '+':
    {
        return static_cast<int>(LeftVal + RightVal);
    }
    case '-':
    {
        return static_cast<int>(LeftVal - RightVal);
    }
    case '*':
    {
        return static_cast<int>(LeftVal * RightVal);
    }
    case '/':
    {
        return static_cast<int>(LeftVal / RightVal);
    }
    case '%':
    {
        return static_cast<int>(LeftVal % RightVal);
    }
    case '^':
    {
        return static_cast<int>(std::pow(LeftVal, RightVal));
    }
    default:
    {
        return 0;
    }
    }
    //return 0; // Не должно достигаться
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//void transformTree(Node* root) {
void ExpressionTree::TransformTree(Node* RootNode)
{
    // FIX_ME: добавлены фигурные скобки для однострочного if
    //if (!root) return;
    if (!RootNode)
    {
        return;
    }

    // FIX_ME: использованы геттеры для обращения к узлам
    //transformTree(root->left);
    //transformTree(root->right);
    TransformTree(RootNode->GetLeft());
    TransformTree(RootNode->GetRight());

    // FIX_ME: фигурная скобка перенесена на следующую строку
    // FIX_ME: использованы геттеры для обращения к узлам
    //if (root->op == '*' && root->left && root->left->op == 'x') {
    if (RootNode->GetOp() == '*' && RootNode->GetLeft() && RootNode->GetLeft()->GetOp() == 'x')
    {
        // FIX_ME: имя переменной должно начинаться с заглавной буквы
        // FIX_ME: использован геттер для обращения к узлу
        //Node* temp = root->left;
        Node* Temp = RootNode->GetLeft();

        // FIX_ME: использованы cеттеры и геттер для обращения к узлам
        //root->left = root->right;
        //root->right = temp;
        RootNode->SetLeft(RootNode->GetRight());
        RootNode->SetRight(Temp);
    }
}

// FIX_ME: фигурная скобка перенесена на следующую строку
//void printTree(std::ofstream& ofs, Node* root, int indent = 0) {
void ExpressionTree::PrintTree(std::ofstream& Ofs, Node* RootNode, int Indent) const
{
    // FIX_ME: добавлены фигурные скобки для однострочного if
    //if (!root) return;
    if (!RootNode)
    {
        return;
    }

    // FIX_ME: фигурная скобка перенесена на следующую строку
    // FIX_ME: использованы геттеры для обращения к узлам
    //if (root->right) {
    if (RootNode->GetRight())
    {
        //printTree(ofs, root->right, indent + 4);
        PrintTree(Ofs, RootNode->GetRight(), Indent + 4);
    }

    // FIX_ME: фигурная скобка перенесена на следующую строку
    //for (int i = 0; i < indent; ++i) {
    for (int i = 0; i < Indent; ++i)
    {
        //ofs << " ";
        Ofs << " ";
    }

    // FIX_ME: использованы геттеры для обращения к узлам
    // FIX_ME: фигурная скобка перенесена на следующую строку
    //if (root->op == '#') {
    if (RootNode->GetOp() == '#')
    {
        //ofs << root->value << std::endl;
        Ofs << RootNode->GetValue() << std::endl;
    }
    // FIX_ME: использован геттер для обращения к узлу
    // FIX_ME: фигурная скобка перенесена на следующую строку
    //else if (root->op == 'x') {
    else if (RootNode->GetOp() == 'x')
    {
        //ofs << "x" << std::endl;
        Ofs << "x" << std::endl;
    }
    // FIX_ME: фигурная скобка перенесена на следующую строку
    //else {
    else
    {
        // FIX_ME: использован геттер для обращения к узлу
        //ofs << root->op << std::endl;
        Ofs << RootNode->GetOp() << std::endl;
    }

    // FIX_ME: использованы геттеры для обращения к узлам
    // FIX_ME: фигурная скобка перенесена на следующую строку
    //if (root->left) {
    if (RootNode->GetLeft())
    {
        //printTree(ofs, root->left, indent + 4);
        PrintTree(Ofs, RootNode->GetLeft(), Indent + 4);
    }
}

bool ExpressionTree::LoadFromFile(const std::string& FileName)
{
    std::ifstream InputFile(FileName);
    if (!InputFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл " << FileName << std::endl;
        return false;
    }

    std::string Expression = "";
    std::getline(InputFile, Expression);
    InputFile.close();

    Expression.erase(std::remove_if(Expression.begin(), Expression.end(), ::isspace), Expression.end());

    try
    {
        Root = BuildExpressionTree(Expression);
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
    if (!Root)
    {
        throw std::runtime_error("Дерево выражения не построено");
    }
    return EvaluateExpressionTree(Root, XValue);
}

void ExpressionTree::Transform()
{
    TransformTree(Root);
}

void ExpressionTree::PrintTree(std::ofstream& Out) const
{
    if (!Root)
    {
        Out << "Дерево пусто" << std::endl;
        return;
    }
    PrintTree(Out, Root, 0);
}