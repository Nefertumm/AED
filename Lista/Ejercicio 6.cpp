#include <iostream>
#include <list>
using namespace std;

void reemplazaSecuencia(list<int> &L, list<int>& SEQ, list<int>& REEMP)
{
	if (SEQ.empty() || L.empty()) return;
	list<int>::iterator p = L.begin();
	
	
	while(p != L.end())
	{
		bool found = false;
		list<int>::iterator r = p;
		list<int>::iterator q = SEQ.begin();
		while(r != L.end() && q != SEQ.end())
		{
			if (*r == *q)
			{
				r++;
				q++;
				found = true;
			}
			else
			{
				found = false;
				break;
			}
		}
		if (found == true)
		{
			p = L.erase(p,r);
			L.insert(p, REEMP.begin(), REEMP.end());
			for(int i=0;i<REEMP.size();i++) { p++; }
			found = false;
		}
		else
			p++;
	}
	
}

int main(int argc, char *argv[]) {
	list<int> L = {1,2,3,4,5,6,1,2,7,8,1,2,3};
	list<int> SEQ = {1,2,3};
	list<int> REEMP = { 9,9,9,9 };
	for (int x : L) cout << x << " ";
	cout << endl;
	reemplazaSecuencia(L, SEQ, REEMP);
	for (int x : L) cout << x << " ";
	return 0;
}

