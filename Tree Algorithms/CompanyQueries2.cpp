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
const int MOD = 1000000007;
const int N = 2e5 + 1;
const int LOG = 18;
const int INF = 1e9;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ord_set;// find_by_order(); order_of_key();
template <typename T> 
      using minheap=priority_queue<T,vector<T>,greater<T>>;
template <typename T> 
      using maxheap=priority_queue<T>;
inline int add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }
inline int sub(int a, int b) { a -= b; if (a < 0) a += MOD; return a; }
inline int mul(long long a, long long b) { return (a * b) % MOD; }
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void init_code()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);  
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif // ONLINE_JUDGE
}
int par[N], up[LOG][N], level[N];

void build(int n)
{
    for (int i = 1; i <= n; i++)
        up[0][i] = par[i];
    for (int i = 1; i < LOG; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
}
int getLca(int u, int v)
{
    if (level[u] > level[v])
    swap(u, v);
    int k = level[v] - level[u];
    for (int i = 0; i < LOG; i++)
    {
        if (k & (1 << i))
        {
            v = up[i][v];
        }
    }
    if (u == v) return u;
    for (int jump = LOG - 1; jump >= 0; jump--)
    {
        if (up[jump][u] != up[jump][v])
        {
            u = up[jump][u];
            v = up[jump][v];
        }
    }
    return par[u];
}
void dfs(vector<vector<int>> &adj, int node = 1, int par = 0, int depth = 0)
{
    level[node] = depth;
    for (auto &child: adj[node])
    {
        if (child != par)
            dfs(adj, child, node, depth + 1);
    }
}
int main()
{
    
    init_code();
    int n, q;
    cin >> n >> q;
    par[1] = 1;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
        adj[i].push_back(par[i]);
        adj[par[i]].push_back(i);
    }
    build(n);
    dfs(adj);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << getLca(u, v) << "\n";
    }
    return 0;
}