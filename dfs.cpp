#include<bits/stdc++.h>
using namespace std;
#define ll long
struct node
{
    int val;
    node*ptr;
};
void dfs(node s[],ll vert,ll &res,ll lim)
{
    //cout<<" currently on element "<<vert<<endl;
    s[vert].val=1;
   node *pp=s[vert].ptr;
    while(pp!=NULL)
    {
        ll w=pp->val;
        if(w==lim)
            res++;
        else if(s[w].val!=1)
        {
            dfs(s,w,res,lim);
        }
        pp=pp->ptr;
    }
    s[vert].val=0;
}
int main()
{
    ll i,j,k,n,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n][n],res=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                cin>>a[i][j];
        }
        //Creating adjacency list
        node s[n*n+1],*pp,*head,*temp; //write condition for n=1;
        if(n==1)
        {
            if(a[n-1]==0)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        else{
        for(i=0;i<=n*n;i++)
        {
            s[i].val=0;
            s[i].ptr=NULL;
        }
        ll left,right,up,down;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                ll index[4]={};               //[0]=up,[1]=down, [2]=left, [3]=right;
                if(a[i][j]==0)
                {                //Not valid for a[i][j]=1;
                if(j!=n-1)
                {
                    if(a[i][j+1]==0)
                        index[3]=1;
                    if(i!=0)
                    {
                        if(a[i-1][j]==0)
                            index[0]=1;
                    }
                    if(i!=n-1)
                    {
                        if(a[i+1][j]==0)
                            index[1]=1;
                    }
                }
                if(j!=0)
                {
                    if(a[i][j-1]==0)
                        index[2]=1;
                        if(j==n-1)
                        {
                            if(i!=0)
                        {
                        if(a[i-1][j]==0)
                            index[0]=1;
                        }
                        if(i!=n-1)
                        {
                        if(a[i+1][j]==0)
                            index[1]=1;
                        }
                        }
                }
                pp=&s[i*n+j+1];
                while(pp->ptr!=NULL)
                {
                    pp=pp->ptr;
                }
                for(k=0;k<4;k++)
                {
                    if(index[k]==1)
                    {
                        head=new node;
                        head->ptr=NULL;
                        switch(k)
                        {
                        case 0:
                            head->val=(i-1)*(n)+j+1;
                            pp->ptr=head;
                            pp=head;
                            break;
                        case 1:
                            head->val=(i+1)*(n)+j+1;
                            pp->ptr=head;
                            pp=head;
                            break;
                        case 2:
                            head->val=i*n+j;
                            pp->ptr=head;
                            pp=head;
                            break;
                        case 3:
                            head->val=i*n+j+2;
                            pp->ptr=head;
                            pp=head;
                            break;
                        }
                    }
                }
                }
            }
        }
       /* cout<<" list is "<<endl;
        for(i=1;i<=n*n;i++)
        {
            cout<<i<<" :";
            pp=s[i].ptr;
            while(pp!=NULL)
            {
                cout<<pp->val<<" ";
                pp=pp->ptr;
            }
            cout<<endl;
        }*/
        // Making DFS from adjacency starting from 1
        dfs(s,1,res,n*n);
        cout<<res<<endl;
        }
    }
    return 0;
}
