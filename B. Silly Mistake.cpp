#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,a,i,cn=0,flag=0,prev=0;
    cin>>n;
    map<ll,bool>mp,vis;
    vector<ll>arr;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a>0)
        {
            cn++;
            if(mp.count(a)==true)
            {
                flag=1;
                continue;
            }
            mp[a]=true;
        }
        else
        {
            if(mp.count(-a)==false || vis[-a]==true)
            {
                flag=1;
                continue;
            }
            cn--;
            vis[-a]=true;
            if(cn==0)
            {
                arr.push_back(i-prev+1);
                prev=i+1;
                mp.clear();
                vis.clear();
            }
        }
    }
    if(flag || cn>0)
        cout<<"-1"<<endl;
    else
    {
        cout<<arr.size()<<endl;
        for(i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
    }
    return 0;
}
