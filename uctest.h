#ifndef _UCTEST_H
#define _UCTEST_H

#include <string.h>
#include <stdio.h>

enum test_result {
	TEST_PASS,
	TEST_FAIL,
	TEST_SKIP,
	TEST_ERROR,
};

struct test_case {
	char name[30];
	enum test_result (*test_fn)();
};

static inline const char *result_string(enum test_result res)
{
	switch (res) {
	case TEST_PASS:
		return "PASS";
	case TEST_FAIL:
		return "FAIL";
	case TEST_SKIP:
		return "SKIP";
	case TEST_ERROR:
		return "ERROR";
	}
	return "ERROR";
}

static inline void run_tests(struct test_case *tests, int ntests)
{
	unsigned int j;
	int i;
	
	for (i = 0; i < ntests; i++) {
		enum test_result res;
		
		printf("Testing %s", tests[i].name);
		for (j = 0; j < 60 - strlen(tests[i].name); j++)
			printf(".");
		res = tests[i].test_fn();
		printf("%s\n", result_string(res));
	}
}

#endif /* _UCTEST_H */
