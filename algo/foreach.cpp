#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct sum
{
    void operator()(int n) {sum += n;}
    int sum{0};
};
int main()
{
    vector<int> nums{3,4,2,8,15,267};
    auto print = [](const int& n) {cout<<" "<<n;};
    cout << "before";
    for_each(nums.cbegin(),nums.cend(),print);
    cout<<'\n';

    for_each(nums.begin(), nums.end() ,[](int &n){});

}
