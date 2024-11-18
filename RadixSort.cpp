#include<iostream>
using namespace std;

int Max(int arr[], int num)
{
    int max = arr[0];
    for (int i = 1; i < num; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countsort(int arr[], int num, int mod)
{
    int output[num];
    int i, count[10] = { 0 };
    for (i = 0; i < num; i++)
        count[(arr[i] / mod) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = num - 1; i >= 0; i--)
    {
        output[count[(arr[i] / mod) % 10] - 1] = arr[i];
        count[(arr[i] / mod) % 10]--;
    }
    for (i = 0; i < num; i++)
        arr[i] = output[i];

}

void radixsort(int arr[], int num)
{
    int m = Max(arr, num);
    for (int mod = 1; m / mod > 0; mod *= 10)
        countsort(arr, num, mod);
}

int main()
{
    int num;
    cout<<"Enter number of elements present in array:";
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    radixsort(arr, num);
    for (int i = 0; i < num; i++)
        cout << arr[i] << " ";
}
