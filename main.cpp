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
int bang[sized];
int st[sized*4+8];
int la[sized*4+8];
// void lazy(int id){
//     st[id]+=la[id];
//     la[id*2]+=la[id];
//     la[id*2+1]+=la[id];
//     la[id]=0;
// }
void update(int l,int r,int u,int v, int id){
    // lazy(id);
    if(r<u || l>v) return;
    if(l>=u && r<=v){
        // la[id]+=(r-l+1-st[id])-st[id];
        // lazy(id);
        st[id]+=(r-l+1-st[id])-st[id];
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,u,v,id*2);
    update(mid+1,r,u,v,id*2+1);
    st[id]=st[id*2]+st[id*2+1];
}
int print(int l,int r,int u,int v,int id){
    // lazy(id);
    if(r<u || l>v) return 0;
    if(l>=u && r<=v) return st[id];
    int mid=(l+r)>>1;
    return print(l,mid,u,v,id*2)+print(mid+1,r,u,v,id*2+1);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int type;
        cin>>type;
        if(type==0){
            int l,r;
            cin>>l>>r;
            update(1,n,l,r,1);
        }
        if(type==1){
            int s,e;
            cin>>s>>e;
            cout<<print(1,n,s,e,1)<<endl;
        }
    }
    for(int i=0;i<n*4+3;i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
    return 0;
}