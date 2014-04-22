add_definitions(-DUNICODE -D_UNICODE)

add_executable(desktop desktop.cpp)
target_link_libraries(desktop shlwapi)
