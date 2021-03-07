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
            int getSize(void) const;
            Node* getHead(void) const;
            Node* getTail(void) const;
            void setSize(int new_size);
            void setHead(Node *head_new_pointer);
            void setTail(Node *tail_new_pointer);
        //Insertion of elements
            void addElement(Music new_music);
            void addElementAtFirst(Music new_music);
            void addElementAtPosition(Music new_music, int position);
        //Remotion of elements
            int removeElementByName(Music new_music);
        //Display elements
            Node* getOneElementNode(Music new_music);
            void displayList();
            void displayOneElement(int position);
            void displayOneElement(Music new_music);
            void displayFirstElement();
            void displayLastElement();

        /*===================== (New) Methods required by second task (with this project) ======================= */

            void addElement(const LinkedList& new_list); //insertion of a list on this list
            void removeElementByName(const LinkedList& new_list); //remotion of all songs of a list on this list
            LinkedList(const LinkedList& new_list); //constructor by copy of a list
            
            LinkedList operator+(const LinkedList& new_list);
            void operator>>(Node* &tail_pointer);
            void operator<<(const Node* new_pointer);
};
#endif