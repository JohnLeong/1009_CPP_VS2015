#include "SocialMediaPostStorage.h"

namespace ICT1009
{
	namespace DataStorage
	{
		SocialMediaPostStorage::SocialMediaPostStorage()
			: scrapeTarget("")
		{

		}

		SocialMediaPostStorage::~SocialMediaPostStorage()
		{

		}

		bool SocialMediaPostStorage::addPost(SocialMediaPost post)
		{
			postList.push_back(post);
			return true;
		}

		string SocialMediaPostStorage::getScrapeTarget()
		{
			return scrapeTarget;
		}

		void SocialMediaPostStorage::setScrapeTarget(string scrapeTarget)
		{
			this->scrapeTarget = scrapeTarget;
		}
	}
}