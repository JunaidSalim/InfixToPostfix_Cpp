#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class IntStack
{
    struct Node
    {
        double data;
        Node *next;
        Node *prev;
    };
    Node *top;

public:
    IntStack()
    {
        top = NULL;
    }
    void push(double val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        if (!top)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            top = newNode;
        }
        else
        {
            newNode->prev = top->prev;
            newNode->next = top;
            top->prev->next = newNode;
            top->prev = newNode;
            top = newNode;
        }
    }

    double pop()
    {
        if (!top)
        {
            cout << "\nEmpty Stack";
        }
        else
        {
            double temp2;
            if (top->next == top)
            {
                temp2 = top->data;
                delete top;
                top = NULL;
                return temp2;
            }
            Node *temp = top;
            top = temp->next;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            temp2 = temp->data;
            delete temp;
            return temp2;
        }
    }

    void display()
    {
        if (!top)
        {
            cout << "\nStack is Empty";
        }
        else
        {
            cout << endl;
            Node *temp = top;
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != top);
        }
        cout << endl;
    }
    friend class Stack;
};

class Stack
{

    struct Node
    {
        string data;
        Node *next;
        Node *prev;
    };
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(string val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        if (!top)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            top = newNode;
        }
        else
        {
            newNode->prev = top->prev;
            newNode->next = top;
            top->prev->next = newNode;
            top->prev = newNode;
            top = newNode;
        }
    }

    string pop()
    {
        if (!top)
        {
            cout << "\nEmpty Stack";
        }
        else
        {
            string temp2;
            if (top->next == top)
            {
                temp2 = top->data;
                delete top;
                top = NULL;
                return temp2;
            }
            Node *temp = top;
            top = temp->next;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            temp2 = temp->data;
            delete temp;
            return temp2;
        }
    }

    void display()
    {
        if (!top)
        {
            cout << "\nStack is Empty";
        }
        else
        {
            cout << endl;
            Node *temp = top;
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != top);
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return (this->top == NULL) ? 1 : 0;
    }

    int checkOperator(string val)
    {
        if (val == "+" || val == "-" || val == "*" || val == "/" || val == "^")
        {
            return 1;
        }
        else if (val == ")")
        {
            return 2;
        }
        else if (val == "(")
        {
            return 3;
        }

        return 0;
    }
    void readInfix(string infix)
    {
        string str = "";
        for (int i = 0; i < infix.length(); i++)
        {
            string s = "";
            s = infix[i];
            if (checkOperator(s) == 0)
            {
                str += infix[i];
            }
            else
            {
                if (!str.empty())
                {
                    this->push(str);
                }
                str = "";
                str = infix[i];
                this->push(str);
                str = "";
            }
        }
        if (!str.empty())
        {
            this->push(str);
        }

        this->push(")");
    }

    int checkPrecedence(string val)
    {
        if (val == "+" || val == "-")
        {
            return 1;
        }
        else if (val == "*" || val == "/")
        {
            return 2;
        }
        else if (val == "^")
        {
            return 3;
        }
        else if (val == "(" || val == ")")
        {
            return -1;
        }
        return 0;
    }
    Stack InfixToPostFix()
    {
        Stack STACK;
        Stack PostFix;
        STACK.push("(");
        Node *temp = this->top;
        Node *temp2 = STACK.top;

        while (!(STACK.isEmpty()) && temp->next != top)
        {
            if (checkOperator(temp->data) == 0)
            {
                PostFix.push(temp->data);
            }
            else if (checkOperator(temp->data) == 1)
            {
                do
                {
                    if (checkPrecedence(temp->data) <= checkPrecedence(temp2->data) && !(STACK.isEmpty()))
                    {
                        string c = STACK.pop();
                        if (c != "(")
                        {
                            PostFix.push(c);
                        }
                        temp2 = STACK.top;
                    }
                    else
                    {
                        temp2 = temp2->next;
                    }
                } while (temp2 != STACK.top);
                STACK.push(temp->data);
            }
            else if (checkOperator(temp->data) == 3)
            {
                STACK.push(temp->data);
            }
            else if (checkOperator(temp->data) == 2)
            {
                Node *temp4 = STACK.top;
                while (temp4->data != "(")
                {
                    PostFix.push(STACK.pop());
                    temp4 = STACK.top;
                }
            }
            if (checkOperator((temp->next)->data) == 2)
            {
                temp2 = STACK.top;
                while (temp2->data != "(")
                {
                    PostFix.push(STACK.pop());
                    temp2 = STACK.top;
                }
            }
            temp = temp->next;
            temp2 = STACK.top;
        }
        return PostFix;
    }

    void reverse()
    {
        if (top == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = top;
        Node *prev = current->prev;
        Node *next = nullptr;

        do
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        } while (current != top);
        top = prev;
    }
    bool isOperator(string t)
    {
        if (t == "+" || t == "-" || t == "*" || t == "/" || t == "^")
        {
            return 1;
        }
        return 0;
    }

    double add(double o1, double o2)
    {
        return o1 + o2;
    }
    double sub(double o1, double o2)
    {
        return o1 - o2;
    }
    double multiply(double o1, double o2)
    {
        return o1 * o2;
    }
    double divide(double o1, double o2)
    {
        return o1 / o2;
    }

    double calculate(double opnd1, double opnd2, string oprtr)
    {

        double result = 0;
        if (oprtr == "+")
        {
            result = add(opnd1, opnd2);
        }
        else if (oprtr == "-")
        {
            result = sub(opnd1, opnd2);
        }
        else if (oprtr == "*")
        {
            result = multiply(opnd1, opnd2);
        }
        else if (oprtr == "/")
        {
            result = divide(opnd1, opnd2);
        }
        else if (oprtr == "^")
        {
            result = pow(opnd1, opnd2);
        }
        return result;
    }

    double Evaluate()
    {
        IntStack value;
        Node *temp = this->top;
        double operand1;
        double operand2;
        double result = 0;
        do
        {
            if (!isOperator(temp->data))
            {
                double t = stoi(temp->data);
                value.push(t);
            }
            else
            {
                operand1 = value.pop();
                operand2 = value.pop();
                result = calculate(operand2, operand1, temp->data);
                value.push(result);
            }
            temp = temp->next;
        } while (temp != top);

        return value.pop();
    }
    void i_display()
    {
        if (!top)
        {
            cout << "\nStack is Empty";
        }
        else
        {
            cout << endl;
            Node *temp = this->top;
            while (temp->next != top)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    friend class IntStack;
};

// 12+3*8*(3/4-2)---> for checking purpose
int main()
{
    system("cls");
    Stack s;
    string input;
    cout << "\nEnter Infix Expression (WITHOUT SPACES): \n";
    cin >> input;
    s.readInfix(input);
    system("cls");
    cout << "\nInfix: ";
    s.reverse();
    s.i_display();

    Stack s2;
    s2 = s.InfixToPostFix();
    cout << "\nPostfix: ";
    s2.reverse();
    s2.display();

    cout << "\nValue: \n"
         << s2.Evaluate();
    return 0;
}
