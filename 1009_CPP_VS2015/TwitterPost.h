#pragma once
#ifndef TWITTER_POST_H
#define TWITTER_POST_H
#define TWITTER_POST_NAMESPACE_START namespace ICT1009 { namespace DataStorage {
#define TWITTER_POST_NAMESPACE_END }}
#include "SocialMediaPost.h"

TWITTER_POST_NAMESPACE_START
class TwitterPost : public SocialMediaPost
{
	PV_GET_SET(unsigned int, TwitterPost, retweets, Retweets)
public:
	TwitterPost();
	~TwitterPost();
};
TWITTER_POST_NAMESPACE_END
#endif