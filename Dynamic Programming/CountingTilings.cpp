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
int dp[1000][1 << 10];
int n, m;
void generateMask(int mask, vector<int> &nextMasks, int row = 0, int newMask = 0)
{
    if (row == n)
    {
        nextMasks.push_back(newMask);
        return;
    }
    
    if (!(mask & (1 << row)))
    {
        generateMask(mask, nextMasks, row + 1, newMask|(1 << row));
        if (row < n - 1 && !(mask & (1 << (row + 1))))
            generateMask(mask, nextMasks, row + 2, newMask);
    }
    else
    {
        generateMask(mask, nextMasks, row + 1, newMask);
    }
}
int helper(int col, int mask)
{
    if (col == m)
        return mask == 0;
    if (dp[col][mask] != -1)
        return dp[col][mask];
    vector<int> nextMasks;
    generateMask(mask, nextMasks);
    int ans = 0;
    for (auto &newMask: nextMasks)
        ans = add(ans, helper(col + 1, newMask));
    return dp[col][mask] = ans;
}
int main()
{
    
    init_code();
    cin >> n >> m;
    fill(&dp[0][0], &dp[0][0] + 1000 * (1 << 10), -1);
    cout << helper(0, 0);
    return 0;
}