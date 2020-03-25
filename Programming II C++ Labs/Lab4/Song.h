#ifndef SONG_H
#define SONG_H

#include <iostream>
using namespace std;

// Declare the enums we will use
enum Genre {CLASSICAL, JAZZ, NEW_AGE, OPERA, POP, ROCK}; 
enum Format {MP3, WMA, WAV};

class Song 
{
public:
    // Constructors
    Song(); // called whenever no parameters are passed through
    Song(const string& title, const string& composer, const string& artist, const string& path, 
        const string& album, const unsigned int year, const Genre genre, const Format format);
            // called when these data members are passed through
    
    // Getters
    string getTitle() const;
    string getComposer() const;
    string getArtist() const;
    string getPath() const;
    string getAlbum() const;
    unsigned int getYear() const;
    Genre getGenre() const;
    Format getFormat() const;
    
    // Setters
    void setTitle(const string& title);
    void setComposer(const string& composer);
    void setArtist(const string& artist);
    void setPath(const string& path);
    void setAlbum(const string& album);
    void setYear(const unsigned int year);
    void setGenre(const Genre genre);
    void setFormat(const Format format);
    
private:
    
    // Data members
    string mTitle;
    string mComposer;
    string mArtist;
    string mPath;
    string mAlbum;
    unsigned int mYear;
    Genre mGenre;
    Format mFormat;
};

#endif /* SONG_H */