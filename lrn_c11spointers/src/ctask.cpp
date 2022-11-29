#include "ctask.h"
#include <iostream>
using namespace std;
ctask::ctask(int arg_id) : mid(arg_id)
{
    //ctor
    cout<<"ctask constructor"<<endl;
}
ctask::~ctask()
{
    cout<<"ctask destructor"<<std::endl;
}
