cmake_minimum_required(VERSION 3.27.0)

project(mpi_cuda_profiler)

set (CMAKE_CXX_STANDARD 26)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_COMPILE_WARNING_AS_ERROR True)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_language(C CXX)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-fproc-stat-report" COMPILER_SUPPORTS_PROC_STAT_REPORT)
if(COMPILER_SUPPORTS_PROC_STAT_REPORT)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fproc-stat-report=abc")
endif()

# for cuPTI # REQUIRED
find_package(CUDAToolkit)

if(CUDAToolkit_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHAVE_CUDA")
endif()

# for mpi
find_package(MPI REQUIRED)


add_subdirectory(lib)
add_subdirectory(include)
#add_subdirectory(tools)
