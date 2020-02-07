#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int l,i,pos1,pos2,a_cn=0,b_cn=0,ans;
    l=str.size();
    ans=l;
    for(i=0;i<l;i++)
        if(str[i]=='b')
        {
            pos1=i;
            break;
        }
    for(i=l-1;i>=0;i--)
        if(str[i]=='b')
        {
            pos2=i;
            break;
        }
    for(i=pos1;i<=pos2;i++)
    {
        if(str[i]=='a')
            a_cn++;
        else
            b_cn++;
    }
    ans-=min(a_cn,b_cn);
    cout<<ans<<endl;
    return 0;
}
