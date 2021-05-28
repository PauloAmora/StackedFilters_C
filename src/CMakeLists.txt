cmake_minimum_required(VERSION 2.8.9)
project(StackedAlternatingAMQs) 

set(CMAKE_CXX_FLAGS " -O3 -Wall -Wextra")

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

#Bring the headers, such as Student.h into the project
include_directories(
        ${PROJECT_SOURCE_DIR}/include/StackedFilter
        ${PROJECT_SOURCE_DIR}/include/QuotientFilter
        ${PROJECT_SOURCE_DIR}/include/CuckooFilter
        ${PROJECT_SOURCE_DIR}/include/BloomFilter
        ${PROJECT_SOURCE_DIR}/include/Optimization
        ${PROJECT_SOURCE_DIR}/include/CallFromC
)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/QuotientFilter/*.cpp"
       "${PROJECT_SOURCE_DIR}/include/CallFromC/*.cpp"
       "${PROJECT_SOURCE_DIR}/include/CallFromC/*.hpp"
        )

#add_executable(ZipfGraphsDataGenerator "${PROJECT_SOURCE_DIR}/Main/ZipfGraphsDataGenerator.cpp" ${all_SRCS})
#add_executable(ZipfGraphsDataGeneratorDiskVersion "${PROJECT_SOURCE_DIR}/Main/ZipfGraphsDataGeneratorDiskVersion.cpp" ${all_SRCS})
#add_executable(FirehoseDataGenerator "${PROJECT_SOURCE_DIR}/Main/FirehoseDataGeneratorDiskVersion.cpp" ${all_SRCS})
#add_executable(FirehoseDataGeneratorDiskVersion "${PROJECT_SOURCE_DIR}/Main/FirehoseDataGenerator.cpp" ${all_SRCS})
#add_executable(URLBlacklistingDiskVersion "${PROJECT_SOURCE_DIR}/Main/URULBlacklistingDiskVersion.cpp" ${all_SRCS})
#add_executable(ZipfDiskVersionAdaptive "${PROJECT_SOURCE_DIR}/Main/ZipfDiskVersionAdaptive.cpp" ${all_SRCS})
#add_executable(ZipfDiskVersionAdaptiveStages "${PROJECT_SOURCE_DIR}/Main/ZipfDiskVersionAdaptiveStages.cpp" ${all_SRCS})
#add_executable(CQFDataGenerator "${PROJECT_SOURCE_DIR}/Main/CQFDataGenerator.cpp" ${all_SRCS})
#add_executable(CuckooDataGenerator "${PROJECT_SOURCE_DIR}/Main/CuckooDataGenerator.cpp" ${all_SRCS})
#add_executable(InsertsDataGenerator "${PROJECT_SOURCE_DIR}/Main/InsertsDataGenerator.cpp" ${all_SRCS})
#add_executable(InsertsDataGenerator2 "${PROJECT_SOURCE_DIR}/Main/OneBitAdjustmentDataGenerator.cpp" ${all_SRCS}) 
#add_executable(URLBlacklisting "${PROJECT_SOURCE_DIR}/Main/URLBlacklisting.cpp" ${all_SRCS})
#add_executable(UniformDataGenerator "${PROJECT_SOURCE_DIR}/Main/UniformDataGenerator.cpp" ${all_SRCS})
#add_executable(Example "${PROJECT_SOURCE_DIR}/Main/Example.cpp" ${all_SRCS})
#add_executable(CallFromC "${PROJECT_SOURCE_DIR}/Main/CallFromC.c" ${all_SRCS})


#add_library(CallFromC ${all_SRCS})
add_executable(CallFromC "${PROJECT_SOURCE_DIR}/Main/CallFromC.c" "${PROJECT_SOURCE_DIR}/include/CallFromC/codecpp.cpp" "${PROJECT_SOURCE_DIR}/include/CallFromC/codecpp.hpp" ${all_SRCS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")