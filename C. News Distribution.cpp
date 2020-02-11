///With DSU

#include<bits/stdc++.h>
#define _size 500500
using namespace std;
int parent[_size],_rank[_size];
class dsu
{
public:
    void makeset(int n)
    {
        for(int i=1;i<=n;i++)
            parent[i]=i,_rank[i]=0;
    }
    int _find(int x)
    {
        if(parent[x]!=x)
            parent[x]=_find(parent[x]);
        return parent[x];
    }
    void _union(int u,int v)
    {
        int x=_find(u),y=_find(v);
        if(x==y)
            return;
        else if(_rank[x]>_rank[y])
            parent[y]=x,_rank[x]+=_rank[y]+1;
        else if(_rank[x]<_rank[y])
            parent[x]=y,_rank[y]+=_rank[x]+1;
        else
        {
            parent[y]=x;
            _rank[x]+=_rank[y]+1;
        }
    }
};
int main()
{
    dsu ds;
    int n,m,t,u,prev;
    cin>>n>>m;
    ds.makeset(n);
    for(int i=0;i<m;i++)
    {
        cin>>t;
        for(int j=0;j<t;j++)
        {
            cin>>u;
            if(j>0)
                ds._union(prev,u);
            prev=u;
        }
    }
    int par;
    /*cout<<"_____________________________________________"<<endl;
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<_rank[i]<<endl;*/
    for(int i=1;i<=n;i++)
    {
        par=ds._find(i);
        //cout<<i<<" "<<par<<" "<<_rank[i]<<endl;
        cout<<_rank[par]+1<<" ";
    }
    return 0;
}

