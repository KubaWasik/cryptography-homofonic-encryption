#include "pch.h"
#include "Homophone.h"

Homophone::Homophone(string text, bool use_polish_frequency_table)
	: rng(rd())
{
	locale_pl = locale("pl_PL.UTF8");
	rng.seed(::time(NULL));
	for (int i = 0; i < text.length(); i++)
	{
		if (isalpha(text[i], locale_pl))
		{
			number_of_occurrences[text[i]] += 1;
		}
	}

	if (use_polish_frequency_table)
	{
		for (const auto &it : number_of_occurrences)
		{
			if (frequency[it.first] > 0)
			{
				while (homophones[it.first].size() < frequency[it.first])
				{
					int number = random_int(10, 226);
					if (not_in_table(number))
					{
						homophones[it.first].push_back(number);
					}
				}
			}
		}
	}
	else
	{
		for (const auto &it : number_of_occurrences)
		{
			if (frequency[it.first] > 0)
			{
				while (homophones[it.first].size() < number_of_occurrences[it.first])
				{
					int number = random_int(10, text.length() + 10);
					if (not_in_table(number))
					{
						homophones[it.first].push_back(number);
					}
				}
			}
		}
	}
}

bool Homophone::not_in_table(int number)
{
	for (const auto &it : homophones) {
		auto at = find(homophones[it.first].begin(), homophones[it.first].end(), number);
		if (distance(homophones[it.first].begin(), at) != homophones[it.first].size()) {
			return false;
		}
	}
	return true;
}

string Homophone::encrypt(string text)
{
	this->cipher = "";
	for (int i = 0; i < text.length(); i++)
	{
		if (frequency[text[i]] > 0)
		{
			int index = random_int(0, homophones[text[i]].size() - 1);
			this->cipher += to_string(homophones[text[i]][index]);
			this->cipher += " ";
		}
		else
		{
			if (text[i] == ' ')
			{
				this->cipher += "_ ";
			}
			else
			{
				this->cipher += text[i];
				this->cipher += " ";
			}
		}
	}
	return this->cipher;
}

string Homophone::decrypt(string cipher)
{
	string text;
	istringstream iss(cipher);
	string s;
	int number;
	while (getline(iss, s, ' '))
	{
		if (!isalpha(s.c_str(), locale_pl))
		{
			number = atoi(s.c_str());
			if (number >= 10)
			{
				for (const auto &it : homophones)
				{
					auto at = find(homophones[it.first].begin(),
						homophones[it.first].end(), number);
					if (distance(homophones[it.first].begin(), at) != homophones[it.first].size())
					{
						text += it.first;
					}
				}
			}
			else
			{
				text += s;
			}
		}
		else
		{
			if (s == "_")
			{
				text += " ";
			}
			else
			{
				text += s;
			}
		}
	}
	return text;
}

bool Homophone::is_number(const string & s)
{
	return !s.empty() && find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

Homophone::~Homophone()
{
}

int Homophone::random_int(int l, int r)
{
	uniform_int_distribution<int> dist(l, r);
	return dist(rng);
}

ostream & operator<<(ostream &output, Homophone const &table)
{
	output << "znak\tliczby\n";
	for (const auto &it1 : table.homophones)
	{
		output << it1.first << ":\t";
		for (const auto &it2 : it1.second)
		{
			output << it2 << " ";
		}
		output << endl;
	}
	return output;
}
