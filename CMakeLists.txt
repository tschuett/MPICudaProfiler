cmake_minimum_required(VERSION 3.27.0)

project(mpi_cuda_profiler)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_COMPILE_WARNING_AS_ERROR True)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_language(C CXX)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-fproc-stat-report" COMPILER_SUPPORTS_PROC_STAT_REPORT)
if(COMPILER_SUPPORTS_PROC_STAT_REPORT)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fproc-stat-report=abc")
endif()

# for cuPTI
#find_package(CUDA required)

# for mpi
#find_package(MPI required)



add_subdirectory(lib)
add_subdirectory(include)
#add_subdirectory(tools)
