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
int bang[sized];
vector<int>a;
map<int,int> dd;
int n,q;
void solve(){
	int l,r;
	cin>>l>>r;
	a.clear();
	for(int i=1;i<=n;i++){
		if(bang[i]<l || bang[i]>r) continue;
		a.push_back(bang[i]);
	}
	int ans=0;
	// cerr<<a.size()<<endl;
	if(a.size()==0) {
		cout<<0<<endl;
		return;
	}
	for(int i=0;i<a.size()-1;i++){
		ans+=abs(a[i]-a[i+1]);
	}
	cout<<ans<<endl;
}
void solve2(){
	int l,r;
	cin>>l>>r;
	
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
	cin>>n>>q;
	int bien=-inf;
	for(int i=1;i<=n;i++){
		cin>>bang[i];
		bien=max(bien,bang[i]);
		dd[bang[i]]++;
	}
	if(n<=5000 && q<=5000){
		for(int i=0;i<q;i++){
			solve();
		}
	}
	else{
		for(int i=0;i<q;i++){
			solve2();
		}
	}
    return 0;
}