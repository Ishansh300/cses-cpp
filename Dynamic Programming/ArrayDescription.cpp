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
const int N = 1e5 + 1;
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
int dp[N][101];
int helper(vector<int> &nums, int m, int index = 0)
{
    if (index == nums.size())
    {
        return 1;
    }
    if (nums[index] == 0)
    {
        int left = 1, right = m;
        if (index != 0)
        {
            left = max(1, nums[index - 1] - 1);
            right = min(nums[index - 1] + 1, m);
        }
        // debug(index, left, right);
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            nums[index] = i;
            if (dp[index][i] == -1)
                dp[index][i] = helper(nums, m, index + 1);
            ans = add(ans, dp[index][i]);
        }
        nums[index] = 0;
        return ans;
    }
    else
    {
        if (index > 0 && abs(nums[index] - nums[index - 1]) > 1)
            return 0;
        else
            return helper(nums, m, index + 1);
    }
}
int main()
{
    init_code();
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    fill(&dp[0][0], &dp[0][0] + N * 101, -1);
    cout << helper(nums, m);
    return 0;
}