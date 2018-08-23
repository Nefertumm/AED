#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


void ordena(list<int> &L, bool (*f)(int,int))
{
	if (L.empty()) return;
	list<int>::iterator p = L.begin();
	while(p != L.end())
	{
		list<int>::iterator q = p;
		q++;
		while (q != L.end())
		{
			if (f(*p,*q))
				swap(*p, *q);
			q++;
		}
		p++;
	}
}

int main(int argc, char *argv[]) {
	list<int> L = { 12,31,4,5,6,32,0,-5,6,17 };
	for (auto x : L) cout << x << " ";
	cout << endl;
	// x menor que y	
	ordena(L, [](int x, int y) -> bool {
		return x < y;
	});
	for (auto x : L) cout << x << " ";
	cout << endl;
//	// x mayor que y
	ordena(L, [](int x, int y) -> bool {
		return x > y;
	});
	for (auto x : L) cout << x << " ";
	cout << endl;
//	// valor absoluto
	ordena(L, [](int x, int y) -> bool {
		return abs(x) < y;
	});
	for (auto x : L) cout << x << " ";
	cout << endl;
	
	return 0;
}

