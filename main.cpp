#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
#define int ll
const ll sized = 1e6;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD =  1000000007;
const ll LOG = 20;
struct Node{
    bool isend=false;
    int child[26];
};
void Add(string s){

}
bool found(string s){

}
int a[sized];
int dp[sized];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        Add(s);
    }
    string g;
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            if(found(g.substr(j,i-j+1))==true) dp[i]=(dp[i]+dp[j])%MOD;
        }
    }
    cout<<dp[g.size()-1]<<endl; 
    return 0;
}