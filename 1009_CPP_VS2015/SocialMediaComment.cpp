#include "SocialMediaComment.h"

#ifndef SOCIAL_MEDIA_COMMENT_CPP
#define SOCIAL_MEDIA_COMMENT_CPP
SOCIAL_MEDIA_COMMENT_NAMESPACE_START

SocialMediaComment::SocialMediaComment()
	:commentBy(""), comment("")
{
}

SocialMediaComment::~SocialMediaComment()
{

}		

void SocialMediaComment::printAttributes() 
{
	using std::cout; using std::endl;
	if (this->commentBy != "" && this->comment != "") {
		cout << "---Comment---" << endl;
		cout << "Comment By: " << endl;
		cout << "Comment: " << endl;
	} else {
		cout << "--Empty Comment---" << endl;
	}
}

json SocialMediaComment::getCommentJson()
{
	//PV_GET_SET(string, SocialMediaComment, commentBy, CommentBy)
	//	PV_GET_SET(string, SocialMediaComment, comment, Comment)
	json commentDetails;
	if (commentBy == "" && comment == "") 
		commentDetails = json::object({});
	else 
		commentDetails = json::object({ {"user",commentBy}, {"desc", comment} });	
	return commentDetails;
}

SOCIAL_MEDIA_COMMENT_NAMESPACE_END
#endif