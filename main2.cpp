#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int, int>

const int mod = 1e9 + 7;
const int base = 311;
const int LIM = 3e5 + 5;
const int INF = 1e9;

int n, m;
int trie[LIM][27];
int nnode = 1;
string s;

void ins(string s)
{
    int c = 1;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (trie[c][s[i] - 'a'] == -1)
        {
            nnode++;
            trie[c][s[i] - 'a'] = nnode;
        }
        c = trie[c][s[i] - 'a'];
    }
    trie[c][26] = 1;
}

int d[LIM];

int dp(int k)
{
    if (k == s.size())
        return 1;
    if (d[k] != -1)
        return d[k];

    int ans = 0;
    int c = 1;
    for (int i = k; i < s.size(); i++)
    {
        if (trie[c][s[i] - 'a'] == -1)
            break;
        c = trie[c][s[i] - 'a'];
        if (trie[c][26] == 1)
            ans = (ans + dp(i + 1)) % mod;
    }
    return d[k] = ans;
}

int main()
{
    //	freopen("ten.inp", "r", stdin);
    //	freopen("ten.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(trie, -1, sizeof(trie));
    memset(d, -1, sizeof(d));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        ins(s);
    }

    cin >> s;
    cout << dp(0);

    return 0;
}