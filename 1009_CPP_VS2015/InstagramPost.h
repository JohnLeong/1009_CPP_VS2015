#pragma once
#ifndef INSTAGRAM_POST_H
#define INSTAGRAM_POST_H
#define INSTAGRAM_POST_NAMESPACE_START namespace ICT1009 { namespace DataStorage {
#define INSTAGRAM_POST_NAMESPACE_END } }

#include "SocialMediaPost.h"
INSTAGRAM_POST_NAMESPACE_START
class InstagramPost : public SocialMediaPost
{
public:
	
	enum PostType
	{
		IMAGE,
		VIDEO
	};
	/*	------------Reference-----------
		Json fields		Located
		postedBy		SocialMediaPost
		caption  		SocialMediaPost
		no_of_likes   	SocialMediaPost
		commentList		SocialMediaPost
		post_url			InstagramPost
		display_image_url	InstagramPost
		no_of_comments		InstagramPost
		is_video			InstagramPost
		no_of_video_views	InstagramPost
		date_time			InstagramPost
		location			InstagramPost
	*/

	PV_GET_SET(string, InstagramPost, postUrl, PostUrl)					//Post link
	PV_GET_SET(string, InstagramPost, imageUrl, ImageUrl)					// Post image url for downloading ltr
	PV_GET_SET(unsigned int, InstagramPost, commentsCount, CommentsCount)	//No of comments
	PV_GET_SET(PostType, InstagramPost, type, Type)						//IsVideo
	PV_GET_SET(unsigned int, InstagramPost, videoViews, VideoViews)		//Number of video views will be 0 if post is image
	PV_GET_SET(string, InstagramPost, timeStamp, TimeStamp)				//Datetime
	PV_GET_SET(string, InstagramPost, location, Location)					//location
	
public:
	InstagramPost();
	~InstagramPost();
	void printAttributes();
	json getPostJson();
};

INSTAGRAM_POST_NAMESPACE_END
#endif