# Copyright (c) 2021 HPMicro
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)


# Set target board and toolchain options
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()
set(BOARD "hpm5361_kaiser" CACHE STRING "Target board")
set(HPM_BUILD_TYPE "ram_xip" CACHE STRING "HPM build type")
# Set RISC-V toolchain options
set(RV_ARCH "rv32imafdc" CACHE STRING "RISC-V arch")
set(RV_ABI "ilp32d" CACHE STRING "RISC-V ABI")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Locate HPM SDK
find_package(hpm-sdk REQUIRED HINTS $ENV{HPM_SDK_BASE})

# Normalize paths so the prefix mapping works regardless of slashes used.
if(NOT SOURCE_PREFIX_MAP_PATH STREQUAL "")
    file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}" _src_prefix_map_from)
    file(TO_CMAKE_PATH "${SOURCE_PREFIX_MAP_PATH}" _src_prefix_map_to)

    sdk_compile_options(
        "-fdebug-prefix-map=${_src_prefix_map_from}=${_src_prefix_map_to}"
        "-ffile-prefix-map=${_src_prefix_map_from}=${_src_prefix_map_to}"
    )
endif()

#路径映射：让 Windows 侧可见
# SDK 路径映射
file(TO_CMAKE_PATH "$ENV{HPM_SDK_BASE}" _sdk_prefix_map_from)
set(_sdk_prefix_map_to "\\\\wsl.localhost\\archlinux\\home\\kaiser\\Codes\\HPM_Develop\\hpm_sdk")
sdk_compile_options(
    "-fdebug-prefix-map=${_sdk_prefix_map_from}=${_sdk_prefix_map_to}"
    "-ffile-prefix-map=${_sdk_prefix_map_from}=${_sdk_prefix_map_to}"
)
#板级目录路径映射
file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}/../hpm5361_kaiser" _board_prefix_map_from)
set(_board_prefix_map_to "\\\\wsl.localhost\\archlinux\\home\\kaiser\\Codes\\HPM_Develop\\HPM5361_CtrlBoard\\hpm5361_kaiser")
sdk_compile_options(
    "-fdebug-prefix-map=${_board_prefix_map_from}=${_board_prefix_map_to}"
    "-ffile-prefix-map=${_board_prefix_map_from}=${_board_prefix_map_to}"
)
# 链接路径映射：hpm_sdk/boards/hpm5361_kaiser 符号链接指向的真实目录
file(TO_CMAKE_PATH "$ENV{HPM_SDK_BASE}/boards/hpm5361_kaiser" _board_link_prefix_map_from)
set(_board_link_prefix_map_to "\\\\wsl.localhost\\archlinux\\home\\kaiser\\Codes\\HPM_Develop\\HPM5361_CtrlBoard\\hpm5361_kaiser")
sdk_compile_options(
    "-fdebug-prefix-map=${_board_link_prefix_map_from}=${_board_link_prefix_map_to}"
    "-ffile-prefix-map=${_board_link_prefix_map_from}=${_board_link_prefix_map_to}"
)

#
if(${CMAKE_BUILD_TYPE} STREQUAL "debug")
    sdk_compile_options(-Og)
endif()

#
project(rmcs_slave)

sdk_app_inc(inc)
sdk_app_src(src/main.c)
