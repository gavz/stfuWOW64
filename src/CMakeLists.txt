cmake_minimum_required(VERSION 3.14)
project(stfuwow64 C)

set(CMAKE_C_STANDARD 99)

add_library(stfuwow64 SHARED stfuwow64.c)



target_link_libraries(stfuwow64 -fno-stack-check -fno-stack-protector -mno-stack-arg-probe -s -Wl,-static)
set_target_properties(stfuwow64 PROPERTIES PREFIX "")
set_target_properties(stfuwow64 PROPERTIES OUTPUT_NAME "wow64log")
