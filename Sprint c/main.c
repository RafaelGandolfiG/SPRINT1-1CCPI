// importando as bibliotecas necessárias
#include <stdio.h>
#include <windows.h>

// criando uma função que calcula a porcentagem
int calculo_porcentagem(int porcentagem_atual, int porcentagem_final){
    // temos variaveis da porcentagem atual e a porcentagem final que sera carregado
    // retorna a diferença de porcentagem da bateria
    return porcentagem_final-porcentagem_atual;
}

// criando uma funçãp que calcula os kwh
float calculo_kwh(int porcentagem_atual, int porcentagem_final, float bateria_total){
    // temos variaveis como a porcentagem atual, a porcentagem final e a potencia da bateria
    // criamos uma variavel que contem a diferença de porcentagem da bateria
    int diferenca=porcentagem_final-porcentagem_atual;
    //criamos uma variavel que contem o calculo principal da função
    float calculo=(diferenca/100.0)*bateria_total;
    // retornamos a variavel calculo
    return calculo;
}

// criando a função que calcula o tempo
float calcular_tempo(float energia, float potencia){
    // temos variaveis como a energia e a potencia
    // criamos a variavel calculo que guarda o calculo do tempo
    float calculo=energia/potencia;
    // retornamos a variavel calculo
    return calculo;
}

int main() {

    // declarando variaveis int
    int porcentagem;
    int porcentagem_final;
    int calculo;
    int escolha;

    // declarando variaveis float
    float potencia=11.0;
    float tarifa=1.30;
    float bateria_total;
    float tempo_hora;
    float tempo_min;
    float energia;
    float custo;
    float dinheiro;
    float troco;

    // inicio do programa
    printf("----------SIMULADOR DE RECARGA----------\n");
    // delay de 1 segundo
    Sleep(1000);

    // pergunta a capacidade da bateria do carro do cliente
    printf("Digite a capacidade da bateria do carro (kWh): ");
    // le a capacidade da bateria e guarda na variavel bateria_total
    scanf("%f",&bateria_total);

    // se a variavel bateria_total for ou igual a zero
    if (bateria_total<=0){
        printf("Bateria invalida\n");
        // encerra o programa
        return 0;
    }

    // cria um menu de opções com validação usando do-while
    // executa o do
    do {
        printf("1-Carregar ate 100%%\n2-Carregar ate x%%\nEscolha: ");
        // le a opção e guarda na variavel escolha
        scanf("%d",&escolha);
        // se o if vor verdadeiro
        if (escolha!=1 && escolha!=2){
            // mostra que a escolha foi invalida
            printf("Escolha invalida\n");
        }
    // enquanto a variavel escolha for diferente de 1 e 2
    } while (escolha!=1 && escolha!=2);

    // switch da variavel escolha
    switch (escolha){
        // caso seja igual a 1
        case 1:
            // pergunta a porcentagem da bateria atual
            printf("Digite a porcentagem de sua bateria (em porcentagem): ");
            // le a porcentagem e guarda na variavel porcentagem
            scanf("%d",&porcentagem);
            // se a porcentagem estiver fora do intervalo de 0 a 100
            if (porcentagem<0 || porcentagem>100){
                printf("Porcentagem invalida\n");
                // encerra o programa
                return 0;
            }
            // se nao se a porcentagem for igual a 100
            else if (porcentagem==100){
                // mostra que a bateria esta cheia
                printf("A bateria ja esta cheia");
                // encerra o programa
                return 0;
            }
            // define a porcentagem_final como sendo 100
            porcentagem_final=100;
            // break do switch
            break;
        // caso seja igual a 2
        case 2:
        // pergunta  aporcentagem da bateria atual
            printf("Digite a porcentagem de sua bateria (em porcentagem): ");
            // le e guarda a porcentagem na variavel porcentagem
            scanf("%d",&porcentagem);
            // se a porcentagem estiver fora do intervalo de 0 a 100
            if (porcentagem<0 || porcentagem>100){
                // mostra que a porcentagem esta invalida
                printf("Porcentagem invalida\n");
                // encerra o programa
                return 0;
            }
            // senao se a bateria estiver em 100
            else if (porcentagem==100){
                // mostra que a beteria ja esta cheia
                printf("A bateria ja esta cheia");
                // encerra o programa
                return 0;
            }
            // pergunta ate qual % o usuario quer carregar
            printf("Deseja carregar ate quantos porcento ? ");
            // le e guarda na variavel porcentagem_final
            scanf("%d",&porcentagem_final);
            // se a porcentagem final estiver fora do intervalo de 0 a 100 ou for menor que a porcentagem inicial
            if (porcentagem_final<0 || porcentagem_final>100 || porcentagem_final<=porcentagem){
                // mostra que a porcentagem esta invalida
                printf("Porcentagem invalida\n");
                // encerra o programa
                return 0;
            }
            // break do switch
            break;

        // caso nao seja nem 1 ou 2
        default:
            printf("Escolha invalida");
            // encerra o porgrama
            return 0;
    }
    // cria a variavel calculo que guarda a função calculo_porcentagem
    // utiliza as variaveis porcentagem e porcentagem_final como argumentos
    calculo=calculo_porcentagem(porcentagem,porcentagem_final);

    // cria a variavel energia que guarda a função calculo_kwh
    // utiliza as variaveis porcentagem, porcentagem_final e bateria_total como argumentos
    energia=calculo_kwh(porcentagem,porcentagem_final,bateria_total);
    // cria a variavel tempo_hora que guarda a função calcular_tempo
    // utiliza as variaveis energia e potencia como argumentos
    tempo_hora=calcular_tempo(energia,potencia);
    // cria a variavel tempo_min que é o produto da variavel tempo_hora por 60
    tempo_min=tempo_hora*60;
    // cria a variavel custo que é o produto da tarifa pela energia
    custo=energia*tarifa;

    // mostra a quantidade em % que ira ser carregada
    printf("Carregar %d%%\n",calculo);
    // mostra o total a ser pago
    printf("Total a pagar R$%.2f\n",custo);
    // pergunta ao usuario a quantia que ele dara 
    printf("Digite a quantia de dinheiro que ira fornecer: ");
    // le e guarda a quantia na variavel dinheiro
    scanf("%f",&dinheiro);

    // se a variavel dinheiro for menor que o custo-0.001
    if (dinheiro<custo-0.001){
        // mostra que o saldo é insuficiente
        printf("Saldo insuficiente\n");
        // encerra o programa
        return 0;
    }
    // senão
    else{
        // calcula o troco
        troco=dinheiro-custo;
        // mostra o troco
        printf("Troco: R$ %.2f\n",troco);
    }

    printf("Carregando...\n");
    // começa a carregar
    // para a porcentagem inicial, sendo ela menor ou igual a porcentagem final
    // adiciona 1%
    for (int i=porcentagem; i<=porcentagem_final; i++){
        // mostra a porcentagem da bateria
        printf("%d%%\n",i);
        // delay de 1 segundo
        Sleep(1000);
    }

    // mostra que a carga foi concluida
    printf("Carga concluida!!\n");

    // mostra um relatorio formatado contendo todas as informações mais importantes
    printf("\n----------RELATORIO----------\n");
    printf("Bateria do carro: %.0f kWh\n",bateria_total);
    printf("Carga inicial: %d%%\n",porcentagem);
    printf("Carga final: %d%%\n",porcentagem_final);
    printf("Energia carregada: %.2f kWh\n",energia);
    printf("Tempo estimado: %.2f horas (%.0f minutos)\n",tempo_hora,tempo_min);
    printf("Tarifa: R$ %.2f por kWh\n",tarifa);
    printf("Custo total: R$ %.2f\n",custo);

    // encerra o programa
    return 0;
}