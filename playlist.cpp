#include "./include/playlist.h"

/*!
    * In this .cpp file is implemented a playlist class, which each object is a music playlist.
    * Each playlist has a name (with a string variable) and a linked list's pointer to storage all songs.
*/
    /*--------------- Constructor and Destructor -----------------------------------*/
    //Default Constructor
    Playlist(){
        /**
            * Constructs an empty playlist with a default-constructed allocator.
        */
        playlist_name = "NULL";
        music_list = new LinkedList();
        music_list->head_pointer = nullptr;
        music_list->tail_pointer = nullptr;
    }