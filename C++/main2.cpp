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
int bang[2*sized+5];
int st[2*sized*4];
void update(int l,int r,int u,int v,int id,int val){
    if(v<l || u>r) return;
    if(u<=l && r<=v){
        st[id]+=val;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,u,v,id*2,val);
    update(mid+1,r,u,v,id*2+1,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get_min(int l,int r,int u,int v,int id){
    if(v<l || u>r) return inf;
    if(u<=l && r<=v) return st[id];
    int mid=(l+r)/2;
    return min(get_min(l,mid,u,v,id*2),get_min(mid+1,r,u,v,id*2+1));
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int old=n;
    n=n*2;
    for(int i=0;i<m;i++){
        int type;
        cin>>type;
        if(type==1){
            int u,val;
            cin>>u>>val;
            update(1,n,u,u,1,val);
            update(1,n,u+old,u+old,1,val);
        }
        if(type==2){
            int i,j;
            cin>>i>>j;
            if(j<i) j+=old;
            cout<<get_min(1,n,i,j,1)<<endl;
        }
    }
    return 0;
}