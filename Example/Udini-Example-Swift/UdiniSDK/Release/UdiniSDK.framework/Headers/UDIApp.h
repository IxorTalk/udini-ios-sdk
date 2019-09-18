//
//  UdiniApp.h
//  udini
//
//  Created by Andy Jacobs on 28/11/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "UDIOptions.h"
#import "UDIUser.h"
#import "UDIBadge.h"

NS_ASSUME_NONNULL_BEGIN


NS_SWIFT_NAME(UdiniFeedbackDelegate)
@protocol UDIFeedbackDelegate <NSObject>
@optional

- (void) bluetoothStateChanged:(CBManagerState)state;

- (void) didDiscoverDevices:(NSArray<UDIDevice *> * _Nonnull)devices;
- (void) didDiscoverDevice:(UDIDevice * _Nonnull)device;
- (void) didLoseDevice:(UDIDevice * _Nonnull)device;
- (void) device:(UDIDevice * _Nonnull)device inCoolDownWithRemainingTime:(NSTimeInterval)time;

/**
 * Tells the delegate that a specific action did succeed
 *
 * @param device The device that describes the BLE device that has been written to.
 * @param deviceAction The deviceAction that has been written to, if nil it was a generic action (invokeOnProximity).
 */
- (void) device:(UDIDevice * _Nonnull)device didSucceedForAction:(UDIDeviceAction *)deviceAction;

/**
 * Tells the delegate that an error occured for a specific device
 *
 * @param device The device that describes the BLE device that has been written to.
 * @param deviceAction The deviceAction that has been written to, if nil it was a generic action (invokeOnProximity).
 * @param error The error that occured.
 */
- (void) device:(UDIDevice * _Nonnull)device forAction:(UDIDeviceAction *)deviceAction didFailWithError:(NSError *)error;

/**
 * Tells the delegate that the state has changed for a specific device
 *
 */
- (void) device:(UDIDevice * _Nonnull)device stateDidChange:(UDIDeviceState)state forAction:(UDIDeviceAction * _Nullable)action;

/**
 * Tells the delegate that the state has changed for a specific device
 *
 */
- (void) invokeOnProximityWillStartForDevice:(UDIDevice * _Nonnull)device withBadge:(UDIBadge * _Nonnull)badge;


@end

/**
 * Udini iOS top-level class. Provides facilities to start and stop
 * all udini services.
 */
NS_SWIFT_NAME(UdiniApp)
@interface UDIApp : NSObject

/**
 * Configures the default Udini app with the provided options.
 * Raises an exception if any configuration step fails.
 * This method is thread safe.
 *
 * @param options The Udini application options used to configure the service.
 */
+ (void) configureWithOptions:(UDIOptions *)options NS_SWIFT_NAME(configure(options:));

/**
 * Returns the current configured options object
 */
+ (UDIOptions *) getOptions;

/**
 * This will start all configured Udini services
 */
+ (void) start;

/**
 * This will stop all configured Udini services
 */
+ (void) stop;

/**
 * Returns a YES if the udini services are scanning
 */
+ (BOOL) isRunning;

/**
 * Returns the current state of the core bluetooth manager
 */
+ (CBManagerState) currentBluetoothState;


/**
 * Call this method from the [UIApplicationDelegate application:openURL:options:] method of the AppDelegate for your app. It should be invoked for the proper processing of responses during interaction with the Udini authorization flow.
 */
+ (BOOL) application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

/**
 * If there is a user session persistent on disk that is valid
 * It will return the current User model object.
 * If not it will return nil, and a login is needed.
 */
+ (UDIUser * _Nullable) hasValidUserSession;

/**
 * Add a Delegate that conforms to UDIFeedbackDelegate to receive specific Udini module feedback.
 */
+ (void) setFeedbackDelegate:(id<UDIFeedbackDelegate> _Nullable)delegate;

/**
 * Invalidates the badge cache
 */
+ (void) invalidateBadgesCache;

/**
 * Invokes an action on a device for a specific badge.
 *
 * @param action The action you whish to invoke.
 * @param device The device where the action should be invoked on.
 * @param badge The badge where the device is linked to
 */

+ (void) invokeAction:(UDIDeviceAction *)action
             onDevice:(UDIDevice *)device
             forBadge:(UDIBadge *)badge
NS_SWIFT_NAME(invoke(action:device:badge:));

/**
 * Set a callback which informs you when a user session becomes invalid.
 * This can occur when the authorization tokens are no longer valid.
 */
+ (void) userSessionDidBecomeInvalid:(void (^)(NSError * _Nullable error))handler;


+ (UNAuthorizationStatus) notifcationsAuthorizationStatus;
+ (void) requestNotificationPermissionsWithCompletionHandler:(void (^)(BOOL granted, NSError *__nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
