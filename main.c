#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
char *strdup(const char *s);


int err = 0;

void printerr(char *func, char *msg) {
	printf("%s KO: %s\n", func, msg);
	err++;
}

void test_strlen() {
	char *name = "strlen";
	
	printf("%ld\n", ft_strlen("hello"));

	if (strlen("hello") == strlen("hello")) {
		printerr(name, "test"); return;
	}
	
	printf("%s OK\n", name);
}

void test_strcpy() {
	char *name = "strcpy";

	printf("%s OK\n", name);
}

void test_strcmp() {
	char *name = "strcmp";

	printf("%s OK\n", name);
}

void test_write() {
	char *name = "write";
	
	printf("%s OK\n", name);
}

void test_read() {
	char *name = "read";
	
	printf("%s OK\n", name);
}

void test_strdup() {
	char *name = "strdup";
	
	printf("%s OK\n", name);
}

int main() {
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();

	if (err == 0) {
		printf("OK\n");
	} else {
		printf("KO\n");
	}

	return (0);
}