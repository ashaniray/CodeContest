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
#include <cstring>

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

enum Person
{
	None =  -1, Ja = 0, Sam, Sha, Sid, Tan
};

Person GetPerson(const char* szName)
{
	if ( strcmp(szName, "Ja") == 0 )
		return Ja;
	if ( strcmp(szName, "Sam") == 0 )
		return Sam;
	if ( strcmp(szName, "Sha") == 0 )
		return Sha;
	if ( strcmp(szName, "Sid") == 0 )
		return Sid;
	if ( strcmp(szName, "Tan") == 0 )
		return Tan;

	return None;
}

ostream& operator << (ostream& os, Person& p)
{
	switch(p)
	{
		case Ja:
		os << "Ja";
		return os;
		case Sam:
		os << "Sam";
		return os;
		case Sha:
		os << "Sha";
		return os;
		case Sid:
		os << "Sid";
		return os;
		case Tan:
		os << "Tan";
		return os;
	}
	os << "None";
	return os;
}

void ReadInputStream(istream &is)
{
	const int EXCHANGE_TIME = 2;

	int nTestCases = 0;
	is >> nTestCases;
	
	for (int i = 0; i < nTestCases; ++i)
	{
		int M = 0, N = 0;
		char szName[4] = { 0, 0, 0, 0};

		is >> M >> N >> szName;
		Person pIntialSeat = GetPerson(szName);

		Person list [5][20] = {
		None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None, None 
		};


		for (int j = 0; j < 5; ++j)
		{
			int nListLength = 0;
			is >> nListLength;
			for (int k = 0; k < nListLength; ++k)
			{
				string csName;
				is >> csName;
				Person p = GetPerson(csName.c_str());
				list[j][k] = p;
			}
		}

		Person pSitting = pIntialSeat;
		int nTimeLeft = N;
		int nIndexes[5] = {0, 0, 0, 0, 0}; // the pointer
		int Output[5] = {0, 0, 0, 0, 0};
		
		while (nTimeLeft > 0)
		{
			if (nTimeLeft < M)
			{
				Output[pSitting] += nTimeLeft;
				nTimeLeft = 0;
			}
			else
			{
				Output[pSitting] += M;
				nTimeLeft -= M;
			}
			
			// Exchagne
			nTimeLeft -= EXCHANGE_TIME;

			// get the next person
			int nIndex = nIndexes[pSitting];
			Person pNext = list[pSitting][nIndex]; 
			// update the list index of the person
			++nIndex;
			if (list[pSitting][nIndex] == None)
				nIndex = 0;
			nIndexes[pSitting] = nIndex;
			
			// do the actual exchange
			pSitting = pNext;	
		}

		//////////////
		cout << "Case " << i+1 << ":" << endl;
		cout << "Ja " << Output[0] << endl;
		cout << "Sam " << Output[1] << endl;
		cout << "Sha " << Output[2] << endl;
		cout << "Sid " << Output[3] << endl;
		cout << "Tan " << Output[4] << endl;
	}
}


