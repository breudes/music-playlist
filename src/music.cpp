#include "../include/music.h"
/*!
    * In this .cpp file is implemented a Music Class, which each element is a music with a 'title' of the track,
    * and an 'artist' of the track. Both of properties are in a string variable.
*/
    /*--------------------- Constructors and Destructor -----------------------------------*/
    //Constructors 

    //Music
    Music::Music(){
        /**
            * Constructs an empty default constructor.
        */
    }    
    //Music
    Music::Music(std::string title_name, std::string artist_name){
        /**
            * Constructs an music object with the properties given by user input;
            * @param 'title_name': a string value;
            * @param 'artist_name': a string value.
        */
        this->title = title_name;
        this->artist = artist_name;
    }
    //Music
    Music::Music(const Music &new_song){
        /**
            * Constructs an music object with the properties of another music object;
            * @param 'new_song': a const music object.
        */
        this->title = new_song.title;
        this->artist = new_song.artist;
    }

    //Destructor

    //~Music
    Music::~Music(){
        /**
            * Destructs the music object, i.e., clear the value of string (but not its address in storage).
        */
        this->title.clear();
        this->artist.clear();
    }

    /* ---------------------------- Member functions --------------------------------*/
    /* ---------------------------- Getters and setters -----------------------------*/    
    
    //Get Title
    std::string Music::getTitle(void){
        /**
            * Returns the 'title' propertie, each means, the title of a music object.
        */
        return this->title;
    }
    //Get Artist
    std::string Music::getArtist(void){
        /**
            * Returns the 'artist' propertie, each means, the artist of a music object.
        */
        return this->artist;
    }
    //Set Title
    void Music::setTitle(std::string title_name){
        /**
            * Set a new title name, each means, refresh 'title' of a music object.
            * @param 'title_name': a string variable;
        */
        this->title = title_name;
    }
    //Set Artist
    void Music::setArtist(std::string artist_name){
        /**
            * Set a new artist name, each means, refresh 'artist' of a music object.
            * @param 'artist_name': a string variable;
        */
        this->artist = artist_name;
    }