#include <random>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // gerador de pontos
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    int N = 100000;
    double sum = 0;
    for (int i = 0; i < N; i++) 
    {
        double x = distribution(generator); // gera número
        double y = distribution(generator);

        if ((pow(x,2) + pow(y,2)) <= 1) 
        {
            sum++;
        }
    }
    cout << "sum = " << sum << endl;
    cout << 4 * sum / N << endl;
    
    return 0;
}
