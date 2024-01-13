#include <string.h>
#include <stdio.h>

int __ffsll(long long value)
{
	int ret;

	asm (
		"mv a0, %1\n"
		"beqz a0, ffs_out\n"
		"mv t1, a0\n"
		"li a0, 64\n"
		"li t2, 32\n"

		"ffs_loop:\n"
		"sll t3, t1, t2\n"
		"seqz t3, t3\n"
		"addi t3, t3, -1\n"
		"and t3, t3, t2\n"
		"sub a0, a0, t3\n"
		"sll t1, t1, t3\n"
		"srl t2, t2, 1\n"
		"bne t2, x0, ffs_loop\n"

		"ffs_out:\n"
		"mv %0, a0\n"
		: "=r"(ret) : "r"(value)
	);
	return ret;
}

int main()
{
	long long out, val[] = {
		0xfffffffff0000000,
		0xaaaaaaaaaaaaaaaa,
		0x5555555555555555,
		0x10000000000,
		0x55555,
		0x555,
		0x3,
		0x2,
		0x1,
		0x8000000000000000,
		/* Must terminate with 0 */
		0,
	};


	for (long long *ptr= val; ; ++ptr) {
		printf("0x%016llx -> 0x%x\n", *ptr, __ffsll(*ptr));
		if (!*ptr)
			break;
	}

	return 0;
}
