/***
 * In this challenge you will create a menu driven application that will simulate a user playing songs from a playlist of songs
 * 
 * We will use a list to simulate the user selecting the first song in the play then selecting next and previous to play forward of backwards through the playlist.alignas
 * We will also allow users to add new song to the playlist and they will be added prior to the currently playing song.
 * 
 * The menu looks as follows: 
 * 
 * F - Play First Song
 * N - Play Next Song
 * P - Play Previous Song
 * A - Add and play a new Song at current location
 * L - List the current playlist
 * 
 * =================================
 * Enter a selection (Q to quit): 
 * 
 * And the available playlist is modeled as a std::list<Song> 
 * I will provide the Song class. Following are the songs in the playlist. 
 * I grabbed these from the pop charts, you can use them or change them to any songs you wish. 
 * 
 * God's Plan                   Drake                           5
 * Never Be The Same            Camila Cabello                  5
 * Pray For Me                  The Weekend and K.Lamar         4
 * The Middle                   Zedd, Maren Morris & Grey       5
 * Wait                         Maroone 5                       4
 * Whatever It Takes            Imagine Dragons                 3
 * 
 * Note: 
 * If you have trouble reading input, you can clear std::cin and ignore everything in the buffer with: 
 * 
 * std::cin.clear();
 * std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
 * 
 * ****/

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
        friend std::ostream &operator<<(std::ostream &os, const Song &s);
        std::string name;
        std::string artist;
        int rating;
    public:
        Song() = default;
        Song(std::string name, std::string artist, int rating) : name {name}, artist {artist}, rating {rating} {}
        std::string get_name() const {
            return artist;
        }
        int get_rating() const {
            return rating;
        }

        bool operator<(const Song &rhs) const {
            return this->name < rhs.name;
        }

        bool operator==(const Song &rhs){
            return this->name == rhs.name;
        }
};

std::ostream &operator<<(std::ostream &os, const Song &s){
    os << std::setw(20) << std::left << s.name
        << std::setw(20) << std::left << s.artist
        << std::setw(2) << std::left << s.rating;
        return os;
}

void display_menu(){
    std::cout << "\nF - Play First Song\n";
    std::cout << "N - Play Next Song\n";
    std::cout << "P - Play Previous Song\n";
    std::cout << "A - Add and play a new Song at current location\n";
    std::cout << "L - List the current playlist\n";
    std::cout << "=========================================\n";
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song){
    // This function should display
    // Playing: followed by the song that is playing

    std::cout << "Playing: \n";
    std::cout << song << std::endl; 

    // std::cout << "You implement this function\n";
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song){
    // This function should display the current playlist and then the current song playing.

    for(const Song &song : playlist){
        std::cout << song << std::endl;
    }
    std::cout << "Current song: \n";
    std::cout << current_song << std::endl;

    // std::cout << "You implement this function\n";
}

int main(){
    std::list<Song> playlist {
        {"God's Plan", "Drake", 5},
        {"Pray For Me","he Weekend and K.Lamar", 4},
        {"The Middle","Zedd, Maren Morris & Grey",5},
        {"Wait","Maroone 5",4},
        {"Whatever It Takes","Imagine Dragons",3},
    };

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    // std::cout << "To be implemented\n";
    // Your program logic goes here

    char selection{};
    do{
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);
        if(selection == 'F'){
            std::cout << "Playing first song\n";
            current_song = playlist.begin();
            play_current_song(*current_song);
        } else if (selection == 'N'){
            std::cout << "Playing next song\n";
            current_song++;
            if(current_song == playlist.end()){
                std::cout << "Wrapping to start of playlist\n";
                current_song = playlist.begin();
            }
            play_current_song(*current_song);
        } else if (selection == 'P'){
            std::cout << "Playing previous song\n";
            
            if(current_song == playlist.begin()){
                std::cout << "Wrapping to end of playlist\n";
                current_song = playlist.end();
            }
            current_song--;
            play_current_song(*current_song);
        } else if (selection == 'A') {
            std::string name, artist;
            int rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Adding and playing new song\n";
            std::cout << "Enter song name: ";
            getline(std::cin, name);
            std::cout << "Enter song artist: ";
            getline(std::cin, artist);
            std::cout << "Enter your rating (1-5): ";
            std::cin >> rating;
            playlist.insert(current_song, Song{name,artist,rating});
            current_song--;
            play_current_song(*current_song);
        } else if (selection == 'L'){
            std::cout << std::endl;
            display_playlist(playlist, * current_song);
        } else if (selection == 'Q'){
            std::cout << "Quitting\n";
        } else {
             std::cout << "Illegal choice, try again...\n";
        }
    } while (selection != 'Q');

    std::cout << "Thanks for listening\n";
    return 0;
}