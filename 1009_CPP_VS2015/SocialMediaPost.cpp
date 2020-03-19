#include "SocialMediaPost.h"

namespace ICT1009
{
	namespace DataStorage
	{
		SocialMediaPost::SocialMediaPost()
			: likes(0), caption(""), postedBy("")
		{
			//commentList(new vector<SocialMediaComment>())
		}

		SocialMediaPost::~SocialMediaPost()
		{
			//delete commentList;
		}

		vector<string> SocialMediaPost::getHashtags()
		{
			vector<string> hashtagList;

			return hashtagList;
		}

		bool SocialMediaPost::addComment(SocialMediaPost::SocialMediaCommentPtr comment)
		{
			commentList.push_back(comment);
			return true;
		}

		
		json SocialMediaPost::getPostJson()
		{
			json j;
			return j;
		}


		void SocialMediaPost::printAttributes() 
		{
			using std::cout; using std::endl;
			cout << "---SocialMediaPost Attributes---" << endl;
			cout << "Likes: " << this->likes << endl;
			cout << "Caption: " << this->caption << endl;
			cout << "PostedBy: " << this->postedBy << endl;
			for (std::size_t i = 0; i < this->commentList.size(); this->commentList[i++]->printAttributes());
		}
	}
}