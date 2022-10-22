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
const ll MOD = 123456789;
const ll LOG = 20;
int dig[sized];
vector<pii>graph[sized];
int par[sized];
struct Edge{
    int u,v,w;
};
bool cmp(const Edge &a,const Edge &b){
    return a.w<b.w;
}
vector<Edge>e;
int getroot(int u){
    if(par[u]<0) return u;
    return par[u]=getroot(par[u]);
}
void connect(int u,int v){
    u=getroot(u);
    v=getroot(v);
    if(u==v) return;
    if(par[u]<par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
void solve(){
    for(int i=0;i<sized;i++) par[i]=-1;
    for(int i=0;i<e.size();i++){
        int u=e[i].u;
        int w=e[i].w;
        int v=e[i].v;
        
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>dig[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            graph[i].push_back({a,j});
            e.push_back({i,a,j});
        }
    }
    sort(e.begin(),e.end(),cmp);
    for(int i=1;i<=n;i++) solve();
    return 0;
}