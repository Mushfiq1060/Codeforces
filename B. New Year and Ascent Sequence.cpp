#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll q,t,i,n,ans,pos;
    cin>>t;
    vector<ll>Max,Min;
    q=t;
    while(t--)
    {
        cin>>n;
        ll a,flag=0,_max=0,_min=1e7;
        ll j=0;
        for(i=0;i<n;i++)
        {
            cin>>a;
            if(a>_min)
                flag=1;
            _min=min(_min,a);
            _max=max(_max,a);
        }
        if(flag==0)
        {
            Max.push_back(_max);
            Min.push_back(_min);
        }
    }
    ans=q*q;
    sort(Max.begin(),Max.end());
    n=Max.size();
    for(i=0;i<Min.size();i++)
    {
        pos=upper_bound(Max.begin(),Max.end(),Min[i])-Max.begin();
        //cout<<Min[i]<<"   "<<pos<<endl;
        ans-=pos;
    }
    cout<<ans<<endl;
    return 0;
}
