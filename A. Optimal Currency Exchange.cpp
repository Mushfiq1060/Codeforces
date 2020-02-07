#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,d,e;
    cin>>n>>d>>e;
    e*=5;
    if(e>n)
        cout<<n%d<<endl;
    else
    {
        ll ans=1e12;
        for(int i=0;i*e<=n;i++)
            ans=min(ans,(n-(i*e))%d);
        cout<<ans<<endl;
    }
    return 0;
}
