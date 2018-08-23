#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void merge(list<int> &L1, list<int> &L2, list<int> &L)
{
	list<int>::iterator p = L1.begin(), q = L2.begin();
	while (p != L1.end() && q != L2.end())
	{
		if(*p <= *q)
			L.push_back(*p++);
		else
			L.push_back(*q++);
	}
	L.insert(L.end(), p, L1.end());
	L.insert(L.end(), q, L2.end());
}

void mergeSort(list<int> &L)
{
	if (L.size() < 2) return;
	list<int> L1, L2;
	list<int>::iterator p = L.begin();
	advance(p, L.size()/2);
	L1.splice(L1.end(), L, L.begin(), p);
	mergeSort(L1);
	L2.splice(L2.end(), L, p, L.end());
	mergeSort(L2);
	merge(L1,L2,L);
}

int main(int argc, char *argv[]) {
	list<int> L = {31,34,76,4,3,2,5,0,-1};
	for (auto x : L) cout << x << " ";
	cout << endl;
	mergeSort(L);
	for (auto x : L) cout << x << " ";
	return 0;
}

