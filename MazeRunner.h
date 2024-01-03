//
// Created by Rick Lattin on 4/1/21.
//

#ifndef PA04_AMAZING_MAZERUNNER_H
#define PA04_AMAZING_MAZERUNNER_H

#include "DSVector.h"
#include "DSStack.h"
#include "AdjList.h"
#include "Room.h"
#include "ListRoom.h"
#include <utility>

class MazeRunner{
    private:
        DSVector<DSVector<int>> maze;
        DSVector<DSVector<Room>> paths;
        DSStack<Room> backIt;
        AdjList adjRooms;

        DSVector<Room> portalRooms;
        DSVector<Room> portalDestinations;

        int numRows;
        int numCols;

        int numPortals;
        std::pair<int, int> startCords;
//        int startRow;
//        int startCol;
        std::pair<int, int> endCords;
        int endRow;
        int endCol;



        int tempCounter = 0;
    public:
        MazeRunner();
        MazeRunner(DSVector<DSVector<int>>, AdjList);           //constructors
        void fillMaze(char*);               //took in all info from text file
        void fillAllRooms();                //used info from text file to creat the adjacency list
        void addPortals();                  //added the portals to adj list from text file info
        void addEnds();                     //added dummy room to each connect as way of terminating iterator
        void runBacktracking();             //preforms iterative backtracking to find possible paths
        void displayPaths();
        void findMaxMinPaths();             //find min and mix paths from vector of recorded paths
};

#endif //PA04_AMAZING_MAZERUNNER_H
