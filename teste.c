#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_string.h"

int main() {
	String cadeia = string_new();
	printf("Digite aqui sua string: ");
	
	string_input(&cadeia);
	
	string_print(cadeia);
	
	printf("O número de caracteres 'a's é: %d\n", string_count(cadeia, 'a'));
	
	string_remove_all(&cadeia, ' ');
	
	string_print(cadeia);
	
	printf("O número de caracteres é: %d\n", string_length(cadeia));
	
	string_append(&cadeia, 'A');
	
	string_print(cadeia);
	printf("Novo tamanho da string: %d\n", string_length(cadeia));
	
	string_destroy(&cadeia);
}
