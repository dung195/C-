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
vector<int>a;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        a.push_back(b);
    }
    int ans=-inf;
    for(int i=0;i<n-1;i++){
        int kq=0;
        for(int j=i+1;j<n;j++){
            for (int k = i; k <= j; k++)
            {
                kq^=a[k];
            }
        ans=max(ans,kq);
        }
    }
    cout<<ans<<endl;
    return 0;
}