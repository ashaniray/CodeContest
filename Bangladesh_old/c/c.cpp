#include <iostream>
#include <deque>
#include <map>
#include <iterator>
#include <cmath>
#include <algorithm>

using namespace std;

long Distance(const pair<int, int>& first, const pair<int, int>& second);
void ReadInputStream(istream &is);
void Compute(int nTestCase, deque<pair<int, int> >& dqFirst, deque<pair<int, int> >& dqSecond);

int main()
{
	istream & is = cin;

	ReadInputStream(is);
	return 0;
}

void ReadInputStream(istream &is)
{
	int nTestCases = 0;
	is >> nTestCases;
	
	for (int i = 0; i < nTestCases; ++i)
	{
		int nPoints1 = 0, nPoints2 = 0;
		is >> nPoints1 >> nPoints2;

		deque<pair<int, int> > dqPoint1;
		for (int j = 0; j < nPoints1; ++j)
		{
			int x = 0, y = 0;
			is >> x >> y;
			dqPoint1.push_back(make_pair(x,y));
		}

		deque<pair<int, int> > dqPoint2;
		for (int k = 0; k < nPoints2; ++k)
		{
			int x = 0, y = 0;
			is >> x >> y;
			dqPoint2.push_back(make_pair(x,y));
		}

		Compute(i+1, dqPoint1, dqPoint2);
	}
}


long Distance(const pair<int, int>& first, const pair<int, int>& second)
{
	int xDiff = first.first - second.first;
	int yDiff = first.second - second.second;

	double d = sqrt(xDiff*xDiff + yDiff*yDiff);

	long lRet = (long)(d + 0.5);
	cout << "Diff for (" << first.first << "," << first.second << ") " << 
		" and second ( " << second.first << "," << second.second << ") " << 
		" is " << lRet << endl;
	return lRet;
}

void Compute(int nTestCase, deque<pair<int, int> >& dqFirst, deque<pair<int, int> >& dqSecond)
{
	deque<int> dqDist;
	typedef deque<pair<int, int> >::iterator PointIterator;
	PointIterator iterFirstEnd = dqFirst.end();
	for (PointIterator iterFirst = dqFirst.begin(); iterFirst != iterFirstEnd; ++iterFirst)
	{
		PointIterator iterSecondEnd = dqSecond.end();
		for (PointIterator iterSecond = dqSecond.begin(); iterSecond != iterSecondEnd; ++iterSecond)
		{
			long lDist = Distance(*iterFirst, *iterSecond);
			dqDist.push_back(lDist);
		}
	}

	long nMaxVal = *max_element(dqDist.begin(), dqDist.end());
	long nMinVal = *min_element(dqDist.begin(), dqDist.end());
	long nResult = nMaxVal - nMinVal;
	cout << "Case " << nTestCase << ":" << nResult << endl;
}
