#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


inline void solve()
{
    string s;
    cin >> s;
    if(s[0]<s[1])
    {
        cout << s[0] << ' ';
        for (LL i = 1; i + 1 < s.size();i++)
        {
            cout << s[i];
        }
        cout << ' ' << s[s.size() - 1] << endl;
    }
    else
    {
        cout << s[0] << ' ' << s[1] << ' ';
        for (LL i = 2; i < s.size();i++)
        {
            cout << s[i];
        }
        cout << endl;
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