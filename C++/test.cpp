#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+9;
int d1[N], d2[N];
vector<int> g[N];
void dfs(int v, int p=-1, int d=0) {
    d1[v] = d;
    for(auto nei : g[v])
        if(nei!=p)
            dfs(nei,v,d+1);
}

int main() {
    int n; cin>>n;
    for(int i=0;i<n-1;++i) {
        int a,b; cin>>a>>b; --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);
    dfs(max_element(d1,d1+n)-d1);
    memcpy(d2,d1,n*4);
    dfs(max_element(d1,d1+n)-d1);
    int diam = *max_element(d1,d1+n);
    for(int i=0;i<n;++i) cout<< diam + (max(d1[i],d2[i])==diam) << '\n';
}