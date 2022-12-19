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

  cout << "quantas variaveis você decide testar\n1. 10\n2. 100\n3. 1000\n4. 10000\n";
  cin >> option;
  switch (option){
    case 1 :
    len = 10;
    break;

    case 2 :
    len = 100;
    break;

    case 3 :
    len = 1000;
    break;

    case 4 :
    len = 10000;
    break;
  }
  cout << "como quer adicionar os elementos.\n1. crecente\n2. decrecente\n3. aleatorio\n4. adicionar entradas\n";
  cin >> option;
  switch (option){
    case 1 :
    preen(len, 1, list);
    break;

    case 2 :
    preen(len, 2, list);
    break;

    case 3 :
    preen(len, 3, list);
    break;

    case 4 :
    preen(len, 4, list);
    break;
  }
  cout << "deseja exibir lista antes da ordenação?\n1. sim\n2. não\n";
  cin >> option;
  if(option == 1){
    print(list, len);
  }
  cout << "qual ordenação deseja fazer?\n1. insertion\n2. heapsort\n3. countingsort\n";
  cin >> option;
  switch (option){
    case 1 :
    insert(len, list, bigO);
    break;

    case 2 :
    heapSort(len, list, bigO);
    break;

    case 3 :
    countingsort(len, list, bigO);
    break;
  }
  cout <<"numero de comparações = " << bigO[0] << ", numero de trocas = " <<bigO[1]<< endl;
  print(list, len);
}