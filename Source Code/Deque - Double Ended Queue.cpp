/*
    Deque - Double-Ended Queue implementation with C++ STL
    Programmed by Hasan Abdullah
    Contact: http://hellohasan.com
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int choise, data;
    deque<int> myDeque;
    deque<int>::iterator it;

    while(true)
    {
        cout<<"\n\nChoose anyone:\n";
        cout<<"1. push_front()\t2. push_back()\t3. pop_front()\t 4. pop_back()\n";
        cout<<"5. front()\t 6. back()\t 7. clear()\t 8. show all elements\t 9. exit\n\n";

        cin>>choise;
        if(choise==1)
        {
            cout<<"Enter an integer to push it front\n";
            cin>>data;
            myDeque.push_front(data);
        }
        else if(choise==2)
        {
            cout<<"Enter an integer to push it back\n";
            cin>>data;
            myDeque.push_back(data);
        }
        else if(choise==3)
        {
            if(!myDeque.empty())
                myDeque.pop_front();
            else
                cout<<"Deque is empty!\n";
        }
        else if(choise==4)
        {
            if(!myDeque.empty())
                myDeque.pop_back();
            else
                cout<<"Deque is empty!\n";
        }
        else if(choise==5)
        {
            cout<<"Top front element is: "<<myDeque.front();
        }
        else if(choise==6)
        {
            cout<<"Top back element is: "<<myDeque.back();
        }
        else if(choise==7)
        {
            myDeque.clear();
            cout<<"Deque is clear now!\n";
        }
        else if(choise==8)
        {
            if(!myDeque.empty())
            {
                cout<<endl<<"Full Deque is:\n";
                for(it=myDeque.begin(); it != myDeque.end(); it++)
                    cout<<*it<<endl;
                cout<<endl;
            }
            else
                cout<<"Deque is empty!\n";

        }
        else if(choise==9)
            break;
        else
            cout<<"Invalid input!\n";

    }


    return 0;
}
