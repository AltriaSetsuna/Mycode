#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

LL n, m, hx, hy;
LL mm[21][21] = {0};
bool horse[21][21] = {0};
const int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
bool bound(LL x,LL y)
{
    return x >= 0 && x <= n && y >= 0 && y <= m;
}

int main()
{
   LOCAL();

   cin >> n >> m >> hx >> hy;
   for (LL i = 0; i < 9;i++)
   {
       LL x = hx + dx[i], y = hy + dy[i];
       if(bound(x,y))
       {
           horse[x][y] = true;
       }
   }
   mm[0][0] = 1;
   for (LL i = 0; i <= n;i++)
   {
       for (LL j = (i == 0 ? 1 : 0); j <= m; j++)
       {
        if(horse[i][j])
        {
            continue;
        }
        mm[i][j] += (bound(i - 1, j) ? mm[i - 1][j] : 0) + (bound(i, j - 1) ? mm[i][j - 1] : 0);
       }
   }
   cout << mm[n][m];
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
