//
// Created by Rick Lattin on 3/26/21.
//

#include "catch2/catch.hpp"

#include "DSStack.h"
#include "DSList.h"
#include "AdjList.h"

#include "DSVector.h"
#include "Room.h"

TEST_CASE("Testing Stack constructor", "DSStack Constructor"){
        DSStack<int> st1;
        DSStack<bool> st2;
        DSStack<Room> st3;

        REQUIRE(st1.isEmpty());
        REQUIRE(st2.isEmpty());
        REQUIRE(st3.isEmpty());
}

TEST_CASE("Testing Stack push function", "DSStack push") {
    DSStack<int> st1;
    st1.push(5);
    st1.push(10);
    st1.push(15);

    REQUIRE(st1.peek() == 15);
}

TEST_CASE("Testing Stack pop function", "DSStack pop") {
    DSStack<int> st1;
    st1.push(5);
    st1.push(10);
    st1.push(15);
    st1.push(20);

    int x = st1.pop();
    int y = st1.pop();
    int z = st1.pop();

    REQUIRE(x == 20);
    REQUIRE(y == 15);
    REQUIRE(st1.peek() == 5);
}

TEST_CASE("Testing Stack isEmpty Function", "DSStack isEmpty"){
    DSStack<int> st1;
    DSStack<int> st2;
    DSStack<int> st3;

    st1.push(5);
    st1.push(10);
    st1.push(15);
    st1.push(20);

    st3.push(100);

    REQUIRE(st1.isEmpty() == false);
    REQUIRE(st2.isEmpty() == true);
    REQUIRE(st3.isEmpty() == false);
}

TEST_CASE("Testing Stack contains function", "DSStack contains"){
    DSStack<int> st1;

    st1.push(5);
    st1.push(10);
    st1.push(15);
    st1.push(20);

    REQUIRE(st1.contains(20) == true);
    REQUIRE(st1.contains(20) == true);
    REQUIRE(st1.contains(7) == false);
}

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//
TEST_CASE("Testing Linked List constructor", "DSList constructor"){
    DSList<int> list1;

    REQUIRE(list1.getTail()== nullptr);
    REQUIRE(list1.getHead()== nullptr);
    REQUIRE(list1.getSize()==0);
}

TEST_CASE("Testing Linked List Add Node Function", "DSList addNode"){
    DSList<int> list1;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);

    REQUIRE(list1.getHead()->data==1);
    REQUIRE(list1.getTail()->data==3);
    REQUIRE(list1.getHead()->next->data==2);
}

TEST_CASE("Testing Linked List Copy constructor", "DSList copy constructor"){
    DSList<int> list1;
    list1.addNode(1);
    list1.addNode(2);

    DSList<int> newList(list1);

    REQUIRE(list1.getTail()->data == newList.getTail()->data);
    REQUIRE(list1.getHead()->data == newList.getHead()->data);
    REQUIRE(list1.getSize() == newList.getSize());
}



TEST_CASE("Testing Linked List Remove Node Function", "DSList removeNode"){
    DSList<int> list1;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);

    list1.removeNode(3);

    REQUIRE(list1.getHead()->data==1);
    REQUIRE(list1.getTail()->data==2);

    list1.removeNode(1);
    list1.removeNode(2);

    REQUIRE(list1.getTail()== nullptr);
}

TEST_CASE("Testing Linked List Get Functions", "DSList getHead, getTail, getSize"){         //maybe make three
    DSList<int> list1;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);

    REQUIRE(list1.getHead()->data==1);
    REQUIRE(list1.getTail()->data==3);
    REQUIRE(list1.getSize()==3);
}

TEST_CASE("Testing Linked List is Empty", "DSList isEmpty"){
    DSList<int> list1;
    DSList<int> list2;
    DSList<int> list3;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);
    list3.addNode(1);

    REQUIRE(list1.isEmpty()==false);
    REQUIRE(list2.isEmpty()==true);
    REQUIRE(list3.isEmpty()==false);
}

TEST_CASE("Testing Linked Assignment Operator", "DSList operator="){
    DSList<int> list1;
    DSList<int> list2;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);

    list2 = list1;

    REQUIRE(list1.getHead()->data == list2.getHead()->data);
    REQUIRE(list1.getTail()->data == list2.getTail()->data);
    REQUIRE(list1.getSize() == list2.getSize());
}
