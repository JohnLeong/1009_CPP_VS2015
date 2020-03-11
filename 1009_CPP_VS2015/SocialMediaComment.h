#pragma once
#ifndef SOCIAL_MEDIA_COMMENT_H
#define SOCIAL_MEDIA_COMMENT_H

#include <string>

using std::string;

namespace ICT1009
{
	namespace DataStorage
	{
		class SocialMediaComment
		{
		private:
			string postedBy;
			string comment;

		public:
			SocialMediaComment();
			~SocialMediaComment();

			string getPostedBy();
			string getComment();

			void setPostedBy(string postedBy);
			void setComment(string comment);
		};
	}
}
#endif