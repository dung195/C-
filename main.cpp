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
int a[sized];
int b[sized];
void solve(){
    memset(a,0,sizeof(a));
    memeset(b,0,sizeof(b));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=n;j++) cin>>b[j];
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++) solve();
    return 0;
}