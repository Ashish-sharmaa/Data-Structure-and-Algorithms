#include<bits/stdc++.h>
#define ll long long
#define maxx 100000007
using namespace std;
int main()
{
    ll v,e,i,j,k,l,n,ans,p;
    cout<<"Enter no. of vertices and edges\n";
    cin>>v>>e;
    vector<pair<ll,ll>>s[v+1]; //! Destination index and weight of edge
    while(e--)
    {
        cout<<"Enter source, destination and edge weight\n";
        cin>>i>>j>>k;
        s[i].push_back(make_pair(j,k));
    }
    //!Assuming source vertex as 1
    ll a[v+1];
    a[1]=1;
    i=1;
    j=1;
    deque<ll>q;
    while(1) //! O(e) (As in worst case, every vertex at each stage would have edge to every vertex of next stage, so total no. of times loop will traversed = no. of edges
    {
        for(auto pos=s[i].begin();pos!=s[i].end();++pos)
        {
            a[pos->first]=a[i]+1;
            if(a[i]+1>j)
                j=a[i]+1;          //! j represents total no. of stages
            q.push_back(pos->first);
        }
        if(q.empty()==1)
            break;
        i=q.front();
        q.pop_front();
    }
//    for(i=1;i<=v;i++)
//        cout<<a[i]<<" ";
//    cout<<endl;
    vector<ll>m[j+1];
    for(i=1;i<=v;i++) //! O(v)
    {
        m[a[i]].push_back(i);
    }
//    for(i=1;i<=j;i++)
//    {
//        cout<<" key value "<<i<<" :";
//        for(auto pos=m[i].begin();pos!=m[i].end();++pos)
//            cout<<*pos<<" ";
//        cout<<endl;
//    }
    ll b[v+1],c[v+1]; //! b for finding min. path length from each vertex to the destination and c to keep track of stage chosen to reach destination
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(i=j-1;i>=1;i--) //!O(e) as we have to traversed every edge of corresponding to every vertex
    {
        for(auto pos=m[i].begin();pos!=m[i].end();++pos)
        {
            k=*pos;
            ans=maxx;
            for(auto pos1=s[k].begin();pos1!=s[k].end();++pos1)
            {
                if((b[pos1->first]+pos1->second)<ans)
                {
                    ans=b[pos1->first]+pos1->second;
                    p=pos1->first;
                }
            }
            b[k]=ans;
            c[k]=p;
        }
    }
    cout<<b[1]<<endl;
    i=1;
    cout<<" Path traversed : 1 ";
    while(c[i]!=0)
    {
        cout<<c[i]<<" ";
        i=c[i];
    }
    return 0;
}

