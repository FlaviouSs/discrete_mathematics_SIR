#include <iostream>
#include <stdio.h>
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
using namespace std;
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
struct modelo_sir{
    double indiviuos_suscetiveis;
    double indiviuos_infectados;
    double indiviuos_recuperados;
};
typedef modelo_sir modelo_sir;
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
void simulacao_do_modeloSIR(modelo_sir [], int, double, double, double);
void imprimeResultado_modelo(modelo_sir [], int);
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
int main(){
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    int dias_tempo; // Tempo de análise
    float coef_a, coef_b; // Taxas de transmissão e recuperação dos infectados // Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    double populacao_inicial; // Tamanho da população inicial; // Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    double infectados_iniciais; // Infectados iniciais // Flavio Alecio de Morais Santos and Luiz Henrique Dantas
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
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
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    dias_tempo++;
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    modelo_sir estrutura_analise[dias_tempo]; // Criação do vetor 'estrutura_analise' do tipo modelo_sir, cada índice representa o dia
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    estrutura_analise[0].indiviuos_suscetiveis = populacao_inicial - infectados_iniciais;
    estrutura_analise[0].indiviuos_infectados = infectados_iniciais; // Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    estrutura_analise[0].indiviuos_recuperados = 0.00;
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    simulacao_do_modeloSIR(estrutura_analise, dias_tempo, coef_a, coef_b, populacao_inicial); // Realiza a operação do modelo SIR, armazenando o resultado na estrutura modelo_sit 'estrutura_analise'
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    imprimeResultado_modelo(estrutura_analise, dias_tempo);
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    return 0;
}
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
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
    }   // Flavio Alecio de Morais Santos and Luiz Henrique Dantas
}// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
void imprimeResultado_modelo(modelo_sir estrutura[], int tempo){
    cout << "==============================RESULTADO==============================" << endl;// Flavio Alecio de Morais Santos and Luiz Henrique Dantas

    for(int k = 0; k < tempo; k++){ // Flavio Alecio de Morais Santos and Luiz Henrique Dantas
        printf("Dia %2d:\t\tSuscetíveis = %8.0lf\t\tInfectados = %8.0lf\t\tRecuperados = %8.0lf\n", k, estrutura[k].indiviuos_suscetiveis, estrutura[k].indiviuos_infectados, estrutura[k].indiviuos_recuperados);
    }// Flavio Alecio de Morais Santos and Luiz Henrique Dantas
    cout << "=====================================================================" << endl;
}
// Flavio Alecio de Morais Santos and Luiz Henrique Dantas