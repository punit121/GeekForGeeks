#include <iostream>

using namespace std;

int min_f(int a[],int l,int r)
{
    int m = a[l]; // assume a[l] is the minimum element
    for(int i=l;i<=r;i++)
    {
        if(a[i]<m)
        {
         m = a[i];
        }
    }
    return m;
}
int max_f(int a[],int l,int r)
{
    int m = a[l]; // assume a[l] is mx element
    for(int i=l;i<=r;i++)
    {
        if(a[i]>m)
        {
         m = a[i];
        }
    }
    return m;
}

void maxunsorted(int a[],int n)
{
    int l=0,r=n-1,minf,maxf;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
        {
            l++;
        }
        else{
        break;
        }
    }

    for(int j=n-1;j>0;j--)
    {
        if(a[j]>a[j-1])
        {
            r--;
        }
        else{
        break;
        }
    }

    if(l==n-1)
    {
     cout <<"Array is already Sorted";
    }
    else
    {
        //finding minimum element in the sub array q[l,r]
        minf = min_f(a,l,r);
        //
        maxf = max_f(a,l,r);
        int k =0;
        for(int i=0;i<=l;i++)
        {
            if(a[i]<=minf)
            {
                k++;
            }
            else{
        break;
        }
        }
        int q=n-1;
        for(int j=n-1;j>=r;j--)
        {
            if(a[j]>=maxf)
            {
                q--;
            }
            else{
        break;
        }
        }
        for(int i=k;i<=q;i++)
        {
            cout<<i<< " ";
        }
    }

}

int main()
{
   int n,a[10000];
   cin >> n;

   for(int i=0;i<n;i++)
   {
       cin >> a[i];
   }

   maxunsorted(a,n);
    //cout << "Hello world!" << endl;
    return 0;
}
