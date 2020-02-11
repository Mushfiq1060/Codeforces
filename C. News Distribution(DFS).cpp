#include<bits/stdc++.h>
#define ll long long
#define _size 500100
using namespace std;
vector<ll>graph[_size];
ll vis[_size],c[_size],xd[_size];
class DFS
{
public:
    void dfs(int node,int color)
    {
        vis[node]=1;
        c[node]=color;
        xd[color]++;
        for(int i=0;i<graph[node].size();i++)
            if(vis[graph[node][i]]==0)
                dfs(graph[node][i],color);
    }
};
int main()
{
    DFS me;
    ll node,m,x,u,prev;
    cin>>node>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        for(int j=0;j<x;j++)
        {
            cin>>u;
            if(j!=0)
            {
                graph[u].push_back(prev);
                graph[prev].push_back(u);
            }
            prev=u;
        }
    }
    /*cout<<"__________________________"<<endl;
    for(int i=1;i<=node;i++)
    {
        cout<<i<<"  :  ";
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }*/
    memset(vis,0,sizeof vis);
    for(int i=1,color=0;i<=node;i++,color++)
    {
        if(vis[i]==0)
            me.dfs(i,color);
        cout<<xd[c[i]]<<" ";
    }
    /*cout<<"_____________________________"<<endl;
    for(int i=1;i<=node;i++)
        cout<<i<<" "<<c[i]<<endl;*/
    return 0;
}
