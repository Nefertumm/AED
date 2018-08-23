#include <iostream>
#include <string>
#include <list>
#include <cmath>
using namespace std;

list<string> josephus(list<string> &nombres, int n)
{
	list<string> orden;
	if (nombres.empty()) return orden;
	list<string>::iterator p = nombres.begin();
	int mueve;
	if (n > (int)nombres.size())
		mueve = n % (int)nombres.size(); // Sacamos el modulo para ahorrar movimientos en el for.
	else
		mueve = n;
	cout << mueve <<  " ";
	while(!nombres.empty())
	{
		for(int i=0;i<mueve;i++) 
		{ 
			p++;
			if (p == nombres.end())
				p = nombres.begin();
		}
		orden.push_back(*p);
		p = nombres.erase(p);
		if (p == nombres.end())
			p = nombres.begin();
	}
	return orden;
}


int main(int argc, char *argv[]) {
	list<string> nombres = {"a","b","c","d","e","f","g"};
	auto orden = josephus(nombres, rand());
	for (auto x : orden) cout << x << " ";
	cout << endl;
	
	return 0;
}

