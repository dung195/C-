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
int pre[sized];
int suf[sized];
map<int,vector<int> > mp;
map<int,int>cnt;
int st[sized*4];
void buildtree(int l,int r,int id){
	if(l==r){
		st[id]=bang[l];
		return;
	}
	int mid=(l+r)>>1;
	buildtree(l,mid,id*2);
	buildtree(mid+1,r,id*2+1);
	st[id]=max(st[id*2],st[id*2+1]);
}
void update(int l,int r,int u,int v,int id,int val){
	if(u>r || v<l) return;
	if(l>=u && r<=v){
		st[id]+=val;
		return;
	}
	int mid=(l+r)>>1;
	update(l,mid,u,v,id*2,val);
	update(mid+1,r,u,v,id*2+1,val);
	st[id]=max(st[id*2],st[id*2+1]);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>bang[i];
		mp[bang[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		pre[i]=i-1;
		suf[i]=i+1;
	}
	buildtree(1,n,1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=st[1];
		int count=cnt[x];
		int pos=mp[x][count];
		ans+=(x+bang[pre[pos]]+bang[suf[pos]]);
		cnt[x]++;
		update(1,n,pos,pos,1,0-x);
		bang[pos]=0;
		// pre[pos+1]=pos-1;
		// suf[pos-1]=pos+1;
		suf[pre[pos]]=suf[pos];
		pre[suf[pos]]=pre[pos];
	}
	cout<<ans<<endl;
    return 0;
}