#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,ll> >graph[105];
bool bfs(int u,int v,int color)
{
    queue<int>qu;
    int vis[105];
    memset(vis,-1,sizeof vis);
    qu.push(u);
    vis[u]=1;
    while(!qu.empty())
    {
        int x=qu.front();
        qu.pop();
        for(int i=0;i<graph[x].size();i++)
        {
            if(graph[x][i].second==color && vis[graph[x][i].first]==-1)
            {
                qu.push(graph[x][i].first);
                vis[graph[x][i].first]=1;
                if(graph[x][i].first==v)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    int node,edge,u,v,color;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>color;
        graph[u].push_back(make_pair(v,color));
        graph[v].push_back(make_pair(u,color));
    }
    int q;
    cin>>q;
    while(q--)
    {
        int cn=0;
        cin>>u>>v;
        for(int i=1;i<=edge;i++)
            if(bfs(u,v,i))
                cn++;
        cout<<cn<<endl;
    }
    return 0;
}
