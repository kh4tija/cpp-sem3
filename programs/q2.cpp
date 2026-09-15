#include <iostream>
using namespace std;
int main()
{
    int nums[] = {2,7,11,15};
    int n=4;
    int target=9;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (nums[i]+nums[j]==target)
            {
                cout<<"["<<i<<","<<j<<"]"<<endl;
                return 0;
            }
        }
    }
}