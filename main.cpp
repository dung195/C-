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
int mcd[sized];
void solve(){
    int c,k;
    cin>>c>>k;
    int cnt=c/(k+1);
    int tmp1=mcd[cnt]*2;
    int tmp2=mcd[c]-mcd[cnt];
    cout<<tmp1+tmp2<<endl;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>bang[i];
    sort(bang+1,bang+n+1);
    reverse(bang+1,bang+n+1);
    for(int i=1;i<=n;i++){
        mcd[i]=mcd[i-1]+bang[i];
    }
    for(int i=0;i<q;i++) solve();
    return 0;
}