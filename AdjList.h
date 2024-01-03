//
// Created by Rick Lattin on 3/26/21.
//

#ifndef PA04_AMAZING_ADJLIST_H
#define PA04_AMAZING_ADJLIST_H

#include "DSList.h"
#include "DSVector.h"
#include "Room.h"
#include "ListRoom.h"
#include <map>


class AdjList{
private:
    DSVector<ListRoom> allRooms;
public:
    AdjList();
    void add_room(Room);             //added room to adjacency list
    void add_edge(ListRoom, Room);   //added connection to room in adjacency list
    DSVector<ListRoom>& getAllRooms();
    void display();
    void setIteratorsAdj();
};

#endif //PA04_AMAZING_ADJLIST_H
