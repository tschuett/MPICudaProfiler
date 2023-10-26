#include <mpi.h>

int MPI_Finalize( void ) {
  int result = PMPI_Finalize();
  return result;
}
