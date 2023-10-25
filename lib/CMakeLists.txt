add_library(profiler
           Slurm.cpp
           CPU.cpp
#           NVML.cpp
           JSON.cpp
           )


target_include_directories(profiler PRIVATE  ../include)



add_subdirectory(mpi_profiler)


if (CUDAToolkit_FOUND)
endif()
