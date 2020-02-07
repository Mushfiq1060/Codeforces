#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,d;
    cin>>n>>m>>d;
    int arr[m+5],path[n+5];
    memset(path,0,sizeof path);
    for(int i=1;i<=m;i++)
        cin>>arr[i];
    for(int i=n,j=m;i>0 && j>0;j--)
        for(int k=arr[j];k>0;k--)
        {
            path[i]=j;
            i--;
        }
    if(path[1]!=0)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
            cout<<path[i]<<" ";
    }
    else
    {
        int x=1;
        bool flag=false;
        for(int i=0;i<=n;i++)
            if(i+d<=n)
            {
                if(path[i+d]==0)
                {
                    int pos=upper_bound(path+i+d,path+n+1,0)-path;
                    if(x<=m)
                    {
                        for(int k=pos,j=0;j<arr[x];j++)
                            path[k++]=0;
                        for(int k=i+d,j=0;j<arr[x];j++)
                            path[k++]=x;
                        i+=(d+arr[x++]-2);
                    }
                }
            }
        x=1;
        for(int i=0;i<=n;i++)
            if(i+d<=n)
            {
                if(path[i+d]==0)
                    flag=true;
                else
                    i+=d+arr[x++]-2;
            }
        if(flag)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
                cout<<path[i]<<" ";
        }
    }
    return 0;
}

