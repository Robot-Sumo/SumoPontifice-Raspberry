cmake_minimum_required (VERSION 2.8) 
project (thread)
#set(raspicam_DIR /usr/local/lib/cmake/)
find_package(Threads REQUIRED)
add_executable (main main.cpp)  
target_link_libraries (main ${CMAKE_THREAD_LIBS_INIT})


