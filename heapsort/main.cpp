#include <iostream>

using namespace std;

void swap_f(int *m,int *n)
{
    int temp;

    temp = *m;
    *m = *n;
    *n = temp;
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && a[l]>a[largest])
        largest = l;
    if(r<n && a[r]>a[largest])
        largest = r;
    if(largest != i)
    {
        swap_f(&a[i],&a[largest]);

        // heapify the sub-tree
        heapify(a,n,largest);
    }


}

void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap_f(&a[0],&a[i]);

        //heaapifying the reduced heap
        heapify(a,i,0);
    }
}
void printarray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n,a[1000];
    cout << "Enter size of array  ";

    cin >> n;

    for(int i = 0;i<n;i++ ){
        cin >> a[i];

    }
    //using heap sort algorithm
    heapsort(a,n);
    // printing the sorted array
    printarray(a,n);
   // cout << "Hello world!" << endl;
    return 0;
}
