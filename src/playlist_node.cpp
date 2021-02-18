#include "../include/playlist_node.h"
    //Constructors
    PlaylistNode::PlaylistNode(){
        this->next_playlist_pointer = nullptr;
    }
    PlaylistNode::PlaylistNode(Playlist new_playlist, PlaylistNode *new_pointer){
        this->playlist_set = new_playlist;
        this->next_playlist_pointer = new_pointer;
    }
    //Destructor
    PlaylistNode::~PlaylistNode(){
        delete this->next_playlist_pointer;
        delete this;
    }
    //Getters and setters
    Playlist PlaylistNode::getPlaylistSet(){
        return this->playlist_set;
    }
    PlaylistNode* PlaylistNode::getPlaylistPointer(){
        return this->next_playlist_pointer;
    }
    void PlaylistNode::setPlaylistSet(Playlist new_playlist){
        this->playlist_set.setPlaylistName(new_playlist.getPlaylistName());
    }
    void PlaylistNode::setPlaylistPointer(PlaylistNode *new_pointer){
        this->next_playlist_pointer = new_pointer;
    }