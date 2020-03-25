#include "utility.h"

ostream & operator<<(ostream& out, const Song& s)
{
    out << s.getTitle()    << ',';
    out << s.getComposer() << ',';
    out << s.getArtist()   << ',';
    out << s.getPath()     << ',';
    out << s.getAlbum()    << ',';
    out << s.getYear()     << ',';
    out << s.getGenre()    << ',';
    out << s.getFormat();
	
    return out;
}

// overload >> here for homework 2