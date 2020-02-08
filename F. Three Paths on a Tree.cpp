#include<bits/stdc++.h>
#define ll long long
#define _size 200200
using namespace std;
vector<ll>graph[_size];
bool vis[_size];
ll p,y,z=0,level[_size],parent[_size],dis[_size];
ll bfs(int node)
{
    memset(level,0,sizeof level);
    memset(vis,0,sizeof vis);
    memset(parent,0,sizeof parent);
    queue<ll>qu;
    qu.push(node);
    vis[node]=1;
    level[node]=0;
    p=0;
    while(!qu.empty())
    {
        ll x=qu.front();
        qu.pop();
        for(int i=0;i<graph[x].size();i++)
            if(!vis[graph[x][i]])
            {
                ll m;
                m=graph[x][i];
                qu.push(m);
                vis[m]=1;
                level[m]=level[x]+1;
                parent[m]=x;
                if(p<level[m])
                {
                    y=m;
                    p=level[m];
                }
            }
    }
    return y;
}
ll bfs2(int node)
{
    queue<ll>qu;
    qu.push(node);
    vis[node]=1;
    dis[node]=0;
    while(!qu.empty())
    {
        ll x=qu.front();
        qu.pop();
        for(int i=0;i<graph[x].size();i++)
            if(!vis[graph[x][i]])
            {
                ll m=graph[x][i];
                qu.push(m);
                vis[m]=1;
                dis[m]=dis[x]+1;
                if(p<dis[m])
                {
                    p=dis[m];
                    y=m;
                }
            }
    }
    return y;
}
int main()
{
    ll n,u,v,a,b,c,f;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    a=bfs(1);
    b=bfs(a);
    c=b;
    memset(vis,0,sizeof vis);
    vis[a]=1;
    while(parent[b]>0)
    {
        vis[b]=1;
        b=parent[b];
    }
    y=p=0;
    b=c;
    while(parent[b]>0)
    {
        f=bfs2(b);
        b=parent[b];
    }
    cout<<level[c]+dis[f]<<endl;
    if(f==0)
        for(int i=1;i<=n;i++)
            if(i!=a && i!=c)
            {
                f=i;
                break;
            }
    cout<<a<<" "<<c<<" "<<f<<endl;
    return 0;
}
