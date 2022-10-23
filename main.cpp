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
int f[10]={1,1,2,6,24,120,720,5040,40320,362880};
int fact(int x){
    return f[x];
}
int cal(int x){
    if(x>=0 && x<=9) return fact(x);
    else return cal(x%10)+cal(x/10);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int y;
    cin>>y;
    for(int i=0;i<N;i++){
        if(cal(i)==y){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}