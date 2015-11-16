//
//  PAPCache.h
//  Anypic
//
//  Created by Héctor Ramos on 5/31/12.
//  Copyright (c) 2013 Parse. All rights reserved.
//

// ca01 ----
// abt this class, from anypic website tut:
// "It provides Anypic with custom caching behavior used to quickly display up to date information about photos. When the current user likes or comments on a given photo, we manually update the local cache as soon as the request is sent. This allows us to propagate the model change throughout the app without needing to wait for the initial save request to finish and then refreshing the content.''

// ----

#import <Foundation/Foundation.h>

@interface PAPCache : NSObject

+ (id)sharedCache;

- (void)clear;
- (void)setAttributesForPhoto:(PFObject *)photo likers:(NSArray *)likers commenters:(NSArray *)commenters likedByCurrentUser:(BOOL)likedByCurrentUser;
- (NSDictionary *)attributesForPhoto:(PFObject *)photo;
- (NSNumber *)likeCountForPhoto:(PFObject *)photo;
- (NSNumber *)commentCountForPhoto:(PFObject *)photo;
- (NSArray *)likersForPhoto:(PFObject *)photo;
- (NSArray *)commentersForPhoto:(PFObject *)photo;
- (void)setPhotoIsLikedByCurrentUser:(PFObject *)photo liked:(BOOL)liked;
- (BOOL)isPhotoLikedByCurrentUser:(PFObject *)photo;
- (void)incrementLikerCountForPhoto:(PFObject *)photo;
- (void)decrementLikerCountForPhoto:(PFObject *)photo;
- (void)incrementCommentCountForPhoto:(PFObject *)photo;
- (void)decrementCommentCountForPhoto:(PFObject *)photo;

- (NSDictionary *)attributesForUser:(PFUser *)user;
- (NSNumber *)photoCountForUser:(PFUser *)user;
- (BOOL)followStatusForUser:(PFUser *)user;
- (void)setPhotoCount:(NSNumber *)count user:(PFUser *)user;
- (void)setFollowStatus:(BOOL)following user:(PFUser *)user;

- (void)setFacebookFriends:(NSArray *)friends;
- (NSArray *)facebookFriends;
@end
