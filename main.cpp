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
int par[sized];
struct Edge{
    int u,v,w,pos;
};
vector<Edge>krus;
vector<int>ans;
bool cmp(const Edge &a,const Edge &b){
    return a.w<b.w;
}
int getroot(int u){
    if(par[u]<0) return u;
    par[u]=getroot(par[u]);
    return par[u];
}
void connect(int u,int v){
    u=getroot(u);
    v=getroot(v);
    if(u==v) return;
    if(par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mst.inp","r",stdin);
	freopen("mst.out","w",stdout);
    for(int i=0;i<sized;i++) par[i]=-1;
    int sub;
    cin>>sub;
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        krus.push_back({u,v,w,i});
    }
    sort(krus.begin(),krus.end(),cmp);
    int cnt=0;
    for(int i=0;i<krus.size();i++){
        int u=krus[i].u;
        int v=krus[i].v;
        int w=krus[i].w;
        int pos=krus[i].pos;
        if(getroot(u)==getroot(v)) continue;
        connect(u,v);
        ans.push_back(pos);
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}