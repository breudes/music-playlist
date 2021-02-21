#include "../include/playlist_list.h"  
//Constructor
PlaylistList::PlaylistList(){
    this->size = 0;
    this->head_playlist = nullptr;
    this->tail_playlist = nullptr;
}

//Destructor 
PlaylistList::~PlaylistList(){
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
int PlaylistList::getSize(void){
    return this->size;
}
PlaylistNode* PlaylistList::getPlaylistHead(void){
    return this->head_playlist;
}
PlaylistNode* PlaylistList::getPlaylistTail(void){
    return this->tail_playlist;
}
void PlaylistList::setSize(int new_size){
    this->size = new_size;
}
void PlaylistList::setPlaylistHead(PlaylistNode *head_new_pointer){
    this->head_playlist = head_new_pointer;
}
void PlaylistList::setPlaylistTail(PlaylistNode *tail_new_pointer){
    this->tail_playlist = tail_new_pointer;
}

//Search of playlists
PlaylistNode* PlaylistList::getPlaylistByName(std::string playlist_name){
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
void PlaylistList::addPlaylist(Playlist new_playlist){
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
void PlaylistList::removePlaylistByName(std::string playlist_name){
    PlaylistNode *auxiliary_playlist = head_playlist;
    PlaylistNode *previous_playlist = auxiliary_playlist;

    while(auxiliary_playlist!=nullptr){
        if(auxiliary_playlist->getPlaylistSet().getPlaylistName() == playlist_name) break;
        if(auxiliary_playlist == nullptr) break;
        previous_playlist = auxiliary_playlist;
        auxiliary_playlist = auxiliary_playlist->getPlaylistPointer();
    }

    if(auxiliary_playlist==head_playlist) head_playlist = auxiliary_playlist->getPlaylistPointer();
    free(auxiliary_playlist);
    --size;  
}
//Display elements
void PlaylistList::displayPlaylists(){
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

void PlaylistList::displayPlaylistByName(std::string playlist_name){
    PlaylistNode *auxiliary_playlist = new PlaylistNode();
    auxiliary_playlist = this->getPlaylistByName(playlist_name);
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Playlist name: " << auxiliary_playlist->getPlaylistSet().getPlaylistName() << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    if(auxiliary_playlist->getPlaylistSet().getMusicList()!=nullptr) auxiliary_playlist->getPlaylistSet().displayPlaylist();
    free(auxiliary_playlist);
}
