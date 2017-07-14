#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cuda_runtime.h>

#define BLOCK_SIZE 512
#define GRID_SIZE 1024
#define N 500000000//(GRID_SIZE*GRID_SIZE*BLOCK_SIZE)

#define checkCudaErrors(error) {\
	if (error != cudaSuccess) {\
		printf("CUDA Error - %s:%d: '%s'\n",__FILE__,__LINE__,cudaGetErrorString(error));\
		exit(1);\
		}\
}\

__global__ void init_sieve(int *primes) {
	int i = (blockIdx.y * gridDim.x + blockIdx.x) * blockDim.x + threadIdx.x; //(blockDim.x * blockDim.y * blockIdx.x) + (blockDim.x * threadIdx.y) + threadIdx.x;
	if (i<N) {
		primes[i] = i;
	}
}

__global__ void prime_sieve(int *primes) {
	
	//unsigned long long i = threadIdx.x + blockIdx.x * blockDim.x;
   	int i = (blockIdx.y * gridDim.x + blockIdx.x) * blockDim.x + threadIdx.x; //(blockDim.x * blockDim.y * blockIdx.x) + (blockDim.x * threadIdx.y) + threadIdx.x;
	if (i > 1 && i<N/2) {	
		for (int j=2*i; j<N; j+=i) {
			primes[j]=0;
		}

	}
}
__global__ void prime_count(int *primes) {
	int i = (blockIdx.y * gridDim.x + blockIdx.x) * blockDim.x + threadIdx.x;
	if (i > 1 && i<N) {
		if (primes[i]) {
			atomicAdd(&primes[0],1);
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
	prime_count<<<dimGrid,dimBlock>>>(d_primes);
	checkCudaErrors(cudaMemcpy(h_primes,d_primes,N*sizeof(int),cudaMemcpyDeviceToHost));
	checkCudaErrors(cudaFree(d_primes));
	
	int size = 0;
	int total = N;
	size = h_primes[0];

	printf("Length = %d\tPrimes = %d\n",total,size);

	free(h_primes);
	return 0;

	// GTX 780 Ti ~3GB 
	// nvcc 41.cu -o 41.o -arch=sm_30 -Xcompiler -Ofast
}

/*
	100m 0m15.093s
	299m 0m59.660s
	399m 1m27.943s
	499m 1m57.786s
	599m 2m35.930s
	699m 3m23.022s
	799m 4m14.884s
	899m 5m20.725s

4	999m 6m26.204s
12	999m 1m47.437s

*/
