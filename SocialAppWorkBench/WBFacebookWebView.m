//
//  WBFacebookWebView.m
//  SocialAppWorkBench
//
//  Created by Ishani on 6/27/14.
//  Copyright (c) 2014 Ishani. All rights reserved.
//

#import "WBFacebookWebView.h"
#import "WBAccessFacebook.h"
#import "WBFBUserActions.h"
#import "WBAppDelegate.h"
#import "WBAccessLinkedIn.h"


@interface WBFacebookWebView ()

@end

@implementation WBFacebookWebView
{
    WBAccessFacebook *accessFb;
    WBTwitterConnect *accessTwitter;
    WBAccessLinkedIn *accessLinkedIn;
    NSString *accessTokenReceived;
    WBAppDelegate *delegate;
}
@synthesize fbWebView;
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    delegate = [[UIApplication sharedApplication]delegate];
    if(delegate.socialType == 1)
    {
        accessFb = [WBAccessFacebook getInstance];
        [accessFb setDelegate:self];
        [accessFb initiateFacebookLogin:fbWebView];
    }
    else if (delegate.socialType == 3)
    {
        accessTwitter = [WBTwitterConnect getInstance];
        [accessTwitter setDelegate:self];
        [accessTwitter twitterLogin:fbWebView];
    }
    else if (delegate.socialType == 2)
    {
        accessLinkedIn = [WBAccessLinkedIn getInstance];
        [accessLinkedIn setDelegate:self];
        [accessLinkedIn initiateLinkedInLogin:fbWebView];
    }
//    else if (delegate.socialType == 4)
//    {
//        [self.fbWebView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://10.203.238.196:9001/snf/"]]];
//    }
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//delegate Methods for Facebook Delegate
-(void)actionOnSuccessLogin
{
            UIStoryboard *mainStoryboard = [UIStoryboard storyboardWithName:@"Main_iPhone" bundle:nil];
            WBFBUserActions *vc = (WBFBUserActions*)[mainStoryboard instantiateViewControllerWithIdentifier:@"WBFBUserActions"];
            [self presentViewController:vc animated:YES completion:nil];
}



//delegate Methods for Twitter successful login
-(void)actionOnSuccessLoginTwitter
{
    UIStoryboard *mainStoryboard = [UIStoryboard storyboardWithName:@"Main_iPhone" bundle:nil];
    WBFBUserActions *vc = (WBFBUserActions*)[mainStoryboard instantiateViewControllerWithIdentifier:@"WBFBUserActions"];
    [self presentViewController:vc animated:YES completion:nil];
}



@end
