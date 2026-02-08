#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define uset unordered_set
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int mod = 1000000007;
const int N = 9e6 + 2;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ord_set;// find_by_order(); order_of_key();
template <typename T> 
      using minheap=priority_queue<T,vector<T>,greater<T>>;
template <typename T> 
      using maxheap=priority_queue<T>;
ll add(ll a, ll b) { a = a % mod; b = b % mod; return (a + b) % mod;}
ll mul(ll a, ll b) { a = a % mod; b = b % mod; return (a * b) % mod; }
ll sub(ll a, ll b) { a = a % mod; b = b % mod; return ((a - b) + mod) % mod; }
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void init_code()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);  
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif // ONLINE_JUDGE
}

bool vis[3001][3001];
int main()
{
    
    init_code();
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
       cin >> grid[i];
    }
    string ans;
    fill(&vis[0][0], &vis[0][0] + 3001 * 3001, false);
    queue<pair<int, int>> que;
    que.push({0,0});
    vis[0][0] = true;
    while(!que.empty())
    {
        int sz = que.size();
        char minChar = 'Z';
        vector<pair<int, int>> temp;
        while (sz--)
        {
            auto [i, j] = que.front();
            que.pop();
            minChar = min(minChar, grid[i][j]);
            temp.push_back({i, j});
        }
        ans += minChar;
        for (auto [i, j] : temp)
        {
            if (grid[i][j] == minChar)
            {
                if (i + 1 < n && !vis[i + 1][j])
                {
                    que.push({i + 1, j});
                    vis[i + 1][j] = true;
                }
                if (j + 1 < n && !vis[i][j + 1])
                {
                    que.push({i, j + 1});
                    vis[i][j + 1] = true;
                }
            }
        }
    }
    cout << ans;
    return 0;
}