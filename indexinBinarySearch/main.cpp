#include <iostream>

using namespace std;
// Hackerearth solution

// Simple binary search algorithm
int binarySearch(int arr[], int l, int r, int x)
{
    if (r>=l)
    {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

int findpos(int arr[], int key)
{
    int l = 0, h = 1;
    int val = arr[0];

    // Find h to do binary search
    while (val < key)
    {
        l = h;        // store previous high
        h = 2*h;      // double high index
        val = arr[h]; // update new val
    }

    // at this point we have updated low and
    // high indices, Thus use binary search
    // between them
    return binarySearch(arr, l, h, key);
}
int main()
{
     int i,m,n,qq,arr[10000],q[10000];
    cin>>n;//scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>qq;
    for(i=0;i<qq;i++)
    {
           cin>>q[i];
    }
    for(i=0;i<qq;i++)
    {
        m=findpos(arr,q[i]);
        cout << m+1 <<"\n";
    }
    //printf("Hello World!\n");
    return 0;
}
