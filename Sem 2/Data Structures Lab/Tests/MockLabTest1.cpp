#include <iostream>
#include <cstdlib>

using namespace std;

class Stack
{
    char *stack;
    int top, size;

public:
    Stack(int);
    char pop();
    void push(char element);
    void display();
};

Stack::Stack(int len)
{
    stack = new char[len];
    top = -1;
    size = len;
}

char Stack::pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        top -= 1;
        return stack[top + 1];
    }
}

void Stack::push(char element)
{
    if (top + 1 == size)
    {
        return;
    }
    else
    {
        top += 1;
        stack[top] = element;
    }
}

void Stack::display()
{
    for (int i = 0; i <= top; i++)
        cout << stack[i];
}

bool isOperator(char *a)
{
    char op = *a;
    if (op == '*' || op == '/' || op == '+' || op == '-' || op == '<' || op == '>' || ((op == '!' || op == '=') && a[1] == '='))
        return true;
    else
        return false;
}

int getPrecedence(char a)
{
    if (a == '(')
        return 0;
    else if (a == '*' || a == '/')
        return 5;
    else if (a == '+' || a == '-')
        return 4;
    else if (a == '<' || a == '>' || a == '!' || a == '=')
        return 3;
}

string infix_to_postfix(string infix)
{
    string postfix = "";
    Stack stack(infix.length());
    int curr_pre = 0, op_pre = 0;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            stack.push('(');
            curr_pre = 0;
        }
        else if (isOperator(&infix[i]))
        {
            if (infix[i] == '*' || infix[i] == '/')
            {
                curr_pre = 5;
                stack.push(infix[i]);
            }
            else if (infix[i] == '+' || infix[i] == '-')
            {
                if (curr_pre > 3)
                {
                    char x = stack.pop();
                    do
                    {
                        postfix.push_back(x);
                        x = stack.pop();
                    } while (x != -1 && x != '(');
                }
                stack.push('(');
                stack.push(infix[i]);
                curr_pre = 0;
            }
        }
        else if (infix[i] == ')')
        {
            char ch = stack.pop();
            while (ch != '(' && ch != -1)
            {
                postfix.push_back(ch);
                ch = stack.pop();
            }
            char op = stack.pop();
            curr_pre = getPrecedence(op);

            stack.push(op);
        }
        else
        {
            postfix.push_back(infix[i]);
        }
        cout << postfix << "\t\t\t";
        stack.display();
        cout << endl;
    }
    char ch = stack.pop();
    while (ch != '(' && ch != -1 && ch != 0)
    {
        postfix.push_back(ch);
        ch = stack.pop();
    }
    return postfix;
}

int main()
{
    string expr;
    cout << "Enter the String : ";
    cin >> expr;
    cout << infix_to_postfix(expr);
}