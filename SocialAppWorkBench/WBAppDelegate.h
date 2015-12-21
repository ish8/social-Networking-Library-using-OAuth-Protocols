//
//  WBAppDelegate.h
//  SocialAppWorkBench
//
//  Created by Ishani on 6/27/14.
//  Copyright (c) 2014 Ishani. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WBAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic,strong) NSString *appAccessToken;
@property (assign) int socialType;
@end
