#include "SocialMediaPost.h"

SOCIAL_MEDIA_POST_NAMESPACE_START
SocialMediaPost::SocialMediaPost()
	: likes(0), caption(""), postedBy("")
{
}

SocialMediaPost::~SocialMediaPost()
{
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

		
nlohmann::json SocialMediaPost::getPostJson()
{
	nlohmann::json j;
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

SOCIAL_MEDIA_COMMENT_NAMESPACE_END