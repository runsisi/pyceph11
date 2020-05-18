cmake_minimum_required(VERSION 2.8.12)
project(pyceph11)

add_subdirectory(pybind11)

pybind11_add_module(radosx radosx/radosx.cc)
pybind11_add_module(rbdx rbdx/rbdx.cc)

target_include_directories(rbdx PRIVATE json/single_include)
