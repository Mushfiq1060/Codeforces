#include<bits/stdc++.h>
#define ll long long
#define mod  1000000007
using namespace std;
int main()
{
    ll x,y,n,ans;
    cin>>x>>y>>n;
    ll arr[7]={0,x,y,y-x,-x,-y,-y+x};
    if(n%6==0)
    {
        ans=arr[6]%mod;
        if(ans<0)
            ans+=mod;
        cout<<ans<<endl;
    }
    else
    {
        ans=arr[n%6]%mod;
        if(ans<0)
            ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}
