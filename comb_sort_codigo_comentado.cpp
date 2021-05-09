#include <iostream>
#include <algorithm> //swap

using namespace std;

/* Calcula próximo gap */
int next_gap(int gap){

    /* Gap não pode ser menor do que 1 */
    if (gap <= 1)
        return 1;

    return gap/1.3;
}

/* Comb_sort crescente */
void comb_sort_cres(int *v, int size){

    /* tamanho inicial do gap (tamnho  do vetor) */
    int gap = size;

    int swapped = 1;

    /* Ordena até gap == 1 e na última passagem não ter tido troca*/
    while(gap != 1 || swapped == 1){
        gap = next_gap(gap);

        swapped = 0;
        
        /* Loop de iteração sob o vetor considerando o gap */
        for (int i = 0; i < size - gap; i++){
            if (v[i] > v[i + gap]){
                swap(v[i], v[i + gap]);
                swapped = 1;
            }
                
        }
    }
}

/* Comb_sort decrescente */
void comb_sort_decres(int *v, int size){

    /* tamanho inicial do gap (tamnho  do vetor) */
    int gap = size;

    int swapped = 1;

    /* Ordena até gap == 1 e na última passagem não ter tido troca*/
    while(gap != 1 || swapped == 1){
        gap = next_gap(gap);

        swapped = 0;

        /* Loop de iteração sob o vetor considerando o gap */
        for (int i = 0; i < size - gap; i++){
            if (v[i] < v[i + gap]){
                swap(v[i], v[i + gap]);
                swapped = 1;
            }
                
        }
    }
}

