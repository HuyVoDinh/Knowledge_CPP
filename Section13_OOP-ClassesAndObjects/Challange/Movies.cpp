#include <iostream>
#include "28_Movies.h"

/**********************************************************************************
    Movies no-args constructor
**********************************************************************************/

Movies::Movies(){
    Movie movie1 {"Big", "PG-13",2};
    Movie movie2 {"Star Wars", "PG",5};
    Movie movie3 {"Cinderella", "PG",2};
    movies.push_back(movie1);
    movies.push_back(movie2);
    movies.push_back(movie3);
}

/**********************************************************************************
 * Movies destructor
**********************************************************************************/
Movies::~Movies(){

}

/**********************************************************************************
 * add_movie expects the name of the move, rating and watched count
 * 
 * It will search the movies vector to see if a movie object already exists with the same name
 * 
 * If it does then return false since the movie already exists
 * Otherwise, create a movie object from the provided information and add that movie object to the movies vector and return true
**********************************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched){
    for(Movie const &movie : movies){          // the loop, that collection or iterating through that collection,/ It's not going to modify the collection. And I want to be sure that it doesn't modify the collection.  This will do that right because these are all returned by copy, but it's not very efficient. So what I'd rather do is change this  to a reference. But if i just leave it as a reference, then this could potentially change it. So I really want to make this a const. So I want this to be a reference to a const movie at each iteration. So if I try to change it by accident or by mistake or even intentionally => Compiler error.
        if(movie.get_name() == name){
            return false;
        }
    }
    Movie temp {name, rating, watched};
    movies.push_back(temp);
    return true;
}

/**********************************************************************************
 * increment_watched expects the name of the move to increment the watched count
 * 
 * It will search the movies vector to see if a movie object already exists with the same name
 * If it does then increment that objects watched by 1 and return true
 * 
 * Otherwise, return false since then no movies object with the movie name provided exists to increment
**********************************************************************************/

bool Movies::increment_watched(std::string name){
    for(Movie &movie : movies){
        if(movie.get_name() == name){
            movie.increment_watched();
            return true;
        }
    }
    return false;
}


/**********************************************************************************
 * Display
 * 
 * Display all the movie objects in the movies vector for each movie call the movie.display method so the movie object displays itself
**********************************************************************************/

void Movies::display() const{
    if(movies.size() == 0){
        std::cout << "Sorry, no movies to display\n";
    } else {
        std::cout << "\n==============================================\n";
        for(const auto &movie : movies){
            movie.display();
        }
        std::cout << "\n==============================================\n";
    }
}