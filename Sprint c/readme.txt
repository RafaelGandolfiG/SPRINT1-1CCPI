O programa simula uma sessão de recarga de um carro elétrico, calculando quanto de energia será carregada,
quanto tempo vai levar, quanto vai custar e mostra ao final um relatório contendo essas informações.

Foi utilizado diversas funções auxiliares, antes do main(), como a função calculo_porcentagem, que calcula a
porcentagem da bateria que será carregada, tendo como parâmetros a porcentagem inicial e a porcentagem final,
retornando a diferença entre elas. A próxima função é a calculo_kwh que calcula quanto de energia foi gasta no
processo, tendo como parâmetros a porcentagem atual, a porcentagem final e a bateria total, retornando um cálculo
em que esses 3 parâmetros são usados. A última função auxiliar é a função calcular_tempo, em que são utilizados
a energia e a potência como parâmetros e retornando a divisão entre os dois.

No início do programa o usuário fornece a capacidade da bateria de seu carro, se for menor ou igual a 0, ele
mostra que a bateria é inválida e encerra o programa.

Em seguida, é apresentado um menu de opções para o usuário escolher entre carregar a bateria até 100% ou até um
valor específico. Esse menu utiliza uma estrutura de repetição do-while para garantir que o usuário informe uma
opção válida. Após a escolha, o programa solicita a porcentagem atual da bateria e, dependendo da opção escolhida,
também solicita a porcentagem final desejada, realizando validações para evitar valores inválidos.

Depois disso, o programa realiza os cálculos principais, determinando a energia que será carregada em kWh, o tempo
estimado da recarga e o custo total com base na tarifa definida. Em seguida, o usuário informa o valor de pagamento,
e o sistema verifica se é suficiente, calculando o troco caso necessário.

Após o pagamento, o programa simula o processo de recarga utilizando um laço de repetição for, que incrementa a
porcentagem da bateria gradualmente até atingir o valor final.

Ao final, é exibido um relatório com todas as informações da sessão de recarga, como capacidade da bateria,
porcentagem inicial e final, energia carregada, tempo estimado, tarifa aplicada e custo total.

Além disso, foi utilizada a biblioteca windows.h, que permite o uso da função Sleep(), responsável por
criar pequenos atrasos no programa. Essa função foi utilizada para simular o tempo de carregamento e tornar a
execução mais próxima de um sistema real.

Equipe 04 - 1CCPI

Rafael Gandolfi Gonçalves - 569036 - 1CCPI
Rafael Lins - 570588 - 1CCPI
Cauã Paes - 569906 - 1CCPI
Guilherme Miranda - 573107 - 1CCPI
Carlos Eduardo - 572949 - 1CCPI
João Pedro Soler - 569725 - 1CCPI
