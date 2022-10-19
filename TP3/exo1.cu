#include <stdio.h>

__global__ void add(int *a, int *b, int *c)
{
    int index = blockDim.x * blockIdx.x + threadIdx.x;
    c[index] = a[index] + b[index];
}

int main(void)
{
    int numberOfBlock = 32;
    int threadsPerBlock = 8;
    int vectorSize = numberOfBlock * threadsPerBlock;
    int size = vectorSize * sizeof(int);

    int *a = (int *)malloc(size);
    int *b = (int *)malloc(size);
    int *c = (int *)malloc(size);

    for (int i = 0; i < vectorSize; ++i)
    {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    int *da, *db, *dc;

    cudaMallocManaged(&da, size);
    cudaMallocManaged(&db, size);
    cudaMallocManaged(&dc, size);

    cudaMemcpy(da, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(db, b, size, cudaMemcpyHostToDevice);
    cudaMemcpy(dc, c, size, cudaMemcpyHostToDevice);

    add<<<numberOfBlock, threadsPerBlock>>>(da, db, dc);

    cudaMemcpy(c, dc, size, cudaMemcpyDeviceToHost);

    for (int i = 0; i < vectorSize; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}