__kernel void octal_transform(__global int *A, __global int *B)
{
	int tid = get_global_id(0);
	int num = A[tid];
	int octal_digits[100];
	int idx = 0;
	int octal_number = 0;

	while(num > 0)
	{
		octal_digits[idx++] = num % 8;
		num = num / 8;
	}

	for(int i=idx-1; i>=0; i--)
		octal_number = octal_number * 10 + octal_digits[i];
	B[tid] = octal_number;
}