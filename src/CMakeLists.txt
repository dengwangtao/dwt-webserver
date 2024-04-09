
include_directories(./include)

include_directories(./thirdparty)

aux_source_directory(./webserver SRC_LIST)

add_executable(server main.cpp ${SRC_LIST})

target_link_libraries(server pthread mysqlclient)
