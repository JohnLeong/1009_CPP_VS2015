#pragma once
#ifndef INSTAGRAM_POST_H
#define INSTAGRAM_POST_H

#include <string>
#include "SocialMediaPost.h"

using std::string;

namespace ICT1009
{
	namespace DataStorage
	{
		class InstagramPost
		{
		public:
			enum PostType
			{
				IMAGE,
				VIDEO
			};

		private:
			string location;
			PostType postType;

		public:
			InstagramPost();

			string getLocation();
			PostType getPostType();

			void setLocation(string location);
			void setPostType(PostType postType);
		};
	}
}

#endif