cmake_minimum_required(VERSION 3.10)

set(INTERFACE_VERSION "1.0")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/soa)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/soa/dynamic)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/soa/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/soa/include/changan)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/soa/gen/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/soa/gen/include/changan)


file(GLOB_RECURSE ca_gen_cpp      ${CMAKE_CURRENT_SOURCE_DIR}/soa/gen/*.cpp)
file(GLOB_RECURSE ca_gen_cc       ${CMAKE_CURRENT_SOURCE_DIR}/soa/gen/*.cc)
file(GLOB_RECURSE ca_gen_c        ${CMAKE_CURRENT_SOURCE_DIR}/soa/gen/*.c)
file(GLOB_RECURSE ca_gen_srcs_cpp ${CMAKE_CURRENT_SOURCE_DIR}/soa/gen/src/*.cpp)
file(GLOB_RECURSE ca_gen_srcs_c   ${CMAKE_CURRENT_SOURCE_DIR}/soa/gen/src/*.c)
file(GLOB_RECURSE usr_srcs_cpp    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE dynamic_cpp     ${CMAKE_CURRENT_SOURCE_DIR}/soa/dynamic/*.cpp)
file(GLOB_RECURSE dds_srcs_cpp     ${CMAKE_CURRENT_SOURCE_DIR}/soa/src/*.cpp)
set(ALL_COMPILE_SRC
    ${ca_gen_cc}
    ${ca_gen_cpp}
    ${ca_gen_c}
    ${ca_gen_srcs_cpp}
    ${ca_gen_srcs_c}
    ${usr_srcs_cpp}
    ${dynamic_cpp}
    ${dds_srcs_cpp}
)

file(GLOB_RECURSE all_so ${CMAKE_CURRENT_SOURCE_DIR}/soa/lib/j3/*)
file(GLOB_RECURSE all_json ${CMAKE_CURRENT_SOURCE_DIR}/soa/json/*)

set(PJ_LIBS ${all_so})
set(PJ_JSON ${all_json})
add_definitions(-DIN_ZADAS)
add_definitions(-DIN_ZROS)


link_directories(${CMAKE_CURRENT_SOURCE_DIR}/soa/lib/j3)

add_executable(edc_agent ${ALL_COMPILE_SRC} )
find_package(Threads)
target_link_libraries(edc_agent PRIVATE base.zros core.zros live_msg_transport.zros nif_msgs.zros nif_live_msg.zros node_if.zros)

target_link_libraries(edc_agent PRIVATE protobuf  pthread json-c )

target_link_libraries(edc_agent PRIVATE ddsc iceoryx_hoofs iceoryx_posh_config iceoryx_posh iceoryx_posh_gateway iceoryx_platform iceoryx_binding_c iceoryx_posh_roudi)

# add_custom_command(TARGET edc_agent POST_BUILD
#                    COMMAND ${CMAKE_STRIP} "$<TARGET_FILE:${PROJECT_NAME}>"
#                    COMMENT "Strip debug symbols done on final binary.")

install(TARGETS edc_agent RUNTIME DESTINATION bin)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/soa/client.xml DESTINATION bin)
install(FILES ${PJ_JSON} DESTINATION bin)
install(FILES ${PJ_LIBS} DESTINATION lib)