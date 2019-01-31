cmake_minimum_required (VERSION 2.8) 
project (raspicam_test)
set(raspicam_DIR /usr/local/lib/cmake/)
#find_package(raspicam REQUIRED)
find_library(wiringPi_LIBS wiringPi wiringSerial)
#find_package(Threads REQUIRED)

add_executable (serialTest serialTest.cpp)  
target_link_libraries (serialTest ${wiringPi_LIBS} )

#target_link_libraries (serialTest ${raspicam_LIBS} ${CMAKE_THREAD_LIBS_INIT} )

# add_executable (wiring wiring.cpp) 
# target_link_libraries(wiring ${wiringPi_LIB} ${raspicam_LIBS})





