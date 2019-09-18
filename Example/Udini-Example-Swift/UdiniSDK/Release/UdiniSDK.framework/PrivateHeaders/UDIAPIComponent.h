//
//  UDIAPIComponent.h
//  udini
//
//  Created by Andy Jacobs on 29/11/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDIComponent.h"
#import "UDIBadge.h"
#import "UDIPersistenceComponent.h"
#import "UDIUser.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The Udini API Component is responsible for all communications between
 * the SDK and Udini backend environment
 * It will fetch all BLE Assets that that are allowed to connect to by the user.
 */
NS_SWIFT_NAME(UdiniAPIComponent)
@interface UDIAPIComponent : NSObject <UDIComponent>

@property (nonatomic, strong) UDIPersistenceComponent *persistenceManager;

/**
 * Configures the default Udini API Component with the provided options.
 * Raises an exception if any configuration step fails.
 * This method is thread safe.
 *
 * @param options The Udini API Component options used to configure the service.
 */
- (void) configureWithOptions:(NSDictionary *)options;


- (void) getCurrentUserWithAccessToken:(NSString *)accessToken
                  andCompletionHandler:(void (^)(UDIUser * _Nullable user, NSError * _Nullable error))completionHandler;

- (void) updateProfilePictureForUser:(UDIUser *)user
                         accessToken:(NSString *)accessToken
                               image:(UIImage *)image
               withCompletionHandler:(void (^)(UDIUser * _Nullable user, NSError * _Nullable error))completionHandler;
/**
 * Gets the badges from the Udini backend environment.
 *
 * @param completionHandler A block object to be executed when the task finishes. This block has no return value and takes two arguments: the server response mapped to UDIBadge model items and the error that occurred, if any.
 */
- (void) getBadgesWithAccessToken:(NSString *)accessToken
             andCompletionHandler:(void (^)(NSArray<UDIBadge *> *assets, NSError *error))completionHandler;

+ (void) logoutFromPresentingController:(UIViewController *)viewController
                  withCompletionHandler:(void (^)(NSError * _Nullable error))completionHandler;

- (void) invokeAction:(UDIDeviceAction *)action
          accessToken:(NSString *)accessToken
withCompletionHandler:(void (^)(NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
