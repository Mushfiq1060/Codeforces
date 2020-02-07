#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i;
    cin>>n;
    while(n--)
    {
        ll m,a;
        cin>>m;
        ll _max[m+10],_min[m+10],pos[m+10],ans[m+10];
        for(i=1;i<=m;i++)
        {
            cin>>a;
            pos[a]=i;
        }
        _max[1]=pos[1];
        _min[1]=pos[1];
        for(i=2;i<=m;i++)
        {
            _max[i]=max(pos[i],_max[i-1]);
            _min[i]=min(pos[i],_min[i-1]);
        }
        for(i=1;i<=m;i++)
        {
            //cout<<i<<" "<<_max[i]<<" "<<_min[i]<<endl;
            if(_max[i]-_min[i]==i-1)
                ans[i]=1;
            else
                ans[i]=0;
        }
        for(i=1;i<=m;i++)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
