#include <algorithm>
#include <cstring>

using namespace std;

template <class T>
class BinaryIndexedTree
{
public:
	static const int maxn = 1000;

	int n;
	T bit[maxn];

	BinaryIndexedTree(void) : n(0)
	{

	}

	void resize(const int & n)
	{
		memset(bit, 0, sizeof bit[0] * this->n);
		this->n = n;
	}

	void add(const int & x, const T & d)
	{
		for (int i = x + 1; i <= n; i += i & -i)
			bit[i - 1] += d;
	}

	T sum(const int & x)
	{
		T ans = 0;
		for (int i = x; i > 0; i -= i & -i)
			ans += bit[i - 1];
		return ans;
	}

	int lower_bound(T s)
	{
		int ans = 0, k = 0, b = 0;
		for (; (1 << k) <= n; k++);
		for (k--; k >= 0; k--)
		{
			b = 1 << k;
			if (ans + b <= n && bit[ans + b - 1] < s)
			{
				ans ^= b;
				s -= bit[ans - 1];
			}
		}
		return ans;
	}

	int upper_bound(T s)
	{
		int ans = 0, k = 0, b = 0;
		for (; (1 << k) <= n; k++);
		for (k--; k >= 0; k--)
		{
			b = 1 << k;
			if (ans + b <= n && bit[ans + b - 1] <= s)
			{
				ans ^= b;
				s -= bit[ans - 1];
			}
		}
		return ans;
	}
};
