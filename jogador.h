//este operador serve para dizer ao compilador de C, que este ficheiro header so deve ser processado
//se ainda nao sido processado anteriormente
//le-se "se ainda nao tiver sido definido JOGADOR_H, define JOGADOR_H".
//Se o teste falhar (i.e. o JOGADOR_H ja foi definido), o compilador salta para o #endif e tudo o que esta
//dentro do #if e ignorado
#ifndef JOGADOR_H
#define JOGADOR_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <math.h>
//Definicao do enumerado Posicao
typedef enum e_Posicao {GR,Defesa,Medio,Avancado} Posicao;

//Dada uma string, retorna a posicao (valor enumerado) correspondente a string recebida
Posicao string_to_posicao(char *s);

//Dada uma posicao, retorna uma String que descreve a posição
const char * posicao_to_string(Posicao p);

//Define o Tipo Estruturado Jogador, e os seus membros
typedef struct S_Jogador
{
    char *primeiro_nome;
    char *ultimo_nome;
    char *clube;
    int ano;
    Posicao pos;
    int internacionalizacoes;
    int golos;
} Jogador;

//Construtor do tipo Jogador, recebe os membros, e cria um novo jogador, e inicializa-o. Devolve
//um ponteiro para o jogador criado
Jogador *jogador(char *primeiro_nome,char *ultimo_nome, int ano, Posicao p, int inter, int golos, char *clube);

//Recebe um ponteiro para um jogador, e liberta a memória usada pelo tipo
void free_jogador(Jogador *j);

//Recebe um ponteiro para um jogador, e cria uma copia (ou clone) profunda do jogador. Devolve um
//ponteiro para o jogador criado
Jogador *jogador_dup(Jogador *j);

//Recebe um ponteiro para um jogador, e o numero de golos marcados num jogo, e adiciona um jogo (internacionalizacao) ao
//jogador, e atualiza o numero de golos marcados pelo jogador
void adiciona_internacionalizacao(Jogador *j, int golos);

//Imprime um jogador para o standard output, usando o formato:
//[<Primeiro Nome>][<Ultimo Nome>][<Ano>][<Posição>][<Internacionalizações>][Golos][Clube Atual]\n
//Exemplo:
//[Cristiano][Ronaldo][1985][Avancado][196][118][Al_Nassr]
void println_jogador(Jogador *j);

//Recebe um array de ponteiros para jogadores, e o numero de elementos no array n, e imprime
//todos os jogadores, pela ordem em que aparecem no array. Caso nao existam elementos no array
//imprime "*\n"
void println_jogadores(Jogador *jogadores[], int n);

//Dado um array de ponteiros para jogadores, e um numero n de jogadores a ler, le do standard input os n jogadores.
//cada jogador deve ser lido numa unica linha, com todos os membros separados por espaco, pela seguinte ordem
//<Primeiro Nome> <Ultimo Nome> <Ano Nascimento> <Posicao> <Internacionalizacoes> <Golos> <Clube Atual>
//Os membros que correspondem a cadeias de caracteres (strings) nao excederao os 100 caracteres cada.
//O metodo retorna o numero de jogadores efetivamente lidos.
int get_jogadores(Jogador *jogadores[], int n);

//Dado um array de ponteiros para jogadores, e um numero n de jogadores a ler, le do ficheiro os n jogadores.
//cada jogador deve ser lido numa unica linha, com todos os membros separados pelo caracter tab "\t", pela seguinte ordem
//<Primeiro Nome>   <Ultimo Nome>   <Ano Nascimento>    <Posicao>   <Internacionalizacoes>  <Golos> <Clube Atual>
//Os membros que correspondem a cadeias de caracteres (strings) podem ter espaços e nao excederao os 100 caracteres cada.
//O metodo retorna o numero de jogadores efetivamente lidos.
int get_jogadores_from_file(FILE *f, Jogador *jogadores[], int n);

//Dado um array de ponteiros para jogadores, um numero n de jogadores, uma string com o primeiro nome,
//e uma string com o ultimo nome, este metodo procura no array jogadores pelo primeiro jogador
//que tenha o primeiro e ultimo nome iguais aos nomes recebidos, e retorna o ponteiro para esse jogador.
//Caso nao exista tal jogador, retorna-se o ponteiro NULL
Jogador *pesquisa_jogador(Jogador *jogadores[], int n, char *primeiro_nome, char *ultimo_nome);

//Dado um array de ponteiros para jogadores, um numero n de jogadores nesse array, retorna o jogador
//com maior numero de golos marcados. Caso nao exista nenhum jogador, retorna-se NULL
Jogador *pesquisa_melhor_marcador(Jogador *jogadores[], int n);

//dado um array de entrada de ponteiros de jogadores in, e um array de saida de ponteiros de jogadores out,
//um inteiro n que corresponde ao numero de elementos de in, e um Predicado sobre Jogadores
//esta funcao procura no array in todos os jogadores que satisfaze o predicado, colocando-os no 
//array de saida out. A funcao retorna o numero de elementos encontrados e guardados em out.
int pesquisa_jogadores(Jogador *in[], Jogador *out[], int n, int (*p) (Jogador*));

//dado um array de entrada de ponteiros de jogadores in, e um array de saida de ponteiros de jogadores out,
//um inteiro n que corresponde ao numero de elementos de in, e uma string com um nome de um clube
//esta funcao procura no array in todos os jogadores que pertencam ao clube recebido, colocando-os no 
//array de saida out. A funcao retorna o numero de elementos encontrados e guardados em out.
int pesquisa_jogadores_clube(Jogador *in[], Jogador *out[], int n, char* clube);

//dado um array de entrada de ponteiros de jogadores in, um array de saida de ponteiros de jogadores out,
//um inteiro n que corresponde ao numero de elementos de in, e dois inteiros que correspondem
//a um numero minimo e maximo de internacionalizacoes, esta funcao procura no array in todos
//os jogadores com numero de internacionalizacoes compreendido entre os valores minimo e maximo (inclusive),
//colocando-os no array de saida out. A funcao retorna o numero de elementos encontrados e guardados em out.
int pesquisa_jogadores_inter(Jogador *in[], Jogador *out[], int n, int min_inter, int max_inter);


void test_Jogador_File_Loading(void);

void test_Jogador_Sorting(void);

void test_Jogador_Pesquisa(void);

#endif