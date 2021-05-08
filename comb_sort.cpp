#include <iostream>
#include <algorithm> //swap

using namespace std;

/* Calcula próximo gap */
int next_gap(int gap){
    return gap/1.3;
}

/* Comb_sort crescente */
void comb_sort(int *v, int size){

    /* tamanho inicial do gap (tamnho  do vetor) */
    int gap = size;

    /* Ordena até gap == 1 */
    while(gap > 1){
        gap = next_gap(gap);

        /* Loop de iteração sob o vetor considerando o gap */
        for (int i = 0; i < size - gap; i++){
            if (v[i] > v[i + gap])
                swap(v[i], v[i + gap]);
        }
    }
}

/* Comb_sort decrescente */
void comb_sort(int *v, int size){

    /* tamanho inicial do gap (tamnho  do vetor) */
    int gap = size;

     /* Ordena até gap == 1 */
    while(gap > 1){
        gap = next_gap(gap);

        /* Loop de iteração sob o vetor considerando o gap */
        for (int i = 0; i < size - gap; i++){

            if (v[i] < v[i + gap])
                swap(v[i], v[i + gap]);
        }
    }
}

