# Introduction
    A linked list it's a simple and linear data structure, formed by nodes, where each node has a object element and another node pointer. The list use a node as a pointer, i.e., a node pointer who points to another node pointer, with this relation is possible the construction of linked list. The first node pointer is called by 'head' and the last node pointer is called by 'tail', these pointers has the adress of the first and last element of list, respectively; and the 'tail' pointer points to a null value (in c++, points to nullptr).

    In this project the node of a list has a music element, with a title and artist. Each node connects to the next node, i.e., each music is connected with the next music on list. But this project also requires multiple playlists, so, it was also implemented a linked list where the node has a playlist element, with the playlist name and its list of music. 

    Tying everything up, the system has one linked list with music elements and one linked list with playlist elements. In other words, was implemented a music management system, where you can add, remove or display one music or playlist.

    This project was a task presents on class called 'Program Language I', in the course of IT at Federal University of Rio Grande do Norte (Brazil).
# Structure 
    This project has two linked list implement, the first one with music objects and the second (and last one) with playlist objects. But, lets go from the beginning, ok? 

    A music object has a title track and its artist. The first linked list was made to storage all songs of the system, where you can add, remove and display songs on it; and, a playlist object has a name and a music set (the first linked list).

    The second linked list was made to storage all playlists of the system, which means you can also add, remove, and display playlists on it. The songs are connected, i.e., if you add a song on system, this song could be added on a playlist; and, if you remove a song of the system, this same song must be removed from all playlists of the system.

    This project has a 'main' menu with 3 (three) options, they are:
        1. Manage songs from system;
        2. Manage playlists from system;
        3. Manage one playlist from system.

    And, obviously, each option has a individual menu with especific requests from it. But all options has the management system, i.e., the add, remove and display regular options. See 'Limitations' part to know a little bit more about this 'main' menu.
# Compiling
    A Makefile is used to compile this project. From the project's root folder, assuming `$` is the terminal prompt, follow these steps:

    ```
    # Clone project
    $ git clone https://github.com/breudes/music-playlist.git   
    # Compile project
    $ make     
    # Execute 
    $ ./main    
    ```
# Input and commands examples
    1. Manage Songs

    1.1 Add Song
    # The 'option' value equals 1 and 3 leads to add song at first or last position of list, respectively
    # without ask for a position value.
        ```
        $ Insert track title:
        $ good days
        $ Insert track artist:
        $ sza
        $ Inform your option value:
        # Add at position option (add song at one position of list)
        $ 2
        $ Inform your position value:
        $ 1
        # Output message
        $ Music is now on this music system!  
        ```
    1.2 Remove
        ```
        $ Insert track title:
        $ good days
        $ Insert track artist:
        $ sza
        # If song was on system, gets this message
        $ Music is now removed from this music system!
        # Otherwise
        $ Music was not found on this music system! 
        ```
    1.3 Display # This option works similar to add and remove options.
    1.4 Display All Songs # This option displays all songs without user input.

    2. Manage Playlists

    2.1 Add Playlist
        ```
        $ Insert playlist name:
        $ sza's best songs
        # Output message
        $ Playlist was added on system!  
        ```
    2.2 Remove Playlist # This option works similar to add option.
    2.3 Display Playlist # This option works similar to add option.
    2.4 Display All Playlists # This option displays all playlists without user input.

    3. Manage One Playlist

    3.1 Add Song on Playlist
        ```
        $ Insert track title:
        $ go gina
        $ Insert track artist:
        $ sza
        # If the music is on system, the successful message
        $ Music is now on this playlist!
        # Otherwise
        $ Music not founded. Add music on system before add a music in one playlist.
        ```
    3.2 Move Song of Playlist
        ```
        $ Insert track title:
        $ go gina
        $ Insert track artist:
        $ sza
        # If the music is on system, the successful message
        $ Music was removed from this playlist!
        # Otherwise
        $ Music not founded. Add music on system before move a music in one playlist.
        ```
    3.3 Remove Song on Playlist # This option works similar to move option.
    3.4 Display Next Song of Playlist # This option displays next songs playing on playlist without user input.
    3.5 Display All Songs of Playlist # This option displays all songs in playlist without user input.

# Limitations
    These are the limitations of this project:

    1. You can only manage a especific playlist if you select the third option on 'main menu';
    2. You can only add a playlist on system by default add option, i.e., the playlist its added on tail of linked list (last position on list);
    3. You can only remove or display one particular playlist by its name, i.e., you must insert the chosen playlist's name;
    4. The 'remove' option is only available by name, which means, you can only remove a song or playlist if insert its name.
# Difficulties
    These are the difficulties there came up during the development of this project:

    1. The implementation of playlists linked list, only because of the remotion part (take too long to solve its problems);
    2. The remotion of songs from system and from all the playlists, was difficult but it's working.
# Author
    This projet was made by breudes (https://github.com/breudes). Full name author: Brenda Alexandra de Souza Silva.
# License
    This project is under MIT licence. See LICENSE for more details.