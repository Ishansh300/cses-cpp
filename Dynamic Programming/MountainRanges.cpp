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
const int INF = 1e9 + 5;
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
int helper(int root, vector<int> &nums, vector<int> &left, vector<int> &right, int parHeight = INF)
{
    if (root == -1)
        return 0;
    int leftHeight = helper(left[root], nums, left, right, nums[root]);
    int rightHeight = helper(right[root], nums, left, right, nums[root]);
    int add = (nums[root] < parHeight) ? 1 : 0;
    return add + max(leftHeight, rightHeight);
}
int main()
{
    
    init_code();
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> par(n, -1), left(n, -1), right(n, -1);
    stack<int> ngr_left;
    int root;
    for (int i = 0; i < n; i++)
    {
        int last = -1;
        while (!ngr_left.empty() && nums[ngr_left.top()] <= nums[i])
        {
            last = ngr_left.top();
            ngr_left.pop();
        }
        if (last != -1)
        {
            left[i] = last;
            par[last] = i;
        }
        if (!ngr_left.empty())
        {
            right[ngr_left.top()] = i;
            par[i] = ngr_left.top();
        }
        if (par[i] == -1)
            root = i;
        ngr_left.push(i);
    }
    cout << helper(root, nums, left, right);
    return 0;
}