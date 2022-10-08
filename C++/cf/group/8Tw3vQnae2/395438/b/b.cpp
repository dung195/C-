#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
#define int ll
const ll sized = 1e7+5;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
bool dd[sized];
int mcd[sized];
int bang[sized];
void solve(){
    int n,c;
    cin>>n>>c;
    for(int i=0;i<=c*2;i++){
        dd[i]=false;
        mcd[i]=0;
    }
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        dd[a]=true;
        bang[i]=a;
    }
    for(int i=1;i<=c*2;i++) mcd[i]=mcd[i-1]+dd[i];
    for(int v=1;v<=c;v++){
        if(dd[v]==0){
            for(int y=1;y<=n;y++){
                if(dd[bang[y]]==1){
                    if(v*bang[y]>c) break;
                    if(mcd[(v+1)*bang[y]-1]-mcd[v*bang[y]-1]>0){
                    cout<<"No\n";
                    return ;
                    }
                }
            }
        }
    }
    cout<<"Yes\n";
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}