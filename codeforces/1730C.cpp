#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
void solve()
{
    string s;
    cin >> s;
    vector<int> m(s.size() + 1, 9);
    for (int i = s.size()-1; i >= 0;i--)
    {
        m[i] = min(m[i + 1], s[i] - '0');
    }
    vector<int> num(10, 0);
    string t = "0123456789";
    string ans;
    for (int i = 0; i < s.size();i++)
    {
        for (int j = 0; j <= m[i];j++)
        {
            while(num[j])
            {
                num[j]--;
                ans += t[j];
            }
        }
        if(s[i]-'0'==m[i])
        {
            ans += t[m[i]];
        }
        else 
        {
            num[min(9, s[i] - '0' + 1)]++;
        }
    }
    for (int i = 0; i <= 9;i++)
    {
        while(num[i])
        {
            ans += t[i];
            num[i]--;
        }
    }
    cout << ans << endl;
    return;
}
int main() 
{
    #ifdef OY_LOCAL
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    
    
    LL t;
    cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
} 