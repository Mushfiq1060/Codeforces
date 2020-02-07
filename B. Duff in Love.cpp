#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>arr;
map<ll,bool>mp;
map<ll,bool>::iterator it;
void store(ll n)
{
    ll i,s;
    s=sqrt(n);
    for(i=1;i<=s;i++)
        if(n%i==0)
        {
            arr.push_back(i);
            if(i!=(n/i))
                arr.push_back(n/i);
        }
    sort(arr.begin(),arr.end());
}
void per(ll n)
{
    ll i,s;
    s=sqrt(n);
    for(i=2;i<=s;i++)
        mp[i*i]=true;
}
int main()
{
    ll n,i;
    cin>>n;
    store(n);
    per(n);
    for(i=arr.size()-1;i>=0;i--)
    {
        bool flag=true;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(arr[i]%it->first==0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<arr[i]<<endl;
            break;
        }
    }
    return 0;
}
