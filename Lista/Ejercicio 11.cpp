#include <iostream>
#include <list>
#include <string>
using namespace std;

bool is_palindromo(string S)
{
	list<char> palindromo;
	
	for(int i=0;i<S.size();i++) { 
		if (S[i] != ' ')
			palindromo.push_back(S[i]); 
	}
	list<char>::iterator p = palindromo.begin();
	list<char>::iterator q = palindromo.end();
	q--;
	while(p != q)
	{
		if (*p != *q)
			return false;
		if (++p == q--) break;
	}
	return true;
}

int main(int argc, char *argv[]) {
	string S = "alli si maria avisa y asi va a ir a mi silla";
	cout << is_palindromo(S) << endl;
	return 0;
}

