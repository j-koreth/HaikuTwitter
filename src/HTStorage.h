/*
 * Copyright 2010-2012 Martin Hebnes Pedersen, martinhpedersen @ "google mail"
 * All rights reserved. Distributed under the terms of the MIT License.
 */ 

#ifndef HT_STORAGE_H
#define HT_STORAGE_H

#include <string>
#include <Path.h>

class HTTweet;

#define HAIKUTWITTER_ATTR_ID          "HaikuTwitter:id"          // Tweet id
#define HAIKUTWITTER_ATTR_FULLNAME    "HaikuTwitter:fullname"    // Full name of author
#define HAIKUTWITTER_ATTR_SCREENNAME  "HaikuTwitter:screenname"  // Screen name (twitter username) of author
#define HAIKUTWITTER_ATTR_WHEN        "HaikuTwitter:when"        // Time & date tweet was created
#define HAIKUTWITTER_ATTR_TEXT        "HaikuTwitter:text"        // The tweet's content
#define HAIKUTWITTER_ATTR_IMAGEURL    "HaikuTwitter:imageurl"    // URL to author's profile image
#define HAIKUTWITTER_ATTR_SOURCE      "HaikuTwitter:source"      // Name of tweet's source (Application)
#define HAIKUTWITTER_CACHE_IMAGE      "HaikuTwitter:cache:image" // Raw image data
#define HAIKUTWITTER_CACHE_IMAGE_SIZE "HaikuTwitter:cache:size"  // Size of image data

#define CACHE_EXPIRE_TIME 7*24*3600 // Bitmap cache expire time

class HTStorage {
public:
			static status_t         saveTweet(HTTweet*);
			static HTTweet*         loadTweet(entry_ref* ref);
			
			static status_t         cacheBitmap(BMallocIO* bitmapData, std::string& url);
			static status_t         findBitmap(std::string& url, BMallocIO** buffer);
			static status_t         cleanupBitmapCache();

			
			static void             makeMimeType(bool remakeMIMETypes);
			static void             makeIndices();
			
private:
			static status_t         getTweetPath(BPath&);
			static status_t         getCachePath(BPath&);
			static void             addAttribute(BMessage& msg, const char* name, const char* publicName, int32 type = B_STRING_TYPE, 
										bool viewable = true, bool editable = false, int32 width = 200);
			static unsigned int     FNVHash(const std::string& str);
};


#endif // HT_STORAGE_H
