#pragma once
#ifndef TWITTER_POST_H
#define TWITTER_POST_H

#include "SocialMediaPost.h"

namespace ICT1009
{
	namespace DataStorage
	{
		class TwitterPost : public SocialMediaPost
		{
		private:
			unsigned int retweets;

		public:
			TwitterPost();
			~TwitterPost();

			unsigned int getRetweets();

			void setRetweets(unsigned int retweets);
		};
	}
}
#endif