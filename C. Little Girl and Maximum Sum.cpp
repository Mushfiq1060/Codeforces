#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,q,pos,x,y,i,sum=0;
    cin>>n>>q;
    ll arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n,greater<int>());
    for(i=1;i<n;i++)
        arr[i]+=arr[i-1];
    while(q--)
    {
        cin>>x>>y;
        pos=y-x+1;
        sum+=arr[pos-1];
    }
    cout<<sum<<endl;
    return 0;
}
