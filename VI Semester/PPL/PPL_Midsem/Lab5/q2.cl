__kernel void ones_complement(__global int *A, __global int *B)
{
	int tid = get_global_id(0);
	int num = A[tid];
	int cnt = 1;
	int res = 0;
	int temp;

	while(num > 0)
	{
		temp = num % 10;
		num /= 10;

		if(temp == 0)
			res = (cnt * 1) + res;
		else
			res = (cnt * 0) + res;
		cnt *= 10;
	}
	B[tid] = res;
}