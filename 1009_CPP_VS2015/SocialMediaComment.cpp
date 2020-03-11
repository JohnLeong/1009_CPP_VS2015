#include "SocialMediaComment.h"

namespace ICT1009
{
	namespace DataStorage
	{
		SocialMediaComment::SocialMediaComment()
		{
		}

		SocialMediaComment::~SocialMediaComment()
		{

		}

		string SocialMediaComment::getPostedBy()
		{
			return postedBy;
		}

		string SocialMediaComment::getComment()
		{
			return comment;
		}

		void SocialMediaComment::setPostedBy(string postedBy)
		{
			this->postedBy = postedBy;
		}

		void SocialMediaComment::setComment(string comment)
		{
			this->comment = comment;
		}
	}
}