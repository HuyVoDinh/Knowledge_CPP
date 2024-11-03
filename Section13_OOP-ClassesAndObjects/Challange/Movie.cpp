#include "Movie.h"

Movie::Movie(std::string name_val, std::string rating_val, int watched_val) : name{name_val}, rating{rating_val}, watched {watched_val}{
}

Movie::Movie(const Movie &movie) : name{movie.name}, rating{movie.rating}, watched {movie.watched}{
}

Movie::~Movie(){

}

std::string Movie::get_name() const{
    return name;
}

int Movie::increment_watched(){
    return 0;
}

void Movie::display() const{
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}