#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
#define int ll
const ll sized = 1e6+5;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
bool danhdau[sized];
int getbit(int x,int b){
    return (x>>b)&1;
}
int bo(int a){
    int f=0;
    for(int i=20;i>=0;i--){
        if(getbit(a,i)==1) {
            f=a^(1<<i);
            break;
        }
    }
    return f;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        danhdau[a]=true;
    }
    int res=0;
    for(int x=1;x<=n;x++){
        if(danhdau[x]==true) continue;
        res+=2*bo(x);
    }
    cout<<res<<endl;
    return 0;
    //abc
}