#ifndef INVESTIGATIONQUEUE_H
#define INVESTIGATIONQUEUE_H

#include<iostream>
#include "Crime.h"
using namespace std;

class QueueNode
{
public:
    Crime* crime;
    QueueNode* next;

    QueueNode(Crime* c)
    {
        crime=c;
        next=NULL;
    }
};

class InvestigationQueue
{
private:
    QueueNode* front;
    QueueNode* rear;

public:
    InvestigationQueue()
    {
        front=rear=NULL;
    }

    void enqueue(Crime* c)
    {
        QueueNode* temp=new QueueNode(c);

        if(front==NULL)
            front=rear=temp;
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }

    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"No pending investigations\n";
            return;
        }

        QueueNode* temp=front;
        front=front->next;

        cout<<"Processed FIR: "<<temp->crime->fir<<endl;
        delete temp;

        if(front==NULL)
            rear=NULL;
    }

    void displayPending()
    {
        QueueNode* temp=front;

        if(temp==NULL)
        {
            cout<<"No pending investigations\n";
            return;
        }

        while(temp!=NULL)
        {
            cout<<"Pending FIR: "<<temp->crime->fir<<" ("<<temp->crime->type<<")\n";
            temp=temp->next;
        }
    }
};

#endif

