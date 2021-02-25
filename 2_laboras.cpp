#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <bitset>
using namespace std;
void Unicode(int& temp);
void UTF8(int& temp, string &utf);
void Binary(string byte);
int main()
{
	string utf;
	int temp;
	Unicode(temp);
	UTF8(temp, utf);
}
void Unicode(int &temp)
{
	stringstream ss;
	cout << "Iveskite skaiciu: ";
	cin >> temp;
	ss << "U+" << uppercase << setfill('0') << setw(4) << hex << temp;
	cout << ss.str() << endl;
}
void UTF8(int& temp,string &utf)
{
	stringstream ss;
	string byte1;
	string byte2;
	string byte3;
	string byte4;
	unsigned n;
	if (temp > 0 && temp < 128)
	{
		ss << hex << temp;
		cout << ss.str();
	}
	else if (temp >= 128 && temp < 2048)
	{
		ss << hex << temp;
		ss >> n;
		bitset <16> bit(n);
		string utf(bit.to_string());
		byte1 = "110" + utf.substr(5,5);
		byte2 = "10" + utf.substr(10);
		Binary(byte1);
		Binary(byte2);
	}
	else if (temp >= 2048 && temp < 65535)
	{
		ss << hex << temp;
		ss >> n;
		bitset <24> bit(n);
		string utf(bit.to_string());
		byte1 = "1110" + utf.substr(8, 4);
		byte2 = "10" + utf.substr(12,6);
		byte3 = "10" + utf.substr(18);
		Binary(byte1);
		Binary(byte2);
		Binary(byte3);
}
	else
	{
		ss << hex << temp;
		ss >> n;
		bitset <33> bit(n);
		string utf(bit.to_string());
		byte1 = "11110" + utf.substr(12, 3);
		byte2 = "10" + utf.substr(15,6);
		byte3 = "10" + utf.substr(21, 6);
		byte4 = "10" + utf.substr(27);
		Binary(byte1);
		Binary(byte2);
		Binary(byte3);
		Binary(byte4);
	}
}
void Binary(string byte)
{
	stringstream ss;
	bitset <8>lab(byte);
	unsigned n1 = lab.to_ulong();
	ss << uppercase << hex << n1;
	string bs1(ss.str());
	cout << bs1 << " ";
}