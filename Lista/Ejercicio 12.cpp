#include <iostream>
#include <list>
using namespace std;

void compacta(list<int> &L, list<int> &S)
{
	if (L.empty() || S.empty()) return;
	list<int>::iterator q = S.begin();
	
	while(L.size() > 1 && q != S.end())
	{
		int suma = 0;
		list<int>::iterator p = L.begin(); // No estoy seguro de que en todas las iteraciones se deba volver al inicio de L.
		for(int i=0;i<*q;i++) {
			suma += *p;
			p = L.erase(p);
			if (p==L.end()) break;
		}
		L.insert(L.begin(), suma);
		++q;
	}
}

int main(int argc, char *argv[]) {
	list<int> L = { 1,2,3,4,5,6,7,8,9 }; // valores random de prueba
	list<int> S = { 3,2 };
	for (auto x : L) cout << x << " ";
	cout << endl;
	compacta(L,S);
	for (auto x : L) cout << x << " ";
	cout << endl;
	return 0;
}

