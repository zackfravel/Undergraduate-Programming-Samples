#include "Song.h"

    // Constructors
    Song::Song()
    {
        mTitle      = "(no title)";
        mComposer   = "(no composer)";
        mArtist     = "(no artist)";
        mPath       = "C:\\";
        mAlbum      = "(no album)";
        mYear       = 1900;
        mGenre      = ROCK;
        mFormat     = MP3;
    }
    
    Song::Song(const string& title, const string& composer, const string& artist, const string& path, 
        const string& album, const unsigned int year, const Genre genre, const Format format)
    {
        mTitle      = title;
        mComposer   = composer;
        mArtist     = artist;
        mPath       = path;
        mAlbum      = album;
        mYear       = year;
        mGenre      = genre;
        mFormat     = format;
    }
            
    
    // Getters
    string Song::getTitle() const
    {
        return mTitle;
    }
    
    string Song::getComposer() const
    {
        return mComposer;
    }
    
    string Song::getArtist() const
    {
        return mArtist;
    }
    
    string Song::getPath() const
    {
        return mPath;
    }
    
    string Song::getAlbum() const
    {
        return mAlbum;
    }
    
    unsigned int Song::getYear() const
    {
        return mYear;
    }
    
    Genre Song::getGenre() const
    {
        return mGenre;
    }
    
    Format Song::getFormat() const
    {
        return mFormat;
    }
    
    
    // Setters
    void Song::setTitle(const string& title)
    {
        mTitle = title;
    }
    
    void Song::setComposer(const string& composer)
    {
        mComposer = composer;
    }
    
    void Song::setArtist(const string& artist)
    {
        mArtist = artist;
    }
    
    void Song::setPath(const string& path)
    {
        mPath = path;
    }
    
    void Song::setAlbum(const string& album)
    {
        mAlbum = album;
    }
    
    void Song::setYear(const unsigned int year)
    {
        mYear = year;
    }
    
    void Song::setGenre(const Genre genre)
    {
        mGenre = genre;
    }
    
    void Song::setFormat(const Format format)
    {
        mFormat = format;
    }