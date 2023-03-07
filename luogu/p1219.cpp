#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

priority_queue<string, vector<string>, less<string>> q;
LL n, ans = 0;
LL get_pos(LL pick)
{
    LL step = 1;
    LL ans = 1;
    while(step!=pick)
    {
        step *= 2;
        ans++;
    }
    return ans;
}
void dfs(LL row,LL col,LL ld,LL rd, string s)
{
    if(row==n)
    {
        q.emplace(s);
        while(q.size()>3)
        {
            q.pop();
        }
        ans++;
        return;
    }
    LL blank = ~(col | ld | rd) & (1 << n) - 1;
    while(blank)
    {
        LL pick = blank & (-blank);
        dfs(row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1, s + char(get_pos(pick) + '0'));
        blank &= blank - 1;
    }
    return;
}
int main()
{
   LOCAL();
   cin >> n;
   string s;
   dfs(0, 0, 0, 0, s);
   vector<string> t;
   while(q.size())
   {
        t.emplace_back(q.top());
        q.pop();
   }
   for (LL i = 2; i >= 0;i--)
   {
        for (LL j = 0; j < n;j++)
        {
            cout << int(t[i][j] - '0') << " \n"[j + 1 == n];
        }
   }
   cout << ans << endl;
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
