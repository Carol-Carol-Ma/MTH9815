cmake_minimum_required(VERSION 3.20)
project(9815hw2)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT "/usr/local/include/boost")
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(9815hw2 products.hpp soa.hpp productservice.hpp main.cpp)
