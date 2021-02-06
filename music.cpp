#include <string>
#include <iostream>

class Music{
    private:
        std::string title; //title of the song
        std::string artist; //name of the song's artist
    public:
        //Constructors 
        Music(){
            
        }
        
        Music(std::string title_name, std::string artist_name){
            title = title_name;
            artist = artist_name;
        }

        //Destructor
        ~Music(){
            title.clear();
            artist.clear();
        }
        
        //Getters and setters (member functions)
        std::string getTitle(void){
            return title;
        }

        std::string getArtist(void){
            return artist;
        }

        void setTitle(std::string title_name){
            title = title_name;
        }

        void setArtist(std::string artist_name){
            artist = artist_name;
        }
};