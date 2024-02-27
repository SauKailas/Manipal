__kernel void check_prime(__global int *A, __global int *B)
{
	int tid = get_global_id(0);
	int num = A[tid];
	int flag = 1;

	for(int i=2; i<num; i++)
		if(num % i == 0)
		{
			flag = 0;
			break;
		}

	if(flag == 0)
		B[tid] = num * num;
}