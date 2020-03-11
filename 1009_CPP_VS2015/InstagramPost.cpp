#include "InstagramPost.h"


namespace ICT1009
{
	namespace DataStorage
	{
		InstagramPost::InstagramPost()
		{
		}

		string InstagramPost::getLocation()
		{
			return location;
		}

		InstagramPost::PostType InstagramPost::getPostType()
		{
			return postType;
		}

		void InstagramPost::setLocation(string location)
		{
			this->location = location;
		}

		void InstagramPost::setPostType(InstagramPost::PostType postType)
		{
			this->postType = postType;
		}
	}
}