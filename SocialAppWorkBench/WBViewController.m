//
//  WBViewController.m
//  SocialAppWorkBench
//
//  Created by Ishani on 6/27/14.
//  Copyright (c) 2014 Ishani. All rights reserved.
//

#import "WBViewController.h"
#import "WBAccessFacebook.h"
#import "WBAppDelegate.h"

@interface WBViewController ()

@end

@implementation WBViewController
{
    WBAccessFacebook *accessFb;
    WBAppDelegate *delegate;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
     accessFb = [WBAccessFacebook getInstance];
    delegate = [[UIApplication sharedApplication]delegate];
    
    
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)FaceBookConnect:(id)sender {
   delegate.socialType   = 1;
    
}
- (IBAction)LinkedInConnect:(id)sender {
    delegate.socialType   = 2;
}
- (IBAction)TwitterConnect:(id)sender {
    delegate.socialType   = 3;
}
@end
