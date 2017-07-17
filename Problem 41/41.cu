#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cuda_runtime.h>

extern "C" {
	#include "euler.h"
}

#define BLOCK_SIZE 1024
#define GRID_SIZE 1024
#define N 1000000000//(GRID_SIZE*GRID_SIZE*BLOCK_SIZE)

#define checkCudaErrors(error) {\
	if (error != cudaSuccess) {\
		printf("CUDA Error - %s:%d: '%s'\n",__FILE__,__LINE__,cudaGetErrorString(error));\
		exit(1);\
		}\
}\

__global__ void init_sieve(int *primes) {
	int i = (blockIdx.y * gridDim.x + blockIdx.x) * blockDim.x + threadIdx.x; 
	if (i<N) {
		primes[i] = i;
	}
}

__global__ void prime_sieve(int *primes) {
   	int i = ((blockIdx.y * gridDim.x + blockIdx.x) * blockDim.x + threadIdx.x); 
	if (i > 1 && i<N/2) {	
		for (int j=2*i; j<N; j+=i) {
			primes[j]=0;
		}

	}
}

int main() {
	int *h_primes=(int*)malloc(N * sizeof(int));
	if (h_primes == NULL) {
		printf("malloc failed\n");
		exit(1);
	}
	int *d_primes;
	dim3 dimBlock(BLOCK_SIZE);
	dim3 dimGrid(GRID_SIZE,GRID_SIZE);

	checkCudaErrors(cudaMalloc( (void**)&d_primes, N*sizeof(int)));
        checkCudaErrors(cudaMemcpy(d_primes,h_primes,N*sizeof(int),cudaMemcpyHostToDevice));	
	init_sieve<<<dimGrid,dimBlock>>>(d_primes);
	prime_sieve<<<dimGrid,dimBlock>>>(d_primes);
	checkCudaErrors(cudaMemcpy(h_primes,d_primes,N*sizeof(int),cudaMemcpyDeviceToHost));
	checkCudaErrors(cudaFree(d_primes));
	
	int index=N-1;
	while (index) {
		if (h_primes[index]) {
			if (is_pandigital(h_primes[index])) {
				printf("%d\n",h_primes[index]);
				break;
			}
		}
		index--;
	}
	
	free(h_primes);
	return 0;

}
