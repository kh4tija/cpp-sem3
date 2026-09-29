#include <iostream>
using namespace std;
void sumOfSquaresByParity(int arr[], int n, int result[])
{
    int odd=0, even=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2==0)
        {
            even += arr[i]*arr[i];
        }
        else
        {
            odd += arr[i]*arr[i];
        }
    }
    result[0] = even;
    result[1] = odd;
}
int main()
{
    int arr[]={1,3,5};
    int n= 3;
    int result[2];
    sumOfSquaresByParity(arr, n, result);
    cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;
    return 0;
}