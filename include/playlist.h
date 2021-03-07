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
    public:
        //Constructors
        Playlist(); 
        ~Playlist(); //Destructor
        //Getters and Setters
        std::string getPlaylistName() const;
        Node* getMusicList() const;
        LinkedList* getMusicSet() const;
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
        void displaySongs(Node *head);
        void displayPlaylist();
        void displayNextSong();

        /*===================== (New) Methods required by second task (with this project) ======================= */
        void addSong(const Playlist &new_playlist); //insertion of songs of another list on this list
        int removeSong(const Playlist &new_playlist); //remotion of songs of another list on this list
        Playlist(const Playlist &new_playlist); //Constructor by Copy

        Playlist operator+(const Playlist &new_playlist);
        Playlist operator+(Music new_song);
        Playlist operator-(const Playlist &new_playlist);
        Playlist operator-(Music new_song);
        void operator>>(Node* &new_song);
        void operator<<(const Music new_song);
};
#endif