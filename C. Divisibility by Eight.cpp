#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int i,j,k,l,p=0;
    l=str.size();
    for(i=l-1;i>=0;i--)
    {
        p+=(str[i]-'0');
        if(p%8==0)
        {
            cout<<"YES"<<endl<<p<<endl;
            return 0;
        }
        for(j=i-1;j>=0;j--)
        {
            p+=((str[j]-'0')*10);
            if(p%8==0)
            {
                cout<<"YES"<<endl<<p<<endl;
                return 0;
            }
            for(k=j-1;k>=0;k--)
            {
                p+=((str[k]-'0')*100);
                if(p%8==0)
                {
                    cout<<"YES"<<endl<<p<<endl;
                    return 0;
                }
                p-=((str[k]-'0')*100);
            }
            p-=((str[j]-'0')*10);
        }
        p-=(str[i]-'0');
    }
    cout<<"NO"<<endl;
    return 0;
}
