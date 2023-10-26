#include <mpi.h>

int MPI_Init(int *argc, char ***argv) {
  int result = PMPI_Init(argc, argv);
  return result;
}
