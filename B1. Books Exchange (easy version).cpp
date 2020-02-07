#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+5],ans[n+5];
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        for(int i=1;i<=n;i++)
        {
            int cn=1,pos=arr[i],p;
            while(i!=pos)
            {
                cn++;
                pos=arr[pos];
            }
            cout<<cn<<" ";
        }
        cout<<endl;
    }
    return 0;
}
