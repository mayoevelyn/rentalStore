//-----------------------------------------------------------------------------
// Title:            Media class
// Files:            media.h
//-----------------------------------------------------------------------------
// Media class: An interface for a media item.
//-----------------------------------------------------------------------------

#ifndef MEDIA_H
#define MEDIA_H

class Media {
public:
  // constructor
  Media(char mediaType = "");
  // mutator function
  static Media* makeMedia(char mediaType);
  
protected:
  // holds the type of media
  char mediaType;
};

#endif
