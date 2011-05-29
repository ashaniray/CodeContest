#define TEST

#include <iostream>
#ifdef TEST
#include <fstream>
#endif

#include <deque>
#include <map>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <cstdlib>

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
	for (int i = 0;  ; ++i)
	{
		string csDouble;
		is >> csDouble;

		if (csDouble == "0e0")
			break;

		double d = strtod(csDouble.c_str(), 0);	

		int nExponent = 0;
		double dTemp = d;
		while (dTemp < 1 && dTemp >= 0.5)
		{
			dTemp/= 2;
			nExponent ++;
		}

		double dPower = pow(2, nExponent);

		int nMantissa = 0;
		cout << nMantissa << " " << nExponent << endl;
	}
}


