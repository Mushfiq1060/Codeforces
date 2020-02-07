#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,k,i,j;
    cin>>n>>k;
    string str,ans;
    cin>>str;
    ans=str;
    for(i=0;i<k;i++)
        for(j=i;j<n;j+=k)
            ans[j]=str[i];
    if(ans>=str)
        cout<<n<<endl<<ans<<endl;
    else
    {
        for(i=k-1;i>=0;i--)
        {
            if(ans[i]=='9')
                for(j=i;j<n;j+=k)
                    ans[j]='0';
            else
            {
                for(j=i;j<n;j+=k)
                    ans[j]++;
                break;
            }
        }
        cout<<n<<endl<<ans<<endl;
    }
    return 0;
}
