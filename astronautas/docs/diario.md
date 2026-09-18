# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

**- Versão do OpenCode (`opencode --version`):** Versão 1.18.31

**- Modelo usado:** Big Pickle

## Parte 1: antes de programar

**- O que cada classe guarda:** Na parte 1 do projeto temos três classes: Astronauta, que guarda as informações de um astronauta (uma pessoa); Voo, que guarda as informações de uma viagem, bem como os dados (cpfs) dos astronautas que nela estavam; e, Agencia, que guarda as informações dos astronautas (cpfs) e voos (codigos) e organiza as operações que podem ser feitas.

**- O que acontece em `LANCAR_VOO`, em palavras:** A agencia verifica a existência do voo, confere o estado, checa se tem alguém a bordo (para cada cpf procura o astronauta, verifica se está vivo e disponível). Depois de todas essas verificações, dá instruções para os astronautas embarcarem e manda o voo mudar o estado.

**- Uma dúvida que eu tinha antes de começar:**

## Parte 1: uso de IA para entender algo

**- O que perguntei (ou "não usei"):**
**- O que aprendi:**

## Primeiro contato: revisão sem editar

**- As três melhorias que a IA sugeriu, em uma linha cada:** Perdi o histórico das melhorias que a IA sugeriu.

**- A que escolhi e por quê:** Alterar um comando de `removerAstronauta`. A escolha foi baseada no mínimo de mudança que a IA faria no programa, pois ainda não me sentia segura em permitir uma mudança mais robusta. 

**- O que mudou no código, e se os seis testes continuaram passando:** A mudança foi bem básica e quase imperceptível, apenas uma linha:
```ANTES
bool removerAstronauta(string numCpf){
     for (int i = 0; i < cpfs.size(); i++) {
         if (cpfs[i] == "111") {
            cpfs.erase(cpfs.begin() + i); 
            break; 
         }
     }
}
```

```DEPOIS
bool removerAstronauta(string numCpf){
        for(int i = 0; i < cpfs.size(); i++){
            if(cpfs[i] == numCpf){
                cpfs.erase(cpfs.begin() + i);
                return true;
            }
        }
        return false;
}
```

**- O que entendi que não sabia antes:** A IA explicou que existe uma regra simples na qual, se depois do laço não há mais nada a fazer, `return` é mais curto. Se há (ex.: imprimir, contar, continuar o laço para outro objetivo), aí usa `break` com uma variável bool/flag. 

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

**- Primeira mensagem (o pedido do plano):**

Este programa em C++11 controla astronautas e voos de uma agência espacial. Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp. Os testes em testes/parte1 passam. Quero dois comandos novos: LISTAR_ASTRONAUTAS e HISTORICO cpf. A saída exata está abaixo.

Missão 1: LISTAR_ASTRONAUTAS e HISTORICO
LISTAR_ASTRONAUTAS mostra todos os astronautas em três grupos, na ordem de cadastro dentro de cada grupo. No grupo disponiveis entram os vivos que não estão em nenhum voo em curso. No grupo em voo entram os vivos que estão em um voo em curso, com o código desse voo. No grupo mortos entram os mortos. Grupo vazio mostra (nenhum). Os dois exemplos abaixo são do mesmo cenário: Ana voou no 10, que terminou com sucesso, e agora está no 20, em curso. Bruno morreu em outro voo.

LISTA DE ASTRONAUTAS
== disponiveis ==
333 Carla Souza (28 anos)
== em voo ==
111 Ana Maria (30 anos) - voo 20
== mortos ==
222 Bruno Costa (35 anos)
HISTORICO cpf mostra os voos dos quais o astronauta participou, com o estado atual de cada um,
na ordem de cadastro dos voos. Participou significa que o voo foi lançado com ele a bordo. Voo
só planejado não aparece. Sem voos: (nenhum voo). CPF desconhecido: ERRO: astronauta 999
nao cadastrado.
HISTORICO DE 111 Ana Maria
voo 10: finalizado com sucesso
voo 20: em curso

Não mude nenhum comando que já existe nem a saída deles. Não use nada fora da biblioteca padrão. Vou conferir com bash testes/testar.sh missao1 e depois com bash testes/testar.sh parte1. Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.
 
**- O plano que a IA apresentou, resumido:** Perdi o histórico do plano para a missão 1 que a IA forneceu.

**- Mudei algo no plano antes de liberar?** Não mudei nada no plano que a IA sugeriu, apenas aceitei.

**- Resultado de `testar.sh missao1` e de `testar.sh parte1`:** 

```testes/testar.sh parte 1
OK    01_cadastros
OK    02_passageiros_planejados
OK    03_lancamento_finalizacao
OK    04_explosao_e_mortes
OK    05_operacoes_invalidas
OK    06_cenario_completo

6 de 6 testes passaram.
```
```testes/testar.sh missao1
OK    01_listar_astronautas
OK    02_historico

2 de 2 testes passaram.
```
**- Precisei refazer? O que mudou no pedido:** Não precisei refazer nada, atendeu bem ao que eu havia solicitado.

## Missão 2: SALVAR e CARREGAR

**- Primeira mensagem:**

Este programa em C++11 controla astronautas e voos de uma agência espacial. Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp. Os testes em testes/parte1 passam. Recentemente foi feita a inclusão de dois novos comandos para a missão 1 LISTAR_ASTRONAUTAS e HISTORICO cpf. Eles atendem fazem o que tem que ser feito e os testes em testes/missao1 passam. Quero dois comandos novos: SALVAR e CARREGAR. O funcionamento está abaixo.

Missão 2: SALVAR e CARREGAR
SALVAR nome_do_arquivo grava todos os dados em um arquivo de texto e imprime OK: dados salvos em nome_do_arquivo. Se não conseguir abrir o arquivo para escrita: ERRO: nao foi possivel salvar em nome_do_arquivo.
CARREGAR nome_do_arquivo substitui todos os dados atuais pelos do arquivo e imprime OK: dados carregados de nome_do_arquivo. Se o arquivo não existir: ERRO: nao foi possivel carregar de nome_do_arquivo, e os dados atuais continuam como estavam.
O formato do arquivo é escolha sua e da IA, desde que seja texto e que carregar depois de salvar reconstrua tudo: astronautas com vivo e disponível, voos com estado e lista de CPFs. Peça que a IA mostre o formato com um exemplo e explique como o programa reconstrói os objetos ao ler.

Teste: bash testes/testar.sh missao2. Ele roda três arquivos em sequência: o primeiro monta um cenário e salva em dados_teste.txt; o segundo, em outra execução do programa, carrega e continua operando; o terceiro tenta carregar um arquivo que não existe. Depois: bash testes/ testar.sh parte1. 

Não mude nenhum comando que já existe nem a saída deles. Não use nada fora da biblioteca padrão. Vou conferir com bash testes/testar.sh missao2 e depois com bash testes/testar.sh parte1. Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.

**- O plano, resumido:**
De maneira resumida, na missão 2, a IA alterou: 
O que                                   | Onde            | Por quê
#include <fstream>                      | topo do arquivo | ofstream/ifstream para ler e escrever arquivos
void Agencia::salvar(string arquivo)    | classe Agencia  | grava tudo e imprime OK: ... ou ERRO: ...
void Agencia::carregar(string arquivo)  | classe Agencia  | limpar os vectors, lê o arq e reconstroi os objetos
void Astronauta::definirEstado(bool vivo, bool disp)  |classe Astronauta  | sem isso não dá pra restaurar o estado vivo/disponível ao carregar
void Voo::definirEstado(string es)  |classe Voo  | sem isso não dápara restaurar o estado do voo ao carregar
SALVAR e CARREGAR  | main()  | ler o nome do arquivo e chamar os métodos

**- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):** O arquivo tinha o formato de um campo por linha, dessa forma:

```ASTRONAUTAS
3
111
Ana Maria
30
1
```
**- Resultado de `testar.sh missao2` e de `testar.sh parte1`:**

```testes/testar.sh parte 1
OK    01_cadastros
OK    02_passageiros_planejados
OK    03_lancamento_finalizacao
OK    04_explosao_e_mortes
OK    05_operacoes_invalidas
OK    06_cenario_completo

6 de 6 testes passaram.
```
```testes/testar.sh missao2
OK    01_salvar
OK    02_carregar
OK    03_arquivo_inexistente

3 de 3 testes passaram.
```


**- Precisei refazer? O que mudou no pedido:** Não precisei refazer nada, atendeu bem ao que eu havia solicitado. Durante sua execução, ele colocou um método como privado, depois constatou que precisava que ele fosse público e ele mesmo alterou na hora.

## Missão 3: RELATORIO

**- Primeira mensagem:**

-------------------------------------------------------------------------------------------------MISSÃO 3-------------------------------------------------------------------------------------------------

Este programa em C++11 controla astronautas e voos de uma agência espacial. Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp. Os testes em testes/parte1 passam. Recentemente foi feita a inclusão de quatro novos comandos, dois deles para a missão 1 LISTAR_ASTRONAUTAS e HISTORICO cpf, e os outros dois para a missão 2 SALVAR e CARREGAR. Eles atendem fazem o que tem que ser feito e os testes em testes/parte1, testes/missao1 e testes/missao2 passam. Quero um comando novo: RELATORIO. O funcionamento está abaixo.

Missão 3: RELATORIO
RELATORIO imprime a linha RELATORIO seguida de nove linhas sobre o estado atual:
RELATORIO
voos planejados: 0
voos em curso: 0
voos finalizados com sucesso: 1
voos finalizados com explosao: 2
astronautas cadastrados: 4
astronautas vivos: 2
astronautas mortos: 2
astronauta mais experiente: 111 Ana Maria (voos lancados: 1)
taxa de sucesso: 33%
Regras:
• A experiência de um astronauta é o número de voos já lançados em que ele estava a bordo. Voo ainda planejado não conta. Astronauta morto continua contando. Em caso de empate, vale o cadastrado primeiro. Se ninguém voou: astronauta mais experiente: (nenhum).
• Taxa de sucesso é a parte inteira de sucessos * 100 / finalizados, onde finalizados são os com sucesso mais os com explosão. Sem voos finalizados: taxa de sucesso: (nenhum voo finalizado).

Teste: bash testes/testar.sh missao3. Depois: bash testes/testar.sh parte1.
Dois testes desta missão usam a Missão 2, então faça a Missão 2 antes. O teste 04 monta um cenário, pede o RELATORIO e salva em dados_teste.txt. O teste 05, em outra execução, carrega esse arquivo e pede o RELATORIO de novo. A resposta tem que ser a mesma. Um erro comum aqui é guardar a experiência num contador dentro do astronauta e esquecer de gravar esse contador
no arquivo.

Não mude nenhum comando que já existe nem a saída deles. Não use nada fora da biblioteca padrão. Vou conferir com bash testes/testar.sh missao2 e depois com bash testes/testar.sh parte1. Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.

**- O plano, resumido:**
De maneira resumida, na missão 3, a IA alterou: 
O que                                | Onde                     | Por quê
void Agencia::relatorio()            | parte public da Agencia  | imprime as 10 linhas do RELATORIO
int contarVoosLancados(string cpf)   | parte privada da Agencia | conta em quantos voos lançados o astronauta estava a bordo (a experiência)
RELATORIO                            | main()                   | chamar agencia.relatorio()

**- Resultado de `testar.sh missao3` e de `testar.sh parte1`:**

```testes/testar.sh parte 1
OK    01_cadastros
OK    02_passageiros_planejados
OK    03_lancamento_finalizacao
OK    04_explosao_e_mortes
OK    05_operacoes_invalidas
OK    06_cenario_completo

6 de 6 testes passaram.
```
```testes/testar.sh missao3
OK    01_relatorio_vazio
OK    02_relatorio_cenario
OK    03_relatorio_empate
OK    04_salvar_para_relatorio
OK    05_relatorio_apos_carregar

5 de 5 testes passaram.
```

**- Precisei refazer? O que mudou no pedido:** Não precisei refazer nada, atendeu bem ao que eu havia solicitado.

## Missão 4: livre

**- O que escolhi e por quê:** dentre as ideias sugeridas no material, tomei a liberdade de escolher a opção "destino e duração do voo, e um comando que mostra a agenda". A escolha foi motivada pelo menor grau de dificuldade da implementação, o que reduz a possibilidade de erros por parte da IA e facilita a elaboração dos testes.
**- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos (escritos antes de pedir):** Os novos comando foram DEFINIR_VOO e AGENDA. DEFINIR_VOO é responsável por atualizar os voos cadastrados com o destino e o tempo de duração da viagem. AGENDA imprime a linha AGENDA DE VOOS seguida de linhas correspondentes a quantidade de voos que foram atualizados (previamente cadastrados). A impressão deve ser feita na ordem que foram definidos/atualizados, não cadastrados. Além disso, DEFINIR_VOO passa por algumas validações usuais para verificar a veracidade das informações prestadas: por exemplo, não há como definir a duração de uma viagem com tempo menor ou igual a 0, não há a possibilidade de definir um voo se não houverem todos os parâmetros, não é possível definir um voo que não foi cadastrado, não é possível definir um voo que já foi definido antes. A saída esperada é mostrada a seguir:

OK: voo 10 cadastrado
ERRO: duracao do voo deve ser maior que 0
ERRO: duracao do voo deve ser maior que 0
ERRO: destino nao pode ser vazio
ERRO: voo 99 nao cadastrado
OK: voo 10 atualizado
ERRO: voo 10 ja possui destino e duracao
AGENDA DE VOOS
Voo 10 - Lua - 120 minutos

**- Primeira mensagem:**
-------------------------------------------------------------------------------------------------MISSÃO 4-------------------------------------------------------------------------------------------------
Este programa em C++11 controla astronautas e voos de uma agência espacial. Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp. Os testes em testes/parte1 passam. Recentemente foi feita a inclusão de 5 novos comandos, dois deles para a missão 1 LISTAR_ASTRONAUTAS e HISTORICO cpf, outros dois para a missão 2 SALVAR e CARREGAR, e um para a missão 3 RELATORIO. Eles atendem fazem o que tem que ser feito e os testes em testes/parte1, testes/missao1, testes/missao2 e testes/missao3 passam. Quero dois comandos novos: DEFINIR_VOO, e um comando que mostra a AGENDA. O funcionamento está abaixo.

DEFINIR_VOO é responsável por atualizar os voos cadastrados com o destino e o tempo de duração da viagem. 
AGENDA imprime a linha AGENDA DE VOOS seguida de linhas correspondentes a quantidade de voos que foram atualizados (previamente cadastrados). A impressão deve ser feita na ordem que foram definidos/atualizados, não cadastrados, dessa maneira:

OK: voo 10 cadastrado
OK: voo 20 cadastrado
OK: voo 30 cadastrado
OK: voo 30 atualizado
OK: voo 10 atualizado
OK: voo 20 atualizado
AGENDA DE VOOS
Voo 30 - Marte - 300 minutos
Voo 10 - Lua - 120 minutos
Voo 20 - EstacaoEspacial - 60 minutos 

O DEFINIR_VOO passa por algumas validações usuais para verificar a veracidade das informações prestadas: por exemplo, não há como definir a duração de uma viagem com tempo menor ou igual a 0, não há a possibilidade de definir um voo se não houverem todos os parâmetros, não é possível definir um voo que não foi cadastrado, não é possível definir um voo que já foi definido antes. A saída esperada é mostrada a seguir:

OK: voo 10 cadastrado
ERRO: duracao do voo deve ser maior que 0
ERRO: duracao do voo deve ser maior que 0
ERRO: destino nao pode ser vazio
ERRO: voo 99 nao cadastrado
OK: voo 10 atualizado
ERRO: voo 10 ja possui destino e duracao
AGENDA DE VOOS
Voo 10 - Lua - 120 minutos

Se nenhum voo for definido quando a agenda for chamada, deve aparecer a mensagem (nenhum), dessa forma:

AGENDA DE VOOS
(nenhum)

Além disso, não é possível cadastrar um voo que já foi cadastrado, como fazia em funcionalidade já existente.

Não mude nenhum comando que já existe nem a saída deles. Não use nada fora da biblioteca padrão. Vou conferir com bash testes/testar.sh missao4 e depois com bash testes/testar.sh parte1. Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.

**- O que veio, comparado com o que eu esperava:**

De maneira resumida, na missão 4, a IA alterou: 
O que                                | Onde                     | Por quê
#include <sstream>                   | topo do arquivo          | para ler destino e duração do que sobra na linha
Em Voo: campos string destino; int duracao; | classe Voo        | guarda o destino e duração
Voo::definirDestinoDuracao(dest, dur)| classe Voo               | seta os dois campos
Voo::jaDefiniu()                     | classe Voo               | saber se o voo já foi atualizado
Voo:: getDestino() e getDuracao()    | classe Voo               | usados na AGENDA
vector<int> voosDefinidos;           |private Agencia           | guarda o código dos voos na ordem em qie foram definidos
Agencia::definirVoo(codigo, parametros)| public Agencia         | valida e atualiza o voo
Agencia::agenda()                    |public Agencia            |imprime a AGENDA DE VOOS
DEFINIR_VOO e AGENDA                 | main()                   | chamar os métodos

**- `testar.sh parte1` continuou passando?** Não só `teste.sh parte 1` como todos os outros testes continuaram passando com a inclusão da missão 4.

**- Aceitei, ajustei ou descartei? Por quê:** Aceitei, pois atendia aos critérios que havia estabelecido previamente.

## Fechamento

**- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:**
**- Onde ela errou ou fez algo que eu não pedi:**
**- O que eu faria diferente da próxima vez:**
