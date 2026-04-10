#include<iostream>
#include<string>
#include "CrimeList.h"
#include "InvestigationQueue.h"
#include "CaseHistoryStack.h"
#include "CrimeBST.h"
using namespace std;

string crimeCategories[5]=
{
    "Theft","Murder","Fraud","Cyber Crime","Kidnapping"
};

int main()
{
    CrimeList crimeList;
    InvestigationQueue queue;
    CaseHistoryStack history;
    CrimeBST bst;

    int choice,fir,cat,pos;
    string desc;

    do
    {
        cout<<"\n===== Crime Record Management System =====\n";
        cout<<"1. Add Crime\n";
        cout<<"2. Add Crime at Position\n";
        cout<<"3. Display Crimes\n";
        cout<<"4. Search FIR\n";
        cout<<"5. Delete by FIR\n";
        cout<<"6. Delete at Position\n";
        cout<<"7. View Pending Investigations\n";
        cout<<"8. Process Investigation\n";
        cout<<"9. View History\n";
        cout<<"10. Remove Last History\n";
        cout<<"0. Exit\n";
        cout<<"Choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter FIR: ";
            cin>>fir;
            if(crimeList.firExists(fir))
            {
                cout<<"FIR already exists\n";
                break;
            }

            cout<<"Select Category:\n";
            for(int i=0;i<5;i++)
                cout<<i+1<<". "<<crimeCategories[i]<<endl;
            cin>>cat;

            cout<<"Enter Description: ";
            cin>>desc;

            crimeList.addCrime(fir,crimeCategories[cat-1],desc);
            queue.enqueue(crimeList.getHead());
            history.push("Crime added");
            break;

        case 2:
            cout<<"Enter FIR: ";
            cin>>fir;
            if(crimeList.firExists(fir))
            {
                cout<<"FIR already exists\n";
                break;
            }

            cout<<"Select Category: \n";
            for(int i=0;i<5;i++)
                cout<<i+1<<". "<<crimeCategories[i]<<endl;
            cin>>cat;

            cout<<"\nEnter Description: ";
            cin>>desc;

            cout<<"\nEnter Position: ";
            cin>>pos;

            crimeList.addCrimeAtPosition(fir,crimeCategories[cat-1],desc,pos);
            history.push("Crime added at position");
            break;

        case 3:
            crimeList.displayAll();
            break;

        case 4:
            bst.build(crimeList.getHead());
            cout<<"Enter FIR: ";
            cin>>fir;
            bst.search(fir);
            break;

        case 5:
            cout<<"Enter FIR: ";
            cin>>fir;
            crimeList.deleteCrimeByFIR(fir);
            history.push("Crime deleted");
            break;

        case 6:
            cout<<"Enter Position: ";
            cin>>pos;
            crimeList.deleteCrimeAtPosition(pos);
            history.push("Crime deleted at position");
            break;

        case 7:
            queue.displayPending();
            break;

        case 8:
            queue.dequeue();
            break;

        case 9:
            history.display();
            break;

        case 10:
            history.pop();
            break;
        }
    }
    while(choice!=0);

    return 0;
}

