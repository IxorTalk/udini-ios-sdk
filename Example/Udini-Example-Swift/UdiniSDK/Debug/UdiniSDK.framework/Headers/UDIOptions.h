//
//  UDIOptions.h
//  udini
//
//  Created by Andy Jacobs on 07/12/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* const kUdiniTestEnvironment;
extern NSString* const kUdiniStagingEnvironment;
extern NSString* const kUdiniProductionEnvironment;


NS_ASSUME_NONNULL_BEGIN

/**
 * This class provides constant fields for the Udini SDK.
 */
NS_SWIFT_NAME(UdiniOptions)
@interface UDIOptions : NSObject

/**
 * Initializes a customized instance of UDIOptions with required fields. Use the mutable properties
 * to modify fields for configuring specific services.
 */
- (instancetype) initWithCallbackScheme:(NSString *)callbackScheme;

/**
 * The bearer authentication token used to authenticate every api call.
 */
@property (nonatomic, strong, nonnull) NSString *callbackScheme;

/**
 * A Boolean value indicating whether the badges should be cached persistent on disk.
 * The default value of this property is YES. Setting it to NO will only cache the assets in memory.
 */
@property (nonatomic, readwrite, getter=isCacheBadgesOnDisk) BOOL cacheBadgesOnDisk;

/**
 * Cache user + usersession as long as the rereshtoken is valid
 * The default value of this property is YES. Setting it to NO will only persist the session in memory.
 */
@property (nonatomic, readwrite, getter=isCacheUserSession) BOOL cacheUserSession;


// ADD
// *cooldown time
// *didDiscover devices agregation time = deviceDiscoveryReportDelay // 3s
// lost device = deviceRangeTimeout // 3s

@property (nonatomic, readwrite) NSTimeInterval deviceCooldownInterval;

@property (nonatomic, readwrite) NSTimeInterval deviceDiscoveryReportDelay;

@property (nonatomic, readwrite) NSTimeInterval deviceRangeTimeout;

/**
 * The default environment where the api service is hosted
 * The default value is `kUdiniProductionEnvironment`
 */
@property (nonatomic, readwrite) NSString *environment;

/**
 * The clientId that is used for authorization
 * The default value is `nil`
 */
@property (nonatomic, readwrite) NSString *clientId;

/**
 * The clientSecret that is used for authorization
 * The default value is `nil`
 */
@property (nonatomic, readwrite) NSString *clientSecret;

@end

NS_ASSUME_NONNULL_END
