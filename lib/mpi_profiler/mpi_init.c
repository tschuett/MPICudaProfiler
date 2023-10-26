#include "Entry.h"
#include <mpi.h>

int MPI_Init(int *argc, char ***argv) {

  startProfiler();

  int result = PMPI_Init(argc, argv);
  return result;
}
