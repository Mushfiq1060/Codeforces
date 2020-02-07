#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n],sum=0,p,q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        if(i)
            arr[i]+=arr[i-1];
    }
    if(sum%3!=0)
        cout<<0<<endl;
    else
    {
        p=sum/3;
        q=p*2;
        vector<ll>way;
        ll cn=0,ans=0;
        if(arr[0]==p)
            cn++;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]==q)
                way.push_back(cn);
            if(arr[i]==p)
                cn++;
        }
        for(int i=0;i<way.size();i++)
            ans+=way[i];
        cout<<(ans==0?0:ans)<<endl;
    }
    return 0;
}
