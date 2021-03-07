#ifndef NODE_H
#define NODE_H

#include "../src/music.cpp"

//This class represents a node (an element) of a particular linked list
class Node{
    private:
        Music music_element; //Music object
        Node *next_pointer; //this pointer will be used as a pointer to the next element of the linked list
    public:
        //Constructors
        Node();
        //Destructor
        ~Node();
        //Getters and Setters
        Music getMusicElement() const;
        Node* getNextPointer() const;
        void setMusicElement(Music new_music);
        void setNextPointer(Node *new_pointer);
};
#endif