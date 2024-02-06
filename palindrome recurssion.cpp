#include<iostream>
using namespace std;

bool palindrome(string str, int len,int index)
{
	if (index > len)
		return true;
	if (str[index] != str[len])
		return false;
	palindrome(str, len - 1, index + 1);
}

void main()
{
	string str = "madam";
	int len = size(str);
	
	if(palindrome(str, len, 0))
		cout << "\nstring is palindrome";
	else
		cout << "\nstring is not palindrome";
}