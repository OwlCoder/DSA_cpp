cmake_minimum_required(VERSION 3.5.1)
project(dsa)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

#Bring all the headers into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
set(SOURCES
	src/Vector.cpp
	src/Graph.cpp
)

#Generate the SHARED library from the sources
add_library(dsa SHARED ${SOURCES})

add_executable(main_vector src/main_vector.cpp)
add_executable(main_graph src/main_graph.cpp)

target_link_libraries(main_vector dsa)
target_link_libraries(main_graph dsa)

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS dsa DESTINATION /usr/lib)