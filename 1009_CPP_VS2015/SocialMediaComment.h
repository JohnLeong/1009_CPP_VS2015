#pragma once
#ifndef SOCIAL_MEDIA_COMMENT_H
#define SOCIAL_MEDIA_COMMENT_H
#define SOCIAL_MEDIA_COMMENT_NAMESPACE_START namespace ICT1009 { namespace DataStorage {
#define SOCIAL_MEDIA_COMMENT_NAMESPACE_END } }

#include <string>
#include <iostream>
#define nullptr __nullptr
#include "json.hpp"
#undef nullptr
#include "macros.h"


using nlohmann::json;
using std::string;

SOCIAL_MEDIA_COMMENT_NAMESPACE_START
class SocialMediaComment
{
	PV_GET_SET(string, SocialMediaComment, commentBy, CommentBy)
	PV_GET_SET(string, SocialMediaComment, comment, Comment)

public:
	SocialMediaComment();
	~SocialMediaComment();
	void printAttributes();
	json getCommentJson();
};
SOCIAL_MEDIA_COMMENT_NAMESPACE_END
#endif