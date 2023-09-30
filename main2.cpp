/**
 *    author:  AgentPengin ( Độc cô cầu bại )
 *    created: 23.12.2022 10:08:02
 *    too lazy to update time
**/
#include<bits/stdc++.h>

#define EL '\n'
#define fi first
#define se second
#define NAME "NAME"
#define ll long long
#define lcm(a,b) (a/gcd(a,b))*b
#define db(val) "["#val" = " << (val) << "] "
#define bend(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define ex exit(0)
#define int ll

using namespace std;

const ll mod = 1e9 + 7;
const int inf = 0x1FFFFFFF;
const int N = 1e5 + 5;

struct Info {
	int x,a; 
	bool operator < (const Info &other) const {
		return x < other.x;
	}
} a[N],b[N];

int n,k,nn,mm;

int solve1() {
	if (nn <= 0) return 0;
	int cur = 0,res = 0,du = 0;
	sort(a + 1,a + nn + 1);
	for (int i = nn;i >= 1;i--) {
		if (du > a[i].a) {
			du -= a[i].a;
		} else {
			a[i].a -= du;
			int nguyen = a[i].a / k;
			if (a[i].a % k != 0) nguyen++;
			du = nguyen * k - a[i].a;
			res += nguyen * 2 * a[i].x;
		}
	}
	return res;
}

int solve2() {
	if (mm <= 0) return 0;
	for (int i = 1;i <= mm;i++) b[i].x = abs(b[i].x);
	sort(b + 1,b + mm + 1);
	int cur = 0,res = 0,du = 0;
	for (int i = mm;i >= 1;i--) {
		if (du > b[i].a) {
			du -= b[i].a;
		} else {
			b[i].a -= du;
			int nguyen = b[i].a / k;
			if (b[i].a % k != 0) nguyen++;
			du = nguyen * k - b[i].a;
			res += nguyen * 2 * b[i].x;
		}
	}
	return res;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
		int X,A;
		cin >> X >> A;
		if (X > 0) a[++nn] = {X,A};
		else b[++mm] = {X,A};
    }
    cout << solve1() + solve2();
    
    return 0;
}
// agent pengin wants to take apio (with anya-san)