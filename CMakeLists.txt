cmake_minimum_required(VERSION 3.5.1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(WITH_PYTHON2 "build python2 bindings" ON)
if(WITH_PYTHON2)
  find_package(Python2Interp 2 REQUIRED)
  find_package(Python2Libs ${PYTHON2_VERSION_STRING} EXACT REQUIRED)
endif()

option(WITH_PYTHON3 "build python3 bindings" ON)
if(WITH_PYTHON3)
  find_package(Python3Interp 3 REQUIRED)
  find_package(Python3Libs ${PYTHON3_VERSION_STRING} EXACT REQUIRED)
endif()

include(Distutils)

set(CYTHON_MODULE_DIR ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/cython_modules)

# Keep the default version last
if(WITH_PYTHON3)
  list(APPEND py_vers 3)
endif()
if(WITH_PYTHON2)
  list(APPEND py_vers 2)
endif()
if(NOT py_vers)
  message(FATAL_ERROR "No Python binding enabled. Please enable WITH_PYTHON2 and/or WITH_PYTHON3.")
endif()

foreach(python_version ${py_vers})
  if(${python_version} EQUAL 2)
    set(PYTHON_VERSION ${python_version})
  else(${python_version} EQUAL 2)
    set(PYTHON_VERSION ${python_version})
  endif(${python_version} EQUAL 2)

  find_package(Cython REQUIRED)

  add_subdirectory(src/radosx radosx${PYTHON_VERSION})
  add_subdirectory(src/rbdx rbdx${PYTHON_VERSION})
endforeach()
