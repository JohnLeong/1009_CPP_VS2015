#include "TwitterPost.h"


namespace ICT1009
{
	namespace DataStorage
	{
		TwitterPost::TwitterPost()
		{
		}

		TwitterPost::~TwitterPost()
		{

		}

		unsigned int TwitterPost::getRetweets()
		{
			return retweets;
		}

		void TwitterPost::setRetweets(unsigned int retweets)
		{
			this->retweets = retweets;
		}
	}
}