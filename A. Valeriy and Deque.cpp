#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m,a,_max=0,pos=100010,x,y,z,p,q,cn=1;
    cin>>n>>m;
    ll temp[n];
    deque<ll>qu;
    deque<ll>::iterator it;
    map<ll,pair<ll,ll> >mp;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        qu.push_back(a);
        if(a>_max)
        {
            _max=a;
            pos=i+1;
        }
    }
    it=qu.begin();
    x=qu.front();
    mp[cn].first=*it;
    it++;
    mp[cn].second=*it;
    cn++;
    while(x!=_max)
    {
        y=x;
        qu.pop_front();
        z=qu.front();
        if(y<z)
        {
            it=qu.begin();
            qu.push_back(y);
            mp[cn].first=*it;
            it++;
            mp[cn].second=*it;
        }
        else
        {
            qu.pop_front();
            qu.push_back(z);
            qu.push_front(y);
            it=qu.begin();
            mp[cn].first=*it;
            it++;
            mp[cn].second=*it;
        }
        x=qu.front();
        cn++;
    }
    cn=0;
    while(!qu.empty())
    {
        temp[cn++]=qu.front();
        qu.pop_front();
    }
    while(m--)
    {
        cin>>x;
        if(mp.count(x))
            cout<<mp[x].first<<" "<<mp[x].second<<endl;
        else
        {
            x-=pos;
            p=x%(n-1);
            p++;
            cout<<temp[0]<<" "<<temp[p]<<endl;
        }
    }
    return 0;
}
