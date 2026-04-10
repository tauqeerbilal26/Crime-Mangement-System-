#ifndef CRIME_H
#define CRIME_H

#include<string>
using namespace std;

class Crime
{
public:
    int fir;
    string type;
    string description;
    Crime* next;

    Crime(int f,string t,string d)
    {
        fir=f;
        type=t;
        description=d;
        next=NULL;
    }
};

#endif

