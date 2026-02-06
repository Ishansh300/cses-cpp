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
int main()
{
    
    init_code();
    int n;
    cin >> n;
    vector<array<int, 3>> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int start, end, val;
        cin >> start >> end >> val;
        nums[i] = {end, start, val};
    }
    sort(all(nums));
    ll dp[n + 1];
    dp[0] = 0;
    vector<int> endTimes;
    endTimes.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int start = nums[i][1], end = nums[i][0], val = nums[i][2];
        int lastIndex = lower_bound(endTimes.begin(), endTimes.end(), start) - endTimes.begin() - 1;
        dp[i] = max(val + dp[lastIndex], dp[i - 1]);
        endTimes.push_back(end);
    }
    cout << dp[n];
    return 0;
}