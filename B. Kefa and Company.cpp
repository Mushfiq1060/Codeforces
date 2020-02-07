#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,d,i,a,b,pos1,pos2,ans=0;
    cin>>n>>d;
    ll f_fact[n],money[n];
    vector<pair<ll,ll> >arr;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end());
    f_fact[0]=arr[0].second;
    money[0]=arr[0].first;
    for(i=1;i<n;i++)
    {
        f_fact[i]=f_fact[i-1]+arr[i].second;
        money[i]=arr[i].first;
    }
    if(d!=1)
        d--;
    for(i=0;i<n;i++)
    {
        a=money[i]-d;
        b=money[i]+d;
        pos1=upper_bound(money,money+n,a)-money;
        pos2=(upper_bound(money,money+n,b)-money)-1;
        if(pos1==pos2)
        {
            if(pos1==0)
                ans=max(ans,f_fact[pos1]);
            else
                ans=max(ans,f_fact[pos1]-f_fact[pos1-1]);
        }
        else
        {
            if(pos1==0)
                ans=max(ans,f_fact[pos2]);
            else
                ans= max(ans,f_fact[pos2]-f_fact[pos1-1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
