#include <string.h>
#include <stdio.h>
#include <inttypes.h>

int __flsll(long long value)
{
	uint64_t ret;

	asm (
		"mv t1, %1\n"
		"snez a0, t1\n"
		"li t2, 32\n"

		"fls_loop:"
		"srl t3, t1, t2\n"
		"beqz t3, fls_cont\n"		
		"mv t1, t3\n"
		"add a0, a0, t2\n"

		"fls_cont:\n"
		"srl t2, t2, 1\n"
		"bne t2, x0, fls_loop\n"

		"mv %0, a0\n"
		: "=r"(ret) : "r"(value)
	);
	return ret;
}

int main()
{
	uint64_t out, val[] = {
		0xffffffffffffffff,
		0xaaaaaaaaaaaaaaaa,
		0x5555555555555555,
		0x10000000000,
		0x55555,
		0x555,
		0x3,
		0x2,
		0x1,
		/* Must terminate with 0 */
		0,
	};


	for (uint64_t *ptr= val; ; ++ptr) {
		printf("0x%" PRIx64 " -> 0x%x\n", *ptr, __flsll(*ptr));
		if (!*ptr)
			break;
	}

	return 0;
}
