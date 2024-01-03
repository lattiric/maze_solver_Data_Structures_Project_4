//
// Created by Rick Lattin on 4/1/21.
//

#include "MazeRunner.h"
#include "ListRoom.h"
#include <fstream>

MazeRunner::MazeRunner(){

}

MazeRunner::MazeRunner(DSVector<DSVector<int>> theMaze, AdjList connections) {
    maze = theMaze;
    adjRooms = connections;
}

void MazeRunner::fillMaze(char* arg1) {             //took in all info from text file
    std::ifstream inFS;
    inFS.open(arg1);
    char nRow[100];
    inFS.getline(nRow, 5, ' ');
    numRows = atoi(nRow);
    std::cout<<numRows<<std::endl;
    char nCol[100];
    inFS.getline(nCol, 5);
    numCols = atoi(nCol);
    std::cout<<numCols<<std::endl;

    for(int i = 0; i<numRows; i++) {
        char mazeEl[100];
        DSVector<int> row;
        inFS.getline(mazeEl, numCols+1);
        for(int j = 0; j<numCols; j++){
            row.insert((int)mazeEl[j]-48);
        }
        maze.insert(row);
    }

    for(int i = 0; i<numRows; i++){

        for(int j = 0; j<numCols; j++){
            std::cout<<maze[i][j];
        }
        std::cout<<std::endl;
    }

    char portals[100];
    inFS.getline(portals, 10);
    numPortals = atoi(portals);

    for(int i = 0; i<numPortals; i++){
        char portX[100];
        char portY[100];
        char exitX[100];
        char exitY[100];
        char portCost[100];

        inFS.getline(portX, 100, ' ');
        inFS.getline(portY, 100, ' ');
        inFS.getline(exitX, 100, ' ');
        inFS.getline(exitY, 100, ' ');
        inFS.getline(portCost, 100);

        Room portRoom(false, atoi(portX), atoi(portY));
        Room portRoomDestination(false, atoi(exitX), atoi(exitY), atoi(portCost));
        portalRooms.insert(portRoom);
        portalDestinations.insert(portRoomDestination);
    }

    char startLetter[100];
    char startR[100];
    char startC[100];
    char endLetter[100];
    char endR[100];
    char endC[100];

    inFS.getline(startLetter,5 ,' ');
    inFS.getline(startR,5 ,' ');
    inFS.getline(startC,5);
    inFS.getline(endLetter,5 ,' ');
    inFS.getline(endR,5 ,' ');
    inFS.getline(endC,5);

    startCords.first = atoi(startR);
    startCords.second = atoi(startC);
    endCords.first = atoi(endR);
    endCords.second = atoi(endC);

    std::cout<<startCords.first<<" "<<startCords.second<<std::endl;
    std::cout<<endCords.first<<" "<<endCords.second<<std::endl;
}

void MazeRunner::fillAllRooms() {               //used info from text file to creat the adjacency list
    //int tempCounter = 0;

    for(int i = 0; i<numRows; i++){
        for(int j = 0; j<numCols; j++){
            if(maze[i][j] == 0){
                Room temp(false, i+1, j+1);
                DSList<Room> tempConnections;

                ListRoom roomInMaze(temp);
                roomInMaze.setConnections(tempConnections);
                adjRooms.add_room(temp);

                if(i != 0 && maze[i-1][j] == 0){                    //adds connection to link list in ListRoom Object
                    Room conRoom(false, i, j+1);
                    adjRooms.add_edge(roomInMaze, conRoom);
                }
                if(j != 0 && maze[i][j-1] == 0){
                    Room conRoom(false, i+1, j);
                    adjRooms.add_edge(roomInMaze, conRoom);
                }
                if(i != numRows-1 && maze[i+1][j] == 0){
                    Room conRoom(false, i+2, j+1);
                    adjRooms.add_edge(roomInMaze, conRoom);
                }
                if(j != numCols-1 && maze[i][j+1] == 0){
                    Room conRoom(false, i+1, j+2);
                    adjRooms.add_edge(roomInMaze, conRoom);
                }
                //adjRooms.add_edge(roomInMaze, );
                tempCounter++;
            }
        }
    }
//    for(int y = 0; y<tempCounter; y++){               //printing this
//        std::cout<<"--------";
//        std::cout<<adjRooms.getAllRooms()[y].getCurrRoom().getCords().first<<" ";
//        std::cout<<adjRooms.getAllRooms()[y].getCurrRoom().getCords().second<<" ";
//        std::cout<<adjRooms.getAllRooms()[y].getCurrRoom().getHasPortal()<<" ";
//        std::cout<<"--------";
//        std::cout<<adjRooms.getAllRooms()[y].getConnections().getHead()->data.getCords().first<<" ";
//        std::cout<<adjRooms.getAllRooms()[y].getConnections().getHead()->data.getCords().second<<" ";
//        std::cout<<std::endl;
//    }
}

void MazeRunner::addPortals() {                  //added the portals to adj list from text file info
    for (int x = 0; x < numPortals; x++){
            ListRoom portal(portalRooms[x]);
            int loc = adjRooms.getAllRooms().find(portal);
            std::cout<<loc<<std::endl;
            if(loc != -1){
                std::cout<<"Testing"<<std::endl;
                adjRooms.getAllRooms()[loc].addConnection(portalDestinations[x]);
            }
    }

    for(int x = 0; x<tempCounter; x++){               //printing this
        std::cout<<"--------";
        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCords().first<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCords().second<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCost()<<" ";
        std::cout<<"--------";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getHead()->data.getCords().first<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getHead()->data.getCords().second<<" ";
        std::cout<<"--------";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getTail()->data.getCords().first<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getTail()->data.getCords().second<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getTail()->data.getCost()<<" ";
        std::cout<<std::endl;
    }
}

void MazeRunner::addEnds(){                 //added dummy room to each connect as way of terminating iterator
    Room endRoom;
    for(int i = 0; i<tempCounter; i++){
        adjRooms.getAllRooms()[i].addConnection(endRoom);
    }

    for(int x = 0; x<tempCounter; x++){               //printing this
        std::cout<<"--------";
        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCords().first<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCords().second<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCost()<<" ";
        std::cout<<"--------";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getHead()->data.getCords().first<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getHead()->data.getCords().second<<" ";
        std::cout<<"--------";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getTail()->data.getCords().first<<" ";
        std::cout<<adjRooms.getAllRooms()[x].getConnections().getTail()->data.getCords().second<<" ";
        std::cout<<std::endl;
    }
}

void MazeRunner::runBacktracking() {                //preforms iterative backtracking to find possible paths
    bool stillRun = true;
    bool popStuff = true;
    Room dummyRoom;
    Room tempStart(false, startCords.first, startCords.second);

    Room tempEnd(false, endCords.first, endCords.second);

    backIt.push(tempStart);
    adjRooms.setIteratorsAdj();

    while(!backIt.isEmpty()){   //while its not empty
        DSVector<Room> onePath;
        onePath.insert(tempStart);
            std::cout<<"runs stack thing at all"<<std::endl;
            ListRoom nextRoom;
            ListRoom topRoom(backIt.peek());

            if(adjRooms.getAllRooms()[adjRooms.getAllRooms().find(topRoom)].getItrLRoom() == dummyRoom) {          //
                ListRoom curRoom(backIt.peek());
                adjRooms.getAllRooms()[adjRooms.getAllRooms().find(curRoom)].resetItrLRoom();
                backIt.pop();
                onePath.pop_last();
                //ListRoom lowerRoom(backIt.peek());
                //adjRooms.getAllRooms()[adjRooms.getAllRooms().find(lowerRoom)].moveItrLRoom();
            }
            else {
                std::cout<<"moves iterator"<<std::endl;
                ListRoom prevRoom(backIt.peek());
                ListRoom tempRoom(adjRooms.getAllRooms()[adjRooms.getAllRooms().find(prevRoom)].getItrLRoom());
                nextRoom = tempRoom;
                int nextLoc = adjRooms.getAllRooms().find(nextRoom);
                if(!(backIt.contains(adjRooms.getAllRooms()[nextLoc].getCurrRoom()))) {      //checks to see if its already on stack
                    backIt.push(adjRooms.getAllRooms()[nextLoc].getCurrRoom());
                    onePath.insert(adjRooms.getAllRooms()[nextLoc].getCurrRoom());
                }
                adjRooms.getAllRooms()[adjRooms.getAllRooms().find(prevRoom)].moveItrLRoom();                             //might not give right numbers
            }

            ListRoom lastRoom(backIt.peek());
            std::cout<<"right before last thing"<<std::endl;
//            if(tempEnd == tempEnd) {
            if(adjRooms.getAllRooms()[adjRooms.getAllRooms().find(lastRoom)].getCurrRoom() == tempEnd) {
                stillRun = false;
                paths.insert(onePath);
            }
//        }
    }

//    for(int x = 0; x<tempCounter; x++){               //printing this
//        std::cout<<"--------";
//        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCords().first<<" ";
//        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCords().second<<" ";
//        std::cout<<adjRooms.getAllRooms()[x].getCurrRoom().getCost()<<" ";
//        std::cout<<"--------";
//        std::cout<<adjRooms.getAllRooms()[x].getConnections().getHead()->data.getCords().first<<" ";
//        std::cout<<adjRooms.getAllRooms()[x].getConnections().getHead()->data.getCords().second<<" ";
//        std::cout<<"--------";
//        std::cout<<adjRooms.getAllRooms()[x].getConnections().getTail()->data.getCords().first<<" ";
//        std::cout<<adjRooms.getAllRooms()[x].getConnections().getTail()->data.getCords().second<<" ";
//        std::cout<<std::endl;
//    }

}

//void MazeRunner::testITR(){
//    std::cout<<std::endl;
//    std::cout<<std::endl;
//    adjRooms.getAllRooms()[2].getItrLRoom();
//    std::cout<<adjRooms.getAllRooms()[2].getItrLRoom().getCords().first<<" ";
//    std::cout<<adjRooms.getAllRooms()[2].getItrLRoom().getCords().second<<" ";
//    std::cout<<std::endl;
//    adjRooms.getAllRooms()[2].moveItrLRoom();
//    std::cout<<adjRooms.getAllRooms()[2].getItrLRoom().getCords().first<<" ";
//    std::cout<<adjRooms.getAllRooms()[2].getItrLRoom().getCords().second<<" ";
//    std::cout<<std::endl;
//    adjRooms.getAllRooms()[2].moveItrLRoom();
//    std::cout<<adjRooms.getAllRooms()[2].getItrLRoom().getCords().first<<" ";
//    std::cout<<adjRooms.getAllRooms()[2].getItrLRoom().getCords().second<<" ";
//    std::cout<<std::endl;
//    adjRooms.getAllRooms()[2].moveItrLRoom();
//    std::cout<<adjRooms.getAllRooms()[2].getItrLRoom().getCords().first<<" ";
//    std::cout<<adjRooms.getAllRooms()[2].getItrLRoom().getCords().second<<" ";
//    std::cout<<std::endl;
//}

void MazeRunner::displayPaths(){
    for(int i = 0; i<paths.getNextOpen(); i++){
        for(int j = 0; j<paths.getNextOpen(); j++)
            std::cout<<"("<<paths[i][j].getCords().first<<", "<<paths[i][j].getCords().second<<") ->";
        std::cout<<std::endl;
    }
}

void MazeRunner::findMaxMinPaths(){             //find min and mix paths from vector of recorded paths
    int maxCost;
    int minCost;
    int maxIndex;
    int minIndex;

    for(int i = 0; i<paths.getNextOpen(); i++){
        int currentCost;
        for(int j = 0; j<paths[i].getNextOpen(); j++) {
            currentCost = currentCost+paths[i][j].getCost();
            if(minCost>currentCost) {
                minCost = currentCost;
                minIndex = i;
            }
            if(maxCost<currentCost) {
                maxCost = currentCost;
                maxIndex = i;
            }
        }
    }

    std::cout<<"Least Cost Path Through Maze:"<<std::endl<<"Cost: "<<minCost<<std::endl;
    for(int x = 0; 0<paths[minIndex].getNextOpen(); x++){
        std::cout << "(" << paths[minIndex][x].getCords().first << ", " << paths[minIndex][x].getCords().second << ") ->";
    }

    std::cout<<"Most Cost Path Through Maze:"<<std::endl<<"Cost: "<<maxCost<<std::endl;
    for(int y = 0; 0<paths[maxIndex].getNextOpen(); y++){
        std::cout << "(" << paths[maxIndex][y].getCords().first << ", " << paths[maxIndex][y].getCords().second << ") ->";
    }
}