//
//  WBFBUserActions.m
//  SocialAppWorkBench
//
//  Created by Ishani on 6/27/14.
//  Copyright (c) 2014 Ishani. All rights reserved.
//

#import "WBFBUserActions.h"
#import "WBAccessFacebook.h"
#import "WBAppDelegate.h"

@interface WBFBUserActions ()

@end

@implementation WBFBUserActions
{
   WBAppDelegate *delegate;
    NSString *userAction;
    WBAccessFacebook *accessFb;
    WBTwitterConnect *twitterConnect;
    WBAccessLinkedIn *accessLinkedIn;
}
@synthesize welcomeUserLbl;
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
        [accessFb setDelegateUserActions:self];
        //[welcomeUserLbl setText:accessFb.userNameS];
        [accessFb fetchUserInformation];
        
    }
    else if (delegate.socialType == 3)
    {
        twitterConnect = [WBTwitterConnect getInstance];
        [twitterConnect setDelegateTwitterConnect:self];
        [twitterConnect getUserProfileTwitter];
    }
    else if (delegate.socialType == 2)
    {
        accessLinkedIn = [WBAccessLinkedIn getInstance];
        [accessLinkedIn setDelegateUserActions:self];
        [welcomeUserLbl setText:accessLinkedIn.userNameS];

    }
    
    
    
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)getUserInfo:(NSString*)userName
{
    [welcomeUserLbl setText:userName];
}

-(void)fetchingFBFeeds:(NSDictionary*)dict
{
    NSLog(@"Feeds fetched are : %@",dict);
}

-(void)fetchingLinkedInFeeds:(NSDictionary*)dict
{
    NSLog(@"Feeds fetched are : %@",dict);
}


-(void)postOnUserWall:(BOOL)successfully
{
    if(successfully)
    {
        UIAlertView *successPost = [[UIAlertView alloc]initWithTitle:@"Success" message:@"Your message has been successfully posted ." delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil,nil];
                    [successPost show];
    }
    [self.shareText setText:@""];
}

- (IBAction)clickShare:(id)sender {
    if(self.shareText.text != nil) {
        if(delegate.socialType == 1)
        {
            [accessFb shareWallPost:[NSString stringWithFormat:@"%@",self.shareText.text]];
        }
        else if (delegate.socialType == 2)
        {
            [accessLinkedIn shareWallPost:[NSString stringWithFormat:@"%@",self.shareText.text]];
        }
    }
    else
    {
        UIAlertView *blankPost = [[UIAlertView alloc]initWithTitle:@"Alert" message:@"Message cannot be blank ." delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil,nil];
        [blankPost show];
    }
}

- (IBAction)fetchFeeds:(id)sender {
    if (delegate.socialType == 1)
        [accessFb fetchFeeds];
    else if (delegate.socialType == 3)
        [twitterConnect getTwitterFeeds];
    else if (delegate.socialType == 2)
        [accessLinkedIn fetchFeeds];
}



//delegate Methods for Twitter Delegate
-(void)getTwitterUserInfo:(NSString*)userName
{
    NSLog(@"username = %@",userName);
    NSString *welcomeUser = [NSString stringWithFormat:@"Welcome %@",userName];
    [welcomeUserLbl setText:welcomeUser];
    
    
}
-(void)fetchingTwitterFeeds:(NSDictionary*)dict
{
    NSLog(@"twitterFeeds  = %@",dict);
}
-(void)postTweets:(BOOL)successfully
{
    if(successfully == true)
        NSLog(@"tweet posted successfully");
}


@end
