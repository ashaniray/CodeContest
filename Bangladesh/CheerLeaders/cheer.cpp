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
#include <sstream>

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

int nBeginSide1Count = 0;
int nEndSide1Count = 0;
int nBeginSide2Count = 0;
int nEndSide2Count = 0;
int nBeginSide3Count = 0;
int nEndSide3Count = 0;
int nBeginSide4Count = 0;
int nEndSide4Count_ExFirst = 0;

bool CheckCondition(const string& csPos)
{
	bool isOne = false;
	bool isTwo = false;
	bool isThree = false;
	bool isFour = false;

	if (csPos[0] == '1')
	{
		isOne = isFour = true;
	}

	if (csPos[nEndSide1Count] == '1')
	{
		isOne = isTwo = true;
	}

	if (csPos[nEndSide2Count] == '1')
	{
		isTwo = isThree = true;
	}

	if (csPos[nEndSide3Count] == '1')
	{
		isThree = isFour = true;
	}

	size_t nFirst = csPos.find('1', nBeginSide1Count);
	if (nFirst != string::npos)
	{
		if (nFirst < nEndSide1Count)
			isOne = true;
	}
	size_t nSecond = csPos.find('1', nBeginSide2Count);
	if (nSecond != string::npos)
	{
		if (nSecond < nEndSide2Count)
			isTwo = true;
	}
	size_t nThird = csPos.find('1', nBeginSide3Count);
	if (nThird != string::npos)
	{
		if (nThird < nEndSide3Count)
			isThree = true;
	}
	size_t nFourth = csPos.find('1', nBeginSide4Count);
	if (nFourth != string::npos)
	{
		isFour = true;
	}

	bool bResult = false;
	if (isOne == true && isTwo == true && isThree == true && isFour == true)
		bResult = true;

	return bResult;	
}

void ReadInputStream(istream &is)
{
	const int MODULO = 1000007;
	int nTestCases = 0;
	is >> nTestCases;
	
	for (int i = 0; i < nTestCases; ++i)
	{
		int nRows = 0;
		int nCols = 0;
		int nCheer = 0;

		is >> nRows >> nCols >> nCheer;

		nBeginSide1Count = 0;
		nEndSide1Count = nCols - 1;
		nBeginSide2Count = nEndSide1Count;
		nEndSide2Count = nBeginSide2Count + nRows - 1;
		nBeginSide3Count = nEndSide2Count;
		nEndSide3Count = nBeginSide3Count + nCols - 1;
		nBeginSide4Count = nEndSide3Count;
		nEndSide4Count_ExFirst = nBeginSide4Count + nRows - 2;

		int nResult = 0;
		
		int nBlanks = nEndSide4Count_ExFirst + 1 - nCheer;

		if (nBlanks == 0)
		{
			nResult = 1;
		}
		else if (nBlanks > 0)
		{

			ostringstream ossZeros;
			for (int j = 0; j < nBlanks; ++j)
			{
				ossZeros << "0";
			}
			string csZeros = ossZeros.str();

			ostringstream ossOnes;
			for (int j = 0; j < nCheer; ++j)
			{
				ossOnes << "1";
			}
			string csOnes = ossOnes.str();

			string csString = csZeros + csOnes;

			while (next_permutation(csString.begin(), csString.end()))
			{
				if (CheckCondition(csString))
					++nResult;
			}
		}

		cout << "Case " << i+1 << ": " << nResult << endl;
	}
}


