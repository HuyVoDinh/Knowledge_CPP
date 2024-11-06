#ifndef __MOVIE_H__
#define __MOVIE_H__

#include <vector>
#include <string>
#include <iostream>

class Movie{
    private:
        std::string name;
        std::string rating;
        int watched;
    public:
        Movie(std::string name_val, std::string rating_val, int watched_val);
        Movie(const Movie& movie);
        ~Movie();
        std::string get_name() const;
        int increment_watched();
        void display() const;
};
#endif