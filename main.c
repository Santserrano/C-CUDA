#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "book.h"

// 3.2.2 A KERNEL CALL

/*
Ref: CPU as the host - GPU as the device
CUDA C adds the __global__ qualifier to standard C.
This mechanism alerts the compiler that a function should be
compiled to run on a device instead of the host.
*/

__global__ void kernel( void ) { // compiled to run on GPU
}

__global__ void add( int a, int b, int *c ) {
 *c = a + b;
}

int main( void ) {
	
 int c;
 int *dev_c;
 
 HANDLE_ERROR( cudaMalloc( (void**)&dev_c, sizeof(int) ) );
 
 add<<<1,1>>>( 2, 7, dev_c );
 
 HANDLE_ERROR( cudaMemcpy( &c, dev_c, sizeof(int),
 cudaMemcpyDeviceToHost ) );
 
 printf( "2 + 7 = %d\n", c );
 cudaFree( dev_c );
 return 0;
}