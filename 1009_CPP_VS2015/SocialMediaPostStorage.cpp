#include "SocialMediaPostStorage.h"


SOCIAL_MEDIA_POST_STORAGE_NAMESPACE_START

typedef std::shared_ptr<SocialMediaPost> SocialMediaPostPtr;

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

nlohmann::json SocialMediaPostStorage::getPostJson(const int platform) 
{
	nlohmann::json posts;

	if (platform == 0) 		
		for (size_t i = 0; i < postList.size(); posts.push_back(postList[i++]->getPostJson()));
		
	return posts;
}
nlohmann::json SocialMediaPostStorage::getTargetJson(const int platform, const int mode)
{
	nlohmann::json target;
	if (platform == PLATFORM_INSTAGRAM) {
		if (mode == SCRAPE_MODE_HASHTAG) {
			target["hash_tag"] = this->scrapeTarget;
			target["hash_tag_is_valid"] = this->targetVisibility;
			if (this->targetVisibility != "valid")
				return target;

			target["total_posts"] = this->postsCount;
			target["extracted_posts"] = getPostJson(platform);			
		} else if (mode == SCRAPE_MODE_PROFILE) {
			target["profile_name"] = this->scrapeTarget;
			target["profile_is_viewable"] = this->targetVisibility;
			if (this->targetVisibility != "viewable")
				return target;

			target["profile_description"] = this->targetDescription;
			target["no_of_posts"] = this->postsCount;
			target["no_of_followers"] = this->followersCount;
			target["no_of_following"] = this->followingCount;
			target["extracted_posts"] = getPostJson(platform);
		}

	} else if (platform == PLATFORM_TWITTER) {

	}

	return target;
	
}

vector<SocialMediaPostPtr>* SocialMediaPostStorage::getPostListPtr()
{
	return &postList;
}
SOCIAL_MEDIA_POST_STORAGE_NAMESPACE_END
