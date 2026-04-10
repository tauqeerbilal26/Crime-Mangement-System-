#ifndef CASEHISTORYSTACK_H
#define CASEHISTORYSTACK_H

#include<iostream>
#include<string>
using namespace std;

class HistoryNode
{
public:
    string update;
    HistoryNode* next;

    HistoryNode(string u)
    {
        update=u;
        next=NULL;
    }
};

class CaseHistoryStack
{
private:
    HistoryNode* top;

public:
    CaseHistoryStack()
    {
        top=NULL;
    }

    void push(string update)
    {
        HistoryNode* temp=new HistoryNode(update);
        temp->next=top;
        top=temp;
    }

    void pop()
    {
        if(top==NULL)
        {
            cout<<"No history\n";
            return;
        }

        HistoryNode* temp=top;
        top=top->next;
        cout<<"Removed: "<<temp->update<<endl;
        delete temp;
    }

    void display()
    {
        HistoryNode* temp=top;

        if(temp==NULL)
        {
            cout<<"No history available\n";
            return;
        }

        while(temp!=NULL)
        {
            cout<<temp->update<<endl;
            temp=temp->next;
        }
    }
};

#endif

