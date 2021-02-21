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
        */
        return this->playlist_name;
    }
    //Get Music List
    Node* Playlist::getMusicList(){
        /**
            * Returns the music list of playlist.
        */
        return this->music_list->getHead();
    }

    LinkedList* Playlist::getMusicSet(){
        return this->music_list;
    }

    //Set Playlist Name
    void Playlist::setPlaylistName(std::string new_name){
        /**
            * Set a playlist name.
            *param 'new_name': a string value;
        */
        this->playlist_name = new_name;

    }
    //Set Music List
    void Playlist::setMusicList(LinkedList* new_music_list){
        /**
            * Set a music list, each means, set a linked list with all songs of playlist.
            *param 'new_music_list': a linked list pointer;
        */
        this->music_list->setHead(new_music_list->getHead());
        this->music_list->setTail(new_music_list->getTail());
    }

    /* ---------------------------- Insertion of songs -----------------------------*/
    //Add Song
    void Playlist::addSong(Music new_song){
        this->music_list->addElement(new_song);
    }
    //Add Song At First (Position)
    void Playlist::addSongAtFirst(Music new_song){
        this->music_list->addElementAtFirst(new_song);
    }
    //Add Song At Position
    void Playlist::addSongAtPosition(Music new_song, int position){
        this->music_list->addElementAtPosition(new_song,position);
    }
    //Move song At Position
    void Playlist::moveSong(Music new_music){
        this->music_list->removeElementByName(new_music);
        this->music_list->addElement(new_music);
    }
    /* ---------------------------- Remotion of songs -----------------------------*/
    //Remove Song By Name
    void Playlist::removeSong(Music new_music){
        this->music_list->removeElementByName(new_music);
    }
    /* ---------------------------- Display playlist -----------------------------*/
    //Search Song
    int Playlist::searchSong(Music song){
        int position = -1;
        Node *current_pointer = new Node();
        current_pointer = this->getMusicList();
        Node *previous_pointer = current_pointer;

        while(current_pointer!=nullptr){
            if(current_pointer->getMusicElement().getTitle() == song.getTitle() &&
            current_pointer->getMusicElement().getArtist() == song.getArtist() ) break;

            current_pointer = current_pointer->getNextPointer();
            position++;
        }
        delete current_pointer;
        return position;
    }
    //Display songs
    void Playlist::displaySongs(Node* head){
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
        this->displaySongs(this->music_list->getHead());
    }
    //Display Next Song
    void Playlist::displayNextSong(){
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "              Next Song on Playlist '" << this->getPlaylistName() << "'"<< std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        this->music_list->displayOneElement(song);
    }