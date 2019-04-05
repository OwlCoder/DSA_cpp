//linked list implementation using C++14 and C++11
#include <iostream>

using std::cout;
using std::endl;

//abstract class
template<class T>
class LinkedList
{
    public:
        LinkedList(){ }
        virtual ~LinkedList(){ }
        //pushfront
        virtual void pushFront(const T& key)=0;
        //pushBack
        virtual void pushBack(const T& key)=0;
        //popBack
        virtual void popBack()=0;
        //popFront
        virtual void popFront()=0;
        //access last element
        virtual T& back()=0;
        //access front element
        virtual T& front()=0;
        //access a given key
        virtual T& find(const T& key)=0;
        //access a key at a given position (need to check)
        virtual operator[](const int pos)=0;
        //delete a given key
        virtual void deleteKey(const T& key)=0;
        //delete a key at a given position
        virtual void deletePos(int pos)=0;
        //length of linked list
        virtual int size()=0;
        //swap nodes
        virtual void swap(int pos1, int pos2)=0;
        //reverse a linked list
        virtual void reverse()=0;
        //sort a linked list
        virtual void sort()=0;
        //merge two sorted linked lists
        virtual void merge(const LinkedList& sorted_1, const LinkedList& sorted_2 )=0;
        //detect and remove a loop in linked list
        virtual void removeLoop()=0;
        //rotate a linked list
        virtual void rotate()=0;
        //add two numbers represented by linked list
        virtual LinkedList& add2nums() const=0;
        //print a linked list [try operator overloading]
        virtual void print()=0;
        //print it in reverse [try operator overloading]
        virtual void printReverse()=0;

    public:
        class Node
        {
            public:
                std::unique_ptr<Node> next;
                T val;
            public:
                Node(const T& value)
                {
                    val=value;
                }
        }
    private:

};

template<class T>
class SinglyLinkedList:public LinkedList
{
    public:

    private:
        std::unique_ptr<Node> head;
};

template<class T>
class DoublyLinkedList:public LinkedList
{
    public:
    private:
        std::unique_ptr<Node> head;
        std::unique_ptr<Node> tail;

};

int main()
{

}