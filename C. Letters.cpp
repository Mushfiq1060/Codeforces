#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m,i;
    cin>>n>>m;
    ll arr[n+10],letter[m],pos;
    arr[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    for(i=0;i<m;i++)
    {
        cin>>letter[i];
        pos=lower_bound(arr,arr+n,letter[i])-arr;
        cout<<pos<<" "<<letter[i]-arr[pos-1]<<endl;
    }
    return 0;
}
