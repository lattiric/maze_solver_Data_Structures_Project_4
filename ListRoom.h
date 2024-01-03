//
// Created by Rick Lattin on 4/7/21.
//

#ifndef PA04_AMAZING_LISTROOM_H
#define PA04_AMAZING_LISTROOM_H

#include "DSList.h"
#include "Room.h"

class ListRoom{
    private:
        Room currRoom;                      //one room in the maze
        DSList<Room> connections;           //all of the connections to that one room
    public:
        ListRoom();
        ListRoom(Room);
        bool operator==(ListRoom&);
        void addConnection(Room);
        void setConnections(DSList<Room>);
        void setCurrRoom(Room);
        DSList<Room> getConnections();
        Room getCurrRoom();

        void intIteratorLRoom();        //functions to correctly use the iterators in the DSList class
        void moveItrLRoom();
        void resetItrLRoom();
        Room getItrLRoom();
};

#endif //PA04_AMAZING_LISTROOM_H
