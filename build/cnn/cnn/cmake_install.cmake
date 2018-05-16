# Install script for directory: /home/ubuntu/Duyen/rnng/cnn/cnn

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cnn" TYPE FILE FILES
    "/home/ubuntu/Duyen/rnng/cnn/cnn/aligned-mem-pool.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/cfsm-builder.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/c2w.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/cnn.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/conv.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/cuda.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/devices.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/dict.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/dim.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/exec.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/expr.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/fast-lstm.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/functors.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/gpu-kernels.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/gpu-ops.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/graph.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/gru.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/hsm-builder.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/init.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/lstm.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/mem.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/model.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/mp.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/nodes.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/param-nodes.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/random.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/rnn-state-machine.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/rnn.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/saxe-init.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/shadow-params.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/simd-functors.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/tensor.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/timing.h"
    "/home/ubuntu/Duyen/rnng/cnn/cnn/training.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ubuntu/Duyen/rnng/build/cnn/cnn/libcnn.a")
endif()

