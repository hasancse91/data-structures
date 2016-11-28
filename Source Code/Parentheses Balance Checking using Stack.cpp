#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[10] = "((())())";

    stack<char> myStack;

    for(int i=0; str[i]; i++)
    {
        if(!myStack.empty() && myStack.top()=='(' && str[i]==')')
            myStack.pop();
        else
            myStack.push(str[i]);
    }

    if(myStack.empty())
        printf("%s is Balanced\n", str);
    else
        printf("%s is Not-balanced\n", str);


    return 0;
}

