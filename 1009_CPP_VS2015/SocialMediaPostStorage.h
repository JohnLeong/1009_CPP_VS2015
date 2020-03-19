#pragma once
#ifndef SOCIAL_MEDIA_POST_STORAGE_H
#define SOCIAL_MEDIA_POST_STORAGE_H
#define SOCIAL_MEDIA_POST_STORAGE_NAMESPACE_START namespace ICT1009 { namespace DataStorage {
#define SOCIAL_MEDIA_POST_STORAGE_NAMESPACE_END } }

#include "SocialMediaPost.h"
#include "InstagramPost.h"

using std::vector;

SOCIAL_MEDIA_POST_STORAGE_NAMESPACE_START
class SocialMediaPostStorage
{	
	typedef std::shared_ptr<SocialMediaPost> SocialMediaPostPtr;
	/*	
		PV = private
		PRT = protected
		Syntax: 
		PV_GET_SET(attribute, ClassName, variableName, VariableGetSetName)
	*/
	PV_GET_SET(string, SocialMediaPostStorage, scrapeTarget, ScrapeTarget)				//Profile Name or HashTag name
	PV_GET_SET(string, SocialMediaPostStorage, targetVisibility, TargetVisibility)		//Whether person's profile/hashtag page is viewable/private/unavailable
	PV_GET_SET(string, SocialMediaPostStorage, targetDescription, TargetDescription)	//Profile description
	PV_GET_SET(unsigned int, SocialMediaPostStorage, postsCount, PostsCount)			//Number of post count
	PV_GET_SET(unsigned int, SocialMediaPostStorage, followersCount, FollowersCount)	//Number of followers
	PV_GET_SET(unsigned int, SocialMediaPostStorage, followingCount, FollowingCount)	//Number of following
	PV_GET_SET(vector<SocialMediaPostPtr>, SocialMediaPostStorage, postList, PostList)	//Vector to store all posts	

public:
			
	SocialMediaPostStorage();
	~SocialMediaPostStorage();

	bool addPost(SocialMediaPostPtr post);
	json getProfileJson();
	

		
};

SOCIAL_MEDIA_POST_STORAGE_NAMESPACE_END
#endif