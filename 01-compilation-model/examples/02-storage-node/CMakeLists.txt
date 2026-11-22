cmake_minimum_required(VERSION 3.20)

project(StorageServer CXX)

add_library(storage-core
    src/StorageNode.cpp
    src/MetadataManager.cpp
)
target_include_directories(storage-core PUBLIC include)
target_compile_features(storage-core PUBLIC cxx_std_20)

add_executable(storage-server src/main.cpp)
target_link_libraries(storage-server PRIVATE storage-core)
