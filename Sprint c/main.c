#include <stdio.h>
#include <unistd.h>

int calculo_porcentagem(int porcentagem_atual, int porcentagem_final){
    return porcentagem_final-porcentagem_atual;
}

float calculo_potencia(float tempo, float potencia){
    float calculo;
    calculo=potencia*(tempo/60.0);
    return calculo;
}

float calculo_kwh(int porcentagem_atual, int porcentagem_final, float bateria_total){
    int diferenca=porcentagem_final-porcentagem_atual;
    float calculo=(diferenca/100.0)*bateria_total;
    return calculo;
}

float calcular_tempo(float energia, float potencia){
    if (potencia<=0){
        return 0;
    }
    float calculo=energia/potencia;
    return calculo;
}

int main() {
    
    int porcentagem;
    int porcentagem_final;
    int calculo;
    int escolha;
    
    float potencia=11.0;
    float tarifa=1.30;
    float bateria_total;
    
    float tempo_hora;
    float tempo_min;
    float energia;
    float custo;
    float dinheiro;
    float troco;
    
    printf("----------SIMULADOR DE RECARGA----------\n");
    sleep(1);
    
    printf("Digite a capacidade da bateria do carro (kWh): ");
    scanf("%f",&bateria_total);
    
    if (bateria_total<=0){
        printf("Bateria invalida\n");
        return 0;
    }
    
    printf("1-Carregar ate 100%%\n2-Carregar ate x%%\nEscolha: ");
    scanf("%d",&escolha);
    
    switch (escolha){
        case 1:
            printf("Digite a porcentagem de sua bateria (em %): ");
            scanf("%d",&porcentagem);
            if (porcentagem<0 || porcentagem>100){
                printf("Porcentagem invalida\n");
                return 0;
            }
            porcentagem_final=100;
            break;
            
        case 2:
            printf("Digite a porcentagem de sua bateria (em %): ");
            scanf("%d",&porcentagem);
            if (porcentagem<0 || porcentagem>100){
                printf("Porcentagem invalida\n");
                return 0;
            }
            printf("Deseja carregar ate quantos %? ");
            scanf("%d",&porcentagem_final);
            if (porcentagem_final<0 || porcentagem_final>100 || porcentagem_final<=porcentagem){
                printf("Porcentagem invalida\n");
                return 0;
            }
            break;
            
        default:
            printf("Escolha invalida");
            return 0;
    }
    
    calculo=calculo_porcentagem(porcentagem,porcentagem_final);
    
    energia=calculo_kwh(porcentagem,porcentagem_final,bateria_total);
    tempo_hora=calcular_tempo(energia,potencia);
    tempo_min=tempo_hora*60;
    custo=energia*tarifa;
    
    printf("Carregar %d%%\n",calculo);
    printf("Total a pagar R$%.2f\n",custo);
    printf("Digite a quantia de dinheiro que ira fornecer: ");
    scanf("%f",&dinheiro);
    
    if (dinheiro<custo-0.01){
        printf("Saldo insuficiente\n");
        return 0;
    }
    else{
        troco=dinheiro-custo;
        printf("Troco: R$ %.2f\n",troco);
    }
    
    printf("Carregando...\n");
    for (int i=porcentagem; i<=porcentagem_final; i++){
        printf("%d%%\n",i);
        sleep(1);
    }
    
    printf("Carga concluida!!\n");
    
    printf("\n----------RELATORIO----------\n");
    printf("Bateria do carro: %.0f kWh\n",bateria_total);
    printf("Carga inicial: %d%%\n",porcentagem);
    printf("Carga final: %d%%\n",porcentagem_final);
    printf("Energia carregada: %.2f kWh\n",energia);
    printf("Tempo estimado: %.2f horas (%.0f minutos)\n",tempo_hora,tempo_min);
    printf("Tarifa: R$ %.2f por kWh\n",tarifa);
    printf("Custo total: R$ %.2f\n",custo);
    
    return 0;
}