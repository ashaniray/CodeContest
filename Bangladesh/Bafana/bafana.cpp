//#define TEST

#include <iostream>
#ifdef TEST
#include <fstream>
#endif

#include <deque>
#include <map>
#include <iterator>
#include <cmath>
#include <algorithm>

using namespace std;

void ReadInputStream(istream &is);

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

	ReadInputStream(is);
	return 0;
}

void ReadInputStream(istream &is)
{
	int nTestCases = 0;
	is >> nTestCases;
	
	for (int i = 0; i < nTestCases; ++i)
	{
		int nStartPlayerK = 0;
		int nPassesP = 0;
		int nPlayersN = 0;

		is >> nPlayersN >> nStartPlayerK >> nPassesP;

		int nResult = (nStartPlayerK + nPassesP - 1) % nPlayersN;
		nResult++;


		cout << "Case " << i+1 << ": " << nResult << endl;
	}
}


