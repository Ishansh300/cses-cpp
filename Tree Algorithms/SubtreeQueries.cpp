#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define uset unordered_set
const int mod=1000000007;
const int N = 2e5 + 2;
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
int startTime[N], endTime[N], values[N], ft[2 * N + 1];
int timer = 1;
void dfs(vector<vector<int>> &adj, int node = 1, int par = 0)
{
    startTime[node] = timer;
    ft[timer++] = values[node];

    for (auto &child: adj[node])
    {
        if (child != par)
            dfs(adj, child, node);
    }
    endTime[node] = timer;
    ft[timer++] = values[node];
}
struct BIT{
    int n;
    vector<ll> bit;

    BIT(int _n)
    {
        n = _n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta)
    {
        // ++idx;
        for(; idx <= n; idx += (idx & -idx))
          bit[idx] += delta;
    }

    ll query(int idx)
    {
        // ++idx;
        ll sum = 0;
        for(; idx > 0; idx -= (idx & -idx))
            sum += bit[idx];
        return sum;
    }

};
int main()
{
    
    init_code();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i<=n; i++)
        cin >> values[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj);
    BIT fen(2 * n);
    for (int i = 1; i <= 2 * n; i++)
        fen.update(i, ft[i]);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int node, val;
            cin >> node >> val;
            int delta = val - values[node];
            values[node] = val;
            fen.update(startTime[node], delta);
            fen.update(endTime[node], delta);
        }
        else
        {
            int node;
            cin >> node;
            cout << (fen.query(endTime[node]) - fen.query(startTime[node] - 1)) / 2 << "\n";
        }
    }
    return 0;
}