// esse é o código do mais leve - alterar para aleatorização e depois busca local
// para rodar passar o in.txt (./mochila < in1.txt)
// objetivos: primeiro da um shuffle na entrada, depois realiza uma rodada aleatoria de adição.
// com os itens sobrados aplica-se uma condição (se cabe) de entrada e faz uma segunda rodada de adição.
// 1 amostra é a quantidade de vez que roda o código

#include<chrono>
#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

int main() {
    int n = 0;
    int W = 0;
    vector<item> mochila;
    vector<item> items;
    cin >> n >> W; // lendo número de items e peso
    items.reserve(n);
    double peso, valor;
    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }

    //imprimir
    // cout << "itens lidos: (id, peso, valor)" << endl;
    // for(auto& el: items){
    //     cout << el.id << "\t" << el.peso << "\t" << el.valor << endl;
    // }

    // gera probabilidade de 50%
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_int_distribution<int> distribution(0,1);
    cout << distribution(generator) << endl; // gera número
    
    // aleatorizar vetor
    // random_shuffle(vetor.begin(), vetor.end())

    // aleatorizar mochila
    // peso = 0;
    // valor = 0;
    // for(auto& el : items){
    //     if(){
    //         mochila.push_back(el);
    //         peso += el.peso;
    //         valor += el.valor;
    //     }
    // }

    return 0;
}