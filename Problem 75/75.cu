#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cuda_runtime.h>

#define BLOCK_SIZE 512
#define THREAD_SIZE 512 
#define L 150000

#define checkCudaErrors(error) {\
	if (error != cudaSuccess) {\
		printf("CUDA Error - %s:%d: '%s'\n",__FILE__,__LINE__,cudaGetErrorString(error));\
		exit(1);\
		}\
}\

__global__ void singular_integer_triangle(int *array) {
	int p = blockIdx.x * blockDim.x + threadIdx.x;		
	if (p <= L) {
	for (long a=sqrt((float)p); a<p/2; a++) {
		for (long b=a+1; b<p/2; b++) {
			if (a*a + b*b == (p-a-b)*(p-a-b)) {
				array[p]++;
				if (array[p] > 1) return;
			}
		}
	}
	}

}

int main() {
	int *h_array = (int*)calloc(L,sizeof(int));
	if (h_array == NULL) {
		printf("malloc() failed/n");
		exit(1);
	}
	int *d_array;
	checkCudaErrors(cudaMalloc( (void**)&d_array, L*sizeof(int)));
        checkCudaErrors(cudaMemcpy(d_array,h_array,L*sizeof(int),cudaMemcpyHostToDevice));	
	singular_integer_triangle<<<BLOCK_SIZE,THREAD_SIZE>>>(d_array);
	checkCudaErrors(cudaMemcpy(h_array,d_array,L*sizeof(int),cudaMemcpyDeviceToHost));
	checkCudaErrors(cudaFree(d_array));

	int count = 0;
	//   printf("[");
	for (int i=0; i<L; i++) {
		if (h_array[i]==1) count++;
	//	printf("%d,",h_array[i]);
	}
	//printf("%d]\n",h_array[29]);*/
	printf("%d\n",count);

	free(h_array);
	return 0;
}
