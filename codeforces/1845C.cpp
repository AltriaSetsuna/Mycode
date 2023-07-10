#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) ((x) + (k) - 1) / (k)
void LOCAL();
using namespace std;


inline void solve()
{
    string s;
    cin >> s;
    LL len;
    cin >> len;
    string l, r;
    cin >> l >> r;

    vector<LL> a[10];
    for (LL i = 0;i<s.size();i++)
    {
        a[s[i] - '0'].emplace_back(i);
    }
    LL pos = -1;
    for (LL i = 0; i < len;i++)
    {
        LL tmp = -1;
        for (char j = l[i]; j <= r[i];j++)
        {
            auto it = upper_bound(all(a[j - '0']), pos);
            if(it==a[j-'0'].end())
            {
                YES();
                return;
            }
            tmp = max(tmp, *it);
        }
        pos = max(pos, tmp);
    }
    NO();
    return;
}


int main()
{
   LOCAL();
   LL t;
   cin >> t;
   while(t--)
   {
       solve();
   }
   return 0;
}
void LOCAL()
{
   #ifdef OY_LOCAL
   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   #endif
   ios::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
}
