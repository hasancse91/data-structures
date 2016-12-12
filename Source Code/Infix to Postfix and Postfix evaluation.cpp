#include<bits/stdc++.h>

using namespace std;

string convertInfixToPostfix(string infix);
int operatorPrecedence(char ch);
int evaluatePostfixExpression(string postfix);
int calculate(int a, int b, char operatorSign);

int main()
{
    string infixExpression, postfixExpression;
    int result;

    infixExpression = "(1+(2^3)*4)/3"; //"(A+(B^C)*D)/C" 123^4*+3/

    postfixExpression = convertInfixToPostfix(infixExpression);

    cout<<"Infix Expression: "<<infixExpression<<endl;
    cout<<"Postfix Expression: "<<postfixExpression<<endl;

    result = evaluatePostfixExpression(postfixExpression);

    cout<<"\nResult is: "<<result<<endl;

    return 0;
}

string convertInfixToPostfix(string infix)
{
    string postfix = "";
    stack <char> myStack;
    char ch;

    for(int i=0; infix[i]; i++)
    {
        ch = infix[i];

        if(ch=='(') //if found opening bracket
            myStack.push(ch);
        else if(ch==')') //if found closing bracket
        {
            while(!myStack.empty() && myStack.top()!='(')
            {
                postfix = postfix + myStack.top();
                myStack.pop();
            }

            if(!myStack.empty() && myStack.top()=='(')
               myStack.pop();

        }
        else //found operator or operand
        {
            int priority = operatorPrecedence(ch); //^ is highest, then * and /. then + and -

            if(priority==0) //found operand
                postfix = postfix + ch;
            else //found operator
            {
                if(myStack.empty())
                    myStack.push(ch);
                else
                {
                    while(!myStack.empty()
                          && myStack.top()!='('
                            && priority<=operatorPrecedence(myStack.top()))
                    {
                        postfix = postfix + myStack.top();
                        myStack.pop();
                    }
                    myStack.push(ch);
                }

            }
        }
    }

    while(!myStack.empty())
    {
        postfix += myStack.top();
        myStack.pop();
    }

    return postfix;
}

int evaluatePostfixExpression(string postfix)
{
    stack <int> myStack;
    char ch;
    //1 2 3 ^ 4 * + 3 /
    for(int i=0; postfix[i]; i++)
    {
        ch = postfix[i];
        if(ch>='0' && ch<='9') //found operand
            myStack.push(ch-'0'); //char to int conversion
        else //found operator
        {
            int a,b;
            b = myStack.top();
            myStack.pop();

            a = myStack.top();
            myStack.pop();

            myStack.push(calculate(a, b, ch));
        }
    }

    return myStack.top();
}

int calculate(int a, int b, char operatorSign)
{
    if(operatorSign=='+')
        return a+b;
    else if(operatorSign=='-')
        return a-b;
   else if(operatorSign=='*')
        return a*b;
   else if(operatorSign=='/')
        return a/b;
     else if(operatorSign=='^')
        return pow(a,b);

}

int operatorPrecedence(char ch)
{
    if(ch=='^')
        return 3; //highest priority for exponential operator
    else if(ch=='/' || ch=='*')
        return 2; //high priority than + or - operator
    else if(ch=='+' || ch=='-')
        return 1; //lowest priority among operators
    else
        return 0; //works for operands

}

