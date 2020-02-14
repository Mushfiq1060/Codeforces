#include<bits/stdc++.h>
#define _size 100100
#define inf INT_MAX
using namespace std;
vector<int>graph[_size],weight[_size];
int dist[_size],parent[_size],node,edge;
struct info
{
    int node,cost;
    info(int u,int v)
    {
        node=u;
        cost=v;
    }
    bool operator < (const info& m) const
    {
        return cost>m.cost;
    }
};
void Dijkstra(int src)
{
    bool vis[_size];
    memset(vis,false,sizeof vis);
    for(int i=0;i<=node;i++)
        dist[i]=inf;
    dist[src]=0;
    parent[src]=src;
    priority_queue<info>qu;
    qu.push(info(src,0));
    while(!qu.empty())
    {
        info x=qu.top();
        qu.pop();
        int y=x.node;
        vis[y]=true;
        for(int i=0;i<graph[y].size();i++)
        {
            int p=graph[y][i];
            if(vis[p]==false && dist[y]+weight[y][i]<dist[p])
            {
                dist[p]=dist[y]+weight[y][i];
                //cout<<"in    "<<y<<"   "<<graph[y][i]<<"  "<<dist[p]<<endl;
                qu.push(info(p,dist[p]));
                parent[p]=y;
            }
        }
    }
}
int main()
{
    int u,v,w;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }
    Dijkstra(node);
    if(dist[1]==inf)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int b=1;
    while(b!=node)
    {
        cout<<b<<" ";
        b=parent[b];
    }
    cout<<node<<endl;
    return 0;
}
/**
5 14
1 5 16
1 5 15
1 5 14
1 3 5
1 2 20
1 2 10
2 3 2
2 3 10
3 5 3
2 5 8
2 5 3
1 5 13
5 6 5
4 3 5
**/
