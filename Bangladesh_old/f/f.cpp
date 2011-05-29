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
		int nMax = 0;
		int nValue = 0;
		
		int nStudents = 0;
		is >> nStudents;
		for (int j = 0; j < nStudents; ++j)
		{
			is >> nValue;
			if (nMax < nValue)
				nMax = nValue;
		}
		cout << "Case " << i+1 << ": " << nMax << endl;
	}
}


