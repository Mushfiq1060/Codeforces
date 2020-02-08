#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n],vessel[n],link[n],q;
    memset(vessel,0,sizeof vessel);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        link[i]=i+1;
    cin>>q;
    while(q--)
    {
        ll ch,p,x,flag=0;
        cin>>ch;
        if(ch==2)
        {
            cin>>p;
            p-=1;
            cout<<vessel[p]<<endl;
        }
        else
        {
            cin>>p>>x;
            p-=1;
            ll rem=x,q,r;
            r=p;
            while(rem>0&&p<n)
            {
                if(vessel[p]<arr[p])
                {
                    q=vessel[p];
                    vessel[p]+=min(rem,abs(arr[p]-vessel[p]));
                    rem-=min(rem,abs(arr[p]-q));
                }
                if(vessel[p]>=arr[p])
                    p=link[p],flag=1;
            }
            if(flag)
                link[r]=p;
        }
    }
    return 0;
}
