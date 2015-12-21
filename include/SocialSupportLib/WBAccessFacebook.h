//
//  WBAccessFacebook.h
//  SocialAppWorkBench
//
//  Created by Ishani on 6/27/14.
//  Copyright (c) 2014 Ishani. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol WBSocialFBLoginDelegate
-(void)actionOnSuccessLogin;

@end

@protocol WBSocialFBResponseDelegate

-(void)getUserInfo:(NSString*)userName;
-(void)fetchingFBFeeds:(NSDictionary*)dict;
-(void)postOnUserWall:(BOOL)successfully;
@end




@interface WBAccessFacebook : NSObject<UIWebViewDelegate,NSURLConnectionDataDelegate,NSURLConnectionDelegate>
{
    id<WBSocialFBLoginDelegate> delegate;
    id<WBSocialFBResponseDelegate> delegateUserActions;
}
+ (WBAccessFacebook *) getInstance;
@property (nonatomic,retain) id<WBSocialFBLoginDelegate> delegate;
@property (nonatomic,retain) id<WBSocialFBResponseDelegate> delegateUserActions;

@property (nonatomic,retain) NSString* userNameS;

@property (nonatomic,strong) NSString *accessTokenString;

- (void)shareWallPost:(NSString *)messagePost;

- (NSString *)intWithAppId:(NSString *)apiKey requestedPermissions:(NSString *)requestedPermissions;
-(NSString *)checkForAccessToken:(NSString *)urlString;

-(void)initiateFacebookLogin:(UIWebView *)webView;
-(void)fetchUserInformation;
-(void)fetchFeeds;


@end
