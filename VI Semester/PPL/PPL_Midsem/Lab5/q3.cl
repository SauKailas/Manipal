__kernel void swap_adjacent(__global int *A)
{
	int tid = get_global_id(0);

	if(tid % 2 == 0)
	{
		int temp = A[tid];
		A[tid] = A[tid+1];
		A[tid+1] = temp;
	}
}