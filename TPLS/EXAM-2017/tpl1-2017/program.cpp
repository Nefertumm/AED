#define USECHRONO
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include "eval.hpp"

using namespace aed;
using namespace std;

bool antes_que(list<int>& L1, list<int>::iterator p, list<int>::iterator q)
{
  if (p == q) return false;
  bool p_found = false;
  list<int>::iterator r = L1.begin();
  while (r != L1.end())
  {
    if (r == p && !p_found)
      p_found = true;
    if (r == q && !p_found)
      return false;
    r++;
  }
  return true;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void extract_range(list<int> &L1, list<int>::iterator p, 
                   list<int>::iterator q, list<int> &L2) 
{
  if (antes_que(L1, p, q))
  {
    while (p != q)
    {
      L2.push_back(*p);
      p = L1.erase(p);
    }
  }
}

bool esta(vector<int> rep, int x)
{
  auto p = find(rep.begin(), rep.end(), x);
  if (p != rep.end())
    return true;
  return false;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int add_elements(list<int>& L, stack<int> &S) 
{
  vector<int> repetidos;
  if (L.empty()) return (int)repetidos.size();
  list<int>::iterator p = L.begin();
  while (!S.empty())
  {
    if (S.top() <= *p)
    {
      L.insert(p, S.top());
      S.pop();
      p = L.begin();
    }
    else
      p++;
    if (p == L.end())
    {
      L.insert(p, S.top());
      S.pop();
      p = L.begin();
    }
  }
  
  p = L.begin(); // No me gusta para nada esto.
  int ant_valor = *p;
  p++;
  while (p != L.end())
  {
    if (*p == ant_valor && !esta(repetidos, *p))
      repetidos.push_back(*p);
    ant_valor = *p;
    p++;
  }
  
  return (int)repetidos.size();
}

void divisors(int x, list<int> &divs)
{
  for(int i=2;i<=x;i++)
  {
    if (x % i == 0)
      divs.push_back(i);
  }
}

bool coprimos(int x, int y)
{
  list<int> divX, divY;
  divisors(x, divX);
  divisors(y, divY);
  list<int>::iterator p = divX.begin();
  list<int>::iterator q = divY.begin();
  while (p != divX.end() || q != divY.end())
  {
    if (*p == *q)
      return false;
    p++;
    q++;
  }
  return true;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
bool coprimos(list<int>&L) {
  auto p = L.begin();
  while (p!=L.end())
  {
    auto q = p;
    q++;
    while (q != L.end())
    {
      if (!coprimos(*p, *q))
        return false;
      q++;
    }
    p++;
  }
  return true;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  ev.eval<1>(extract_range,vrbs);
  h1 = ev.evalr<1>(extract_range,seed,vrbs);
  
  ev.eval<2>(add_elements,vrbs);
  h2 = ev.evalr<2>(add_elements,seed,vrbs);
  
  ev.eval<3>(coprimos,vrbs);
  h3 = ev.evalr<3>(coprimos,seed,vrbs);

  printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
         seed,h1,h2,h3);
  
  return 0;
}
