cmake_minimum_required(VERSION 3.0.0)
project(shared_in VERSION 2.0.0 LANGUAGES C CXX)
project(shared_out VERSION 2.0.0 LANGUAGES C CXX)
project(shared_destroy VERSION 2.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS_ON)


add_executable(shared_in shared.c writemem.c )
add_executable(shared_out shared.c readmem.c )
add_executable(shared_destroy shared.c destroyblock.c )