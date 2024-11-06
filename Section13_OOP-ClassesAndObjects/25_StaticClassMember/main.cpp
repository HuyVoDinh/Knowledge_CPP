#include <iostream>
#include "Player.h"
using namespace std;

void display_active_player(){
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main(){
    display_active_player();            // call display active players and display active players is simply going to ask the player class to get the number of players. At this point we have none.
    Player hero{"Hero"};
    display_active_player();            

    {
        Player frank {"Frank"};
        display_active_player();  
    }
    display_active_player();  // destructor will be called. It display 1

    Player *enemy = new Player("Enemy", 100,100);   //create enemy object on the heap since it's a dynamic allocation.
    display_active_player();  //display 2
    delete enemy;           
    display_active_player();  
    return 0;
}