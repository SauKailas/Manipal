#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<CL/cl.h>

#define MAX_SOURCE_SIZE (0x100000)

int main()
{
	int LIST_SIZE, N;

	printf("Enter the length of the string: ");
	scanf("%d", &LIST_SIZE);

	printf("Enter the value of N: ");
	scanf("%d", &N);

	char *A = (char*)malloc(LIST_SIZE * sizeof(char));
	char *B = (char*)malloc(N * LIST_SIZE * sizeof(char));

	printf("Enter the string: ");
	gets(A);

	FILE *fp;
	char *source_str;
	size_t source_size;

	fp = fopen("q1add.cl", "r");
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

	cl_mem bufA = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE*sizeof(char), NULL, &status);
	cl_mem bufB = clCreateBuffer(context, CL_MEM_WRITE_ONLY, N*LIST_SIZE*sizeof(char), NULL, &status);

	status = clEnqueueWriteBuffer(command_queue, bufA, CL_TRUE, 0, LIST_SIZE*sizeof(char), A, 0, NULL, NULL);

	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &status);
	status = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	cl_kernel kernel = clCreateKernel(program, "copy_string", &status);

	status = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&bufA);
	status = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&bufB);
	status = clSetKernelArg(kernel, 2, sizeof(int), (void*)&LIST_SIZE);

	size_t global_item_size = LIST_SIZE;
	size_t local_item_size = 1;

	status = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
	status = clFinish(command_queue);

	status = clEnqueueReadBuffer(command_queue, bufB, CL_TRUE, 0, LIST_SIZE*sizeof(int), B, 0, NULL, NULL);

	printf("RESULTS:\n");
	printf("Resultant String: ");
	puts(B);

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