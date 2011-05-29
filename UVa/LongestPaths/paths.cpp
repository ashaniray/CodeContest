#define TEST 1

#include <iostream>
#ifdef TEST
#include <fstream>
#endif

#include <vector>
#include <map>
#include <iterator>

using namespace std;

void ReadInputStream(istream &is);
void Process(int nCaseNo, int nMaxPoints, int nStart, vector<pair<int, int> >& vpEdges);

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
	for (int nCaseNo = 1; ; ++nCaseNo)
	{
		int nPoints = 0;
		is >> nPoints;

		if (nPoints == 0)
			return;
		
		int nStartingPoint = 0;
		is >> nStartingPoint;

		int nFirst = 0, nSecond = 0;
		vector<pair<int, int> > vpEdges;
		while (1)
		{
			is >> nFirst >> nSecond;
			if (nFirst == 0 && nSecond == 0)
				break;

			vpEdges.push_back(make_pair(nFirst, nSecond));
		}
		Process(nCaseNo, nPoints, nStartingPoint, vpEdges);
	}
}

void Process(int nCaseNo, int nMaxPoints, int nStart, vector<pair<int, int> >& vpEdges)
{
	int nLength = 0;
	int nFinishPoint = 0;
	cout << "Case " << nCaseNo << ": The longest path from " <<
		nStart << " has length " << nLength
		<< ", finishing at " << nFinishPoint << "."
		<< endl;
}

