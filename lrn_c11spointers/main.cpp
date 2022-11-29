#include <iostream>
#include <memory>
#include "ctask.h"
using namespace std;

int main()
{
    cout << "start of main function" << endl;
    unique_ptr<ctask> taskptr(new ctask(23));
    if(taskptr != nullptr) {cout<<"taskptr is not nullptr"<<endl;}
    else {cout<<"taskptr is nullptr"<<endl;}
    int id = taskptr->mid;
    cout<<id<<endl;

    unique_ptr<int> upi;
    if(upi != nullptr) {cout<<"upi is not nullptr"<<endl;}
    else {cout<<"upi is nullptr"<<endl;}
    return 0;
}
