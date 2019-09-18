//
//  UDIServiceRequests.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 17/07/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UDIBadge.h"
#import "UDIUser.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniServiceRequests)
@interface UDIServiceRequests : NSObject

/**
 * Get the badges.
 */
+ (void) getBadgesWithCompletionHandler:(void (^)(NSArray<UDIBadge *> * _Nullable assets, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(getBadges(completionHandler:));

/**
 * Get user profile.
 */
+ (void) getUserProfileWithCompletionHandler:(void (^)(UDIUser * _Nullable user, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(getUserProfile(completionHandler:));

/**
 * Update the profile picture image for the current logged in user.
 */
+ (void) updateProfilePictureForCurrentUser:(UIImage *)image withCompletionHandler:(void (^)(UDIUser * _Nullable user, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(updateProfilePicture(image:completionHandler:));

/**
 * Start the Udini login flow.
 */
+ (void) loginFromPresentingController:(UIViewController *)viewController
                 withCompletionHandler:(void (^)(UDIUser * _Nullable user, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(login(from:completionHandler:));

/**
 * Logout
 */
+ (void) logoutFromPresentingController:(UIViewController *)viewController
                  withCompletionHandler:(void (^)(NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(logout(from:completionHandler:));

@end

NS_ASSUME_NONNULL_END
