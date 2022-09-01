#include <iostream>
using namespace std;

int getVal(char nucleotide)
{
	switch (nucleotide) 
	{
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'T':
		return 3;
	default:
		return -1;
	}
}

string getNucleotide(int remainder)
{
	if (remainder == 0)
		return "A";
	else if (remainder == 1)
		return "C";
	else if (remainder == 2)
		return "G";
	else if (remainder == 3)
		return "T";
}

int patternToNumber(string pattern)
{
	//recursively converts string pattern of biological nucleotides (A,C,G,T) into a corresponding decimal number
	//this is done by treating each nucleotide as a single digit in a base-4 number
	//A = 0
	//C = 1
	//G = 2
	//T = 3
	if (pattern.length() > 1) //n-1 problem
	{
		return 4 * patternToNumber(pattern.substr(0, pattern.length() - 1)) + getVal(pattern[pattern.size()-1]);
	}
	else //base case
	{
		return getVal(pattern[pattern.size() - 1]);
	}
}

string numberToPattern(int number)
{
	//iteratively converts decimal number into a corresponding string pattern of biological nucleotides (A,C,G,T)
	//done by dividing number by 4 until the number becomes 0.
	string pattern = "";
	while (number > 0)
	{
		int numToAdd = number % 4;
		pattern += getNucleotide(numToAdd);
		number /= 4;
	}
	reverse(pattern.begin(), pattern.end());
	return pattern;
}

int main()
{
	string genomeExample = "CACGT"; //283
	cout << patternToNumber(genomeExample) << endl;
	int decimalNumberExample = 283; //CACGT
	cout << numberToPattern(decimalNumberExample) << endl;
}