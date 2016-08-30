# uctest
A small - single header file - unit test library

# Example
```
#include "uctest.h"

enum test_result test1(void)
{
	/* do something right */
	return TEST_PASS;
}

enum test_result test2(void)
{
	/* do something wrong */
	return TEST_FAIL;
}

struct test_case tests[] = {
	{
		.name = "Test1",
		.test_fn = test1,
	},
	{
		.name = "Test2",
		.test_fn = test2,
	},
};

int main(void)
{
	int ntests = sizeof(tests)/sizeof(tests[0]);

	run_tests(tests, ntests);
}
```
This will result in the following:

```
Testing Test1.......................................................PASS
Testing Test2.......................................................FAIL
```
