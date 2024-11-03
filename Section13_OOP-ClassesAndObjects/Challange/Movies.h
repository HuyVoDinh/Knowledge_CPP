#ifndef __MOVIES_H__
#define __MOVIES_H__

#include "Movie.h"
#include <vector>
#include <string>


class Movies{
    private:
        std::vector<Movie> movies;
    public:
        Movies();           // Constructor
        ~Movies();          // Destructor
        /******************************************************
        add_movie expects the name of the move, rating and watched count

        It will search the movies vector to see if a movie object already exists with the same name.

        If it does then return false since the movie already exists
        Otherwise, create a movie object to the movies vector and return true
        ******************************************************/
        bool add_movie(std::string name, std::string rating, int watched);
        
        /******************************************************
        increment_watched expects the name of the move to increment the watched count

        It will search the movies vector to see if a movie object already exists wit h the same name. 
        If it does then increment that objects watched by 1 and return true.  

        Otherwise, return false since then no movies object with the movie name provided exists to increment
        
        ******************************************************/

        bool increment_watched(std::string name);
        
        /******************************************************
        display

        display all  the movie objects in the movies vector.  
        for each movie call the movie.display method so he movie object displays itself
        ******************************************************/

       void display() const;
};

#endif