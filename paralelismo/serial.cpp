#include <iostream>
#include <cmath>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int N = 1000000000;
    vector<double> sum;
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        int id, i, Nthrds, istart, iend;
        id = omp_get_thread_num(); // uma thread 0 e uma thread 1
        Nthrds = omp_get_num_threads(); // em ambas threads a variavel será 2;
        istart = id * N / Nthrds; // na thread 0 istart será 0, e na thread 1 será metade de N;
        iend = (id+1) * N / Nthrds; // na thread 0 iend será metade de N e na thread 1 será N;
        if (id == Nthrds-1) iend = N; // se for a thread 1, iend será N;
        for (i = istart; i < iend; i++) // thread 0 realiza sum da primeira metade, e thread 2 da segunda
            sum.push_back(((pow(-1,i))/(2*i+1)));
    }

    cout << "sum = " << accumulate(sum.begin(), sum.end(), 0) << endl;
    
    return 0;
}
