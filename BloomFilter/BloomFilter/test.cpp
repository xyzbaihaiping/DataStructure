#include "BloomFilter.h"

void Test()
{
	BloomFilter<> bm(100);
	bm.Set("hash");
	bm.Set("hash");
	bm.Set("hahhjl");
	cout <<"hash?"<< bm.Test("hash") << endl;
	cout << "jjjj?" << bm.Test("hash") << endl;
	cout << "hal?" << bm.Test("hash") << endl;
	cout << "vvvv?" << bm.Test("vvvv") << endl;

}
int main()
{
	Test();
	getchar();
	return 0;
}