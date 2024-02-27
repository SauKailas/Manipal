__kernel void bin_to_dec(__global int *A, __global int *B)
{
	int tid = get_global_id(0);
	int num = A[tid];
	int dig;
	int dec = 0;
	int pow = 1;

	while(num > 0)
	{
		dig = num % 10;
		num /= 10;
		dec += dig * pow;
		pow *= 2;
	}
	B[tid] = dec;
}