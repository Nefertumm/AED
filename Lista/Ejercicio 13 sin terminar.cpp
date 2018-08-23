#include <iostream>
#include <list>
using namespace std;
// Mal planteado 4sure
list<int> maxSublist(list<int> &L)
{
	list<int> max;
	if (L.empty()) return max;
	list<int>::iterator p = L.begin();
	int suma_aux = 0;
	int suma_lista = 0;
	while (p != L.end())
	{
		suma_aux += *p;
		if ( suma_aux > suma_lista )
		{
			suma_lista += *p;
			suma_aux += *p;
			max.push_back(*p);
			++p;
		}
		else
		{
			suma_aux = 0;
			++p;
		}
	}
	return max;
}

int main(int argc, char *argv[]) {
	list<int> L = {1,2,-5,4,-3,2};
	for (auto x : L) cout << x << " ";
	cout << endl;
	list<int> S = maxSublist(L);
	for (auto x : S) cout << x << " ";
	cout << endl;
	return 0;
}

