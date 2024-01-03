//
// Created by Rick Lattin on 3/26/21.
//

#ifndef PA04_AMAZING_ROOM_H
#define PA04_AMAZING_ROOM_H

#include <utility>

class Room{
    private:
        std::pair<int, int> cords;      //represented as Row, Collum
        bool isOpen;
        int cost;

    public:
        Room();
        Room(bool, int, int);           //goes row, col for the ints
        Room(bool, int, int, int);  //goes cost, rowP, colP, row, col for the ints
//        Room(Room&);
//        ~Room();
//        Room& operator= (Room&);
        std::pair<int, int > getCords();
        bool operator== (Room&);
        bool getIsOpen();
        int getCost();

        void setIsOpen(bool);
        void setCost(int);

        void setCords(int, int);
};

#endif //PA04_AMAZING_ROOM_H
