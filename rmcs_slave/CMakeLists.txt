# Copyright (c) 2021 HPMicro
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)


# Set target board and toolchain options
set(BOARD "hpm5361_kaiser" CACHE STRING "Target board")
set(RV_ARCH "rv32imafdc" CACHE STRING "RISC-V arch")
set(RV_ABI "ilp32d" CACHE STRING "RISC-V ABI")
set(HPM_BUILD_TYPE "ram_xip" CACHE STRING "HPM build type")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

# Locate HPM SDK
find_package(hpm-sdk REQUIRED HINTS $ENV{HPM_SDK_BASE})

#
project(rmcs_slave)

sdk_app_inc(inc)
sdk_app_src(src/main.c)
