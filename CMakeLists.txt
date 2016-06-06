cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pcd_write)
find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Executables - - - - - - - - - - - - - - - - 

add_executable (save  src/save.cpp)
target_link_libraries (save ${PCL_LIBRARIES})

add_executable (read src/read.cpp)
target_link_libraries (read ${PCL_LIBRARIES})

add_executable (view src/view.cpp)
target_link_libraries (view ${PCL_LIBRARIES})

add_executable (transform src/transform.cpp)
target_link_libraries (transform ${PCL_LIBRARIES})