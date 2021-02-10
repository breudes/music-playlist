#include <string>
#include <iostream>
#include "./include/node.h"
/*!
    * In this .cpp file is implemented a Node Class, which each element is a music element with a node's pointer to the next node
    * (which has another music element). Each node is important for a linked list, because the beginning until the end of a list
    * is all made by nodes; in our case, each node storage a music object, with a title and an artist.
*/
    /*--------------------- Constructors and Destructor -----------------------------------*/
    //Constructors
    Node::Node(){
        /**
            * Constructs an empty default constructor.
        */
        this->music_element.setTitle("");
        this->music_element.setArtist("");
        this->next_pointer = nullptr;
    }
    Node::Node(Music music, Node *pointer){
        /**
            * Constructs an node object with the properties given by user input.
        */
        this->music_element.setTitle(music.getTitle());
        this->music_element.setArtist(music.getArtist());
        this->next_pointer->setNextPointer(pointer);
    }
    //Destructor
    Node::~Node(){
        /**
            * Destructs the node object, i.e., delete the 'next_pointer' pointer and 
            * clear the value of strings in 'music element' object (but not its address in storage).
        */
        this->music_element.getTitle().clear();
        this->music_element.getArtist().clear();
        delete this->next_pointer;
    }

    /* ---------------------------- Member functions --------------------------------*/
    /* ---------------------------- Getters and setters -----------------------------*/ 
    //Get Music Element
    Music Node::getMusicElement(){
        /**
            * Returns the 'music_element' propertie, each means, the music element of node's pointer.
        */
        return this->music_element;
    }
    //Get Next Pointer
    Node* Node::getNextPointer(){
        /**
            * Returns the 'next_pointer' propertie, each means, the node pointer's next pointer.
        */
        return this->next_pointer;
    }
    //Set Music Element
    void Node::setMusicElement(Music new_music){
        /**
            * Set a new music element, each means, refresh 'music_element' of a node object.
            *param 'new_music': a music object;
        */
        this->music_element.setTitle(new_music.getTitle());
        this->music_element.setArtist(new_music.getArtist());
    }
    //Set Next Pointer
    void Node::setNextPointer(Node *new_pointer){
        /**
            * Set a new node pointer, each means, refresh 'next_pointer' (a node pointer) of a node object.
            *param 'new_pointer': a node pointer;
        */
        this->next_pointer = new_pointer;
    }