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
typedef tree<int, null_type, less<int>, rb_tree_tag,
			 tree_order_statistics_node_update>// find_by_order(); order_of_key();
	ord_set;
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

int dp[N][2];
int main()
{

	init_code();
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < N; i++)
	{
		dp[i][0] = add(2LL * dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = add(dp[i - 1][0], 4LL * dp[i - 1][1]);
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << add(dp[n][0], dp[n][1]) << "\n";
	}
	return 0;
}