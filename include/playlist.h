#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <string>
#include <iostream>
#include "music.cpp"
#include "linked_list.cpp"

public class Playlist(){
    public:
        std::string playlist_name;
        LinkedList *music_list;
};

#endif