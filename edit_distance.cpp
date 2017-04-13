////! Ashish Sharma  !//
////! C.S.E (B.Tech) !//
////! Nit Jalandhar  !//
//#include<bits/stdc++.h>
//#define ll long long
//#define lg long
//#define dd double
//#define fl float
//#define ch char
//#define modd 1000000007
//#define maxx (long long)1e18
//#define minn -(long long)1e18
//#define scf(a) scanf("%lld",&a)
//#define scdf(a) scanf("%ld",&a)
//#define prt(a) printf("%lld",a)
//#define prts(a) printf("%lld ",a)
//#define prdt(a) printf("%ld",a)
//#define prdts(a) printf("%ld ",a)
//#define get(a) cin>>a
//#define puts(a) cout<<a<<" "
//#define put(a) cout<<a
//#define loop(i,a,b) for(i=a;i<=b;i++)
//#define rev(i,a,b) for(i=a;i>=b;i--)
//#define nxt printf("\n")
//#define space printf(" ")
//#define mem(s) memset(s,0,sizeof(s))
//#define memi(s) memset(s,-1,sizeof(s))
//#define pb push_back
//#define popb pop_back()
//#define pbf push_front
//#define popf pop_front()
//using namespace std;
////! Three operation of insert,remove or replace each with cost 1; find min. cost to make both strings equal
//ll dp[105][105];
//ll solve(string s1,string s2,ll n1,ll n2)
//{
//    if(n1==-1)
//    return n2+1;
//    if(n2==-1)
//        return n1+1;
//    if(dp[n1][n2]!=-1)
//    {
//        return dp[n1][n2];
//    }
//    if(s1[n1]==s2[n2])
//    {
//        dp[n1][n2]=solve(s1,s2,n1-1,n2-1);
//    }
//    else
//    {
//        dp[n1][n2]=1+min(solve(s1,s2,n1-1,n2),min(solve(s1,s2,n1,n2-1),solve(s1,s2,n1-1,n2-1)));
//    }
//    return dp[n1][n2];
//}
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    // freopen( "test_case.txt", "r", stdin);
//    // freopen( "output.txt", "w", stdout);
//    ll t;
//    cin>>t;
//    while(t--){
//    ll i,j,k,l,n,l1,l2;
//    for(i=0;i<105;i++)
//    {
//        for(j=0;j<105;j++)
//            dp[i][j]=-1;
//    }
//    string s1,s2;
//    cin>>l1>>l2;
//    cin>>s1>>s2;
//    dp[l1-1][l2-1]=solve(s1,s2,l1-1,l2-1);
//    cout<<dp[l1-1][l2-1]<<endl;}
//}
//
//
//
//
//
// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
#include<bits/stdc++.h>
using namespace std;

// Utility function to find minimum of three numbers
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];

    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }

    return dp[m][n];
}

// Driver program
int main()
{
    // your code goes here
    string str1 = "geek";
    string str2 = "geesek";

    cout << editDistDP(str1, str2, str1.length(), str2.length());

    return 0;
}
