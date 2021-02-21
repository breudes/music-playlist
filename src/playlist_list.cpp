#include "../include/playlist_list.h"  
/*!
    * In this .cpp file is implemented a particular linked list, which each element is a playlist 
    * object (music class is included), each playlist object has a playlist name and a music linked list 
    * (this one implement as 'linked_list' on this project). 
*/
//Constructor
PlaylistList::PlaylistList(){
    /** Constructs a playlist list object, i.e., set the length to 0 (zero) and allocate pointers of head and tail 
      *from the playlist linked list.
    */
    this->size = 0;
    this->head_playlist = nullptr;
    this->tail_playlist = nullptr;
}

//Destructor 
PlaylistList::~PlaylistList(){
    /** Destructs a playlist list, i.e., deallocate all pointers presents on the playlist linked list.
    */
    PlaylistNode *current_playlist = nullptr;
    current_playlist = this->head_playlist;

    while(current_playlist!=nullptr){
        PlaylistNode *auxiliary_playlist = current_playlist->getPlaylistPointer();
        delete current_playlist;
        current_playlist = auxiliary_playlist;
    }
    
    this->head_playlist = nullptr;
}

//Getters and setters
//Get Size
int PlaylistList::getSize(void){
    /** Returns the size of list, i.e., the length of the playlist linked list.
      * @return: an integer value.
    */
    return this->size;
}
//Get Playlist Head
PlaylistNode* PlaylistList::getPlaylistHead(void){
    /** Returns the head pointer of list, i.e., a pointer with the address of the first element on playlist linked list.
      * @return: a playlist node pointer.
    */
    return this->head_playlist;
}
//Get Playlist Tail
PlaylistNode* PlaylistList::getPlaylistTail(void){
    /** Returns the tail pointer of list, i.e., a pointer with the address of the last element on playlist linked list.
      * @return: a playlist node.
    */
    return this->tail_playlist;
}
//Set Size
void PlaylistList::setSize(int new_size){
    /** Set a new size value on playlist list. 
      * @param new_size: an integer value.
    */
    this->size = new_size;
}
//Set Playlist Head
void PlaylistList::setPlaylistHead(PlaylistNode *head_new_pointer){
    /** Set a new playlist head pointer on playlist list, i.e., a new pointer of the first element on playlist list.
      * @param head_new_pointer: a playlist node pointer.
    */
    this->head_playlist = head_new_pointer;
}
//Set Playlist Tail
void PlaylistList::setPlaylistTail(PlaylistNode *tail_new_pointer){
    /** Set a new playlist tail pointer on playlist list, i.e., a new pointer of the last element on playlist list.
      * @param tail_new_pointer: a playlist node pointer.
    */
    this->tail_playlist = tail_new_pointer;
}

//Search of playlists
//Get Playlist By Name
PlaylistNode* PlaylistList::getPlaylistByName(std::string playlist_name){
    /** Returns a playlist node after search for an especific playlist by name, name passed as user input.
      * @param playlist_name: playlist name to search to (string value).
      * @return: playlist node to playlist founded.

    */
    PlaylistNode *auxiliary_playlist = head_playlist;
    while(auxiliary_playlist!=nullptr){
        if(auxiliary_playlist==nullptr) break;
        if(auxiliary_playlist->getPlaylistSet().getPlaylistName() == playlist_name) break;
        auxiliary_playlist = auxiliary_playlist->getPlaylistPointer();
    }
    if(auxiliary_playlist==nullptr){
        return nullptr;
    }else return auxiliary_playlist;
}

//Insertion of playlists
//Add Playlist
void PlaylistList::addPlaylist(Playlist new_playlist){
    /** Add a playlist on system. With a playlist object passed as user input.
      * @param new_playlist: playlist object.
    */
    PlaylistNode* new_play = new PlaylistNode();
    new_play->setPlaylistSet(new_playlist);
    new_play->setPlaylistPointer(nullptr);
    PlaylistNode* auxiliary_playlist  = new PlaylistNode();
    if(head_playlist==nullptr && size==0){
        head_playlist = new_play;
        tail_playlist = new_play;
    }else{
        auxiliary_playlist = head_playlist;
        while(auxiliary_playlist->getPlaylistPointer()!=nullptr){
            
            auxiliary_playlist = auxiliary_playlist->getPlaylistPointer();
        }
        auxiliary_playlist->setPlaylistPointer(new_play);
        tail_playlist = new_play;
    }
    size++;
}
//Remotion of elements
//Remove Playlist By Name
void PlaylistList::removePlaylistByName(std::string playlist_name){
    /** Removes a particular playlist by its name, name passed as user input.
      * @param playlist_name: playlist name to remove (string value).
    */
    PlaylistNode *auxiliary_playlist = head_playlist;

    while(auxiliary_playlist!=nullptr){
        if(auxiliary_playlist->getPlaylistSet().getPlaylistName() == playlist_name) break;
        if(auxiliary_playlist == nullptr) break;
        auxiliary_playlist = auxiliary_playlist->getPlaylistPointer();
    }

    if(auxiliary_playlist==head_playlist) head_playlist = auxiliary_playlist->getPlaylistPointer();
    free(auxiliary_playlist);
    --size;  
}
//Display elements
//Display Playlists
void PlaylistList::displayPlaylists(){
    /** Displays all playlists presents on system.
    */
    PlaylistNode *auxiliary_playlist = new PlaylistNode();
    auxiliary_playlist = this->head_playlist;

    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "                       ALL PLAYLISTS                         " << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    
    while(auxiliary_playlist!=nullptr){
        if(auxiliary_playlist->getPlaylistSet().getPlaylistName()!="NULL"){
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Playlist name: " << auxiliary_playlist->getPlaylistSet().getPlaylistName() << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
            auxiliary_playlist->getPlaylistSet().displayPlaylist();
        }
        auxiliary_playlist=auxiliary_playlist->getPlaylistPointer();
    }

    free(auxiliary_playlist);
}
//Display Playlist By Name
void PlaylistList::displayPlaylistByName(std::string playlist_name){
    /** Display one particular playlist, search by its name, name its passed as user input.
      * @param playlist_name: playlist name to search to (string value).
    */
    PlaylistNode *auxiliary_playlist = new PlaylistNode();
    auxiliary_playlist = this->getPlaylistByName(playlist_name);
    
    if(auxiliary_playlist->getPlaylistSet().getMusicList()!=nullptr){
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "Playlist name: " << auxiliary_playlist->getPlaylistSet().getPlaylistName() << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        auxiliary_playlist->getPlaylistSet().displayPlaylist();
    } 
    free(auxiliary_playlist);
}