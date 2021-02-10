#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream>
#include "../linked_list.cpp"

//This class represents a playlist set, which each element has a name and a linked list with music elements.
class Playlist{
    private:
        std::string playlist_name; //playlist's name
        LinkedList *music_list; //playlist's songs
        int next_song; //a position with a integer value to storage the order of plays in a playlist
    public:
        //Constructors
        Playlist(); 
        Playlist(std::string playlist_name, LinkedList* music_list);
        ~Playlist(); //Destructor
        //Getters and Setters
        std::string getPlaylistName();
        LinkedList* getMusicList();
        void setPlaylistName(std::string new_name);
        void setMusicList(LinkedList* new_music_list);  
        //Insertion of songs
        void addSong(Music new_song);
        void addSongAtFirst(Music new_song);
        void addSongAndName(Music new_song, std::string playlist_name);
        void addSontAtPosition(Music new_song, int position);
        void moveSong(int position);
        //Remotion of songs
        void removeSong();
        void removeSongAtFirst();
        void removeSontAtPosition(int position);
        //Display songs
        void displaySongs(Node *head);
        void displayPlaylist();
        void displayNextSong();
};
#endif