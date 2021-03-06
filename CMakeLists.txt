cmake_minimum_required(VERSION 2.8.9)
project(CallCPPFromLib) 

set(CMAKE_CXX_FLAGS " -O3 -Wall -Wextra")

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

#Bring the headers, such as Student.h into the project
include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/QuotientFilter/*.cpp"
        "${PROJECT_SOURCE_DIR}/include/CallFromC/*.cpp"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
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

add_executable(CallFromC "${PROJECT_SOURCE_DIR}/CallFromC.c" ${all_SRCS})

target_link_libraries(CallFromC "${PROJECT_SOURCE_DIR}/libs/libCallFromC.so" m)
#set_target_properties(CallFromC PROPERTIES LINKER_LANGUAGE CXX)