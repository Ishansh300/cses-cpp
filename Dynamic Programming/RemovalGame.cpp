
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
const int N = 5002;
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
ll dp[5000][5000];
ll helper(vector<int> &nums, int i, int j)
{
    if (i == j)
        return nums[i];
    if (dp[i][j] != 1e18)
        return dp[i][j];
    ll takeLeft = nums[i] - helper(nums, i + 1, j);
    ll takeRight = nums[j] - helper(nums, i, j - 1);
    return dp[i][j] = max(takeLeft, takeRight);
}
 
int main()
{
    
    init_code();
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    fill(&dp[0][0], &dp[0][0] + 5000LL * 5000, (ll)1e18);
    ll gain = helper(nums, 0, n - 1);
    ll ans = (accumulate(all(nums), 0LL) + gain) / 2;
    cout << ans;
    return 0;
}