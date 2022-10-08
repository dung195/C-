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
vector<pii>g;
vector<int>hoanh;
vector<int>tung;
int cal(int x,int y){
    int ans=0;
    for(int i=0;i<g.size();i++){
        int x0=g[i].first;
        int y0=g[i].second;
        ans+=abs(x-x0)+abs(y-y0);
    }
    return ans;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("ROBOT.inp","r",stdin);
	// freopen("ROBOT.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g.push_back({a,b});
        hoanh.push_back(a);
        tung.push_back(b);
    }
    int x=0;
    int y=0;
    int dis=cal(0,0);
    sort(hoanh.begin(),hoanh.end());
    sort(tung.begin(),tung.end());
    n--;
    for(int i=0;i<m;i++){
        char s;
        cin>>s;
        if(s=='E'){
            int pos=equal_range(hoanh.begin(),hoanh.end(),x).second-hoanh.begin()-1;
            if(hoanh.begin()+pos+1==hoanh.end()){
                dis+=n;
                cout<<dis<<endl;
                continue;
            }
            x++;
            dis=dis+pos+1-(n-pos);
        }
        if(s=='W'){
            int pos=equal_range(hoanh.begin(),hoanh.end(),x).second-hoanh.begin()-1;
            if(hoanh.begin()+pos+1==hoanh.end()){
                dis-=n;
                cout<<dis<<endl;
                continue;
            }
            x--;
            dis=dis-(pos+1)+(n-pos);
        }
        if(s=='N'){
            int pos=equal_range(tung.begin(),tung.end(),y).second-1-tung.begin();
            if(tung.begin()+pos+1==tung.end()){
                dis+=n;
                cout<<dis<<endl;
                continue;
            }
            y++;
            dis=dis+pos+1-(n-pos);
        }
        if(s=='S'){
            int pos=equal_range(tung.begin(),tung.end(),y).second-tung.begin()-1;
            if(tung.begin()+pos+1==tung.end()){
                dis-=n;
                cout<<dis<<endl;
                continue;
            }
            y--;
            dis=dis-(pos+1)+(n-pos);
        }
        cout<<dis<<endl;
    }
    return 0;
}