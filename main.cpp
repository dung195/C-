#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
// #define int ll
const ll sized = 1005;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
string substr(string a,string b){
    int F[sized][sized];
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i]==b[j]){
                F[i+1][j+1]=F[i][j]+1;
            }
            else F[i+1][j+1]=max(F[i+1][j],F[j][i+1]);
        }
    }
    int i=a.size();
    int j=b.size();
    string g="";
    while(F[i][j]>0){
        if(a[i]==b[j]){
            g+=a[i];
            i--;
            j--;
        }
        else{
            if(F[i][j]==F[i-1][j]) i--;
            else j--;
        }
    }
    return g;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    string a,b;
    cin>>a>>b;
    int size_a=a.size();
    int size_b=b.size();
    int ans=0;
    while(substr(a,b)!="   "){
        string g=substr(a,b);
        int tmp=g.size();
        ans+=tmp;
        size_a-=tmp;
        size_b-=tmp;
        string t1="";
        string t2="";
        int i=0;
        int j=0;
        while(j<=g.size()){
            for(int i=0;i<=a.size();i++){
                if(a[i]!=g[j]) t1=t1+a[i];
                else j++;
            }
        }
        j=0;
        while(j<=g.size()){
            for(int i=0;i<=a.size();i++){
                if(b[i]!=g[j]) t2=t2+b[i];
                else j++;
            }
        }
        a=t1;
        b=t2;
    }
    ans+=size_a;
    ans+=size_b;
    cout<<ans<<endl;
    return 0;
}