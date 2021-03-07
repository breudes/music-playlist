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
    std::string Playlist::getPlaylistName() const{
        /**
            * Returns the name of playlist.
            * @return: string value.
        */
        return this->playlist_name;
    }
    //Get Music List
    Node* Playlist::getMusicList() const{
        /**
            * Returns the music list's head pointer of playlist.
            * @return: node pointer.
        */
        return this->music_list->getHead();
    }
    //Get Music Set
    LinkedList* Playlist::getMusicSet() const{
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

    /*===================== (New) Methods required by second task (with this project) ======================= */
    //Add Song
    void Playlist::addSong(const Playlist &new_playlist){
        /**
            * Adds all songs of a given playlist on this playlist. This method allows duplicate songs.
            * The given playlist is passed by reference.
            * @param 'new_playlist': a const playlist reference.
        */
        if(new_playlist.getMusicList()!=nullptr){
            Node *node_pointer = new_playlist.getMusicList();
            while(node_pointer!=nullptr){
                this->music_list->addElement(node_pointer->getMusicElement());
                node_pointer = node_pointer->getNextPointer();
            }
        }
    }
    //Remove Song
    int Playlist::removeSong(const Playlist &new_playlist){
        /**
            * Removes all songs of a given playlist there are on this playlist. The given playlist is passed by reference.
            * @param 'new_playlist': a const playlist reference.
        */
        int removed_songs = 0;

        if(new_playlist.getMusicList()!=nullptr){
            Node *node_pointer = new_playlist.getMusicList();
            while(node_pointer!=nullptr){
                int aux_songs = this->music_list->removeElementByName(node_pointer->getMusicElement());
                if(aux_songs!=0) removed_songs++;
                node_pointer = node_pointer->getNextPointer();
            }
        }

        return removed_songs;
    }

    //Constructor by Copy
    Playlist::Playlist(const Playlist &new_playlist){
        /** 
            * Constructs a playlist with songs of another playlist, this one passed by reference.
            * @param 'new_playlist': a const Playlist reference.
        */
        this->music_list = new_playlist.getMusicSet();
    }

    //Overload of - operator (Playlist object as reference)
    Playlist Playlist::operator+(const Playlist &new_playlist){
        /**
            * Creates a new playlist with all songs from this playlist and from another playlist, this one passed
            * by reference. This method doesn't allows duplicate songs, skipping songs there are on both given playlists.
            * @param 'new_playlist': a const playlist reference;
            * @return: a playlist object.
        */
        Playlist playlist_result;
        playlist_result.setPlaylistName("Play result");

        Node *aux_node_this = new Node();
        Node *node_playlist = new Node();
        Node *node_this = new Node();

        if(this->getMusicSet()->getSize()>new_playlist.getMusicSet()->getSize()){
            aux_node_this = this->getMusicSet()->getHead();
            node_playlist = new_playlist.getMusicSet()->getHead();
            node_this = this->getMusicSet()->getHead();
        }else{
            aux_node_this = new_playlist.getMusicSet()->getHead();
            node_playlist = this->getMusicSet()->getHead();
            node_this = new_playlist.getMusicSet()->getHead();
        }

        while(aux_node_this!=nullptr){                
            playlist_result.addSong(aux_node_this->getMusicElement());
            aux_node_this = aux_node_this->getNextPointer();
        }
        free(aux_node_this);
        
        while(node_playlist!=nullptr){
            while(node_this!=nullptr){ 
                if(node_playlist->getMusicElement().getTitle() != node_this->getMusicElement().getTitle()
                && node_playlist->getMusicElement().getArtist() != node_this->getMusicElement().getArtist()){
                    playlist_result.addSong(node_playlist->getMusicElement());
                }else{
                    node_this = node_this->getNextPointer();
                    break;
                }
            }
            node_playlist = node_playlist->getNextPointer();
        }
        
        free(node_this);
        free(node_playlist);

        return playlist_result;
    }

    //Overload of + operator (Music object as parameter)
    Playlist Playlist::operator+(Music new_song){
        /**
            * Create a new playlist object with this playlist and then adds the song passed by user input. With
            * another words, returns this playlist plus the given song, without change any property of this playlist.
            * @param 'new_song': a music object;
            * @return: a (new) playlist object.
        */
        Playlist new_playlist;
        new_playlist.setPlaylistName("Play result");
        
        Node *new_pointer = this->getMusicList();
        while(new_pointer!=nullptr){
            new_playlist.addSong(new_pointer->getMusicElement());
            new_pointer = new_pointer->getNextPointer();
        }
        new_playlist.addSong(new_song);
        return new_playlist;
    }

    //Overload of - operator (Playlist object as reference)
    Playlist Playlist::operator-(const Playlist &new_playlist){
        /**
            * Creates a new playlist with all songs from this playlist there are not on another playlist, this one passed
            * by reference.
            * @param 'new_playlist': a const playlist reference;
            * @return: a playlist object.
        */
        Playlist playlist_result;
        playlist_result.setPlaylistName("Play result");

        Node *aux_playlist = new Node();
        Node *aux_this = new Node();

        aux_playlist = this->getMusicSet()->getHead();

        while(aux_playlist!=nullptr){
            aux_this = new_playlist.getMusicSet()->getHead();
            while(aux_this!=nullptr){
                if(aux_this->getMusicElement().getTitle() == aux_playlist->getMusicElement().getTitle() &&
                aux_this->getMusicElement().getArtist() == aux_playlist->getMusicElement().getArtist() ){
                    break;
                }
                aux_this = aux_this->getNextPointer();
            }
            if(aux_this==nullptr) playlist_result.addSong(aux_playlist->getMusicElement());
            aux_playlist = aux_playlist->getNextPointer();
        }

        free(aux_playlist);
        free(aux_this);
        return playlist_result;
    }

    //Overload of - operator (Music object as parameter)
    Playlist Playlist::operator-(Music new_song){
        /**
            * Create a new playlist object with this playlist and then removes the song passed by user input. With
            * another words, returns this playlist without the given song, without change any property of this playlist.
            * @param 'new_song': a music object;
            * @return: a (new) playlist object.
        */
        Playlist new_playlist;
        new_playlist.setPlaylistName("Play result");

        Node *new_pointer = this->getMusicList();
        while(new_pointer!=nullptr){
            new_playlist.addSong(new_pointer->getMusicElement());
            new_pointer = new_pointer->getNextPointer();
        }
        new_playlist.removeSong(new_song);
        return new_playlist;
    }

    //Overload of >> operator
    void Playlist::operator>>(Node* &new_song){
        /**
            * Get the last element of this playlist, adds its properties on the given node reference; and then
            * removes this element of this playlist.
            * @param 'new_song': a node reference.
        */
        if(this->getMusicSet()->getSize()>0){
            new_song->setMusicElement(this->getMusicSet()->getTail()->getMusicElement());
            this->removeSong(this->getMusicSet()->getTail()->getMusicElement());
        }else{
            new_song = nullptr;
        }
    }

    //Overload of << operator
    void Playlist::operator<<(const Music new_song){
        /**
            * Adds a given song on this list. The song is given by user input.
            * @param 'new_song': a const Music object.
        */
        if(new_song.getTitle()!=""){
            this->addSong(new_song);
        }else return;
    }