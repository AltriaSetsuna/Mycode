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

typedef struct node
{
    LL x, y;
} node;
LL dis(node&a,node&b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}
inline void solve()
{
    node t[3];
    cin >> t[0].x >> t[0].y >> t[1].x >> t[1].y >> t[2].x >> t[2].y;
    cout << (dis(t[0], t[1]) + dis(t[0], t[2]) - dis(t[1], t[2])) / 2 + 1 << endl;
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
