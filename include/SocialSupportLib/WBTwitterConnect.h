//
//  WBTwitterConnect.h
//  twitterTrial
//
//  Created by Ishani on 7/10/14.
//  Copyright (c) 2014 WorkBench. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WBToken.h"
#import "WBConsumer.h"

@protocol WBSocialTwitterLoginCompleteDelegate
-(void)actionOnSuccessLoginTwitter;

@end

@protocol WBSocialTwitterResponseDelegate

-(void)getTwitterUserInfo:(NSString*)userName;
-(void)fetchingTwitterFeeds:(NSDictionary*)dict;
-(void)postTweets:(BOOL)successfully;


@end


@interface WBTwitterConnect : NSObject<UIWebViewDelegate,NSURLConnectionDataDelegate,NSURLConnectionDelegate>
{
    // id<WBSocialTwitterLoginDelegate> delegate;
    WBConsumer* consumer;
    WBToken* requestToken;
    WBToken* accessToken;
}

+ (WBTwitterConnect *) getInstance;
@property (nonatomic,strong) WBToken* accessToken;
@property (weak, nonatomic) IBOutlet UIWebView *twitterWebviewTemp;
@property (nonatomic,retain) id<WBSocialTwitterLoginCompleteDelegate> delegate;
@property (nonatomic,retain) id<WBSocialTwitterResponseDelegate> delegateTwitterConnect;

-(void)twitterLogin:(UIWebView *)webView;
-(void)getUserProfileTwitter;
-(void)writeTweets:(NSString*)tweetMessage;
-(void)getTwitterFeeds;
@end
