#include <iostream>
#include <list>
using namespace std;

void reemplazaSecuencia(list<int> &L, list<int>& SEQ, list<int>& REEMP)
{
	if (SEQ.empty() || L.empty()) return;
	list<int>::iterator p = L.begin();
	list<int>::iterator q = SEQ.begin();
	list<int>::iterator r, s;
	bool found = false;
	
	while(p != L.end())
	{
		r=p;
		q=SEQ.begin();
		while(r != L.end() && q != SEQ.end())
		{
			if (*r == *q)
			{
				if (*r == *SEQ.begin()) s=r;
				r++;
				q++;
				found = true;
			}
			else
			{
				r++;
				q=SEQ.begin();
				found = false;
			}
		}
		if (found == true)
		{
			p = L.erase(s,r);
			L.insert(p, REEMP.begin(), REEMP.end());
			found = false;
		}
		else
			p++;
	}
	
}

int main(int argc, char *argv[]) {
	list<int> L = {1,2,3,1000,1000,2000,1,2,3,5455,5797,5487,16631,554,231,4123,45,46,3,32,1,2,3};
	list<int> SEQ = {1,2,3};
	list<int> REEMP = { 1,2,3,4,512,1,2,3 };
	for (int x : L) cout << x << " ";
	cout << endl;
	reemplazaSecuencia(L, SEQ, REEMP);
	for (int x : L) cout << x << " ";
	return 0;
}

