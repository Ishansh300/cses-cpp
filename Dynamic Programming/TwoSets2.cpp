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
const int N = 125001;
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
int dp[N];
int main()
{
    
    init_code();
    int n;
    cin >> n;
    fill(dp, dp + N, 0);
    int sum = (n * (n + 1)) / 2;
    if (sum % 2)
        cout << 0;
    else
    {
        sum /= 2;
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= i; j--)
            {
                dp[j] = add(dp[j], dp[j - i]);
            }
        }
        long long inv2 = (MOD + 1) / 2;
        cout << mul(dp[sum], inv2);
    }
    return 0;
}