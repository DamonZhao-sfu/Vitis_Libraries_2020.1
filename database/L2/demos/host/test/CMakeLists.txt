cmake_minimum_required(VERSION 3.16)
project(MyExample)

find_package(Arrow REQUIRED)


add_executable(arrow_conversion arrow_conversion.cpp)

# Specify where to look for header files
target_include_directories(arrow_conversion PRIVATE
    /localhdd/hza215/Vitis_Libraries/database/L2/demos/host
)

target_link_libraries(arrow_conversion PRIVATE Arrow::arrow_shared )

#cmake -S . -B build -DCMAKE_PREFIX_PATH=/localhdd/hza215/bin/lib && cmake --build build
