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
int tong(int n,int m){
    int ssh=(n-m)/2+1;
    return ((n+m)*ssh)/2;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FUNC.inp","r",stdin);
	freopen("FUNC.out","w",stdout);
    int n;
    cin>>n;
    int gh_c,gh_l;
    if(n%2==0){
        gh_c=n;
        gh_l=n-1;
    }
    else{
        gh_c=n-1;
        gh_l=n;
    }
    // cout<<tong(gh_c,2)<<endl;
    // cout<<tong(gh_l,1)<<endl;
    cout<<tong(gh_c,2)-tong(gh_l,1)<<endl;
    return 0;
}