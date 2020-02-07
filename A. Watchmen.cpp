#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i,x,y,cn=0,p,q,ans=0;
    cin>>n;
    map<ll,ll>mpx,mpy;
    map<ll,ll>::iterator it;
    map<pair<ll,ll>,ll>same;
    map<pair<ll,ll>,ll>::iterator point;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        mpx[x]++;
        mpy[y]++;
        same[{x,y}]++;
    }
    for(it=mpx.begin();it!=mpx.end();it++)
    {
        p=it->second;
        p--;
        ans+=((p*(p+1))/2);
    }
    for(it=mpy.begin();it!=mpy.end();it++)
    {
        p=it->second;
        p--;
        ans+=((p*(p+1))/2);
    }
    for(point=same.begin();point!=same.end();point++)
    {
        p=point->second;
        p--;
        ans-=((p*(p+1))/2);
    }
    cout<<ans<<endl;
    return 0;
}





























