#include <iostream>
#include <stdio.h>

using namespace std;

struct modelo_sir{
    double indiviuos_suscetiveis;
    double indiviuos_infectados;
    double indiviuos_recuperados;
};
typedef modelo_sir modelo_sir;

void simulacao_do_modeloSIR(modelo_sir [], int, double, double, double);
void imprimeResultado_modelo(modelo_sir [], int);

int main(){

    int dias_tempo; // Tempo de análise
    float coef_a, coef_b; // Taxas de transmissão e recuperação dos infectados
    double populacao_inicial; // Tamanho da população inicial;
    double infectados_iniciais; // Infectados iniciais

    cout << "Digite a quantidade de dias para a análise: ";
    cin >> dias_tempo;
    cout << "Digite o valor de a (taxa de transmissão dos infectados): ";
    cin >> coef_a;
    cout << "Digite o valor de b (taxa de recuperação dos infectados): ";
    cin >> coef_b;
    cout << "Digite o tamanho da população para o início da análise: ";
    cin >> populacao_inicial;
    cout << "Digite a quantidade de infectados iniciais: ";
    cin >> infectados_iniciais;
    cout << endl;
    cout << "VALORES SETADOS PELO USUÁRIO PARA UTILIZAÇÃO DO MODELO SIR: " << endl;
    cout << "Tempo = " << dias_tempo << " dias" << endl;
    cout << "Taxa de transmissão = " << coef_a <<"\t\tTaxa de recuperação = " << coef_b << endl;
    cout << "Infectados iniciais = " << infectados_iniciais << endl;
    cout << "População = " << populacao_inicial << " indivíduos" << endl << endl;

    dias_tempo++;

    modelo_sir estrutura_analise[dias_tempo]; // Criação do vetor 'estrutura_analise' do tipo modelo_sir, cada índice representa o dia

    estrutura_analise[0].indiviuos_suscetiveis = populacao_inicial - infectados_iniciais;
    estrutura_analise[0].indiviuos_infectados = infectados_iniciais;
    estrutura_analise[0].indiviuos_recuperados = 0.00;

    simulacao_do_modeloSIR(estrutura_analise, dias_tempo, coef_a, coef_b, populacao_inicial); // Realiza a operação do modelo SIR, armazenando o resultado na estrutura modelo_sit 'estrutura_analise'

    imprimeResultado_modelo(estrutura_analise, dias_tempo);

    return 0;
}

void simulacao_do_modeloSIR(modelo_sir estrutura[], int tempo, double c_a, double c_b, double populacao){
    for(int k = 1; k < tempo; k++){
        if((estrutura[k - 1].indiviuos_suscetiveis - (c_a * estrutura[k - 1].indiviuos_suscetiveis * estrutura[k - 1].indiviuos_infectados)) < 0){ //Suscetivos não podem ser menor que zero
            estrutura[k].indiviuos_suscetiveis = 0;
        }
        else{
        estrutura[k].indiviuos_suscetiveis = estrutura[k - 1].indiviuos_suscetiveis - (c_a * estrutura[k - 1].indiviuos_suscetiveis * estrutura[k - 1].indiviuos_infectados);
        }
        estrutura[k].indiviuos_infectados = estrutura[k - 1].indiviuos_infectados + (c_a * estrutura[k - 1].indiviuos_suscetiveis * estrutura[k - 1].indiviuos_infectados) - (c_b * estrutura[k - 1].indiviuos_infectados);
        if(estrutura[k].indiviuos_infectados > populacao){ // Número de infectados não pode ser > que a população
            estrutura[k].indiviuos_infectados = populacao;
        }
        estrutura[k].indiviuos_recuperados = estrutura[k - 1].indiviuos_recuperados + (c_b * estrutura[k - 1].indiviuos_infectados);
    }   
}

void imprimeResultado_modelo(modelo_sir estrutura[], int tempo){
    cout << "==============================RESULTADO==============================" << endl;

    for(int k = 0; k < tempo; k++){
        printf("Dia %2d:\t\tSuscetíveis = %8.0lf\t\tInfectados = %8.0lf\t\tRecuperados = %8.0lf\n", k, estrutura[k].indiviuos_suscetiveis, estrutura[k].indiviuos_infectados, estrutura[k].indiviuos_recuperados);
    }
    cout << "=====================================================================" << endl;
}
