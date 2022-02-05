#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+1],s=0,d=0,p,t=0;
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0,j=n-1; i<=j;)
    {
        if(a[i]>a[j])
        {
            p=a[i];
            i++;
        }
        else
        {
            p=a[j];
            j--;
        }
        if(t&1)s+=p;
        else d+=p;
        t++;
        cout << t << endl;
    }
    cout<<d<<" "<<s<<endl;
}
