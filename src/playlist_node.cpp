#include "../include/playlist_node.h"
    //Constructors
    PlaylistNode::PlaylistNode(){
        /** Constructs the playlist node, i.e, allocate next pointer on the playlist node.
        */
        this->next_playlist_pointer = nullptr;
    }
    PlaylistNode::PlaylistNode(Playlist new_playlist, PlaylistNode *new_pointer){
        this->playlist_set = new_playlist;
        this->next_playlist_pointer = new_pointer;
    }
    //Destructor
    PlaylistNode::~PlaylistNode(){
        /** Destructs the playlist node, i.e, deallocate all pointers presents on the playlist node.
        */
        delete this->next_playlist_pointer;
        delete this;
    }
    //Getters and setters
    //Get Playlist Set
    Playlist PlaylistNode::getPlaylistSet(){
        /** Returns the playlist set of playlist node. With a playlist object.
          * @return: playlist object.
        */
        return this->playlist_set;
    }
    //Get Playlist Pointer
    PlaylistNode* PlaylistNode::getPlaylistPointer(){
        /** Returns the next pointer of playlist node. With a playlist node pointer.
          * @return: playlist node's pointer.
        */
        return this->next_playlist_pointer;
    }
    //Set Playlist Name
    void PlaylistNode::setPlaylistSet(Playlist new_playlist){
        /** Set a new playlist name on playlist node. With a playlist object name.
          * @param new_playlist: playlist object.
        */
        this->playlist_set.setPlaylistName(new_playlist.getPlaylistName());
    }
    //Set Playlist Pointer
    void PlaylistNode::setPlaylistPointer(PlaylistNode *new_pointer){
        /** Set a new next pointer on playlist node. With a playlist node's pointer.
           * @param new_pointer: playlist node's pointer.
        */
        this->next_playlist_pointer = new_pointer;
    }