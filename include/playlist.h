#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <string>
#include <iostream>
#include "../linked_list.cpp"

class Playlist{
    private:
        std::string playlist_name;
        LinkedList *music_list;
    public:
        //Constructors
        Playlist(); 
        Playlist(std::string playlist_name, LinkedList* music_list);
        Playlist(Playlist other_playlist);
        ~Playlist(); //Destructor
        //Getters and Setters
        std::string getPlaylistName();
        void getMusicList();
        void setPlaylistName(std::string new_name);
        void setMusicList(LinkedList* new_music_list);  
        //Insertion of songs
        void addSong(Music new_song);
        void addSongAtFirst(Music new_song);
        void addSontAtPosition(Music new_song, int position);
        void moveSong(int position);
        //Remotion of songs
        void removeSong();
        void removeSongAtFirst();
        void removeSontAtPosition(int position);
        //Display songs
        void displayPlaylist();
        void displayNextSong();
};

#endif