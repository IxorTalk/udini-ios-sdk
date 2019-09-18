//
//  UDIDevice.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 01/03/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDIDeviceAction.h"
#import "UDICompany.h"
#import "UDIBeacon.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniDevice)
@interface UDIDevice : NSObject <NSCopying>

/**
 * All beacon tags that are affiliated with the BLEAsset
 */
@property (nonatomic, strong, nullable) NSArray<UDIDeviceAction *> *actions;
@property (nonatomic, assign) NSInteger bleNumber;

@property (nonatomic, strong, nullable) NSUUID *advertisedServiceUuid;
@property (nonatomic, strong, nullable) NSUUID *uartServiceUuid;
@property (nonatomic, strong, nullable) NSUUID *deviceReadCharacteristicUuid;
@property (nonatomic, strong, nullable) NSUUID *deviceWriteCharacteristicUuid;

@property (nonatomic, strong, nullable) UDICompany *company;

@property (nonatomic, strong, nullable) NSString *deviceName;
@property (nonatomic, strong, nullable) NSString *deviceId;
@property (nonatomic, strong, nullable) NSString *deviceInformation;
@property (nonatomic, strong, nullable) NSString *image;

@property (nonatomic, strong, nullable) UDIBeacon *beacon;

/**
 * Boolean value that indicates if any action has a invokeOnProximity flag set
 */
@property (nonatomic, readonly) BOOL hasActionWithInvokeOnProximity;

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary<NSString *, id> *) toDictionary;

@end

NS_ASSUME_NONNULL_END

typedef NS_ENUM(NSUInteger, UDIDeviceState) {
    kConnecting NS_SWIFT_NAME(connecting),
    kConnected NS_SWIFT_NAME(connected),
    kDiscoveringServices  NS_SWIFT_NAME(discoveringServices),
    kDiscoveredServices NS_SWIFT_NAME(discoveredServices),
    kDiscoveringCharacteristics NS_SWIFT_NAME(discoveringCharacteristics),
    kDiscoveredCharacteristics NS_SWIFT_NAME(discoveredCharacteristics),

    kPerformingAction NS_SWIFT_NAME(performingAction),
    kActionPerfomed NS_SWIFT_NAME(actionPerfomed),

    // REMOVE: kResponseNotification NS_SWIFT_NAME(responseNotification),

    kDisconnecting NS_SWIFT_NAME(disconnecting),
    kDisconnected NS_SWIFT_NAME(disconnected)
} NS_SWIFT_NAME(UdiniDeviceState);
