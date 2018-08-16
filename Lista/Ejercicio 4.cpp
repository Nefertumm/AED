#include <list>
#include <iostream>
using namespace std;

typedef list<int> lista;

void invert(lista &L)
{
    if (L.empty()) return;

    lista::iterator p = L.begin();
    lista::iterator q = L.end();
    q--;
    while (p != q)
    {
        swap(*p, *q);
        if (++p == q--) return;
    }
}



int main() {
    lista L = {1,2,3,4,5,6};
    for (int x : L) cout << x << " ";
    cout << endl;
    invert(L);
    for (int x : L) cout << x << " ";
    return 0;
}
