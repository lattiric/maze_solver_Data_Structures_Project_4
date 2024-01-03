//
// Created by Rick Lattin on 3/26/21.
//

#include "Room.h"
#include <utility>

Room::Room(){
    isOpen = false;
    cost = 1;
    cords = std::make_pair(0,0);
}

Room::Room(bool isOp, int row, int col){
    cords = std::make_pair(row, col);
    isOpen = isOp;
    cost = 1;
}

Room::Room(bool isOp, int row, int col, int costOld){
    cords = std::make_pair(row, col);
    isOpen = isOp;
    cost = costOld;
}

//Room::Room(Room& old){
//    isOpen = old.isOpen;
//    hasPortal = old.hasPortal;
//    portalCost = old.portalCost;
//    cordX = old.cordX;
//    cordY = old.cordY;
//}

//Room::~Room() {
//    delete this;
//}
//
//Room& Room::operator=(Room& old) {
//    hasPortal = old.hasPortal;
//    portalCost = old.portalCost;
//    cordX = old.cordX;
//    cordY = old.cordY;
//
//    return* this;
//}

bool Room::operator==(Room& old) {
    if(cost == old.cost && cords.first == old.cords.first && cords.second == old.cords.second)
        return true;
    else
        return false;
}

std::pair<int, int> Room::getCords() {
    return cords;
}

bool Room::getIsOpen() {
    return isOpen;
}

int Room::getCost() {
    return cost;
}

//-------------------------

void Room::setIsOpen(bool x) {
    isOpen = x;
}

void Room::setCost(int x) {
    cost = x;
}

void Room::setCords(int row, int col) {
    std::pair<int, int> temp;
    temp.first = row;
    temp.second = col;
    cords = temp;
}
