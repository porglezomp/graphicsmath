#include <stdio.h>
#include "quat.h"
#include "test.h"

int main() {
	test(quat() == quat(), "identity");
	done();
	return 0;
}
