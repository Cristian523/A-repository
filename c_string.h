#ifndef C_STRING_H
#define C_STRING_H


typedef struct String {
	char* str;
	int length;
	int Max_length;
} String;

String string_new_with_size(int);
String string_new_with_str(char*, int);
String string_new();
int string_input(String*);
int string_length(String);
int string_append(String*, char);
void string_destroy(String*);
int string_remove(String*, char);
void string_remove_all(String*, char);
int string_search(String, char);
int string_count(String, char);
void string_print(String);
int string_parseInt(String, int*);

#endif
