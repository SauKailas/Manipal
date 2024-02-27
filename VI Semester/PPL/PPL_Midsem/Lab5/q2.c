#include<stdio.h>
#include<stdlib.h>
#include<CL/cl.h>

#define MAX_SOURCE_SIZE (0x100000)

int main()
{
	int LIST_SIZE;

	printf("Enter the number of elements: ");
	scanf("%d", &LIST_SIZE);

	int *A = (int*)malloc(LIST_SIZE * sizeof(int));
	int *B = (int*)malloc(LIST_SIZE * sizeof(int));

	printf("Enter the elements: ");
	for(int i=0; i<LIST_SIZE; i++)
		scanf("%d", &A[i]);

	FILE *fp;
	char *source_str;
	size_t source_size;

	fp = fopen("q2.cl", "r");
	if(!fp)
	{
		printf("Cannot open kernel file!\n");
		exit(1);
	}

	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);

	cl_int status;
	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices, ret_num_platforms;

	status = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);

	status = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &status);

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &status);

	cl_mem bufA = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE*sizeof(int), NULL, &status);
	cl_mem bufB = clCreateBuffer(context, CL_MEM_WRITE_ONLY, LIST_SIZE*sizeof(int), NULL, &status);

	status = clEnqueueWriteBuffer(command_queue, bufA, CL_TRUE, 0, LIST_SIZE*sizeof(int), A, 0, NULL, NULL);

	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &status);
	status = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	cl_kernel kernel = clCreateKernel(program, "ones_complement", &status);

	status = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&bufA);
	status = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&bufB);

	size_t global_item_size = LIST_SIZE;
	size_t local_item_size = 1;

	status = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
	status = clFinish(command_queue);

	status = clEnqueueReadBuffer(command_queue, bufB, CL_TRUE, 0, LIST_SIZE*sizeof(int), B, 0, NULL, NULL);

	printf("RESULTS:\n");
	for(int i=0; i<LIST_SIZE; i++)
		printf("Ones Complement of %d is %d\n", A[i], B[i]);

	status = clFlush(command_queue);
	status = clReleaseKernel(kernel);
	status = clReleaseProgram(program);
	status = clReleaseMemObject(bufA);
	status = clReleaseMemObject(bufB);
	status = clReleaseCommandQueue(command_queue);
	status = clReleaseContext(context);

	free(A);
	free(B);

	return 0;
}