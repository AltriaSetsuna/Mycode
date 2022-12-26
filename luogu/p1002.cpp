#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};
LL mp[21][21] = {0};
int n, m, hx, hy;
bool check(int x,int y)
{
    return x >= 0 && x <= n && y >= 0 && y <= m;
}
void solve()
{
    mp[hx][hy] = -1;
    for (int i = 0; i < 8;i++)
    {
        int xx = hx + dx[i];
        int yy = hx + dy[i];
        if(check(xx, yy))
            mp[xx][yy] = -1;
    } 
    for (int i = 0; i <= m;i++)
    {
        if(mp[0][i]==-1)
            break;
        mp[0][i] = 1;
    }
    for (int i = 0; i <= n;i++)
    {
        if(mp[i][0]==-1)
            break;
        mp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(mp[i][j]==-1)
            {
                mp[i][j] = 0;
                continue;
            }
            mp[i][j] = mp[i - 1][j] + mp[i][j - 1];
        }
    }
}

int main() 
{
    // #ifdef OY_LOCAL
    // freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> hx >> hy;
    solve();
    cout << mp[n][m];
    return 0;
} 