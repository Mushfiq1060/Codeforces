#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,s,i,p;
        cin>>n;
        vector<ll>ans;
        map<ll,ll>_find;
        ans.push_back(0);
        ans.push_back(1);
        _find[1]=1;
        s=sqrt(n);
        for(i=2;i<=s;i++)
        {
            p=n/i;
            if(!_find[p])
            {
                ans.push_back(i);
                if(i!=p)
                    ans.push_back(p),_find[p]=1;
                _find[i]=1;
            }
        }
        if(!_find[n])
            ans.push_back(n);
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

