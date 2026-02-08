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
const ll INF = 1e18;
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

pair<ll, ll> dp[1 << 20];
int main()
{
    
    init_code();
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    fill(dp, dp + (1 << 20), make_pair(n + 1, 0));
    dp[0] = {1, 0}; // 0 ride 0 weight
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i)) continue;
            auto [ride, weight] = dp[mask];
            int newMask = mask|(1 << i);
            if (nums[i] + weight <= x)
            {
                weight += nums[i];
            }
            else
            {
                ride++;
                weight = nums[i];
            }
            dp[newMask] = min(dp[newMask], {ride, weight});
        }
    }
    ll ans = dp[(1 << n) - 1].first;
    cout << ans;
    return 0;
}