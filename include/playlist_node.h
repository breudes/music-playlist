#ifndef PLAYLIST_NODE_H
#define PLAYLIST_NODE_H
#include "../src/playlist.cpp"

/* *This class represents a node from a playlist linked list, each node has a playlist object and a playlistNode pointer
/* *to the next playlist on the list */
class PlaylistNode{
    private:
        Playlist playlist_set; //a playlist object
        PlaylistNode *next_playlist_pointer; //a playlistNode pointer
    public:
        //Constructor
        PlaylistNode();
        PlaylistNode(Playlist new_playlist, PlaylistNode *new_pointer);
        //Destructor
        ~PlaylistNode();
        //Getters and setters
        Playlist getPlaylistSet();
        PlaylistNode* getPlaylistPointer();
        void setPlaylistSet(Playlist new_playlist);
        void setPlaylistPointer(PlaylistNode *new_pointer);
};
#endif