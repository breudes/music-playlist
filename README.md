# Introduction

# Structure 
    This project has two linked list implement, the first one with music objects and the second (and last one) with playlist objects. But, lets go from the beginning, ok? 

    A music object has a title track and its artist. The first linked list was made to storage all songs of the system, where you can add, remove and display songs on it; and, a playlist object has a name and a music set (the first linked list).

    The second linked list was made to storage all playlists of the system, which means you can also add, remove, and display playlists on it. The songs are connected, i.e., if you add a song on system, this song could be added on a playlist; and, if you remove a song of the system, this same song must be removed from all playlists of the system.

    This project has a 'main' menu with 3 (three) options, they are:
        1. Manage songs from system;
        2. Manage playlists from system;
        3. Manage one playlist from system.

    And, obviously, each option has a individual menu with especific requests from it. But all options has the management system, i.e., the add, remove and display regular options. See the [Limitations](https://github.com/breudes/music-playlist/tree/master#limitations) part to know a little bit more about this 'main' menu.
# Compiling
    A Makefile is used to compile this project. From the project's root folder, assuming `$` is the terminal prompt, follow these steps:

    ```
    $ git clone https://github.com/breudes/music-playlist.git   #Clone project
    $ make     #Compile project
    $ ./main    #Execute 
    ```
# Input and Output examples

# Limitations
    These are the limitations there came up during the development of this project:

    1. You can only manage a especific playlist if you select the third option on 'main menu';
    2. The 'remove' option is only available by name, which means, you can only remove a song or playlist if insert its name.
# Author
    This projet was made by <a href="https://github.com/breudes">breudes</a>.
# License
    This project is under MIT licence. See <a href="https://github.com/breudes">breudes</a> for more details.