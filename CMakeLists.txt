cmake_minimum_required(VERSION 3.5.1)
project(dsa)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

#Bring all the headers into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
set(SOURCES
	src/Vector.cpp
)

# set(UTILS
	
# )
#Generate the SHARED library from the sources
add_library(vector SHARED ${SOURCES})
# add_library(utils SHARED ${UTILS})

# target_link_libraries(vector utils)

add_executable(main src/main_vector.cpp)

target_link_libraries(main vector)
#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS vector DESTINATION /usr/lib)
#install(TARGETS utils DESTINATION /usr/lib)