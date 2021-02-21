#include "./playlist_list.cpp"

void menu(){
    std::cout << "=========================================================" << std::endl;
    std::cout << "                          MENU                           " << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "1. Manage songs from music system." << std::endl;
    std::cout << "2. Manage playlists from music system." << std::endl;
    std::cout << "3. Manage one playlist from music system." << std::endl;
    std::cout << "4. Quit." << std::endl;
    std::cout << "Select one of the options: " << std::endl;
}

void menuSongs(){
    std::cout << "=========================================================" << std::endl;
    std::cout << "                    MENU SONGS                           " << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "1. Add song on music system." << std::endl;
    std::cout << "2. Remove song on music system." << std::endl;
    std::cout << "3. Display one song from music system." << std::endl;
    std::cout << "4. Display all songs from music system." << std::endl;
    std::cout << "5. Quit." << std::endl;
    std::cout << "Select one of the options: " << std::endl;
}

void menuPlaylists(){
    std::cout << "=========================================================" << std::endl;
    std::cout << "                    MENU PLAYLISTS                       " << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "1. Add playlist on music system." << std::endl;
    std::cout << "2. Remove playlist on music system." << std::endl;
    std::cout << "3. Display one playlist from music system." << std::endl;
    std::cout << "4. Display all playlists from music system." << std::endl;
    std::cout << "5. Quit." << std::endl;
    std::cout << "Select one of the options: " << std::endl;
}

void menuPlaylist(){
    std::cout << "=========================================================" << std::endl;
    std::cout << "                    MENU PLAYLIST                        " << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "1. Add song on playlist." << std::endl;
    std::cout << "2. Move song on playlist (by its name)." << std::endl;
    std::cout << "3. Remove song on playlist (by its name)." << std::endl;
    std::cout << "4. Display next song from this playlist." << std::endl;
    std::cout << "5. Display all songs from this playlist." << std::endl;
    std::cout << "6. Quit." << std::endl;
    std::cout << "Select one of the options: " << std::endl;
}

Music askSong(){
    Music song; //create music object
    std::string track, artist, dummy;
    std::getline(std::cin, dummy); //get some (previous) data in the input stream
    std::cout << "Insert track title: ";
    std::getline(std::cin, track); //get track title
    song.setTitle(track);
    std::cout << "Insert track artist: ";
    std::getline(std::cin, artist); //get track artist
    song.setArtist(artist);
    //return music object
    return song;
}

void deleteSongsFromPlaylist(PlaylistList *all_playlists, Music song){
    PlaylistNode *auxiliary_playlist = all_playlists->getPlaylistHead();
    //std::cout << "AAAAA: " << auxiliary_playlist << std::endl;
    while(auxiliary_playlist!=nullptr){
        auxiliary_playlist->getPlaylistSet().removeSong(song);
        auxiliary_playlist = auxiliary_playlist->getPlaylistPointer();
        if(auxiliary_playlist==nullptr) break;
    }
}

void manageSongs(LinkedList *all_songs, PlaylistList *all_playlists){
    int option = 0;
    
    while(option!=5){
        menuSongs();
        std::cin >> option;
        if(option==5)break;
        if(option==1){ //add song from system
            Music found_song;
            //get music object by user input
            found_song = askSong();
            //Add song on system
            all_songs->addElement(found_song);
            //Output message
            std::cout << "Music is now on this music system!" << std::endl;
        } 
        if(option==2){ //remove song from system
            Music found_song;
            //get music object by user input
            found_song = askSong();
            //Remove song from playlists
            deleteSongsFromPlaylist(all_playlists,found_song);
            //Remove song from system
            all_songs->removeElementByName(found_song);
        }
        if(option==3){ //display song from system
            Music found_song;
            //get music object by user input
            found_song = askSong();            
            //Display found song from system
            all_songs->displayOneElement(found_song);
        }
        if(option==4){ //display all songs from system
            all_songs->displayList();
        }
    }
}

std::string askPlaylistName(){
    std::string name, dummy;    
    std::getline(std::cin, dummy); //get some (previous) data in the input stream
    std::cout << "Insert playlist name: ";
    std::getline(std::cin, name); //get playlist title
    return name;
}

PlaylistNode* getPlaylistByItsName(PlaylistList *all_playlists,std::string name){
    PlaylistNode *auxiliary_playlist = all_playlists->getPlaylistByName(name);
    return auxiliary_playlist;
}

void managePlaylist(PlaylistNode *playlist_pointer){
    int option = -1;

    while(option!=6){
        menuPlaylist();
        std::cin >> option;
        if(option==6) break;
        if(option==1){ //Add song
            std::cout << "1. Add song at first position." << std::endl;
            std::cout << "2. Add song at especific position." << std::endl;
            std::cout << "3. Add song at last position (default option)." << std::endl;
            //Ask add song options
            std::cout << "Inform your option value: " << std::endl;
            int option_add = -1;
            std::cin >> option_add;
            //get music object by user input
            Music found_song;
            found_song = askSong();

            //Add song on system
            if(option_add==1) playlist_pointer->getPlaylistSet().addSongAtFirst(found_song);
            if(option_add==2){
                std::cout << "Inform your position value: " << std::endl;
                int position = -1;
                std::cin >> position;
                playlist_pointer->getPlaylistSet().addSongAtPosition(found_song,position);
            } 
            if(option_add==3) playlist_pointer->getPlaylistSet().addSong(found_song);
            
            //Output message
            std::cout << "Music is now on this playlist!" << std::endl;
        }

        if(option==2){ //Move song
            Music found_song;
            //get music object by user input
            found_song = askSong();
            //Add song on system
            playlist_pointer->getPlaylistSet().moveSong(found_song);
            //Output message
            std::cout << "Music is moved to last position on this playlist!" << std::endl;
        }

        if(option==3){ //Remove song
            Music found_song;
            //get music object by user input
            found_song = askSong();
            //Add song on system
            playlist_pointer->getPlaylistSet().removeSong(found_song);
            //Output message
            std::cout << "Music was removed from this playlist!" << std::endl;
        }

        if(option==4){ //Display next song
            playlist_pointer->getPlaylistSet().displayNextSong();
        }

        if(option==5){ //Display all songs
            playlist_pointer->getPlaylistSet().displayPlaylist();
        }
    }
}

void manageAllPlaylists(PlaylistList *all_playlists){
    int option = -1;
    
    while(option!=5){
        menuPlaylists();
        std::cout << "=========================================================" << std::endl;
        std::cout << "You are on 'all playlists' menu! Enter a new option value: " << std::endl;
        std::cin >> option;

        if(option==5){
            std::cout << "=========================================================" << std::endl;
            std::cout << "You'll go back to 'main' menu!" << std::endl;
            break;
        }

        if(option==1){ //Add playlist
            //Get new playlist's name by user input
            std::string playlist_name = askPlaylistName();
            //Set a new playlist object 
            Playlist new_playlist;
            new_playlist.setPlaylistName(playlist_name);
            //Add playlist on the linked list of playlists
            all_playlists->addPlaylist(new_playlist);
            //Message output
            std::cout << "Playlist was added on system!" << std::endl;
        }
        if(option==2){ //Remove playlist
            //Get playlist's name by user input
            std::string playlist_name = askPlaylistName();
            //Remove playlist on the linked list of playlists
            all_playlists->removePlaylistByName(playlist_name);
            //all_playlists->removeFirstPlaylist();
            //Message output
            std::cout << "Playlist was removed on system!" << std::endl;
        }

        if(option==3){ //Display one playlist
            //Get playlist's name by user input
            std::string playlist_name = askPlaylistName();
            //Search and display playlist by its name
            all_playlists->displayPlaylistByName(playlist_name);
        }

        if(option==4){ //Display all playlists
            all_playlists->displayPlaylists();
        }
    }
}

int main(){
    //Init list of songs and list of playlist from the system
    LinkedList *all_songs = new LinkedList(); //all songs from system
    PlaylistList *all_playlists = new PlaylistList(); //all playlists from system
    PlaylistNode *auxiliary_playlist; //a playlist node pointer
    int option = -1; //option integer to the main menu of the system
    
    //Displays options of the main menu and leads to the chosen option
    while(option!=4){
        menu(); //main menu
        //get option value by user input
        std::cout << "=========================================================" << std::endl;
        std::cout << "You are on 'main' menu! Enter an option value: " << std::endl;
        std::cin >> option;
        
        //Quit of system
        if(option==4){
            std::cout << "=========================================================" << std::endl;
            std::cout << "You are logging off from this music system. Goodbye!" << std::endl;
            break;
        }
        //Manage songs of system
        if(option==1){
            manageSongs(all_songs,all_playlists);
        }
        //Manage playlists of system
        if(option==2){
            manageAllPlaylists(all_playlists);
        }
        //Manage one playlist of system
        if(option==3){
            std::cout << "-------------- Inform the playlist you want to manage -------------" << std::endl;
            std::string playlist_name = askPlaylistName();
            auxiliary_playlist = getPlaylistByItsName(all_playlists,playlist_name);
            if(auxiliary_playlist!=nullptr) managePlaylist(auxiliary_playlist);
            else std::cout << "Playlist not found!" << std::endl;
        }
    }

    //Deallocate a playlist node's pointer and all linked list used on this system
    free(auxiliary_playlist);
    free(all_songs);
    free(all_playlists);
    
    return 0;
}