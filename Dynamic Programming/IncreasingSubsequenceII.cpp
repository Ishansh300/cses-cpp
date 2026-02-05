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
struct BIT{
    int n;
    vector<int> bit;

    BIT(int _n)
    {
        n = _n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta)
    {
        // ++idx;
        for(; idx <= n; idx += (idx & -idx))
          bit[idx] = add(bit[idx], delta);
    }

    int query(int idx)
    {
        // ++idx;
        int sum = 0;
        for(; idx > 0; idx -= (idx & -idx))
            sum = add(sum, bit[idx]);
        return sum;
    }

};

int main()
{
    
    init_code();
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> comp = nums;
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    BIT fen(n);
    int ans = 0;

    for (auto &x: nums)
    {
        int val = lower_bound(all(comp), x) - comp.begin() + 1;
        int dp = 1 + fen.query(val - 1);
        ans = add(ans, dp);
        fen.update(val, dp);
    }
    cout << ans;
    
    return 0;
}