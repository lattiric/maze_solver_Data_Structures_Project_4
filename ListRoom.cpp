//
// Created by Rick Lattin on 4/7/21.
//
#include "ListRoom.h"
#include "Room.h"

ListRoom::ListRoom() {

}

ListRoom::ListRoom(Room roomAt) {
    currRoom = roomAt;
}

bool ListRoom::operator==(ListRoom& old) {
    if((currRoom.getCords().first == old.getCurrRoom().getCords().first) && (currRoom.getCords().second == old.getCurrRoom().getCords().second))
        return true;
    else
        return false;
}

void ListRoom::setConnections(DSList<Room> connecs) {
    connections = connecs;
}

void ListRoom::setCurrRoom(Room roomAt) {
    currRoom = roomAt;
}

DSList<Room> ListRoom::getConnections() {
    return this->connections;
}

Room ListRoom::getCurrRoom() {
    return currRoom;
}

void ListRoom::addConnection(Room rm) {
    connections.addNode(rm);
}

//-----------------------------------------     //functions to correctly use the iterators in the DSList class

void ListRoom::intIteratorLRoom() {
    connections.intIterator();
}

void ListRoom::moveItrLRoom() {
    connections.moveItr();
}

void ListRoom::resetItrLRoom() {
    connections.resetItr();
}

Room ListRoom::getItrLRoom() {
    return connections.getItr()->data;
}
