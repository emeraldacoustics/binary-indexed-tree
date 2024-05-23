#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
#include <utility>
#include <vector>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
class BinaryIndexedTree2
{
public:
	int n;
	map<T, int> occ;
	vector<ordered_set<pair<T, int> > > bit;

	BinaryIndexedTree2(void) : n(0)
	{

	}

	void resize(const int & n)
	{
		occ.clear();
		bit.clear();
		bit.resize(n);
		this->n = n;
	}

	void insert(const int & x, const T & d)
	{
		pair<T, int> p = make_pair(d, occ[d]++);
		for (int i = x + 1; i <= n; i += i & -i)
			bit[i - 1].insert(p);
	}

	int count(const int & x, const T & l, const T & r)
	{
		int ans = 0;
		for (int i = x; i > 0; i -= i & -i)
			ans += bit[i - 1].order_of_key(make_pair(r, 0)) - bit[i - 1].order_of_key(make_pair(l, 0));
		return ans;
	}

	int search(const T & l, const T & r, int s)
	{
		int ans = 0, k = 0, b = 0;
		for (; (1 << k) <= n; k++);
		for (k--; k >= 0; k--)
		{
			b = 1 << k;
			int i = ans + b, c;
			if (i <= n && (c = bit[i - 1].order_of_key(make_pair(r, 0)) - bit[i - 1].order_of_key(make_pair(l, 0))) <= s)
			{
				ans ^= b;
				s -= c;
			}
		}
		return ans;
	}
};
