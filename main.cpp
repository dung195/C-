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
int find_deg(int x){
    int u=log2(x);
    return u+1;
}
vector<int>a;
vector<int>b;
map<int,bool>mp;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n,x,y;
    cin>>n>>x>>y;
    if(x>y) swap(x,y);
    int x_cop=x;
    int y_cop=y;
    while (x!=0)
    {
        a.push_back(x);
        x/=2;
    }
    while (y!=0)
    {
        b.push_back(y/2);
        mp[y]=true;
        y/=2;
    }
    int pre1=0;
    for(int i=0;i<a.size();i++){
        int u=a[i];
        if(mp[u]==true){
            pre1=u;
            break;
        }
    }
    cout<<find_deg(x_cop)+find_deg(y_cop)-2*find_deg(pre1);
    return 0;
}