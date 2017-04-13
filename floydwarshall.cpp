#include<bits/stdc++.h>
#define ll long
#define maxx 10000007
using namespace std;
int main()
{
    ll v,e,i,j,k,l,m,one,two;
    cout<<" Enter no. of edges and no. of vertices\n";
    cin>>v>>e;
    // Vertex numbered from 1 to v;
   ll d[2][v+1][v+1];
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(i==j)
                d[0][i][j]=0;
            else
                d[0][i][j]=maxx;
        }
    }
    while(e--)
    {
        cout<<"Write starting vertex and end vertex and weight\n";
        cin>>i>>j>>k;
        d[0][i][j]=k;
    }
    cout<<" Representing D[0]\n";
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            cout<<d[0][i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    one=0,two=1;
    for(i=1;i<=v;i++)
    {
        cout<<" Prepresenting D["<<i<<"]\n";
        for(j=1;j<=v;j++)
        {
            for(k=1;k<=v;k++)
            {
                l=d[one][j][k];
                m=d[one][j][i]+d[one][i][k];
                d[two][j][k]=min(l,m);
                cout<<d[two][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        swap(one,two);
    }
    return 0;
}
