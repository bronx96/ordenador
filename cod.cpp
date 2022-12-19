#include "cod.h"
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;
//len = tmanha do vetor, option = ordem do vetor, list = vetor
void preen(int len, int option, int *list){
  int max = len;
  if(option == 1){ //ordem crescente
    for (int i = 0; i < len; i++){
      list[i] = i;
    }
  }
  else if(option == 2){ //ordem decrescente
    for (int i = 0; i < len; i++){
      list[i] = max;
      max -- ;
    }
  }
  else if(option == 3){ //ordem aleatoria
    for(int i = 0; i < len; i++){
      list[i] = gen_number(1, len);
    }
  }
  else if(option == 4){
    for (int i = 0; i < len; i++){
      cout <<"lista[" << i <<"] = ";
      cin >> list[i];
    }
  }
}

//imprimir numeros
void print(int *list, int len){
  for(int i = 0; i < len; i++){
    cout << list[i] << ", ";
  }
  cout<< endl;
}

//gerar numeros aleatorios
int gen_number(int i, int f){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(i, f);

    return dis(gen);
}

//funções insertion sort
void insert(int len, int *list, int *bigO){
  int i, chave;
  for(int j = 1; j < len; j++){
    chave = list[j];
    i = j -1;
    while(list[i] > chave && i >= 0){//laço de comparação
      list[i+1] = list[i];
      i = i - 1;
      bigO[0] ++;//numero de comparações
    }
    if(list[i+1] != chave){// trocas apenas se o numero for mudar de posição
      list[i + 1] = chave;
      bigO[1] ++;//numero de trocas
    }
  }
}
//funções heapSort
void heapSort(int len, int *list, int *bigO){
  int aux;
  for(int i = (len -1)/ 2; i >= 0; i--){
    criarHeap(i, len - 1, list, bigO);
  }
  for(int i = len -1; i >= 1; i--){
    aux = list[0];
    list[0] = list[i];
    list[i] = aux;
    criarHeap(0, i - 1, list, bigO);
  }
}
void criarHeap(int ini, int fim, int *list, int *bigO){
  int aux= list[ini];
  int j = ini * 2 + 1;
  while(j <= fim){
    if(j < fim && list[j] < list[j + 1]){
      j++;
    }
    bigO[0]  ++;// comparação efetuada
    if (aux < list[j]){
      list[ini] = list[j];
      ini = j;
      j = 2 * ini + 1;
      bigO[1]++;
    }
    else{
      j = fim + 1;
    }
  }
  list[ini] = aux;
}

//countingsort
void countingsort(int len, int *list, int *bigO){
  int output[10];
  int count[10];
  int max = list[0];

  for (int i = 1; i < len; i++) {
    if (list[i] > max)
      max = list[i];
  }


  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }


  for (int i = 0; i < len; i++) {
    count[list[i]]++;
  }


  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }


  for (int i = len - 1; i >= 0; i--) {
    output[count[list[i]] - 1] = list[i];
    count[list[i]]--;
  }

  
  for (int i = 0; i < len; i++) {
    list[i] = output[i];
  }
}