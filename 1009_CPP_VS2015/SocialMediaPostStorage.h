#pragma once
#ifndef SOCIAL_MEDIA_POST_STORAGE_H
#define SOCIAL_MEDIA_POST_STORAGE_H

#include "SocialMediaPost.h"
#include <vector>

using std::vector;

namespace ICT1009
{
	namespace DataStorage
	{
		class SocialMediaPostStorage
		{
		private:
			string scrapeTarget;
			vector<SocialMediaPost> postList;

		public:
			SocialMediaPostStorage();
			~SocialMediaPostStorage();

			bool addPost(SocialMediaPost post);

			string getScrapeTarget();

			void setScrapeTarget(string scrapeTarget);
		};

	}
}

#endif