//
// Created by Rick Lattin on 3/26/21.
//

#include "AdjList.h"
#include "DSVector.h"
#include "Room.h"
#include <map>

AdjList::AdjList() {

}

void AdjList::add_room(Room n1) {       //added room to adjacency list
    ListRoom temp(n1);
    allRooms.insert(temp);
}

void AdjList::add_edge(ListRoom n1, Room n2) {          //added connection to room in adjacency list
    int loc = allRooms.find(n1);

    if(loc == -1) {
        std::cout<<"add_edge failed *cries*"<<std::endl;
        return;
    }
    else
        allRooms[loc].addConnection(n2);
}

DSVector<ListRoom>& AdjList::getAllRooms() {
    return allRooms;
}

//void AdjList::display(){
//    bool stillRun = true;
//    Room dummyRoom;
//    for(int i = 0; i<allRooms.getNextOpen(); i++){
//        while(stillRun){
//            allRooms[i].intIteratorLRoom();
//            if(allRooms[i].getItrLRoom() == dummyRoom) {
//                stillRun = false;
//                std::cout<<"dummy"<<std::endl;
//            }
//            else{
//                std::cout<<"("<<allRooms[i].getItrLRoom().getCords().first<<", ";
//                std::cout<<allRooms[i].getItrLRoom().getCords().second<<") -> ";
//                allRooms[i].moveItrLRoom();
//            }
//        }
//    }
//}

void AdjList::setIteratorsAdj(){
    for(int i = 0; i<allRooms.getNextOpen(); i++){
        allRooms[i].intIteratorLRoom();
    }
}