#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

typedef list<int> lista;

void basic_sort(list<int> &L){
	list <int> L2;
	while(!L.empty()){
		auto it_min = min_element(L.begin(),L.end());
		L2.push_back(*it_min);
		L.erase(it_min);
	}
	swap(L,L2);
}

void selection_sort(lista& L) {
	if (L.empty()) return;
	lista::iterator p = L.begin();
	while(p!=L.end()) {
		lista::iterator q = min_element(p, L.end());
		swap(*p,*q);
		p++;
	}
}

void concatena(lista &L1,lista &L2,lista &L3){
	L3.insert(L3.end(),L1.begin(),L1.end());
	L3.insert(L3.end(),L2.begin(),L2.end());
}

void concatena(list<lista> &L, lista &LL){
	auto p = L.begin();
	while(p != L.end()){
		auto &q = (*p);
		LL.insert(LL.end(),q.begin(),q.end());
		p++;
	}
}

void concatena(list<lista> &L, lista &LL){
	auto p = L.begin();
	while(p != L.end()){
		auto &q = (*p);
		L.splice(L.end(),q.begin(),q.end())
		p++;
	}
}

	


int main() {
	list<int> L1 = { 2,5,6,4,7,3,8,0,6,4,2,3 };
	list<int> L2 = { 2,5,6,4,7,3};
	lista L3;
	for (int x:L1) cout << x << " ";
	cout << endl;
	for (int x:L2) cout << x << " ";
	cout << endl;
	concatena(L1,L2,L3);
	for (int &x:L3) cout << x << " ";
	
	return 0;
}







