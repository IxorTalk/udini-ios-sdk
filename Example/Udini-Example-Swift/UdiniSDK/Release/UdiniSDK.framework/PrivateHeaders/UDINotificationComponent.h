//
//  UDINotificationComponent.h
//  udini
//
//  Created by Andy Jacobs on 31/01/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDINotification.h"

NS_ASSUME_NONNULL_BEGIN

@interface UDINotificationComponent : NSObject

/**
 * Configures the default Udini Notification Component with the provided options.
 * Raises an exception if any configuration step fails.
 * This method is thread safe.
 *
 * @param options The Udini Notification Component options used to configure the service.
 */
- (void) configureWithOptions:(NSDictionary *)options;

- (BOOL) scheduleImmediateNotification:(UDINotification *)notification;

- (UNAuthorizationStatus) authorizationStatus;

- (void) requestNotificationPermissionsWithCompletionHandler:(void (^)(BOOL granted, NSError *__nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
