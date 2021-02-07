#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <string>
#include <iostream>

//This class represents a Music object, with a title and the artist, both as a string value, and passed by user input
class Music{
    private:
        std::string title; //title of the song
        std::string artist; //name of the song's artist
    public:
        //Constructors
        Music();
        Music(std::string title_name, std::string artist_name);
        //Destructors
        ~Music();
        //Getters and Setters
        std::string getTitle(void);
        std::string getArtist(void);
        void setTitle(std::string title_name);
        void setArtist(std::string artist_name);
};
#endif