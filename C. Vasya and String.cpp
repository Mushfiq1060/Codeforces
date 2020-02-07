#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,k,i,j=0,a_cn=0,b_cn=0,ans=0;
    cin>>n>>k;
    string str;
    cin>>str;
    for(i=0;i<n;i++)
    {
        if(str[i]=='a')
            a_cn++;
        else
            b_cn++;
        if(a_cn>k && b_cn>k)
        {
            ans=max(ans,i-j);
            (str[j]=='a')?a_cn--:b_cn--;
            j++;
        }
        if(i==n-1 && a_cn>=k && b_cn>=k )
        {
            ans=max(ans,i-j+1);
            break;
        }
    }
    if(ans==0)
        ans=n;
    cout<<ans<<endl;
    return 0;
}
