#include <stdio.h>

__global__ void multiply(int *a, int *b, int *c, int vectorSize, int nbRow)
{

    int index = blockDim.x * blockIdx.x + threadIdx.x;
    int row = index / nbRow;
    int col = index % nbRow;

    int rslt = 0;
    for (int i = 0; i < nbRow; i++)
    {
        rslt += a[row * nbRow + i] * b[i * nbRow + col];
    }

    c[index] = rslt;
}

int main(void)
{
    int numberOfBlock = 32;
    int threadsPerBlock = 8;
    int rsltVectorSize = numberOfBlock * threadsPerBlock;
    int vectorSize = sqrt(rsltVectorSize) * 8;
    int nbRow = sqrt(rsltVectorSize);
    int size = vectorSize * sizeof(int);
    int rslSize = rsltVectorSize * sizeof(int);

    int *a = (int *)malloc(size);
    int *b = (int *)malloc(size);
    int *c = (int *)malloc(rslSize);

    for (int i = 0; i < nbRow * 8; ++i)
    {
        a[i] = i;
        b[i] = i;
    }

    for (int i = 0; i < rsltVectorSize; ++i)
    {
        c[i] = 0;
    }

    int *da, *db, *dc;

    cudaMallocManaged(&da, size);
    cudaMallocManaged(&db, size);
    cudaMallocManaged(&dc, rslSize);

    cudaMemcpy(da, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(db, b, size, cudaMemcpyHostToDevice);
    cudaMemcpy(dc, c, rslSize, cudaMemcpyHostToDevice);

    multiply<<<numberOfBlock, threadsPerBlock>>>(da, db, dc, vectorSize, nbRow); // 128 = vectorSize / 2

    cudaMemcpy(c, dc, rslSize, cudaMemcpyDeviceToHost);

    for (int i = 0; i < rsltVectorSize; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}