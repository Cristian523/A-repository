#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_string.h"
#define STRING_DEFAULT_CAPACITY 50

String string_new_with_size(int size) {
	String cadeia;
	cadeia.str = NULL;
	cadeia.Max_length = size;
	cadeia.length = 0;
	return cadeia;
}

String string_new_with_str(char* vet, int max_size) {
	String cadeia;
	cadeia.str = vet;
	cadeia.Max_length = max_size;
	cadeia.length = strlen(vet);
	return cadeia;
	
}

String string_new() {
	String cadeia;
	cadeia.str = NULL;
	cadeia.Max_length = cadeia.length = 0;
	return cadeia;
}

int string_input(String* cadeia) {
	char* aux;
	char x;
	int N, n = 0;
	// Se existir uma string antes, libere a memória.
	if (cadeia->str != NULL) {
		free(cadeia->str);
		cadeia->str = NULL;
		cadeia->length = cadeia->Max_length = 0;
	}
	// Tamanho máximo da string atual
	N = cadeia->Max_length;
	if (N <= 0) 
		N = STRING_DEFAULT_CAPACITY;
	
	// Alocar o vetor para a nova string
	aux = (char*)malloc(N * sizeof(char));
	if (aux == NULL)
		return 0;
	
	// Lê os caracteres até encontrar o '\n'
	while (scanf("%c", &x) == 1) {
		if (x == '\n')
			break;
		
		if (n >= N) {  // Se estiver cheio, dobre o tamanho
			N *= 2;
			char* novo_aux = (char*)realloc(aux, N * sizeof(char));
			if (novo_aux == NULL) {
				free(aux);
				return 0;
			}
			aux = novo_aux;	
		}
		aux[n] = x;
		n++;
	}
	
	// Atribuindo a nova string
	cadeia->Max_length = N;
	cadeia->length = n;
	cadeia->str = aux;
	return 1;
}

int string_length(String cadeia) {
	return cadeia.length;
}

int string_append(String* cadeia, char x) {
	// Caso esta função seja chamada com nenhum tamanho inicial máximo.
	if (cadeia->Max_length <= 0)
		cadeia->Max_length = STRING_DEFAULT_CAPACITY; 
	
	if (cadeia->length >= cadeia->Max_length - 1) {
		cadeia->Max_length *= 2;
		char* aux = (char*)realloc(cadeia->str, cadeia->Max_length * sizeof(char));
		if (aux == NULL)
			return 0;
		cadeia->str = aux;
	}
	cadeia->str[cadeia->length] = x;
	(cadeia->length)++;
	return 1;
}

void string_destroy(String* cadeia) {
	free(cadeia->str);
	cadeia->str = NULL;
	cadeia->length = cadeia->Max_length = 0;
}

int string_remove(String* cadeia, char x) {
	int posicao = -1;
	for (int i = 0; i < cadeia->length; i++) {
		if (cadeia->str[i] == x) {
			posicao = i;
			break;
		}			
	}
	if (posicao != -1) {
		for (int i = posicao; i < cadeia->length - 1; i++) {
			cadeia->str[i] = cadeia->str[i + 1];
		}
		cadeia->str[cadeia->length - 1] = '\0';
		(cadeia->length)--;
		return 1;
	}
	return 0;
}

void string_remove_all(String* cadeia, char x) {
	int i, j = 0;
	char aux;
	for (i = 0; i < cadeia->length; i++) {
		if (cadeia->str[i] != x) {
			cadeia->str[j] = cadeia->str[i];
			j++;
		}
	}
	cadeia->str[j] = '\0';
	cadeia->length = j;
}

int string_search(String cadeia, char x) {
	for (int i = 0; i < cadeia.length; i++) {
		if (cadeia.str[i] == x)
			return 1; 
	}
	return 0;
}

int string_count(String cadeia, char x) {
	int count = 0;
	for (int i = 0; i < cadeia.length; i++) {
		if (cadeia.str[i] == x)
			count++;
	}
	return count;
}

void string_print(String cadeia) {
	for (int i = 0; i < cadeia.length; i++) 
		printf("%c", cadeia.str[i]);
	printf("\n");
}


