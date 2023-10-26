

#static int totalBytes = 0;
#static double totalTime = 0.0;
#
#int MPI_Send(const void* buffer, int count, MPI_Datatype datatype,
#             int dest, int tag, MPI_Comm comm)
#{
#   double tstart = MPI_Wtime();       /* Pass on all arguments */
#   int size;
#   int result    = PMPI_Send(buffer,count,datatype,dest,tag,comm);
#   totalTime  += MPI_Wtime() - tstart;         /* and time          */
#   MPI_Type_size(datatype, &size);  /* Compute size */
#   totalBytes += count*size;
#   return result;
#}

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${MPI_C_HEADER_DIR}")

add_library(mpi_profiler
           mpi_init.c
           mpi_finalize.c
           mpi_send.c
           )


target_include_directories(mpi_profiler PRIVATE  ../../include)
