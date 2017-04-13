#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll val;
    node *ptr;
};
void get_that(ll i,ll b[],ll c[],node a[],ll n,ll &temp)
{
    node *pp;
    deque<ll >s;
    do
    {
        if(s.size()!=0)
            s.pop_front();
        pp=a[i].ptr;
        a[i].val=1;
        while(pp!=NULL)
        {
            if(a[pp->val].val==-1)
            {
                a[pp->val].val=1;
                s.push_back(pp->val);
                temp=temp+c[pp->val];
               // cout<<" element added is "<<pp->val<<endl;
                b[pp->val]=1;
            }
            pp=pp->ptr;
        }
        if(s.size()!=0)
        i=s.front();
    }while(s.size()!=0);
}
int main()
{
    ll i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
    cin>>n>>m;
    node a[n+1],*pp,*head,*first;
    for(i=1;i<=n;i++)
    {
        a[i].val=-1;
        a[i].ptr=NULL;
    }
    while(m--)
    {
        cin>>l>>k;
        pp=&a[l];
        while(pp->ptr!=NULL)
            pp=pp->ptr;
        head=new node;
        head->val=k;
        head->ptr=NULL;
        pp->ptr=head;
        pp=&a[k];
        while(pp->ptr!=NULL)
            pp=pp->ptr;
        head=new node;
        head->val=l;
        head->ptr=NULL;
        pp->ptr=head;
    }/*
    for(i=1;i<=n;i++)
    {
        pp=a[i].ptr;
        cout<<i<<" :";
        while(pp!=NULL)
        {
            cout<<pp->val<<" ";
            pp=pp->ptr;
        }
        cout<<endl;*/
    ll c[n+1],b[n+1];
    for(i=1;i<n+1;i++)
    {
        cin>>c[i];
        b[i]=-1;
    }
    i=1;
    ll temp,res=0;
    while(i<=n)
    {
        j=i;
        if(b[j]==-1)
        {
            //cout<<" entry by :"<<j<<endl;
            temp=c[j];
            b[j]=1;
            get_that(j,b,c,a,n,temp);
            if(temp>res)
                res=temp;
                     //   cout<<" temp is "<<temp<<endl;

        }
        i++; }

    cout<<res<<endl;
    }
    return 0;
}
