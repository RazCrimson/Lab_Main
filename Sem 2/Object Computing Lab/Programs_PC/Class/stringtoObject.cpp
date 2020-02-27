#include <iostream>
#include <regex>
#include <string>
using namespace std;

class PhoneNo
{
    int std, areaCode, number;

public:
    PhoneNo(string&);
    friend ostream &operator<<(ostream &, const PhoneNo &);
};

PhoneNo::PhoneNo(string& num)
{
	regex regex("\\*");

	vector<string> out(std::sregex_token_iterator(num.begin(), num.end(), regex, -1),std::sregex_token_iterator());

	for (auto &s: out) {
		std::cout << s << '\n';
	}
    std = stoi(out[0]);
	
}

ostream &operator<<(ostream &out, const PhoneNo &p)
{
    out << p.std << '-' << p.areaCode << '-' << p.number;
    return out;
}