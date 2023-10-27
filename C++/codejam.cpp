#include<bits/stdc++.h>
using namespace std;
int min(int *arr,int i,int n)
{
    int min=arr[i];
    for(int it=i;it<n;it++)
    {
        if(arr[it]<arr[min])
        min=it;
    }
    // cout<<min<<" ";
    return min;
}

int rev(int *arr,int i,int j)
{
    for(int it=i,jt=j;it<jt;it++,jt--)
    {   int tmp;
        tmp=arr[it];
        arr[it]=arr[jt];
        arr[jt]=tmp;
    }
    
    return j-i+1;
}
void fun()
{
    int n,s=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int j;
        j=min(arr,i,n);
        // cout<<"n "<<n<<"\n";
        s+=rev(arr,i,j);
    }
    cout<<s<<"\n";
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case #"<<i+1<<":";
        fun();
    }
    return 0;
}