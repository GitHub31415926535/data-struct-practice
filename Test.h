#pragma once
#include "Seqlist.h"
#include "SingleList.h"
class Test
{
public:
	enum DataStruct {
		TESTMIN,
		TESTSEQLIST,
		TESTSINGLELIST,
		TESTMAX,
	};

	void call_test(const DataStruct &ds);

private:
	void test_seqlist();
	void test_singlelist();
};

