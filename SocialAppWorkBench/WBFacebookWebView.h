//
//  WBFacebookWebView.h
//  SocialAppWorkBench
//
//  Created by Ishani on 6/27/14.
//  Copyright (c) 2014 Ishani. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WBAccessFacebook.h"
#import "WBTwitterConnect.h"
#import "WBAccessLinkedIn.h"

@interface WBFacebookWebView : UIViewController<WBSocialFBLoginDelegate,WBSocialTwitterLoginCompleteDelegate,WBSocialLinkedInLoginDelegate>

@property (weak, nonatomic) IBOutlet UIWebView *fbWebView;

@end
