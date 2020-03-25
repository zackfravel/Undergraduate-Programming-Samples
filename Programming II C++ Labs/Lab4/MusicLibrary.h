#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include <vector>
#include <iostream>
#include "Song.h"
#include "utility.h"
using namespace std;

class MusicLibrary 
{
public:
    // Constructors
    MusicLibrary();
    //MusicLibrary(const string& filename);
   
    // Methods
    bool add(Song s);
    //bool remove(Song s);
    bool remove(int index);
    void print() const;
    //bool save() const;
    
private:
    
    // Data members
    vector<Song> mLibrary;
    string mOwner;
    string mFilename;
};

#endif /* MUSICLIBRARY_H */