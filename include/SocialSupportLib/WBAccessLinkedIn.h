//
//  WBAccessLinkedIn.h
//  SocialAppWorkBench
//
//  Created by Ishani on 7/4/14.
//  Copyright (c) 2014 Ishani. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol WBSocialLinkedInLoginDelegate
- (void)actionOnSuccessLogin;
@end

@protocol WBSocialLinkedInResponseDelegate
- (void)getUserInfo:(NSString*)userName;
- (void)fetchingLinkedInFeeds:(NSDictionary*)dict;
- (void)postOnUserWall:(BOOL)successfully;
@end

@interface WBAccessLinkedIn : NSObject<UIWebViewDelegate,NSURLConnectionDataDelegate,NSURLConnectionDelegate>
{
    id<WBSocialLinkedInLoginDelegate> delegate;
    id<WBSocialLinkedInResponseDelegate> delegateUserActions;
}

@property (nonatomic,retain) id<WBSocialLinkedInLoginDelegate> delegate;
@property (nonatomic,retain) id<WBSocialLinkedInResponseDelegate> delegateUserActions;
@property (nonatomic,retain) NSString* userNameS;
@property (nonatomic,strong) NSString *accessTokenString;

+ (WBAccessLinkedIn *) getInstance;

- (NSString *)intWithAppID:(NSString *)apiKey requestedScope:(NSString *)scope applicationState:(NSString*)state appRedirectURL:(NSString*)url;
- (NSString *)checkForAccessToken:(NSString *)urlString;
- (NSString *)checkForOauthCode: (NSString *)urlString;
- (void)initiateLinkedInLogin:(UIWebView *)webView;
- (void)requestAccessToken;
- (void)fetchUserInformation;
- (void)fetchFeeds;
- (void)shareWallPost:(NSString *)messagePost;

@end
