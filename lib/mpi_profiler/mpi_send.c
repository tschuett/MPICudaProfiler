

int MPI_Send(const void* buffer, int count, MPI_Datatype datatype,
             int dest, int tag, MPI_Comm comm)
{
   double tstart = MPI_Wtime();       /* Pass on all arguments */
   int size;
   int result    = PMPI_Send(buffer,count,datatype,dest,tag,comm);
   totalTime  += MPI_Wtime() - tstart;         /* and time          */
   MPI_Type_size(datatype, &size);  /* Compute size */
   totalBytes += count*size;
   return result;
}
