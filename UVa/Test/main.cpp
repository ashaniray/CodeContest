#define TEST 1

#include <iostream>
#ifdef TEST
#include <fstream>
#endif

#include <vector>
#include <map>
#include <iterator>
#include <climits>

using namespace std;

struct TestCaseInput
{
public:
	TestCaseInput()
	//TODO: Initialize variables
	{
	}

	friend ostream& operator << (ostream& os, const TestCaseInput& input);
};

ostream& operator << (ostream& os, const TestCaseInput& input)
{
	//TODO: implements the os
	return os;
}


void ReadAndProcessInputs(istream &is);
void Process(long nCaseNo, TestCaseInput& input);
bool ReadTestCase(istream& is, TestCaseInput& input);

int main()
{
#ifdef TEST
	ifstream ifs("input.txt");
	if (!ifs)
	{
		cerr << "Error opening input file" << endl;
		return 0;
	}
#endif
#ifdef TEST
	istream & is = ifs;
#else
	istream & is = cin;
#endif

	ReadAndProcessInputs(is);
	return 0;
}

void ReadAndProcessInputs(istream &is)
{
	unsigned long nMaxCaseNumber = ULONG_MAX;

	for (unsigned long nCaseNo = 1; nCaseNo <= nMaxCaseNumber; ++nCaseNo)
	{
		TestCaseInput input;
		if (ReadTestCase(is, input))
		{
			Process(nCaseNo, input);
		}
		else
		{
			// Bad input..
			break;
		}
	}
}

// Return false for end of test case marker.
// Return true otherwise
bool ReadTestCase(istream& is, TestCaseInput& input)
{
	//TODO: Read a single test case
	return true;
}

void Process(long nCaseNo, TestCaseInput& input)
{
	cout << nCaseNo << " : " << input << endl;
	//TODO: The final processing
}

