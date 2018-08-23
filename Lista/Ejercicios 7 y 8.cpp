#include <iostream>
#include <list>
#include <vector>
using namespace std;

void ascendente1(list<int> &L, list<list<int>> &LL)
{
	if (L.empty()) return;
	list<int>::iterator p = L.begin();
	list<int> aux;
	int last_number;
	
	aux.push_back(*p);
	last_number = *p;
	p++;
	while (p != L.end())
	{
		if (*p <= last_number)
		{
			LL.push_back(aux);
			aux.clear();
		}
		aux.push_back(*p);
		last_number = *p;
		p++;
		if (p == L.end()) LL.push_back(aux);
	}
}

void ascendente2(list<int> &L, vector<list<int>> &VL) 
{
	if (L.empty()) return;
	list<int>::iterator p = L.begin();
	list<int> aux;
	int last_number;
	
	aux.push_back(*p);
	last_number = *p;
	p++;
	while (p != L.end())
	{
		if (*p <= last_number)
		{
			VL.push_back(aux);
			aux.clear();
		}
		aux.push_back(*p);
		last_number = *p;
		p++;
		if (p == L.end()) VL.push_back(aux);
	}
}

int main(int argc, char *argv[]) {
	list<int> L = { 1,2,3,1,2,5,6,9,4,6,5,7,3,1,2,10 };
	// ascendente1
	list<list<int>> LL; cout << "Lista: ";
	for (auto x : L) cout << x << " ";
	cout << endl;
	ascendente1(L, LL);
	cout << "Listas generadas: " << endl;
	for (auto x : LL) {
		for (auto y : x) cout << y << " ";
		cout << endl;
	}
	cout << endl;
	// ascendente2
	
	vector<list<int>> VL; cout << "Lista: ";
	for (auto x : L) cout << x << " ";
	cout << endl;
	ascendente2(L, VL);
	cout << "Listas generadas: " << endl;
	for (auto x : VL) {
		for (auto y : x) cout << y << " ";
		cout << endl;
	}
	return 0;
}

