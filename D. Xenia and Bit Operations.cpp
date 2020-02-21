#include<bits/stdc++.h>
#define ll long long
#define _size 500100
#define inf INT_MAX
using namespace std;
ll arr[_size],tree[_size],op;
bool flag;
bool build_tree(ll left,ll right,ll idx)
{
    if(left==right)
    {
        tree[idx]=arr[left];
        return true;
    }
    ll mid=(left+right)/2;
    flag=build_tree(left,mid,idx*2+1);
    flag=build_tree(mid+1,right,idx*2+2);
    if(flag)
    {
        tree[idx]=tree[idx*2+1]|tree[idx*2+2];
        return false;
    }
    else
    {
        tree[idx]=tree[idx*2+1]^tree[idx*2+2];
        return true;
    }
}
bool update(ll left,ll right,ll idx,ll val,ll pos)
{
    if(left==right)
    {
        tree[idx]=val;
        return true;
    }
    ll mid=(left+right)/2;
    if(pos<=mid)
        flag=update(left,mid,idx*2+1,val,pos);
    else if(pos>mid)
        flag=update(mid+1,right,idx*2+2,val,pos);
    if(flag)
    {
        tree[idx]=tree[idx*2+1]|tree[idx*2+2];
        return false;
    }
    else
    {
        tree[idx]=tree[idx*2+1]^tree[idx*2+2];
        return true;
    }
}
int main()
{
    ll n,query,p;
    cin>>n>>query;
    p=n;
    n=1;
    for(int i=0;i<p;i++)
        n*=2;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build_tree(0,n-1,0);
    while(query--)
    {
        ll idx,val;
        cin>>idx>>val;
        update(0,n-1,0,val,idx-1);
        cout<<tree[0]<<endl;
    }
    return 0;
}
