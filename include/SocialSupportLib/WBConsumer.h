//
//  WBAppDelegate.h
//  twitterTrial
//
//  Created by Ishani on 7/7/14.
//  Copyright (c) 2014 WorkBench. All rights reserved.
//


#import <Foundation/Foundation.h>


@interface WBConsumer : NSObject {
@protected
	NSString *key;
	NSString *secret;
    NSString *realm;
}
@property(copy, readwrite) NSString *key;
@property(copy, readwrite) NSString *secret;
@property(copy, readwrite) NSString *realm;

- (id)initWithKey:(const NSString *)aKey secret:(const NSString *)aSecret realm:(const NSString *)aRealm;

- (BOOL)isEqualToConsumer:(WBConsumer *)aConsumer;

@end
