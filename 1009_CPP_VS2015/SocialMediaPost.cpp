#include "SocialMediaPost.h"

namespace ICT1009
{
	namespace DataStorage
	{
		SocialMediaPost::SocialMediaPost()
			: likes(0), caption(""), commentList(new vector<SocialMediaComment>())
		{
		}

		SocialMediaPost::~SocialMediaPost()
		{
			delete commentList;
		}

		vector<string> SocialMediaPost::getHashtags()
		{
			vector<string> hashtagList;

			return hashtagList;
		}

		bool SocialMediaPost::addComment(SocialMediaComment comment)
		{
			commentList->push_back(comment);
			return true;
		}

		unsigned int SocialMediaPost::getLikes()
		{
			return likes;
		}

		string SocialMediaPost::getCaption()
		{
			return caption;
		}

		string SocialMediaPost::getPostedBy()
		{
			return postedBy;
		}

		vector<SocialMediaComment>* SocialMediaPost::getComments()
		{
			return commentList;
		}

		void SocialMediaPost::setLikes(unsigned int likes)
		{
			this->likes = likes;
		}

		void SocialMediaPost::setPostedBy(string postedBy)
		{
			this->postedBy = postedBy;
		}

		void SocialMediaPost::setCaption(string caption)
		{
			this->caption = caption;
		}
	}
}