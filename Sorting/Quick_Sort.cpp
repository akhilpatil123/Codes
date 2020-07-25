#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int a, int b)
{
    int t=arr[a];
    arr[a]=arr[b];
    arr[b]=t;
}

int partition(vector<int> &arr, int start, int end)
{
    int pivot_index=start;
    int pivot_element=arr[end];
    
    for(int i=start; i<=end-1; i++)
    {
        if(arr[i]<=pivot_element)
        {
            swap(arr, i, pivot_index);
            pivot_index++;
        }
        
    }
    
    swap(arr, pivot_index, end);
    return pivot_index;
}

void quick_sort(vector<int> &arr, int start, int end)
{
    if(start>=end)
        return;
    int pivot_index=partition(arr, start, end);
    quick_sort(arr, start, pivot_index-1);
    quick_sort(arr,pivot_index+1, end);
}

int main()
{
    int n=10;
    int v=0;
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(8);
    arr.push_back(99);
    arr.push_back(5);
    arr.push_back(70);
    arr.push_back(1);
    arr.push_back(26);
    arr.push_back(74);
    arr.push_back(11);

    quick_sort(arr,0, n-1);
    
    for(int i=0; i<n;i++)
    {
        cout<< arr[i]<<" ";
    }
    return 0;
}