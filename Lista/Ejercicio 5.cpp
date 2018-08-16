#include <list>
#include <iostream>
using namespace std;


void junta(list<int> &L, int c)
{
    if (L.empty()) return;
    list<int>::iterator p = L.begin();
    int cant = 0;
    int suma = 0;
    while (p != L.end())
    {
		suma += *p;
		p = L.erase(p);
		cant++;
		
		if (c == cant)
		{
			cant = 0;
			p = L.insert(p,suma);
			suma = 0;
			p++;
		}
		else if (p == L.end())
		{
			p = L.insert(p, suma);
			p++;
		}
    }
}


int main() {
    list<int> L = { 1,2,3,4,5,6,7,8,9,10,11 };
    for (int x : L) cout << x << " ";
    cout << endl;
    junta(L,3);
    for (int x : L) cout << x << " ";
    return 0;
}
