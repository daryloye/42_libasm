#include <stdio.h>
#include <string.h>

int err = 0;

void printerr(char *func, char *msg) {
	printf("%s KO: %s\n", func, msg);
	err++;
}

void test_strlen() {
	char *name = "strlen";
	
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