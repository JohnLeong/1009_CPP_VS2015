#include "SocialMediaPostStorage.h"
#ifndef SOCIAL_MEDIA_POST_STORAGE_CPP
#define SOCIAL_MEDIA_POST_STORAGE_CPP

SOCIAL_MEDIA_POST_STORAGE_NAMESPACE_START
SocialMediaPostStorage::SocialMediaPostStorage()
	: scrapeTarget(""), targetVisibility(""), targetDescription(""),
	postsCount(0), followersCount(0), followingCount(0)
{
}

SocialMediaPostStorage::~SocialMediaPostStorage()
{

}

bool SocialMediaPostStorage::addPost(SocialMediaPostPtr post)
{
	postList.push_back(post);
	return true;
}
json SocialMediaPostStorage::getProfileJson() 
{
	json profile;
	profile["profile_name"] = this->scrapeTarget;
	profile["profile_is_viewable"] = this->targetVisibility;
	if (this->targetVisibility != "viewable")
		return profile;

	json posts;
	for (size_t i = 0; i < postList.size(); posts.push_back(postList[i++]->getPostJson()));	
	profile["profile_description"] = this->targetDescription;
	profile["no_of_posts"] = this->postsCount;
	profile["no_of_followers"] = this->followersCount;
	profile["no_of_following"] = this->followingCount;
	profile["extracted_posts"] = posts;
	return profile;
}
SOCIAL_MEDIA_POST_STORAGE_NAMESPACE_END
#endif