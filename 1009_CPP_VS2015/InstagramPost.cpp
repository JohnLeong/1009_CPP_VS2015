#include "InstagramPost.h"

INSTAGRAM_POST_NAMESPACE_START

InstagramPost::InstagramPost()
	: postUrl(""), imageUrl(""), commentsCount(0), type(InstagramPost::PostType::IMAGE),
	videoViews(0), timeStamp(""), location(""), SocialMediaPost()
{
}

InstagramPost:: ~InstagramPost()
{
}

nlohmann::json InstagramPost::getPostJson()
{
	using json = nlohmann::json;

	json post;
	json jsonComments;
	for (int i = 0; i < this->commentList.size(); ++i) {
		jsonComments.push_back(this->commentList[i]->getCommentJson());
	}
	
	post = json::object({
		{ "caption", this->getCaption() },
		{ "post_url", postUrl },
		{ "display_image_url", imageUrl },
		{ "no_of_likes", this->getLikes() },
		{ "no_of_comments", commentsCount },
		{ "type", type == IMAGE ? "image" : "video" },
		{ "no_of_video_views", videoViews },
		{ "date_time", timeStamp },
		{ "location", location },
		{ "comments",jsonComments }
	});	
	return post;
}


void InstagramPost::printAttributes() 
{
	using std::cout; using std::endl;
	cout << "---InstagramPost Attributes---" << endl;
	cout << "PostUrl: " << this->postUrl << endl;
	cout << "ImageUrl: " << this->imageUrl << endl;
	cout << "CommentsCount: " << this->commentsCount << endl;
	cout << "Type: " << this->type << endl;
	cout << "VideoViews: " << this->videoViews << endl;
	cout << "TimeStamp: " << this->timeStamp << endl;
	cout << "Location: " << this->location << endl;
	cout << "Likes: " << this->getLikes() << endl;
	cout << "Caption: " << this->getCaption() << endl;
	cout << "PostedBy: " << this->getPostedBy()<< endl;
	for (std::size_t i = 0; i < this->commentList.size(); this->commentList[i++]->printAttributes());
}

INSTAGRAM_POST_NAMESPACE_END



