#pragma once
#ifndef SOCIAL_MEDIA_POST_H
#define SOCIAL_MEDIA_POST_H
#define SOCIAL_MEDIA_POST_NAMESPACE_START namespace ICT1009 { namespace DataStorage {
#define SOCIAL_MEDIA_POST_NAMESPACE_END }}

#include <vector>
#include <memory>
#include <ostream>
#include "SocialMediaComment.h"

using std::ostream;
using std::string;
using std::vector;

SOCIAL_MEDIA_POST_NAMESPACE_START
class SocialMediaPost
{
	typedef std::shared_ptr<SocialMediaComment> SocialMediaCommentPtr;

	PV_GET_SET(unsigned int, SocialMediaPost, likes, Likes)	//The number of likes this post has
	PV_GET_SET(string, SocialMediaPost, caption, Caption)	//The caption of this post
	PV_GET_SET(string, SocialMediaPost, postedBy, PostedBy)	//The username of the person who made this post

	//The list of all the comments on this post
	PRT_GET_SET(vector<SocialMediaCommentPtr>, SocialMediaPost, commentList, CommentList)


public:
	SocialMediaPost();
	~SocialMediaPost();

	vector<string> getHashtags();
	bool addComment(SocialMediaCommentPtr comment);	
	void printAttributes();
	virtual nlohmann::json getPostJson();
	
	friend ostream& operator<<(ostream& os, const SocialMediaPost& post);
};
SOCIAL_MEDIA_POST_NAMESPACE_END

#endif