#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int m[2001][2001] = {0};
int lcs(string& a,string& b)
{
    
    for (int i = 1; i <= a.size();i++)
    {
        for (int j = 1; j <= b.size();j++)
        {
            if(a[i-1]==b[j-1])
            {
                m[i][j] = m[i - 1][j - 1] + 1;
            }
            else 
            {
                m[i][j] = max(m[i - 1][j], m[i][j - 1]) ;
            }
        }
    }
    return m[a.size()][b.size()];
}
int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string a, b;
    cin >> a >> b;
    cout << a.size() - lcs(a, b);

    return 0;
} 