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
ll dp[19][11][2];
ll helper(string &nums, int prev, bool tight = true, int index = 0)
{
    if (index == nums.size())
        return 1;
    if (dp[index][prev][tight] != -1)
        return dp[index][prev][tight];
    int ub = tight ? (nums[index] - '0') : 9;
    ll ans = 0;
    for (int i = 0; i <= ub; i++)
    {
        if (i == prev) continue;
        int newPrev = (prev == 10 && i == 0) ? prev : i; 
        ans += helper(nums, newPrev, tight & (i == ub), index + 1);
    }
    return dp[index][prev][tight] = ans;
}
int main()
{
    
    init_code();
    string a, b;
    cin >> a >> b;
    fill(&dp[0][0][0], &dp[0][0][0] + 19 * 11 * 2, (ll)-1);
    ll right = helper(b, 10);
    ll left = 0;
    if (a[0] - '0' > 0)
    {
        fill(&dp[0][0][0], &dp[0][0][0] + 19 * 11 * 2, (ll)-1);
        ll temp = stol(a);
        --temp;
        a = to_string(temp);
        left = helper(a, 10);
    }
    cout << right - left;
    return 0;
}