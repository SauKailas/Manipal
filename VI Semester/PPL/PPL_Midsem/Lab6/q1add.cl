__kernel void copy_string(__global char *A, __global char *B, int N)
{
	int tid = get_global_id(0);
	int len = get_global_size(0);
	int pos = tid;

	for(int i=0; i<N; i++)
	{
		B[pos] = A[tid];
		pos += len;
	}
}