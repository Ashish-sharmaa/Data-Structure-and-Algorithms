// Creating a b tree with max. children as 5 and keys as 4
// Therefore, min. no. of keys possible for internal nodes are 2
#include<bits/stdc++.h>
#define ll long
#define N 5
using namespace std;
using namespace std;
int main()
{
    struct node
    {
        vector<ll>s;
        node *ptr[N];
        node * parent;
    }*pp,*temp,*first=NULL,*head;
    cout<<"No. of element to be inserted\n";
    ll i,j,k,n,m,leng,ele,dis,sizz;
    cin>>n;
    sizz=n;
    while(n--)
    {
        cin>>ele;
        if(first==NULL)
        {
            temp=new node;
            temp->s.push_back(ele);
            for(k=0;k<N;k++)
                temp->ptr[k]=NULL;
            first=temp;
            first->parent=NULL;
        }
        else
        {
            temp=first;
            while(1)
            {
                leng=temp->s.size();
                j=0;
                if(ele>=temp->s[0])
                {
                    for(j=1;j<leng;j++)
                    {
                        if(ele<temp->s[j])
                            break;
                    }
                }
                if(temp->ptr[j]!=NULL)
                {
                    temp=temp->ptr[j];
                }
                else
                    {
                        break;
                    }
            }
            temp->s.push_back(ele);
            sort(temp->s.begin(),temp->s.end());
            if(temp->s.size()>=N)
            {
                while(1)
                {
                head=temp->parent;
                ele=temp->s[N/2];
                if(head!=NULL)
                {
                    head->s.push_back(ele);
                    sort(head->s.begin(),head->s.end());
                    auto pos=find(head->s.begin(),head->s.end(),ele);
                    dis=distance(head->s.begin(),pos)+1;
                    if(head->s.size()!=N)
                    {for(j=N-1;j>dis;j--)  //Maximum no. of nodes is 5 but indexing is 0 to 4
                        head->ptr[j]=head->ptr[j-1];}
                    else
                    {

                    }

                }
                else
                {
                   head=new node;
                   head->parent=NULL;
                   for(j=0;j<N;j++)
                    head->ptr[j]=NULL;
                   head->s.push_back(ele);
                   first=head;
                   dis=1;
                }
                    pp=new node;
                    for(j=0;j<N;j++)
                    {
                        pp->ptr[j]=NULL;
                        if(j<N/2)
                        {
                            pp->s.push_back(temp->s[j]);
                        }
                        if(j<=N/2)
                            pp->ptr[j]=temp->ptr[j];
                    }
                    pp->parent=head;
                    dis--;
                    head->ptr[dis]=pp;
                    pp=new node;
                    for(j=0;j<N;j++)
                        pp->ptr[j]=NULL;
                    for(j=N/2;j<N;j++)
                    {
                        if(j>N/2)
                            pp->s.push_back(temp->s[j]);
                            pp->ptr[j-N/2+1]=temp->ptr[j];
                    }
                    pp->parent=head;
                    dis++;
                    head->ptr[dis]=pp;
                    temp=head;
                    if(temp->s.size()<N)
                        break;
               }
            }
        }
    deque<node*>q;
    pp=first;
    while(1)
    {
        auto pos=pp->s.begin();
        //cout<<endl;
        for(;pos!=pp->s.end();++pos)
        {
            cout<<*pos<<" ";
        }
        cout<<endl;
        for(j=0;j<N;j++)
        {
            /*if(pp->ptr[j]==0)
                cout<<"Null  ";*/
            if(pp->ptr[j]!=NULL)
            {
                //cout<<" Not null ";
                q.push_back(pp->ptr[j]);
            }
            cout<<"  ";
        }
        if(q.size()==0)
            break;
        pp=q.front();
        q.pop_front();
    }
    }

    return 0;
}
