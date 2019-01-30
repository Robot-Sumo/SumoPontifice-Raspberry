cmake_minimum_required (VERSION 2.8) 
project (raspicam_test)
set(raspicam_DIR /usr/local/lib/cmake/)
find_package(raspicam REQUIRED)
find_library(wiringPi_LIB wiringPi)
find_package(Threads REQUIRED)
add_executable (simpletest_raspicam simpletest_raspicam.cpp)  
target_link_libraries (simpletest_raspicam ${raspicam_LIBS} ${CMAKE_THREAD_LIBS_INIT} )

add_executable (wiring wiring.cpp) 
target_link_libraries(wiring ${wiringPi_LIB} ${raspicam_LIBS})

add_executable (button button.cpp) 
target_link_libraries(button ${wiringPi_LIB})


add_executable (interruptTest interruptTest.cpp) 
target_link_libraries(interruptTest ${wiringPi_LIB} ${raspicam_LIBS})


