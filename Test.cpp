#include "Test.h"

void Test::call_test(const DataStruct& ds)
{
	switch (ds)
	{
	case TESTSEQLIST:
			test_seqlist();
			break;
	case TESTSINGLELIST:
		test_seqlist();
		break;
	default:
		std::cout << "the input data struct type error" << std::endl;
		break;
	}
}

void Test::test_seqlist()
{
	Seqlist<int> test(20);
	int array[15] = { 2,5,8,1,9,9,7,6,4,3,2,9,7,7,9 };
	for (int i = 0; i < 15; i++) {
		test.insert(array[i], 0);
	}
	test.insert(1, 0);
	std::cout << (test.find(0) ? "not found" : "found") << 0 << std::endl << std::endl;
	test.remove(7);
	test.print();
}

void Test::test_singlelist()
{
	SingleList<int> list;
	for (int i = 0; i < 20; i++) {
		list.insert(i * 3, i);
	}
	for (int i = 0; i < 5; i++) {
		list.insert(3, i * 3);
	}
	std::cout << "the length of the list is " << list.length() << std::endl;
	list.print();

	list.remove(5);
	list.print();

	list.removeAll(3);
	list.print();

	std::cout << list.get(3) << std::endl;
	std::cout << list.find(18, 1) << std::endl;

	list.makeEmpty();
	list.print();
}
