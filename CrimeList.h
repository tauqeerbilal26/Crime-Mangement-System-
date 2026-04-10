#ifndef CRIMELIST_H
#define CRIMELIST_H

#include<iostream>
#include "Crime.h"
using namespace std;

class CrimeList
{
private:
    Crime* head;

public:
    CrimeList()
    {
        head=NULL;
    }

    Crime* getHead()
    {
        return head;
    }

    bool firExists(int fir)
    {
        Crime* temp=head;
        while(temp!=NULL)
        {
            if(temp->fir==fir)
                return true;
            temp=temp->next;
        }
        return false;
    }

    void addCrime(int fir,string type,string desc)
    {
        Crime* temp=new Crime(fir,type,desc);
        temp->next=head;
        head=temp;
    }

    void addCrimeAtPosition(int fir,string type,string desc,int pos)
    {
        Crime* newNode=new Crime(fir,type,desc);

        if(pos<=1 || head==NULL)
        {
            newNode->next=head;
            head=newNode;
            return;
        }

        Crime* temp=head;
        int count=1;

        while(temp->next!=NULL && count<pos-1)
        {
            temp=temp->next;
            count++;
        }

        newNode->next=temp->next;
        temp->next=newNode;
    }

    void deleteCrimeByFIR(int fir)
    {
        if(head==NULL)
        {
            cout<<"No records\n";
            return;
        }

        if(head->fir==fir)
        {
            Crime* del=head;
            head=head->next;
            delete del;
            cout<<"Crime deleted\n";
            return;
        }

        Crime* temp=head;
        while(temp->next!=NULL && temp->next->fir!=fir)
            temp=temp->next;

        if(temp->next==NULL)
        {
            cout<<"FIR not found\n";
            return;
        }

        Crime* del=temp->next;
        temp->next=del->next;
        delete del;
        cout<<"Crime deleted\n";
    }

    void deleteCrimeAtPosition(int pos)
    {
        if(head==NULL)
        {
            cout<<"No records\n";
            return;
        }

        if(pos<=1)
        {
            Crime* del=head;
            head=head->next;
            delete del;
            cout<<"Crime deleted\n";
            return;
        }

        Crime* temp=head;
        int count=1;

        while(temp->next!=NULL && count<pos-1)
        {
            temp=temp->next;
            count++;
        }

        if(temp->next==NULL)
        {
            cout<<"Invalid position\n";
            return;
        }

        Crime* del=temp->next;
        temp->next=del->next;
        delete del;
        cout<<"Crime deleted\n";
    }

    void displayAll()
    {
        Crime* temp=head;
        int pos=1;

        if(temp==NULL)
        {
            cout<<"No crimes available\n";
            return;
        }

        while(temp!=NULL)
        {
            cout<<"\nPosition: "<<pos++;
            cout<<"\nFIR: "<<temp->fir;
            cout<<"\nType: "<<temp->type;
            cout<<"\nDescription: "<<temp->description<<endl;
            temp=temp->next;
        }
    }
};

#endif

