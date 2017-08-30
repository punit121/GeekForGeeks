#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int l,int r){
    int pivot = a[r],i=l;
        for(int j=0;j<r;j++){
            if(a[j]<pivot){
                swap(&a[j],&a[i]);
                i++;
            }

        }
        swap(&a[i+1],&a[r]);
        return i+1;


}

int kthsmallest(int  a[],int l, int r, int k){
    if(k>0&&k<r-l+1){

        int pos = partition(a,l,r);

        if(pos-l==k-1){
            return a[pos];
        }
        else if(pos-l>k-1){
            return kthsmallest(a,l,pos-1,k);
        }
        return kthsmallest(a,pos+1,r,k-pos+l-1);

    }

}

int main()
{
    int a[100],n,k;

    cout << "Enter Size of Array  ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter K :  ";
    cin>>k;

    cout<<"Kth Smallest Number is: "<<kthsmallest(a,0,n-1,k);

  //  cout << "Hello world!" << endl;
    return 0;
}
