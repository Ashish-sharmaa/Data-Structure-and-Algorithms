#include<bits/stdc++.h>
#define ll long long
#define maxx 1000000000
using namespace std;
class gg
{
public:
    bool operator () (pair<ll,ll>v1,pair<ll,ll>v2)
    {
        return(v1.second>v2.second);
    }
};
int main()
{
    ll i,j,k,l,v,e,st;
    cout<<"Enter no. of vertices and edges\n";
    cin>>v>>e;
    vector<pair<ll,ll>>s[v+1]; //! 1 based indexing
    ll aa[v+1]; //! To prevent space overflow in priority queue
    ll bb[v+1];  //! To keep track of the path
    for(i=1;i<=v;i++)
        {
            aa[i]=maxx;
            bb[i]=0;
        }
    for(i=1;i<=e;i++)
    {
        cout<<"Enter source, destination and weight\n";
        cin>>j>>k>>l;
        s[j].push_back(make_pair(k,l));   //! destination index and weight of edge
    }
    ll flag[v+1];
    memset(flag,0,sizeof(flag));
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,gg>p; //! No need to use tuple as starting vertex in unnecessary, So pair can also be used
    cout<<"Enter starting index \n";
    cin>>i;
    st=i;
    bb[i]=i;
    aa[st]=0;
    while(1)
    {
        if(i!=st&&p.empty()!=1)
            p.pop();
        flag[i]=1;
        for(auto pos=s[i].begin();pos!=s[i].end();++pos)
        {
            if(flag[pos->first]==0&&pos->second+aa[i]<aa[pos->first])
            {
//                cout<<" element "<<pos->first<<" is updated to "<<pos->second+aa[i]<<" by "<<i<<endl;
                aa[pos->first]=pos->second+aa[i];
                bb[pos->first]=i;
                p.push(make_pair(pos->first,aa[pos->first]));
            }
        }
        while(p.empty()!=1)
        {
            if(flag[p.top().first]==0)
            {
                i=p.top().first;
                break;
            }
            else
                p.pop();
        }
        if(p.empty()==1)
            break;
    }
    for(i=1;i<=v;i++)
    {
        cout<<"Distance between "<<st<<" and "<<i<<" is:";
        if(aa[i]==maxx)
            cout<<"infinite\n";
        else
            cout<<aa[i]<<endl;
        cout<<"And path followed is: ";
        j=i;
        vector<ll>V;
        while(1)
        {
            if(j==0)
                break;
            V.push_back(j);
            if(j==st)
                break;
            j=bb[j];
        }
        if(V.size()==1&&i!=st)
        {
            cout<<" No path\n";
            continue;
        }
        for(auto pos=V.end()-1;pos>=V.begin();--pos)
            cout<<*pos<<" ";
        cout<<endl<<endl;
    }
    return 0;
}
