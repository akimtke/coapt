cmake_minimum_required (VERSION 3.1)
project (Part2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(main src/main.c src/QuickSort.c src/AlphaLib.c src/CSVReader.c src/CSVWriter.c)
set_property(TARGET main PROPERTY C_STANDARD 99)
