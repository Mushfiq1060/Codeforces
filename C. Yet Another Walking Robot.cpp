#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string str;
        cin>>str;
        map<pair<int,int>,int>mp;
        mp[{0,0}]=0;
        ll x=0,y=0,ans=1e10,pos1,pos2;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='R')x++;
            else if(str[i]=='L')x--;
            else if(str[i]=='U')y++;
            else y--;
            if(mp.count({x,y})!=0)
            {
                if(ans>=(i-mp[{x,y}]))
                {
                    ans=i-mp[{x,y}];
                    pos1=mp[{x,y}]+1;
                    pos2=i+1;
                }
                mp[{x,y}]=i+1;
            }
            else
                mp[{x,y}]=i+1;
            //cout<<"xy-> "<<x<<" "<<y<<" "<<mp[{x,y}]<<endl;
        }
        if(ans==1e10)
            cout<<"-1"<<endl;
        else
            cout<<pos1<<" "<<pos2<<endl;
    }
    return 0;
}
