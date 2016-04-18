#include "SymmetricMatrix.hpp"
void TestSymmetricMatrix()
{
	int a[4][4] = {
		{0,1,2,3},
		{1,0,3,4},
		{ 2, 3, 0, 5 },
		{ 3, 4, 5, 0 }
	};
	size_t size = sizeof(a) / sizeof(a[0][0]);
	SymmetricMatrix<int> matrix((int *)a, size, 4);
	matrix.display();
	cout << matrix.Access(2,3) << endl;
}
int main()
{
	TestSymmetricMatrix();
	getchar();
	return 0;
}