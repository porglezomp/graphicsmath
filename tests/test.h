#include <cstdio>

int taptestcounter = 0;

void pass(const char *message) {
	printf("ok %i - %s\n", ++taptestcounter, message);
}

void fail(const char *message) {
	printf("not ok %i - %s\n", ++taptestcounter, message);
}

void test(bool condition, const char *message) {
	if (condition) pass(message);
	else fail(message);
}

void done() {
	printf("1..%i\n", taptestcounter);
}
