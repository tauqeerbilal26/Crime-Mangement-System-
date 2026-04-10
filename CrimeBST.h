#ifndef CRIMEBST_H
#define CRIMEBST_H

#include<iostream>
#include "Crime.h"
using namespace std;

class BSTNode
{
public:
    int fir;
    string type;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int f,string t)
    {
        fir=f;
        type=t;
        left=NULL;
        right=NULL;
    }
};

class CrimeBST
{
private:
    BSTNode* root;

public:
    CrimeBST()
    {
        root=NULL;
    }

    void insert(int fir,string type)
    {
        BSTNode* newNode=new BSTNode(fir,type);

        if(root==NULL)
        {
            root=newNode;
            return;
        }

        BSTNode* current=root;
        BSTNode* parent=NULL;

        while(current!=NULL)
        {
            parent=current;
            if(fir < current->fir)
                current=current->left;
            else
                current=current->right;
        }

        if(fir < parent->fir)
            parent->left=newNode;
        else
            parent->right=newNode;
    }

    void build(Crime* head)
    {
        root=NULL;
        Crime* temp=head;

        while(temp!=NULL)
        {
            insert(temp->fir,temp->type);
            temp=temp->next;
        }
    }

    bool search(int fir)
    {
        BSTNode* current=root;

        while(current!=NULL)
        {
            if(fir==current->fir)
            {
                cout<<"Found FIR "<<current->fir<<" ("<<current->type<<")\n";
                return true;
            }
            else if(fir < current->fir)
                current=current->left;
            else
                current=current->right;
        }

        cout<<"FIR not found\n";
        return false;
    }
};

#endif

