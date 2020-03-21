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



SOCIAL_MEDIA_COMMENT_NAMESPACE_START
class SocialMediaComment
{
	PV_GET_SET(std::string, SocialMediaComment, commentBy, CommentBy)
	PV_GET_SET(std::string, SocialMediaComment, comment, Comment)

public:
	SocialMediaComment();
	~SocialMediaComment();
	void printAttributes();
	nlohmann::json getCommentJson();
};
SOCIAL_MEDIA_COMMENT_NAMESPACE_END
#endif