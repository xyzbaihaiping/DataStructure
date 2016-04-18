#include "SparseMatrix.hpp"
void TestSparseMatrix()
{
	int a[4][5] = {
		{1,0,4,0,0},
		{2,0,5,0,0},
		{3,3,0,0,0},
		{0,0,6,0,0}
	};
	SparseMatrix<int> Matrix((int *)a, 4, 5, 0);
	Matrix.display();
	cout << "---------" << endl;
	SparseMatrix<int> Matrix1 =Matrix.Transport();
	Matrix1.display();
	cout << "---------" << endl;
	SparseMatrix<int> Matrix2 = Matrix.FastTransport();
	Matrix2.display();
}
int main()
{
	TestSparseMatrix();
	getchar();
	return 0;
}