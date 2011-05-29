//#define TEST

#include <iostream>
#ifdef TEST
#include <fstream>
#endif

#include <deque>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

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

struct Player
{
	string m_csName;
	int m_nAttack;
	int m_nDefend;

	Player(string csName = "", int nAttack = 0, int nDefend = 0) :
		m_csName(csName), m_nAttack(nAttack), m_nDefend(nDefend) {}

	friend bool PlayerCmp(const Player& first, const Player& second);
};

bool PlayerCmp(const Player& first, const Player& second)
{
	if (first.m_nAttack < second.m_nAttack)
		return false;
	if (first.m_nAttack > second.m_nAttack)
		return true;

	//Attack is equal, check defence
	if (first.m_nDefend < second.m_nDefend)
		return true;
	if (first.m_nDefend > second.m_nDefend)
		return false;

	//Name	
	return first.m_csName < second.m_csName;
}

void ReadInputStream(istream &is)
{
	int nTestCases = 0;
	is >> nTestCases;
	
	for (int i = 0; i < nTestCases; ++i)
	{
		deque<Player> players;

		for (int j = 0; j < 10; ++j)
		{
			string csPlayer = "";
			int nAttackingAbility = 0, nDefendingAbility = 0;

			is >> csPlayer >> nAttackingAbility >> nDefendingAbility;

			Player p(csPlayer, nAttackingAbility, nDefendingAbility);
			players.push_back(p);
		}
		sort (players.begin(), players.end(), PlayerCmp);

		vector<string> vAttackers;
		vector<string> vDefenders;
		for (int k = 0; k < 5; ++k)
		{
			vAttackers.push_back(players[k].m_csName);
		}
		for (int k = 5; k < 10; ++k)
		{
			vDefenders.push_back(players[k].m_csName);
		}
		sort(vAttackers.begin(), vAttackers.end());
		sort(vDefenders.begin(), vDefenders.end());

		cout << "Case " << i+1 << ":" << endl << "(";
		for (int k = 0; k < 5; ++k)
		{
			if (k != 0)
				cout << ", ";
			cout << vAttackers[k];	
		}
		cout << ")" << endl << "(";
		for (int k = 0; k < 5; ++k)
		{
			if (k != 0)
				cout << ", ";
			cout << vDefenders[k];	
		}
		cout << ")" << endl;
	}
}


