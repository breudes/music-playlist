#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream>
#include "../src/linked_list.cpp"

//This class represents a playlist set, which each element has a name and a linked list with music elements.
class Playlist{
    private:
        std::string playlist_name; //playlist's name
        LinkedList *music_list = new LinkedList(); //playlist's songs
        int next_song; //a position with a integer value to storage the order of plays in a playlist
    public:
        //Constructors
        Playlist(); 
        ~Playlist(); //Destructor
        //Getters and Setters
        std::string getPlaylistName();
        Node* getMusicList();
        LinkedList* getMusicSet();
        void setPlaylistName(std::string new_name);
        void setMusicList(LinkedList* new_music_list);  
        //Insertion of songs
        void addSong(Music new_song);
        void addSongAtFirst(Music new_song);
        void addSongAtPosition(Music new_song, int position);
        void moveSong(Music new_music);
        //Remotion of songs
        void removeSong(Music new_music);
        //Display songs
        int searchSong(Music song);
        void displaySongs(Node *head);
        void displayPlaylist();
        void displayNextSong();
};
#endif