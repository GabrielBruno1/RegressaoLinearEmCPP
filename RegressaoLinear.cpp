#include <iostream>
#include<vector>

// Calcula os coeficientes a e b
void coeficientes(const std::vector<int> x, const std::vector<int> y, float& a, float& b){
     float tam = x.size();
     float somax = 0;
     float somay = 0;
     float somaxy = 0;
     float somax2 = 0;
     for(int c=0; c<(x.size()); c++){
        somax += x[c];

     }
     for(int c=0; c<(y.size()); c++){
        somay += y[c];

     }
     for(int c=0; c<(x.size()); c++){
          somaxy += (x[c]*y[c]);
     }
     for(int c=0; c<(x.size()); c++){
          somax2 += (x[c]*x[c]);

     }


     a = (tam * somaxy - somax * somay) / (tam * somax2 - somax * somax);


     b = (somay - a * somax) / tam;







}

// Calcula a previsao
std::vector<int> previsao(const std::vector<int> xteste, float a, float b){
        std::vector<int> prev;
        for(const auto& X : xteste){
                prev.push_back(X*a+b);



        }
        return prev;


}

int main() {
    float a,b;
    std::vector<int> x{1, 2, 3, 4, 5};
    std::vector<int> y{2, 4, 6, 8, 10};
    std::vector<int> xteste{6,7};


    // Calculando os coeficientes a e b
    coeficientes(x, y, a, b);

    //mostrando a previsao para os valores de y_pred por meio do xteste
    std::vector<int> y_pred = previsao(xteste,a,b);
    std::cout << "a previsao e: ";
    for(const auto &x : y_pred){

        std::cout << x << ' ';
    }




    return 0;
}
