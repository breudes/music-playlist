#ifndef PLAYLIST_LIST_H
#define PLAYLIST_LIST_H
#include "../src/playlist_node.cpp"

/* *This class represents a playlist linked list, each node has a playlist object and a playlistNode pointer
/* *to the next playlist on the list */
class PlaylistList{
    private:
        int size; //this linked list length
        PlaylistNode *head_playlist; //a playlistNode pointer
        PlaylistNode *tail_playlist; //a playlistNode pointer
    public:
        //Constructor
        PlaylistList();
        //Destructor 
        ~PlaylistList(); 
        //Getters and setters
        int getSize(void);
        PlaylistNode* getPlaylistHead(void);
        PlaylistNode* getPlaylistTail(void);
        void setSize(int new_size);
        void setPlaylistHead(PlaylistNode *head_new_pointer);
        void setPlaylistTail(PlaylistNode *tail_new_pointer);
        //Search of elements
        PlaylistNode* getPlaylistByName(std::string playlist_name);
        //Insertion of elements
        void addPlaylist(Playlist new_playlist);
        //Remotion of elements
        void removePlaylistByName(std::string playlist_name);
        //Display elements
        void displayPlaylists();
        void displayPlaylistByName(std::string playlist_name);
};
#endif