# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

**- Versão do OpenCode (`opencode --version`):** 1.18.31
**- Modelo usado:** big pickle

## Parte 1: antes de programar

**- O que cada classe guarda:** Na parte 1 do projeto temos três classes: Astronauta, que guarda as informações de um astronauta (uma pessoa); Voo, que guarda as informações de uma viagem ao espaço, bem como os dados (cpfs) dos astronautas que nela estavam; e, Agencia, que guarda as informações dos astronautas (cpfs) e voos (codigos) e organiza as operações que podem ser feitas.

**- O que acontece em `LANCAR_VOO`, em palavras:**
**- Uma dúvida que eu tinha antes de começar:**

## Parte 1: uso de IA para entender algo

**- O que perguntei (ou "não usei"):**
**- O que aprendi:**

## Primeiro contato: revisão sem editar

**- As três melhorias que a IA sugeriu, em uma linha cada:**
**- A que escolhi e por quê:**
**- O que mudou no código, e se os seis testes continuaram passando:**
**- O que entendi que não sabia antes:**

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

**- Primeira mensagem (o pedido do plano):**
-------------------------------------------------------------------------------------------------MISSÃO 1--------------------------------------------------------------------------------------------------
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
 
**- O plano que a IA apresentou, resumido:**
**- Mudei algo no plano antes de liberar?** não mudei nada
**- Resultado de `testar.sh missao1` e de `testar.sh parte1`:**
**- Precisei refazer? O que mudou no pedido:**

## Missão 2: SALVAR e CARREGAR

**- Primeira mensagem:**
-------------------------------------------------------------------------------------------------MISSÃO 2-------------------------------------------------------------------------------------------------

Este programa em C++11 controla astronautas e voos de uma agência espacial. Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp. Os testes em testes/parte1 passam. Recentemente foi feita a inclusão de dois novos comandos para a missão 1 LISTAR_ASTRONAUTAS e HISTORICO cpf. Eles atendem fazem o que tem que ser feito e os testes em testes/missao1 passam. Quero dois comandos novos: SALVAR e CARREGAR. O funcionamento está abaixo.

Missão 2: SALVAR e CARREGAR
SALVAR nome_do_arquivo grava todos os dados em um arquivo de texto e imprime OK: dados salvos em nome_do_arquivo. Se não conseguir abrir o arquivo para escrita: ERRO: nao foi possivel salvar em nome_do_arquivo.
CARREGAR nome_do_arquivo substitui todos os dados atuais pelos do arquivo e imprime OK: dados carregados de nome_do_arquivo. Se o arquivo não existir: ERRO: nao foi possivel carregar de nome_do_arquivo, e os dados atuais continuam como estavam.
O formato do arquivo é escolha sua e da IA, desde que seja texto e que carregar depois de salvar reconstrua tudo: astronautas com vivo e disponível, voos com estado e lista de CPFs. Peça que a IA mostre o formato com um exemplo e explique como o programa reconstrói os objetos ao ler.

Teste: bash testes/testar.sh missao2. Ele roda três arquivos em sequência: o primeiro monta um cenário e salva em dados_teste.txt; o segundo, em outra execução do programa, carrega e continua operando; o terceiro tenta carregar um arquivo que não existe. Depois: bash testes/ testar.sh parte1. 

Não mude nenhum comando que já existe nem a saída deles. Não use nada fora da biblioteca padrão. Vou conferir com bash testes/testar.sh missao2 e depois com bash testes/testar.sh parte1. Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.

**- O plano, resumido:**
**- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):**
**- Resultado de `testar.sh missao2` e de `testar.sh parte1`:**
**- Precisei refazer? O que mudou no pedido:**

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
**- Resultado de `testar.sh missao3` e de `testar.sh parte1`:**
**- Precisei refazer? O que mudou no pedido:**

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
**- `testar.sh parte1` continuou passando?** não só `teste.sh parte 1` como todos os outros testes continuaram passando com a inclusão da missão 4.
**- Aceitei, ajustei ou descartei? Por quê:** aceitei, pois atendia aos critérios que havia estabelecido previamente.

## Fechamento

**- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:**
**- Onde ela errou ou fez algo que eu não pedi:**
**- O que eu faria diferente da próxima vez:**
