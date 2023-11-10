




add_subdirectory(mpi_profiler)


if (CUDAToolkit_FOUND)
add_library(profiler
           Slurm.cpp
           CPU.cpp
           NVML.cpp
           CUPTI.cpp
           JSON.cpp
           Entry.cpp
           )

target_link_libraries(profiler
        PRIVATE
        mpi_profiler
        CUDA::cuda_driver
        CUDA::cupti_static
        CUDA::nvml
        )
else()

add_library(profiler
           Slurm.cpp
           CPU.cpp
           JSON.cpp
           Entry.cpp
           )

target_link_libraries(profiler
        PRIVATE
        mpi_profiler)

endif()


target_include_directories(profiler PRIVATE  ../include)
