#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l1,int r1, int l2, int r2)
{
    int i,j,k;
    int n1=r1-l1+1;
    int n2=r2-l2+1;

    int l[n1], r[n2]; //temp array

    //copy elements in temp array    
    for(i=0;i<n1;i++)  
        l[i]=arr[l1+i];
    for(i=0;i<n2;i++)
        r[i]=arr[l2+i];
        
    i=0;
    j=0;
    k=l1;
    //merge both array into orginal array
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    //appending remaining elements to orginal array
    while(i<n1)
    {
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
    
}

void merge_sort(vector<int> &arr, int start, int end)
{
    if(start>=end) //arr contains only 1 element or invalid array
        return;
    int mid=(start+end)/2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    
    merge(arr, start, mid, mid+1, end);
    
}

int main()
{
    int n=10;
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

    merge_sort(arr,0, n-1);
    
    for(int i=0; i<n;i++)
    {
        cout<< arr[i]<<" ";
    }
    return 0;
}