add_library(profiler
           Slurm.c
           CPU.cpp
           )


target_include_directories(profiler PRIVATE  ../include)



add_subdirectory(mpi_profiler)

