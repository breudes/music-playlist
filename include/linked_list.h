#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <string>
#include <iostream>
#include "../music.cpp"

//This class represents a node (an element) of a particular linked list
class Node{
    public:
        Music music_element; //Music object
        Node *next_pointer; //this pointer will be used as a pointer to the next element of the linked list
};

//This class represents a particular linked list, which each element is a music object.
class LinkedList{ 
    private: 
        int size; //length of linked list
        Node *head_pointer; //pointer to the first element at linked list
        Node *tail_pointer; //pointer to the first element at linked list
    public:
        LinkedList(); //Constructor
        ~LinkedList(); //Destructor
        //Getters and setters
            int getSize(void);
            Node* getHead(void);
            Node* getTail(void);
            void setSize(int new_size);
            void setHead(Node *head_new_pointer);
            void setTail(Node *tail_new_pointer);
        //Insertion of elements
            void addElement(Music new_music);
            void addElementAtFirst(Music new_music);
            void addElementAtPosition(Music new_music, int position);
        //Remotion of elements
            void removeElementAtPosition(int position);
            void removeFirstElement();
            void removeLastElement();
        //Display elements
            void displayList();
            void displayOneElement(int position);
            void displayFirstElement();
            void displayLastElement();
};

#endif