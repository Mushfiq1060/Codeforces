#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        ll arr[n+10],g_req,g=1,b=0,s=0,flag=0,pos,p,fl=0;
        for(i=1;i<=n;i++)
            cin>>arr[i];
        if(n<5)
        {
            cout<<"0 0 0"<<endl;
            continue;
        }
        g_req=(n/3)-1;
        for(i=1;i<n;i++)
        {
            if(arr[i]==arr[i+1])
                g++;
            else
                break;
        }
        if(g>g_req)
        {
            cout<<"0 0 0"<<endl;
            continue;
        }
        if(arr[n/2]==arr[(n/2)+1])
        {
            for(i=n/2;i>g;i--)
                if(arr[i]!=arr[i-1])
                {
                    pos=i-1;
                    flag=1;
                    break;
                }
            if(flag)
                for(i=pos;i>g;i--)
                {
                    if(arr[i]==arr[i-1])
                        b++;
                    else
                    {
                        b++;
                        if(b>g)
                        {
                            p=i;
                            fl=1;
                            break;
                        }
                    }
                    if(fl)
                        break;
                }
        }
        else
            for(i=n/2;i>=g;i--)
            {
                if(arr[i]!=arr[i-1])
                {
                    b++;
                    if(b>g)
                    {
                        p=i;
                        fl=1;
                    }
                    flag=1;
                }
                else
                    b++;
                if(fl)
                    break;
            }
        if(flag==0 || fl==0)
        {
            cout<<"0 0 0"<<endl;
            continue;
        }
        s=p-g-1;
        if(s==0 || (g>=b) || (g>=s))
        {
            cout<<"0 0 0"<<endl;
            continue;
        }
        cout<<g<<" "<<s<<" "<<b<<endl;
    }
    return 0;
}

