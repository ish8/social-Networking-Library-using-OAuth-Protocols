//
//  WBAppDelegate.h
//  twitterTrial
//
//  Created by Ishani on 7/7/14.
//  Copyright (c) 2014 WorkBench. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WBToken : NSObject <NSCoding> {
@protected
	NSString *key;
	NSString *secret;
	NSString *session;
	NSNumber *duration;
	NSMutableDictionary *attributes;
	NSDate *created;
	BOOL renewable;
	BOOL forRenewal;
}
@property(retain, readwrite) NSString *key;
@property(retain, readwrite) NSString *secret;
@property(retain, readwrite) NSString *session;
@property(retain, readwrite) NSNumber *duration;
@property(retain, readwrite) NSString *verifier;
@property(nonatomic, retain, readwrite) NSDictionary *attributes;
@property(readwrite, getter=isForRenewal) BOOL forRenewal;

- (void)setVerifierWithUrl:(NSURL *)aURL;
- (id)initWithKey:(NSString *)aKey secret:(NSString *)aSecret;
- (id)initWithKey:(NSString *)aKey secret:(NSString *)aSecret session:(NSString *)aSession
		 duration:(NSNumber *)aDuration attributes:(NSDictionary *)theAttributes created:(NSDate *)creation
		renewable:(BOOL)renew;
- (id)initWithHTTPResponseBody:(NSString *)body;

- (id)initWithUserDefaultsUsingServiceProviderName:(NSString *)provider prefix:(NSString *)prefix;
- (int)storeInUserDefaultsWithServiceProviderName:(NSString *)provider prefix:(NSString *)prefix;

- (BOOL)isValid;

- (void)setAttribute:(NSString *)aKey value:(NSString *)aValue;
- (NSString *)attribute:(NSString *)aKey;
- (void)setAttributesWithString:(NSString *)aAttributes;
- (NSString *)attributeString;

- (BOOL)hasExpired;
- (BOOL)isRenewable;
- (void)setDurationWithString:(NSString *)aDuration;
- (BOOL)hasAttributes;
- (NSDictionary *)parameters;

- (BOOL)isEqualToToken:(WBToken *)aToken;

+ (void)removeFromUserDefaultsWithServiceProviderName:(const NSString *)provider prefix:(const NSString *)prefix;

@end
