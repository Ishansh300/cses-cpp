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
const int N = 1e6 + 2;
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
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    for (int i = 0; i < m; i++)
        cin >> nums2[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (nums1[i] == nums2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);   
        }
    }
    cout << dp[0][0] << "\n";
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            cout << nums1[i] << " ";
            i++; j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
            i++;
        else
            j++;
    }
 
    return 0;
}