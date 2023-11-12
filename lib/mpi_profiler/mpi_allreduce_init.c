#include <mpi.h>


int MPI_Allreduce_init(const void *sendbuf, void *recvbuf, int count,
             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Info info, MPI_Request *request) {

  int result = PMPI_Allreduce_init(sendbuf, recvbuf, count, datatype, op, comm, info, request);

  return result;
}
