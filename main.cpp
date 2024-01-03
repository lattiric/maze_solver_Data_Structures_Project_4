#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "catch2/catch.hpp"
#include "MazeRunner.h"

int main(int argc, char** argv) {
    int result = 0;
    if(argc > 1){                    //run program
        MazeRunner maze;
        maze.fillMaze(argv[1]);
        maze.fillAllRooms();
        maze.addPortals();
        maze.addEnds();
        maze.runBacktracking();
        //maze.testITR();
        maze.findMaxMinPaths();
    }
    else{                             //run test
        result = Catch::Session().run(argc, argv);
    }
    return result;
}
