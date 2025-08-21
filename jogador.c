#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include "our_ints.h"
#include "our_doubles.h"
#include "jogador.h"

const char *author = "Brandon Mejia";

const char *STRINGS_POSICAO[4] = {"Guarda-redes", "Defesa", "Medio", "Avancado"};

const char *posicao_to_string(Posicao p) 
{
    return STRINGS_POSICAO[p];
}

Posicao string_to_posicao(char *s)
{
    for (int i = 0; i < 4; i++)
        if (strcmp(s, STRINGS_POSICAO[i]) == 0)
            return i;

    return -1;
}

Jogador *jogador(char *primeiro_nome, char *ultimo_nome, int ano, Posicao p, int inter, int golos, char *clube)
{
    Jogador *a = calloc(1, sizeof(Jogador));

    a->primeiro_nome = strdup(primeiro_nome);
    a->ultimo_nome = strdup(ultimo_nome);
    a->ano = ano;
    a->pos = p;
    a->internacionalizacoes = inter;
    a->golos = golos;
    a->clube = strdup(clube);

    return a;
}

void free_jogador(Jogador *j)
{
    free(j->primeiro_nome);
    free(j->ultimo_nome);
    free(j->clube);
    free(j);
}

Jogador *jogador_dup(Jogador *j)
{
    Jogador *copia = malloc(sizeof(Jogador));
    copia->primeiro_nome = strdup(j->primeiro_nome);
    copia->ultimo_nome = strdup(j->ultimo_nome);
    copia->ano = j->ano;
    copia->pos = j->pos;
    copia->internacionalizacoes = j->internacionalizacoes;
    copia->golos = j->golos;
    copia->clube = strdup(j->clube);
    // return jogador(j->primeiro_nome, j->ultimo_nome, j->clube.... etc)
    return copia;
}

void adiciona_internacionalizacao(Jogador *j, int golos)
{
    j->golos = golos >= 0 ? golos + j->golos : j->golos;
    j->internacionalizacoes += 1;
}

void println_jogador(Jogador *j)
{
    printf("[%s][%s][%d][%s][%d][%d][%s]\n", j->primeiro_nome, j->ultimo_nome, j->ano,
           STRINGS_POSICAO[j->pos], j->internacionalizacoes, j->golos, j->clube);
}

void println_jogadores(Jogador *jogador[], int n)
{

    if (n == 0)
        printf("*\n");

    for (int i = 0; i < n; i++)
        printf("[%s][%s][%d][%s][%d][%d][%s]\n", jogador[i]->primeiro_nome, jogador[i]->ultimo_nome, jogador[i]->ano,
               STRINGS_POSICAO[jogador[i]->pos], jogador[i]->internacionalizacoes, jogador[i]->golos, jogador[i]->clube);
}

int get_jogadores(Jogador *jogadores_array[], int n)
{
    char primeiro_nome[44], ultimo_nome[44], posicao[44], clube_atual[44];
    int ano_nascimento, internacionalizacoes, golos;
    int i = 0;

    while (i < n && scanf("%s%s%d%s%d%d%s", primeiro_nome, ultimo_nome, &ano_nascimento,
                          posicao, &internacionalizacoes, &golos, clube_atual) != EOF)
    {
        jogadores_array[i++] = jogador(primeiro_nome, ultimo_nome, ano_nascimento,
                                       string_to_posicao(posicao), internacionalizacoes, golos, clube_atual);
    }
    return i;
}

Jogador *pesquisa_jogador(Jogador *jogadores[], int n, char *primeiro_nome, char *ultimo_nome)
{

    for (int i = 0; i < n; i++)
    {
        if (strcmp(jogadores[i]->primeiro_nome, primeiro_nome) == 0 && strcmp(jogadores[i]->ultimo_nome, ultimo_nome) == 0)
            return jogadores[i];
    }

    return NULL;
}

Jogador *pesquisa_melhor_marcador(Jogador *jogadores[], int n)
{
    if (n == 0)
        return NULL;

    Jogador *best_jogador = jogadores[0];
    for (int i = 1; i < n; i++)
    {
        if (jogadores[i]->golos > best_jogador->golos)
        {
            best_jogador = jogadores[i];
        }
    }

    return best_jogador;
}

int pesquisa_jogadores_clube(Jogador *in[], Jogador *out[], int n, char *clube)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(in[i]->clube, clube) == 0)
            out[j++] = in[i];
    }
    return j;
}

int pesquisa_jogadores_inter(Jogador *in[], Jogador *out[], int n, int min_inter, int max_inter)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (in[i]->internacionalizacoes >= min_inter && in[i]->internacionalizacoes <= max_inter)
            out[j++] = in[i];
    }
    return j;
}

void Complete(char *s, char *s2)
{
    if (strlen(s2) != 0)
    {
        strcat(s, " ");
        strcat(s, s2);
    }
}

typedef int (*Comparer)(const void *, const void *);

int Compara_jogadores(Jogador **jogador, Jogador **jogador2)
{

    if ((*jogador)->internacionalizacoes > (*jogador2)->internacionalizacoes)
    {
        return -1;
    }
    else if ((*jogador)->internacionalizacoes == (*jogador2)->internacionalizacoes)
    {
        return (*jogador)->golos > (*jogador2)->golos ? -1 : 1;
    }

    return 1;
}

int filtro(Jogador *j)
{
    return j->pos == 3 && j->golos < 20;
}

int pesquisa_jogadores(Jogador *in[], Jogador *out[], int n, int (*p)(Jogador *))
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if ((*p)(in[i]))
            out[j++] = in[i];
    }
    return j;
}

int get_jogadores_from_file(FILE *f, Jogador *jogadores[], int n) // Forma 2
{

    char primeiro_nome[44], ultimo_nome[44], posicao[44], clube_atual[50];
    int ano_nascimento, internacionalizacoes, golos, i = 0;

    while (i < n && fscanf(f, "%s\t%s\t%d\t%s\t%d\t%d\t%[^\n]%*[\n]", primeiro_nome, ultimo_nome, &ano_nascimento,
                           posicao, &internacionalizacoes, &golos, clube_atual))
        jogadores[i++] = jogador(primeiro_nome, ultimo_nome, ano_nascimento,
                                 string_to_posicao(posicao), internacionalizacoes, golos, clube_atual);

    return i;
}

void test_G_S2(void)
{
    int n = 0, indice = 0, golos_extra = 0;
    char option, s[50], s2[50];
    Jogador *array_jogadores[50], *array_result[50], *j;

    scanf("%d", &n);
    n = get_jogadores(array_jogadores, n);

    while (scanf("%c", &option) != EOF)
    {

        if (option == '+')
        {
            scanf("%s%s", s, s2);

            j = pesquisa_jogador(array_jogadores, n, s, s2);
            scanf("%d", &golos_extra);

            if (j == NULL)
            {
                printf("Not found!\n");
            }
            else
            {
                adiciona_internacionalizacao(j, golos_extra);

                println_jogador(pesquisa_jogador(array_jogadores, n, s, s2));
            }
        }

        else if (option == '?')
        {
            scanf("%s", s);
            indice = pesquisa_jogadores_clube(array_jogadores, array_result, n, s);
            println_jogadores(array_result, indice);
        }
    }
}

void test_Jogador_File_Loading(void)
{
    int n = 0, indice = 0, golos_extra = 0;
    char option, s[50], s2[50], input[50];
    Jogador *array_jogadores[500], *array_result[500], *j;

    char filename[20];
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");

    fscanf(f, "%d%*c", &n);
    n = get_jogadores_from_file(f, array_jogadores, n);
    while (scanf("%c", &option) != EOF)
    {

        if (option == '+')
        {
            scanf("%s%s", s, s2);

            j = pesquisa_jogador(array_jogadores, n, s, s2);
            scanf("%d", &golos_extra);

            if (j == NULL)

            {
                printf("Not found!\n");
            }

            else
            {
                adiciona_internacionalizacao(j, golos_extra);

                println_jogador(pesquisa_jogador(array_jogadores, n, s, s2));
                memset(s2, 0, sizeof(s2));
            }
        }

        else if (option == '?')
        {
            fgets(input, 50, stdin);
            sscanf(input, "%s%s", s, s2);
            Complete(s, s2);
            memset(s2, 0, sizeof(s2));

            indice = pesquisa_jogadores_clube(array_jogadores, array_result, n, s);

            println_jogadores(array_result, indice);
        }
    }
    free_jogador(*array_jogadores);
    free_jogador(*array_result);
    fclose(f);
}

void test_Jogador_Sorting(void)
{
    int n = 0;
    Jogador *array_jogadores[50];

    char filename[20];
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Erro na abertura do ficheiro\n");
    }

    fscanf(f, "%d", &n);
    n = get_jogadores_from_file(f, array_jogadores, n);

    qsort(array_jogadores, n, sizeof(Jogador *), (Comparer)Compara_jogadores);

    println_jogadores(array_jogadores, n);

    free_jogador(*array_jogadores);
    fclose(f);
}

void test_Jogador_Pesquisa(void)
{
    int n = 0, m;
    Jogador *array_jogadores[50], *array_result[500];

    char filename[20];
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Erro na abertura do ficheiro\n");
    }

    fscanf(f, "%d", &n);

    n = get_jogadores_from_file(f, array_jogadores, n);

    m = pesquisa_jogadores(array_jogadores, array_result, n, filtro);

    println_jogadores(array_result, m);

    free_jogador(*array_jogadores);
    free_jogador(*array_result);
    fclose(f);
}

int main()
{
    test_Jogador_Sorting();
    return 0;
}
