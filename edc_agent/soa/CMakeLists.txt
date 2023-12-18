# CMakeList.txt: Demo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("Demo")
set(CMAKE_C_FLAGS "$ENV{CFLAGS} -O0 -Wall -pthread -g")
set(CMAKE_CXX_FLAGS "$ENV{CFLAGS} -O0 -Wall -pthread -std=c++11 -g")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(GEN_DEST ${CMAKE_CURRENT_SOURCE_DIR}/gen/)
set(DDS_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/)
option(ONLINE_COMPILE "need online compile？" OFF)

file(GLOB_RECURSE ca_gen_cpp ${GEN_DEST}/*.cpp)
file(GLOB_RECURSE ca_gen_c ${GEN_DEST}/*.c)
file(GLOB_RECURSE ca_gen_srcs_cpp ${GEN_DEST}/src/*.cpp)
file(GLOB_RECURSE ca_gen_srcs_c ${GEN_DEST}/src/*.c)
file(GLOB_RECURSE ca_gen_cc ${GEN_DEST}/*.cc)

file(GLOB_RECURSE usr_srcs_cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE dynamic_cpp ${CMAKE_CURRENT_SOURCE_DIR}/dynamic/*.cpp)

#new
include_directories(${GEN_DEST}/)

include_directories(${GEN_DEST}/include)
include_directories(${GEN_DEST}/include/changan)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/changan)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dynamic)
set(ALL_COMPILE_SRC
    ${ca_gen_cc}
    ${ca_gen_cpp}
    ${ca_gen_c}
    ${ca_gen_srcs_cpp}
    ${ca_gen_srcs_c}
    ${usr_srcs_cpp}
)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

file(GLOB_RECURSE all_so ${CMAKE_CURRENT_SOURCE_DIR}/lib/*)
set(PJ_LIBS ${all_so})

# set(PJ_LIBS
#	${CMAKE_CURRENT_SOURCE_DIR}/lib/libddsc.so
#	${CMAKE_CURRENT_SOURCE_DIR}/lib/libiceoryx_binding_c.so
#	${CMAKE_CURRENT_SOURCE_DIR}/lib/libiceoryx_hoofs.so
#	${CMAKE_CURRENT_SOURCE_DIR}/lib/libiceoryx_platform.so
#	${CMAKE_CURRENT_SOURCE_DIR}/lib/libiceoryx_posh.so
#	${CMAKE_CURRENT_SOURCE_DIR}/lib/libiceoryx_posh_config.so
#	${CMAKE_CURRENT_SOURCE_DIR}/lib/libiceoryx_posh_gateway.so
#	${CMAKE_CURRENT_SOURCE_DIR}/lib/libiceoryx_posh_roudi.so
#	)
# 将源代码添加到此项目的可执行文件。
add_executable (client "client.cpp"  ${ALL_COMPILE_SRC} ${dynamic_cpp})

add_executable (server "server.cpp" ${ALL_COMPILE_SRC} ${dynamic_cpp})
# 在线编译docker容器中需指定高版本libstdc++路径
if (ONLINE_COMPILE)
target_link_libraries(client  -lpthread ${PJ_LIBS} /usr/lib64/libstdc++.so.6)
else()
target_link_libraries(client  -lpthread -lprotobuf ${PJ_LIBS})
endif()
target_link_libraries(server  -lpthread  -lprotobuf ${PJ_LIBS})
# TODO: 如有需要，请添加测试并安装目标。
