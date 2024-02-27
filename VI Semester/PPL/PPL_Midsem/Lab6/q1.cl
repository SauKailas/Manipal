__kernel void copy_string(__global char *A, __global char *B, int len)
{
	int tid = get_global_id(0);

	for(int i=0; i<len; i++)
		B[tid * len + i] = A[tid];
}