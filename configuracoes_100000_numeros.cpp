#include <iostream>
#include <iomanip> //setprecision
#include <algorithm> //swap


using namespace std;

/* Quantidade de números */
const int N = 100000;

/* Intervalo */
const int MAX_NUMBER = 100;

/* Quantidade de configurações */
const int N_CONFIG = 5;

/* Vetor para armzenar o resultado de cada configuração */
double config_results[N_CONFIG];

/* Imprime o vetor */
void imprime_vetor(int *v, int N){

    for (int i = 0; i < N; i++)
        cout << v[i] << " ";

    cout << "\n";
}

/* Gera vetor aleatório com positivos e negativos */
void random_v(int vetor[], int quant_numeros, int max_number)
{
	
	srand(time(NULL));

    /* Números do intervalo [-max_number, max_number] */
    max_number += 1;
    
    int signal; 
	int v;

	for (int i = 0; i < quant_numeros; i++)
	{
        /* Gerar negativos e positivos */
        signal = rand() % 2;
        if (signal == 0)
		    v = (rand() % max_number)*(-1);
        if (signal == 1)
            v = (rand() % max_number);
            
		vetor[i] = v;
	}

}

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

/* Gera elementos totalmente desordenados */
void gen_config_1(int *v){

    random_v(v, N, MAX_NUMBER);

    cout << "\nVetor totalmente desordenado\n\n";
    imprime_vetor(v, N);

}

/* gera elementos ordenados crescentemente */
void gen_config_2(int *v){

    comb_sort_cres(v, N);

    cout << "Vetor ordenado crescentemente\n";
    imprime_vetor(v, N);

}

/* gera elementos ordenado descrescentemente */
void gen_config_3(int *v){

    comb_sort_decres(v, N);

    cout << "Vetor ordenado decrescentemente\n";
    imprime_vetor(v, N);

}

/* gera elementos primeira metade crescente, segunda metade descrescente */
void gen_config_4(int *v){

    /* Gerando a metade crescente */
    int sort_cres[N];
    random_v(sort_cres, N, MAX_NUMBER);
    comb_sort_cres(sort_cres, N);
    for (int i = 0; i < N/2; i++){
        v[i] = sort_cres[i];
    }

    /* Gerando a metade descrecente */
    int sort_desc[N];
    random_v(sort_desc, N, MAX_NUMBER);
    comb_sort_decres(sort_desc, N);
    for (int i = 0; i < N/2; i++){
        v[i + N/2] = sort_desc[i];
    }

    cout << "Vetor primeira metade crescente, segunda metade descrescente\n";
    imprime_vetor(v, N);

}

/* gera elementos primeira metade decrescente, segunda metade crescente */
void gen_config_5(int *v){

    /* Gerando a metade descrecente */
    int sort_desc[N];
    random_v(sort_desc, N, MAX_NUMBER);
    comb_sort_decres(sort_desc, N);
    for (int i = 0; i < N/2; i++){
        v[i] = sort_desc[i];
    }

    /* Gerando a metade crescente */
    int sort_cres[N];
    random_v(sort_cres, N, MAX_NUMBER);
    comb_sort_cres(sort_cres, N);
    for (int i = 0; i < N/2; i++){
        v[i + N/2] = sort_cres[i];
    }

    
    cout << "Vetor primeira metade decrescente, segunda metade crescente\n";
    imprime_vetor(v, N);

}

/* Imprimir uma separação visual entre cada configuração */
void print_separator(){
    cout << "--------------------------------------------------------\n";
}

/* Executa o comb_sort_cresc e retorna o tempo de execução em ms */
double get_exec_time(int *v, int config_n){

    clock_t start, end;

    start = clock();
    comb_sort_cres(v, N);
    end = clock();
    double time_taken = (double(end - start)/
                         double(CLOCKS_PER_SEC))*
                         1000;
    
    /* Salvar resultado num vetor */
    config_results[config_n] = time_taken;

    return time_taken;
}

/* Função que mostra resultados de uma ordenação */
void show_results_config(int *v, int config_n){

    double result = get_exec_time(v, config_n);
    cout << "\nVetor ordenado\n\n";
    imprime_vetor(v, N);
    cout << "\n";
    cout << "Tempo de execução: " << fixed
         << result << setprecision(5);
    cout << " ms " << endl;
    print_separator();
}

int main(){

    int teste[N];
    int config = 1;

    /*Configuração 1*/
    cout << "\nConfiguração " << config << "\n";
    gen_config_1(teste);
    show_results_config(teste, config - 1);
    
    config++;
    
    /*Configuração 2*/
    cout << "\nConfiguração " << config << "\n";
    gen_config_2(teste);
    show_results_config(teste, config - 1);
    
    config++;

    /*Configuração 3*/
    cout << "\nConfiguração " << config << "\n";
    gen_config_3(teste);
    show_results_config(teste, config - 1);

    config++;
    
    /*Configuração 4 */
    cout << "\nConfiguração " << config << "\n";
    gen_config_4(teste);
    show_results_config(teste, config - 1);

    config++;

    /*Configuração 5 */
    cout << "\nConfiguração " << config << "\n";
    gen_config_5(teste);
    show_results_config(teste, config - 1);

    /* Impressão dos resultados */
    cout << "Tempos de execuções (ms)\n";
    for (int i = 0; i < N_CONFIG; i++){
        cout << "Configuração " << i + 1 << ": " << config_results[i] << "\n";
    }
    return 0;

}




