project(dct)
cmake_minimum_required(VERSION 3.10)

file(GLOB PROJECT_SOURCES
	*.h
	*.cpp
	)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDART 17)
set(THREADS_PREFER_PTHREAD_FLAGG OFF)

include_directories(SYSTEM /usr/inclue/c++/7)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} Threads::Threads)
