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
const ll N = 1005;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
vector<int>graph[sized];
int p[sized][LOG];
int h[sized];
void dfs(int S){
    for(int i=0;i<graph[S].size();i++){
        h[graph[S][i]]=h[S]+1;
        p[graph[S][i]][0]=S;
        dfs(graph[S][i]);
    }
}
int getbit(int a,int i){
    return (a>>i)&1;
}
int lca(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    int x=h[a]-h[b];
    for(int i=LOG;i>=0;i--){
        if(getbit(x,i)==1) a=p[a][i];
    }
    if(a==b) return a;
    for(int i=LOG-1;i>=0;i--){
        if(p[a][i]!=p[b][i]){
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}
void solve(int cnt){
    for(int i=0;i<N;i++){
        h[i]=0;
        memset(p[i],0,sizeof(p[i]));
        graph[i].clear();	
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        for(int i=1;i<=num;i++){
            int a;
            cin>>a;
            graph[i].push_back(a);
        }
    }
    dfs(1);
    for(int i=1;i<=LOG;i++){
        for(int j=1;j<=n;j++){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
    int q;
    cin>>q;
    vector<int>ans;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
    	ans.push_back(lca(a,b));
    }
    cout<<"Case"<<" "<<cnt<<":"<<endl;
    for(int i=0;i<cnt;i++){
        cout<<ans[i]<<endl;
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}