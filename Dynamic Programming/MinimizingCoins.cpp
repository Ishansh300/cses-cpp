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
const int N = 1e6 + 1;
const int INF = 1e9;
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

int dp[N];
int main()
{
    
    init_code();
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    fill(dp, dp + N, INF);
    sort(all(nums));
    for (int sum = 1; sum <= x; sum++)
    {
        for (auto &coin: nums)
        {
            if (coin > sum) break;
            if (coin == sum)
                dp[sum] = 1;
            else if (dp[sum - coin] != INF)
                dp[sum] = min(dp[sum], 1 + dp[sum - coin]);
        }
    }
    int ans = (dp[x] == INF) ? -1 : dp[x];
    cout << ans;
    return 0;
}