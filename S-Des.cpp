#include<bits/stdc++.h>
#define ll long
using namespace std;
ll p10[11]={0,3,5,2,7,4,10,1,9,8,6};
ll p8[9]={0,6,3,7,4,8,5,10,9};
ll p4[5]={0,2,4,3,1};
ll ip[9]={0,2,6,3,1,4,8,5,7};
ll ep[9]={0,4,1,2,3,2,3,4,1};
ll ip1[9]={0,4,2,3,5,7,2,8,6};
string S0[4][4]={"01","00","11","10","11","10","01","00","00","10","01","11","11","01","11","10"};
string S1[4][4]={"00","01","10","11","10","00","01","11","11","00","01","00","10","01","00","11"};
string  fun(string key1,string key2)
{
    string ma=key1+key2;
    ma='0'+ma;
    string ans;
    for(int i=1;i<=8;i++)
    {
        ans=ans+ma[p8[i]];
    }
    return ans;
}
string fun1(string str,string key)
{
    string s1,s2,St1,St2;
    s1=str.substr(1,4);
    s2=str.substr(5,8);
    s1='0'+s1;
    s2='0'+s2;
    int i,j,k;
    for(i=1;i<=8;i++)
    {
        St1+=s2[ep[i]];
    }
    St1='0'+St1;
    for(i=1;i<=8;i++)
    {
        if(St1[i]==key[i])
          St2+='0';
        else
            St2+='1';
    }
    s1=St2.substr(0,4);
    s2=St2.substr(4,4);
    int pp=(s1[3]-'0')+2*(s1[0]-'0');
    int pp2=(s1[2]-'0')+2*(s1[1]-'0');
    s1=S0[pp][pp2];
    pp=(s2[3]-'0')+2*(s2[0]-'0');
    pp2=(s2[2]-'0')+2*(s2[1]-'0');
    s2=S1[pp][pp2];
    St2='0'+s1+s2;
    St1.clear();
    for(i=1;i<=4;i++)
    {
        St1+=St2[p4[i]];
    }
    s1=str.substr(1,4);
    s2.clear();
    for(i=0;i<=3;i++)
    {
        if(s1[i]==St1[i])
            s2+='0';
        else
            s2+='1';
    }
    return s2;
}
int main()
{
    cout<<" Enter key\n";
    string k1,key,key1,key2;
    cin>>k1;
    int i;
    k1='0'+k1;
    key=key1=key2='0';
    for(i=1;i<=5;i++)
    {
        key1+=k1[p10[i]];
    }
    for(i=6;i<=10;i++)
    {
        key2+=k1[p10[i]];
    }
    key1=key1+key1[1];
    key2=key2+key2[1];
    key1=key1.substr(2,6);
    key2=key2.substr(2,6);
    string ans1=fun(key1,key2);
    key1=key1+key1[0]+key1[1];
    key2=key2+key2[0]+key2[1];
    key1=key1.substr(2,6);
    key2=key2.substr(2,6);
    string ans2=fun(key1,key2);
    cout<<"Enter plain text\n";
    string pt,pt1;
    cin>>pt;
    pt='0'+pt;
    ans1='0'+ans1;
    ans2='0'+ans2;
    for(i=1;i<=8;i++)
    {
        pt1=pt1+pt[ip[i]];
    }
    pt1='0'+pt1;
    string mp1=fun1(pt1,ans1);
    string mp2=pt1.substr(5,4)+mp1;
    mp2='0'+mp2;
    string mp3=fun1(mp2,ans2)+mp2.substr(5,4);
    string finn;
    mp3='0'+mp3;
    for(i=1;i<=8;i++)
    {
        finn=finn+mp3[ip1[i]];
    }
    cout<<finn<<endl;
    return 0;
}
