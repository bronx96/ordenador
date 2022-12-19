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

void heapSort(int len, int *list, int *bigO){
  int aux;
  for(int i = (len -1)/ 2; i >= 0; i--){
    criarHeap(len, list);
  }
  for(int i = len -1; i >= 1; i--){
    aux = list[0];
    list[0] = list[i];
    list[i] = aux;
    criarHeap(len, list);
  }
}