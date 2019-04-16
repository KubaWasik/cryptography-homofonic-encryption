#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <random>
#include <sstream>
#include <algorithm>

using namespace std;

class Homophone
{
private:
	string cipher;
	map<char, int> frequency{
		make_pair('x',1), make_pair('v',1), make_pair('q',1), make_pair('f',1),
		make_pair('h',2), make_pair('g',2), make_pair('b',2), make_pair('l',3),
		make_pair('j',3), make_pair('u',3), make_pair('m',3), make_pair('p',4),
		make_pair('d',4), make_pair('k',4), make_pair('y',4), make_pair('c',4),
		make_pair('t',4), make_pair('s',5), make_pair('w',5), make_pair('r',5),
		make_pair('n',6), make_pair('z',6), make_pair('e',8), make_pair('o',8),
		make_pair('i',9), make_pair('a',9)
	};
	map<char, int> number_of_occurrences;
	map<char, vector<int>> homophones;
	random_device rd;
	typedef mt19937 MyRng;
	MyRng rng;
public:
	Homophone(string);
	friend ostream & operator << (ostream &, Homophone const &);
	bool is_in_table(int);
	string encrypt(string);
	string decrypt(string);
	bool is_number(const string &s);
	int random_int(int, int);

	~Homophone();
};

