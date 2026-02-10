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
const int N = 2e5;
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
struct segtree{
    vector<int> seg;
    int s, e;
    segtree(int n)
    {
        seg.resize(4 * n);
        s = 0; e = n - 1;
    }
    void build(vector<int> &arr, int start = -1, int end = -1, int node = 0)
    {
        if (start == -1 && end == -1)
        {
            start = s; end = e;
        }
        
        if (start == end)
        {
            seg[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, start, mid, 2 * node + 1);
        build(arr, mid + 1, end, 2 * node + 2);
        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }
    int query(int left, int right, int start = -1, int end = -1, int node = 0)
    {
        if (start == -1 && end == -1)
        {
            start = s; end = e;
        }
        if(end < left || start > right)
            return 0;
        if(start >= left && end <= right)
            return seg[node];
        int mid = start + (end - start) / 2;
        int x = query(left, right, start, mid, 2 * node + 1);
        int y = query(left, right, mid + 1, end, 2 * node + 2);
        return max(x, y);
    }
    void update(int index, int val, int start = -1, int end = -1, int node = 0)
    {
        if (start == -1 && end == -1)
        {
            start = s; end = e;
        }
        if (start == end)
        {
            seg[node] += val;
            return;
        }
        int mid = start + (end - start) / 2;
        if(index <= mid)
            update(index, val, start, mid, 2 * node + 1);
        else
            update(index, val, mid + 1, end, 2 * node + 2);
        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }
    int findKth(int val, int start = -1, int end = -1, int node = 0)
    {
        if (start == -1 && end == -1)
        {
            start = s; end = e;
        }
        if (seg[node] < val)
            return -1;
        if (start == end)
            return start;
        int mid = start + (end - start) / 2;
        if (seg[2 * node + 1] >= val)
            return findKth(val, start, mid, 2 * node + 1);
        else
            return findKth(val, mid + 1, end, 2 * node + 2);
    }
};
int main()
{
    
    init_code();
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    segtree st(n);
    st.build(nums);
    while (m--)
    {
        int req;
        cin >> req;
        int index = st.findKth(req);
        if (index == -1)
            cout << 0 << " ";
        else
        {
            st.update(index, -req);
            cout << index + 1 << " ";
        }
    }
    return 0;
}