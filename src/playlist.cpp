#include "../include/playlist.h"
/*!
    * In this .cpp file is implemented a playlist class, which each object is a music playlist.
    * Each playlist has a name (with a string variable) and a linked list's pointer to storage all songs.
*/
    int song = 0; //a position with a integer value to storage the order of plays in a playlist
    /*--------------- Constructor and Destructor -----------------------------------*/
    //Default Constructor
    Playlist::Playlist(){
        /**
            * Constructs an empty playlist with a default-constructed allocator.
        */
        this->playlist_name = "NULL";
    }
    //Destructor
    Playlist::~Playlist(){
        /**
            * Destructs the linked list, i.e., clear the string variable.
            * The linked list will be deleted at its own destructor.
        */
        //Clear string variable
        playlist_name.clear();
    }

    /* ---------------------------- Member functions --------------------------------*/
    
    /* ---------------------------- Getters and setters -----------------------------*/ 
    //Get Playlist Name
    std::string Playlist::getPlaylistName(){
        /**
            * Returns the name of playlist.
            * @return: string value.
        */
        return this->playlist_name;
    }
    //Get Music List
    Node* Playlist::getMusicList(){
        /**
            * Returns the music list's head pointer of playlist.
            * @return: node pointer.
        */
        return this->music_list->getHead();
    }
    //Get Music Set
    LinkedList* Playlist::getMusicSet(){
        /**
            * Returns the music list of playlist.
            * @return: linked list pointer.
        */
        return this->music_list;
    }

    //Set Playlist Name
    void Playlist::setPlaylistName(std::string new_name){
        /**
            * Set a playlist name.
            * @param new_name: a string value.
        */
        this->playlist_name = new_name;

    }
    //Set Music List
    void Playlist::setMusicList(LinkedList* new_music_list){
        /**
            * Set a music list, each means, set a linked list with all songs of playlist.
            * @param new_music_list: a linked list pointer.
        */
        this->music_list->setHead(new_music_list->getHead());
        this->music_list->setTail(new_music_list->getTail());
    }

    /* ---------------------------- Insertion of songs -----------------------------*/
    //Add Song
    void Playlist::addSong(Music new_song){
        /** Add a song on playlist at the last position of playlist. With a music object passed as user input and a position
          * passed as an integer value.
          * @param new_song: music object to be added.
        */
        this->music_list->addElement(new_song);
    }
    //Add Song At First (Position)
    void Playlist::addSongAtFirst(Music new_song){
        /** Add a song on playlist at the first position of playlist. With a music object passed as user input and a position
          * passed as an integer value.
          * @param new_song: music object to be added.
        */
        this->music_list->addElementAtFirst(new_song);
    }
    //Add Song At Position
    void Playlist::addSongAtPosition(Music new_song, int position){
        /** Add a song on playlist at a particular position of playlist. With a music object passed as user input and a position
          * passed as an integer value.
          * @param new_song: music object to be added.
          * @param position: position to the music be added at it.
        */
        this->music_list->addElementAtPosition(new_song,position);
    }
    //Move song At Position
    void Playlist::moveSong(Music new_music){
        /** Moves a song of playlist, i.e., removes song from its position and added the same song on the last 
          * position of playlist. The song is based on a music object passed as user input.
          * @param new_music: music to search to (music object)
        */
        this->music_list->removeElementByName(new_music);
        this->music_list->addElement(new_music);
    }
    /* ---------------------------- Remotion of songs -----------------------------*/
    //Remove Song By Name
    void Playlist::removeSong(Music new_music){
        /** Removes a song of playlist, based on a music object passed as user input.
          * @param new_music: music to search to (music object).
        */
        this->music_list->removeElementByName(new_music);
    }
    /* ---------------------------- Display playlist -----------------------------*/
    //Display songs
    void Playlist::displaySongs(Node* head){
        /** Display each song of playlist using recursion.
          * @param head: the first element of playlist (node pointer).
        */
        if(head!=nullptr){
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Track title: " << head->getMusicElement().getTitle() << std::endl;
            std::cout << "Track artist: " << head->getMusicElement().getArtist() << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
            this->displaySongs(head->getNextPointer());
        }else return;
    }
    //Display Playlist
    void Playlist::displayPlaylist(){
        /** Displays playlist properties.
        */
        this->displaySongs(this->music_list->getHead());
    }
    //Display Next Song
    void Playlist::displayNextSong(){
        /** Displays the next song playing on playlist.
        */
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "              Next Song on Playlist '" << this->getPlaylistName() << "'"<< std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        this->music_list->displayOneElement(song);
    }