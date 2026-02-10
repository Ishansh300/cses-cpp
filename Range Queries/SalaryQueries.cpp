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
const int N = 2e5;
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
struct BIT{
    int n, LOG;
    vector<int> bit;

    BIT(int _n)
    {
        n = _n;
        bit.assign(n + 1, 0);
        LOG = 1;
        while ((LOG << 1) <= n) LOG <<= 1;
    }

    void update(int idx, int delta)
    {
        // ++idx;
        for(; idx <= n; idx += (idx & -idx))
          bit[idx] += delta;
    }

    int query(int idx)
    {
        // ++idx;
        int sum = 0;
        for(; idx > 0; idx -= (idx & -idx))
            sum += bit[idx];
        return sum;
    }

    int findKth(int val)
    {
        int pos = 0;
        for (int jump = LOG; jump > 0; jump >>= 1)
        {
            if (pos + jump <= n && bit[pos + jump] < val)
            {
                val -= bit[pos + jump];
                pos += jump;
            }
        }
        return ++pos;
    }
};
int main()
{
    
    init_code();
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> comp = nums;
    vector<array<int, 3>> queries;
    while (m--)
    {
        char type;
        cin >> type;
        int u, v;
        cin >> u >> v;
        if (type == '!')
        {
            comp.push_back(v);
        }
        queries.push_back({type, u, v});
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    BIT fen(comp.size());
    for (auto &x: nums)
    {
        int index = lower_bound(all(comp), x) - comp.begin() + 1;
        fen.update(index, 1);
    }
    for (auto &query: queries)
    {
        if (query[0] == '?')
        {
            int a = query[1];
            int b = query[2];

            int r = upper_bound(all(comp), b) - comp.begin();
            int l = lower_bound(all(comp), a) - comp.begin();

            cout << fen.query(r) - fen.query(l) << "\n";
        }
        else
        {
            int k = query[1], x = query[2];
            int prevSal = nums[k - 1];
            int index = lower_bound(all(comp), prevSal) - comp.begin() + 1;
            fen.update(index, -1);
            int newIndex = lower_bound(all(comp), x) - comp.begin() + 1;
            fen.update(newIndex, 1);
            nums[k - 1] = x;
        }
    }
    return 0;
}