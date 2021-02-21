#include "./playlist_list.cpp"

//Menu
void menu(){
    /** Displays the main menu of system.
    */
    std::cout << "=========================================================" << std::endl;
    std::cout << "                          MENU                           " << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "1. Manage songs from music system." << std::endl;
    std::cout << "2. Manage playlists from music system." << std::endl;
    std::cout << "3. Manage one playlist from music system." << std::endl;
    std::cout << "4. Quit." << std::endl;
    std::cout << "Select one of the options: " << std::endl;
}

//Menu Songs
void menuSongs(){
    /** Displays the songs menu of system.
    */
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

//Menu Playlists
void menuPlaylists(){
    /** Displays the playlists menu of system.
    */
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

//Menu Playlist
void menuPlaylist(){
    /** Displays the one playlist menu of system.
    */
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

//Ask Song
Music askSong(){
    /** Gets the title and artist track of music object.
      * @return: music object.
    */
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

//Delete Songs from Playlist
void deleteSongsFromPlaylist(PlaylistList *all_playlists, Music song){
    /** Removes one particular song from all playlists of system.
      * @param all_playlists: playlist linked list node.
      * @param song: music object.
    */
    PlaylistNode *auxiliary_playlist = all_playlists->getPlaylistHead();
    //std::cout << "AAAAA: " << auxiliary_playlist << std::endl;
    while(auxiliary_playlist!=nullptr){
        auxiliary_playlist->getPlaylistSet().removeSong(song);
        auxiliary_playlist = auxiliary_playlist->getPlaylistPointer();
        if(auxiliary_playlist==nullptr) break;
    }
}

//Manage Songs
void manageSongs(LinkedList *all_songs, PlaylistList *all_playlists){
    /** Manage all songs of system.
      * @param all_songs: linked list node.
      * @param all_playlists: playlist linked list node.
    */
    int option = 0;
    int option_add = -1;
    int position = -1;
    while(option!=5){
        menuSongs();
        std::cin >> option;
        if(option==5)break;
        if(option==1){ //add song from system
            //Add options
            std::cout << "1. Add song at first position." << std::endl;
            std::cout << "2. Add song at especific position." << std::endl;
            std::cout << "3. Add song at last position (default option)." << std::endl;
            //Ask add song options
            std::cout << "Inform your option value: " << std::endl;
            std::cin >> option_add;
            //get music object by user input
            Music found_song;
            found_song = askSong();

            if(option_add==1) all_songs->addElementAtFirst(found_song);
            if(option_add==2) {
                std::cout << "Inform your position value: " << std::endl;
                std::cin >> position;
                all_songs->addElementAtPosition(found_song,position);
            }
            if(option_add==3) all_songs->addElement(found_song);
            else std::cout << "Invalid option!" << std::endl;
            //Output message
            std::cout << "Music is now on this music system!" << std::endl;
        } 
        if(option==2){ //remove song from system
            Music found_song;
            //get music object by user input
            found_song = askSong();
            //Search on system
            Node *aux_pointer = all_songs->getOneElementNode(found_song);
            if(aux_pointer!=nullptr){
                //Remove song from playlists
                deleteSongsFromPlaylist(all_playlists,found_song);
                //Remove song from system
                all_songs->removeElementByName(found_song);
                std::cout << "Music is now removed from this music system!" << std::endl;
            }else{ 
                std::cout << "Music was not found on this music system!" << std::endl;
            }
            
        }
        if(option==3){ //display song from system           
            //Display options
            std::cout << "1. Display song at first position." << std::endl;
            std::cout << "2. Display song at especific position." << std::endl;
            std::cout << "3. Display song by name." << std::endl;
            std::cout << "4. Display song at last positions." << std::endl;
            //Ask display song options
            std::cout << "Inform your option value: " << std::endl;
            std::cin >> option_add;
            //Display found song from system
            if(option_add==1) all_songs->displayFirstElement();
            if(option_add==2){
                std::cout << "Inform your position value: " << std::endl;
                std::cin >> position;
                all_songs->displayOneElement(position);
            } 
            if(option_add==3){
                Music found_song;
                //get music object by user input
                found_song = askSong();
                //Search on system
                Node *aux_pointer = all_songs->getOneElementNode(found_song);
                if(aux_pointer!=nullptr){
                    all_songs->displayOneElement(found_song);
                }else{ 
                    std::cout << "Music was not found on this music system!" << std::endl;
                }
                
            } 
            if(option_add==4) all_songs->displayLastElement();
        }
        if(option==4){ //display all songs from system
            all_songs->displayList();
        }
    }
}

//Ask Playlist Name
std::string askPlaylistName(){
    /** Ask playlist name and returns its name.
      * @return: string value.
    */
    std::string name, dummy;    
    std::getline(std::cin, dummy); //get some (previous) data in the input stream
    std::cout << "Insert playlist name: ";
    std::getline(std::cin, name); //get playlist title
    return name;
}

//Get Playlist By Its Name
PlaylistNode* getPlaylistByItsName(PlaylistList *all_playlists,std::string name){
    /** Returns a playlist node bases on especific name, name passed as user input. 
      * @param all_playlists: playlist list node.
      * @param name: string value.
      * @return: playlist list node.
    */
    PlaylistNode *auxiliary_playlist = all_playlists->getPlaylistByName(name);
    return auxiliary_playlist;
}

//Manage Playlist
void managePlaylist(LinkedList *all_songs,PlaylistNode *playlist_pointer){
    /** Manage one especific playlist passed by its name. This functions gets the chosen playlist list node.
      * @param all_songs: linked list node.
      * @param playlist_pointer: playlist node.
    */
    int option = -1;
    int option_add = -1;
    while(option!=6){
        menuPlaylist();
        std::cin >> option;
        if(option==6) break;
        if(option==1){ //Add song
            //get music object by user input
            Music found_song;
            found_song = askSong();
            //Search on system
            Node *aux_pointer = all_songs->getOneElementNode(found_song);
            if(aux_pointer!=nullptr){
                std::cout << "1. Add song at first position." << std::endl;
                std::cout << "2. Add song at especific position." << std::endl;
                std::cout << "3. Add song at last position (default option)." << std::endl;
                //Ask add song options
                std::cout << "Inform your option value: " << std::endl;
                std::cin >> option_add;
                //Add song on playlist
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
            }else{
                std::cout << "Music not founded. Add music on system before add a music in one playlist." << std::endl;
            }
        }

        if(option==2){ //Move song
            Music found_song;
            //get music object by user input
            found_song = askSong();
            //Search on system
            Node *aux_pointer = all_songs->getOneElementNode(found_song);
            if(aux_pointer!=nullptr){
                //Moves song on playlist
                playlist_pointer->getPlaylistSet().moveSong(found_song);
                //Output message
                std::cout << "Music is moved to last position on this playlist!" << std::endl;
            }else {
                std::cout << "Music not founded. Add music on system before move a music in one playlist." << std::endl;
            }
        }

        if(option==3){ //Remove song
            Music found_song;
            //get music object by user input
            found_song = askSong();
            //Search on system
            Node *aux_pointer = all_songs->getOneElementNode(found_song);
            if(aux_pointer!=nullptr){
                //Removes song on system
                playlist_pointer->getPlaylistSet().removeSong(found_song);
                //Output message
                std::cout << "Music was removed from this playlist!" << std::endl;
            }else{
                std::cout << "Music not founded. Add music on system before remove a music in one playlist." << std::endl;
            }
        }

        if(option==4){ //Display next song
            playlist_pointer->getPlaylistSet().displayNextSong();
        }

        if(option==5){ //Display all songs
            playlist_pointer->getPlaylistSet().displayPlaylist();
        }
    }
}

//Manage All Playlists
void manageAllPlaylists(PlaylistList *all_playlists){
    /** Manage all playlists of system. This function gets a playlist linked list node.
      * @param all_playlists: playlist list node.
    */
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
            if(auxiliary_playlist!=nullptr) managePlaylist(all_songs,auxiliary_playlist);
            else std::cout << "Playlist not found!" << std::endl;
            free(auxiliary_playlist);
        }
    }

    //Deallocate a playlist node's pointer and all linked list used on this system
    free(all_songs);
    free(all_playlists);
    
    return 0;
}