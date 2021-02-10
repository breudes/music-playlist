#include "./include/playlist.h"
/*!
    * In this .cpp file is implemented a playlist class, which each object is a music playlist.
    * Each playlist has a name (with a string variable) and a linked list's pointer to storage all songs.
*/
    /*--------------- Constructor and Destructor -----------------------------------*/
    //Default Constructor
    Playlist::Playlist(){
        /**
            * Constructs an empty playlist with a default-constructed allocator.
        */
        this->playlist_name = "NULL";
        this->music_list = new LinkedList();
        this->music_list->setHead(nullptr);
        this->music_list->setTail(nullptr);
    }
    //Construtor by Input
    Playlist::Playlist(std::string name, LinkedList* list){
        /**
            * Constructs a playlist based by user input, each means, by a string name and an array of type Linked List.
        */
        this->playlist_name = name;
        this->music_list->setHead(list->getHead());
        this->music_list->setTail(list->getTail());
    }
    //Destructor
    Playlist::~Playlist(){
        /**
            * Destructs the linked list, i.e., clear the string variable and 
            * destructs each element of list and stored space is deallocated.
        */
        //Clear string variable
        playlist_name.clear();
        //Clear linked list object
        Node* current_pointer = music_list->getHead();
        while(current_pointer!=nullptr){
            Node* auxiliary_pointer = current_pointer->getNextPointer();
            delete current_pointer;
            current_pointer = auxiliary_pointer;
        }
        music_list->setHead(nullptr);
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
    LinkedList* Playlist::getMusicList(){
        /**
            * Returns the music list of playlist.
        */
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
    //Add Song and Name
    void Playlist::addSongAndName(Music new_song, std::string playlist_name){
        this->setPlaylistName(playlist_name);
        this->addSong(new_song);
    }
    //Add Song At First (Position)
    void Playlist::addSongAtFirst(Music new_song){
        this->music_list->addElementAtFirst(new_song);
    }
    //Add Song At Position
    void Playlist::addSontAtPosition(Music new_song, int position){
        this->music_list->addElementAtPosition(new_song,position);
    }
    //Move song At Position
    void Playlist::moveSong(int position){
        Node *result = this->music_list->displayNode(position);
        this->music_list->removeElementAtPosition(position);
        this->music_list->addElement(result->getMusicElement());
    }
    /* ---------------------------- Remotion of songs -----------------------------*/
    //Remove Song
    void Playlist::removeSong(){
        this->music_list->removeLastElement();
    }
    //Remove Song At First
    void Playlist::removeSongAtFirst(){
        this->music_list->removeFirstElement();
    }
    //Remove Song At Position
    void Playlist::removeSontAtPosition(int position){
        this->music_list->removeElementAtPosition(position);
    }
    /* ---------------------------- Display playlist -----------------------------*/
    //Display songs
    void Playlist::displaySongs(Node *head){
        if(head==nullptr) return;
        this->music_list->displayFirstElement();
        displaySongs(head->getNextPointer());
    }
    //Display Playlist
    void Playlist::displayPlaylist(){
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "------------------" << this->getPlaylistName() << "------------------" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        Node *head = new Node();
        head = this->music_list->getHead();
        this->displaySongs(head);
        delete head;
    }
    //Display Next Song
    void Playlist::displayNextSong(){
        if(this->next_song==0){
            this->music_list->displayFirstElement();
            next_song++;
        }else{
            this->music_list->displayOneElement(next_song);
            next_song++;
        }
    }