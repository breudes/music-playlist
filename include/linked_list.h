#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <string>
#include <iostream>
#include "../src/node.cpp"

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
            void removeElementByName(Music new_music);
        //Display elements
            void displayList();
            void displayOneElement(int position);
            void displayOneElement(Music new_music);
            void displayFirstElement();
            void displayLastElement();
};
#endif