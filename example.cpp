#include "binary_indexed_tree_vector.hpp"
#include "binary_indexed_tree2_vector.hpp"
#include <iostream>

using namespace std;

int main()
{
	BinaryIndexedTree<int> BIT;
	BinaryIndexedTree2<int> BIT2;

	BIT.resize(4);

	BIT.add(0, 4);
	BIT.add(1, 2);
	BIT.add(2, 3);
	BIT.add(3, 7);

	cout << BIT.sum(4) - BIT.sum(0) << endl;

	return 0;
}