//#define TEST 1

#include <iostream>
#ifdef TEST
#include <fstream>
#endif

#include <vector>
#include <map>
#include <iterator>
#include <climits>
#include <cstring>

using namespace std;

struct TestCaseInput
{
	int nLength;
	int nCuts;
//	vector<int> vPos;
	int vPos[50];
public:
	TestCaseInput()
	: nLength(0)
	, nCuts(0)
	{
		memset(vPos, 0, 50*sizeof(int));
	}

	friend ostream& operator << (ostream& os, const TestCaseInput& input);
};

ostream& operator << (ostream& os, const TestCaseInput& input)
{
	os << "Length: " << input.nLength << " Cut: " << input.nCuts << " Pos: ";
	copy(input.vPos, input.vPos + 50, ostream_iterator<int>(os, " "));
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

bool ReadTestCase(istream& is, TestCaseInput& input)
{
	is >> input.nLength;
	if (input.nLength == 0)
		return false;

	is >> input.nCuts;
	for (int i = 0; i < input.nCuts; ++ i)
	{
		is >> input.vPos[i];
	}
	return true;
}

unsigned long getLength(int i, int j, int *pLengths)
{
	if (i < j)
		return 0;

	unsigned long sum = 0;
	for (int k = 0; k <= j; ++k)
	{
		sum += pLengths[i - k];
	}
	return sum;
}

void Process(long nCaseNo, TestCaseInput& input)
{
#ifdef TEST
	cout << nCaseNo << " " << input << endl;
#endif
	int nMinCutting = -1;

	int nPieces = input.nCuts + 1;
	int *pLengths = new int [nPieces];
	pLengths[0] = input.vPos[0];

	for (int ii = 1; ii < input.nCuts; ++ii)
	{
		pLengths[ii] = input.vPos[ii] - input.vPos[ii-1];
	}
	pLengths[input.nCuts] = input.nLength - input.vPos[input.nCuts - 1];
	unsigned long table [50][50];
	memset(table, 0, 50*50*sizeof(unsigned long));

#ifdef TEST
	cout << "Lengths :" << endl;
	copy(pLengths, pLengths + input.nCuts + 1, ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "----------------------------------------" << endl;
	copy(table[0], table[0] + nPieces, ostream_iterator<unsigned long>(cout, "\t"));
	cout << endl;
#endif
	

	
	for (int j = 1; j < nPieces; ++j)
	{
		for (int i = 0; i < nPieces; ++i)	
		{
			if (j > i)
				continue;

			unsigned long lLen = getLength(i, j, pLengths);
			unsigned long lMin = ULONG_MAX;
			for (long k = 0; k <= j - 1; ++k)
			{
				unsigned long lSum = table[k][i - j + k] + table[j-1-k][i];
				if (lSum < lMin)
					lMin = lSum;
			}
			table[j][i] = lMin + lLen;
		}
#ifdef TEST
		copy(table[j], table[j] + nPieces, ostream_iterator<unsigned long>(cout, "\t"));
		cout << endl;
#endif
	}

	delete [] pLengths;
	pLengths = 0;

	nMinCutting = table[nPieces - 1][nPieces - 1];

	cout << "The minimum cutting is " << nMinCutting << "." << endl;
}

