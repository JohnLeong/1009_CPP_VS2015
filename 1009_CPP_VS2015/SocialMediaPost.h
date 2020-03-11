#pragma once
#ifndef SOCIAL_MEDIA_POST_H
#define SOCIAL_MEDIA_POST_H

#include <string>
#include <vector>
#include "SocialMediaComment.h"

using std::string;
using std::vector;

namespace ICT1009
{
	namespace DataStorage
	{
		class SocialMediaPost
		{
		private:
			unsigned int likes;							//The number of likes this post has
			string caption;								//The caption of this post
			string postedBy;							//The username of the person who made this post
			vector<SocialMediaComment>* commentList;	//The list of all the comments on this post
			//Date date;
			
		public:
			SocialMediaPost();
			~SocialMediaPost();

			vector<string> getHashtags();
			bool addComment(SocialMediaComment comment);

			unsigned int getLikes();
			string getCaption();
			string getPostedBy();
			vector<SocialMediaComment>* getComments();

			void setLikes(unsigned int likes);
			void setPostedBy(string postedBy);
			void setCaption(string caption);
		};
	}
}

#endif