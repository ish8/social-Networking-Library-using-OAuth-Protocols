//
//  WBFBUserActions.h
//  SocialAppWorkBench
//
//  Created by Ishani on 6/27/14.
//  Copyright (c) 2014 Ishani. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WBAccessFacebook.h"
#import "WBTwitterConnect.h"
#import "WBAccessLinkedIn.h"

@interface WBFBUserActions : UIViewController<UITextViewDelegate,WBSocialFBResponseDelegate,WBSocialTwitterResponseDelegate,WBSocialLinkedInResponseDelegate>
@property (weak, nonatomic) IBOutlet UILabel *welcomeUserLbl;
@property (weak, nonatomic) IBOutlet UITextView *shareText;
@property (weak, nonatomic) IBOutlet UITextView *feedsTextView;
@property (weak, nonatomic) IBOutlet UITextField *FeedsNumber;

- (IBAction)clickShare:(id)sender;
- (IBAction)fetchFeeds:(id)sender;

@end
