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
const int N = 2e5;
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
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    BIT fen(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        fen.update(i, 1);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int index = fen.findKth(x);
        fen.update(index, -1);
        cout << nums[index] << " ";
    }
    return 0;
}