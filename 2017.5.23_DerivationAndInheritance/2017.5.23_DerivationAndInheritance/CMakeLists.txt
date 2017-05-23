# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (Demo1)
# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
	)
option (USE1 "Use Algorithm1:" ON)
option (USE2 "Use Algorithm2:" OFF)
option (USE3 "Use Algorithm3:" OFF)

#保存该目录下所有文件名
aux_source_directory(. DIR_SRCS)
# 指定生成目标
add_executable(Demo ${DIR_SRCS})
