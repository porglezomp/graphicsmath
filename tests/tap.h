#ifndef TAP_H
#define TAP_H 1

int tapcounter = 0;

void fail(const char *message) {
	printf("not ok %i - %s\n", ++tapcounter, message);
}

void pass(const char *message) {
	printf("ok %i - %s\n", ++tapcounter, message);
}

void test(bool success, const char *message) {
	if (success) pass(message);
	else fail(message);
}

void done() {
	printf("1..%i\n", tapcounter);
}

#endif