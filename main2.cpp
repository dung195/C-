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
        int x;
        cin>>x;
        a.push_back(x);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+3;j<n;j++){
            if((j-i)%2==0) continue;
            int n=i;
            int m=j;
            int tmp=inf;
            bool ok=true;
            while(n<m){
                int g=a[n]+a[m];
                if(tmp>g) tmp=g;
                else{
                    ok=false;
                    break;
                } 
                n++;
                m--;
            }
            if(ok==true) ans++;
        }
    }
    cout<<ans%30103<<endl;
    return 0;
}