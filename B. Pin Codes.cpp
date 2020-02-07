#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,k,cn=0,flag;
        cin>>n;
        string str[n],ans[n],dup;
        map<string,int>mp;
        for(i=0;i<n;i++)
        {
            cin>>str[i];
            mp[str[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(mp[str[i]]==1)
                ans[i]=str[i];
            else
            {
                dup=str[i];
                flag=0;
                for(j=0;j<4;j++)
                {
                    for(k=0;k<10;k++)
                    {
                        dup[j]=k+'0';
                        if(!mp[dup])
                        {
                            cn++;
                            mp[dup]++;
                            mp[str[i]]--;
                            ans[i]=dup;
                            flag=1;
                            break;
                        }
                    }
                    dup=str[i];
                    if(flag)
                        break;
                }
            }
        }
        cout<<cn<<endl;
        for(i=0;i<n;i++)
            cout<<ans[i]<<endl;
    }
    return 0;
}
