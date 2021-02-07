#include <string>
#include <iostream>
#include "linked_list.cpp"

int main(){
    LinkedList* teste = new LinkedList();

    Music musica,musica2,musica3;
    
    musica.setTitle("cherry");
    musica.setArtist("rina sawayama");

    musica2.setTitle("bad friend");
    musica2.setArtist("rina sawayama");

    musica3.setTitle("good days");
    musica3.setArtist("sza");

    teste->addElement(musica);
    teste->addElement(musica2);
    teste->addElement(musica3);
    
    teste->displayList();
    return 0;
}