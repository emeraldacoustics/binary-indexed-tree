#include <algorithm>
#include <vector>

using namespace std;

template <class T>
class BinaryIndexedTree2
{
public:
	int n;
	vector<vector<T> > bit;

	BinaryIndexedTree2(void) : n(0)
	{
 
	}
 
	void resize(const int & n)
	{
		bit.clear();
		bit.resize(n);
		this->n = n;
	}
 
	void insert(const int & x, const T & d)
	{
		for (int i = x + 1; i <= n; i += i & -i)
			bit[i - 1].push_back(d);
	}
 
	void update(void)
	{
		for (int i = 0; i < n; i++)
			sort(bit[i].begin(), bit[i].end());
	}
 
	int count(const int & x, const T & l, const T & r)
	{
		int ans = 0;
		for (int i = x; i > 0; i -= i & -i)
			ans += lower_bound(bit[i - 1].begin(), bit[i - 1].end(), r) - lower_bound(bit[i - 1].begin(), bit[i - 1].end(), l);
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
			if (i <= n && (c = lower_bound(bit[i - 1].begin(), bit[i - 1].end(), r) - lower_bound(bit[i - 1].begin(), bit[i - 1].end(), l)) <= s)
			{
				ans ^= b;
				s -= c;
			}
		}
		return ans;
	}
};
