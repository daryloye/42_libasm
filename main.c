#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t nbytes);
ssize_t read(int fd, void buf, size_t count);
char *ft_strdup(const char *s);

int err = 0;

void printerr(char *func, char *msg) {
	printf("%s KO: %s\n", func, msg);
	err++;
}

void test_strlen() {
	char *name = "strlen";
	
	if (strlen("hello") != ft_strlen("hello")) {
		printerr(name, "hello"); return;
	}
	if (strlen("0") != ft_strlen("0")) {
		printerr(name, "0"); return;
	}
	if (strlen("") != ft_strlen("")) {
		printerr(name, "null"); return;
	}
	if (strlen("\0") != ft_strlen("\0")) {
		printerr(name, "\0"); return;
	}
	
	printf("%s OK\n", name);
}

void test_strcpy() {
	char *name = "strcpy";

    char src1[] = "hello";
    char dest1[] = "worldddd";
    ft_strcpy(dest1, src1);
	if (strcmp(dest1, src1) != 0) {
		printerr(name, "hello"); return;
	}

	char src2[] = "";
    char dest2[] = "world";
	ft_strcpy(dest2, src2);
	if (strcmp(dest2, src2) != 0) {
		printerr(name, ""); return;
	}

	char src3[] = "world";
    char dest3[] = "";
    ft_strcpy(dest3, src3);
	if (strcmp(dest3, src3) != 0) {
		printerr(name, ""); return;
	}

	printf("%s OK\n", name);
}

void test_strcmp() {
	char *name = "strcmp";

	if (ft_strcmp("hello", "hello") != 0) {
		printerr(name, "hello, hello"); return;
	}
	if (ft_strcmp("hella", "hello") != 'a' - 'o') {
		printerr(name, "hella, hello"); return;
	}
	if (ft_strcmp("hello", "hella") != 'o' - 'a') {
		printerr(name, "hello, hella"); return;
	}
	if (ft_strcmp("", "hello") != 0 - 'h') {
		printerr(name, " , hello"); return;
	}
	if (ft_strcmp("", "") != 0) {
		printerr(name, ""); return;
	}

	printf("%s OK\n", name);
}

void test_write() {
	char *name = "write";

	if (ft_write(1, "hello\n", 6) != write(1, "hello\n", 6)) {
		printerr(name, "hello"); return;
	}
	if (ft_write(1, "", 1) != write(1, "", 1)) {
		printerr(name, "null"); return;
	}
	if (ft_write(2, "test\n", 3) != write(2, "test\n", 3)) {
		printerr(name, "test"); return;
	}
	if (ft_write(4, "test", 3) != write(4, "test", 3)) {
		printerr(name, "invalid fd"); return;
	}

	printf("\n%s OK\n", name);
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