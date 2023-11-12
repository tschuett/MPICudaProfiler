#include <mpi.h>

double totalTime = 0;
double totalBytes = 0;

int MPI_Recv(void *buffer, int count, MPI_Datatype datatype, int source, int tag,
             MPI_Comm comm, MPI_Status *status) {
  double tstart = MPI_Wtime(); /* Pass on all arguments */
  int size;
  int result = PMPI_Recv(buffer, count, datatype, source, tag, comm, status);
  totalTime += MPI_Wtime() - tstart; /* end time          */
  MPI_Type_size(datatype, &size);    /* Compute size */
  totalBytes += count * size;
  return result;
}

/*
  struct cudaPointerAttributes attributes;

  cudaError_t error = cudaPointerGetAttributes(&attributes, ptr);
 */
