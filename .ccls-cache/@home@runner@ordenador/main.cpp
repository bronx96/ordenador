#include <iostream>
#include "cod.h"
using namespace std;
int main() {
  int option, len, list[10000], bigO[2];
  //bigO = eficiencia da ordenação
//len = tmanha do vetor, option = ordem do vetor, list = vetor

  bigO[0] = 0;
  bigO[1] = 0;
  //bigO[0] = comparações, bigO[1] = trocas
  
  len = 100;
  preen(len, 3, list);
  insert(len, list, bigO);
  //insertion, heapsort, countingsort
  print(list, len);

  cout << bigO[0] << " e " <<bigO[1]; 
}