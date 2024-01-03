cmake_minimum_required(VERSION 3.15)
project(PA04_amazing)
set(CMAKE_CXX_STANDARD 14)
set(EXE_NAME PA04_amazing)


##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....
# if you need more, add them here and in the foreach stmt below.
set (input01 "testMaze.txt")
set (input02 "")
set (input03 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03)
    configure_file(${file} ${file} COPYONLY)
endforeach()

Include(FetchContent)           #added for test script
#https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#top
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)


# Create the executable for sorting
add_executable(${EXE_NAME} main.cpp DSList.h DSVector.h DSStack.h AdjList.cpp AdjList.h test.cpp test.cpp Room.cpp Room.h MazeRunner.h MazeRunner.cpp testMaze.txt ListRoom.h ListRoom.cpp)
target_link_libraries(${EXE_NAME} PRIVATE Catch2::Catch2)








