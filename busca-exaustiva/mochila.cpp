#include<iostream>
#include<vector>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

// função para retornar o valor
double mochila(vector<item> I, double C){
    // I = vetor com struct de itens
    // C = capacidade total da mochila
    if (I.size() == 0.0 or C == 0.0) {
        return;
    }

    // pega o último item do vetor, itera sobre ele e remove-o sem seguida
    // do vetor de itens
    item i = I[I.size()];
    I.pop_back();
    double com_i = 0.0, sem_i = 0.0, v = i.valor, p = i.peso;
    com_i += v + mochila(I, C - p);
    sem_i += mochila(I, C);
    return max(com_i, sem_i)
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
