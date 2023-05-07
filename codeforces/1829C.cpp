#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / (k)
void LOCAL();
using namespace std;


inline void solve()
{
    LL n;
    cin >> n;
    vector<LL> f, se, two;
    two.emplace_back(LLONG_MAX);
    for (LL i = 0; i < n;i++)
    {
        LL m;
        string s;
        cin >> m >> s;
        if(s[0]=='1'&&s[1]=='1')
        {
            f.emplace_back(m);
            se.emplace_back(m);
            two.emplace_back(m);
        }
        else if(s[0]=='1')
        {
            f.emplace_back(m);
        }
        else if(s[1]=='1')
        {
            se.emplace_back(m);
        }
    }
    if(f.size()==0||se.size()==0)
    {
        cout << -1 << endl;
    }
    else
    {
        sort(all(f)), sort(all(se)), sort(all(two));
        cout << min(two[0], f[0] + se[0]) << endl;
    }
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
