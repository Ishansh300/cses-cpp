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
const int N = 1e3 + 1;
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
int prices[N], values[N];
int main()
{
    
    init_code();
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> prices[i];
    for (int i = 1; i <= n; i++)
        cin >> values[i];
    vector<int> dp(x + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        vector<int> temp(x + 1, 0);
        for (int j = 1; j <= x; j++)
        {
            if (prices[i] > j)
                temp[j] = dp[j];
            else
                temp[j] = max(values[i] + dp[j - prices[i]], dp[j]);
        }
        swap(dp, temp);
    }
    cout << dp[x];
    return 0;
}