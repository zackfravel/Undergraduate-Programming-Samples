#include "MusicLibrary.h"

// Constructors
    MusicLibrary::MusicLibrary()
    {
        mOwner      = "nobody";
        mFilename   = "";
    }
    
    //MusicLibrary(const string& filename)
   
// Methods
    bool MusicLibrary::add(Song s)
    {
        bool foundSong = false;
        for(int i=0; i < mLibrary.size(); i++)
        {
            if(s.getTitle() == mLibrary[i].getTitle())
            {
                foundSong = true;
            }
        }
        
        if(foundSong)
        {
            return false;
        }
        
        mLibrary.push_back(s);
        return true;
    }
    
    //bool MusicLibrary::remove(Song s);
    
    bool MusicLibrary::remove(int index)
    {
        if(index < 0 || index >= mLibrary.size())
        {
            return false;
        }
        else
        {
            mLibrary.erase(mLibrary.begin()+index);
            return true;
        }
    }
    
    void MusicLibrary::print() const
    {
        for(int j = 0; j < mLibrary.size(); j++)
        {
            cout << mLibrary[j] << endl;
        }
    }
    
    //bool MusicLibrary::save() const;