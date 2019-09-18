//
//  UDIBeaconComponent.h
//  udini
//
//  Created by Andy Jacobs on 28/01/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

// forwards required by this header
@class UDIBeaconComponent;
/**
 * The delegate of a UDIBLEComponent object must adopt the UDIBLEComponentDelegate protocol.
 * Optional methods of the protocol allow the delegate to receive feedback of ongoing actions being taken in the BLE component.
 */
@protocol UDIBeaconComponentDelegate <NSObject>
@optional

/**
 * Tells the delegate that the Udini Beacon Component has started to monitor a set of beacon regions.
 *
 * @param component The Udini Beacon Component object providing this information.
 * @param beaconRegions An array of all regions that are included in the beacon monitoring
 */
- (void) component:(UDIBeaconComponent * _Nonnull)component didStartMonitorRegions:(NSArray<CLBeaconRegion *> * _Nonnull)beaconRegions;

/**
 * Tells the delegate that the Udini Beacon Component has stopped to monitor a set of beacon regions.
 *
 * @param component The Udini Beacon Component object providing this information.
 * @param beaconRegions An array of all regions that were included in the beacon monitoring
 */
- (void) component:(UDIBeaconComponent * _Nonnull)component didStopMonitorRegions:(NSArray<CLBeaconRegion *> * _Nonnull)beaconRegions;

/**
 * Tells the delegate that the Udini Beacon Component did discover a BLE device.
 *
 * @param component The Udini Beacon Component object providing this information.
 * @param region The region that has been discovered.
 */
- (void) component:(UDIBeaconComponent * _Nonnull)component didDiscoverRegion:(CLBeaconRegion * _Nonnull)region;

@end

@interface UDIBeaconComponent : NSObject

/**
 * All assets that will be scanned upon `startScanningAssets`
 */
@property (nonatomic, nullable, strong) NSArray<CLBeaconRegion *> *scannableRegions;

/**
 * The object that acts as the delegate of the Udini Beacon Component.
 * The input source must adopt the UDIBeaconComponentDelegate protocol.`
 * The delegate is not retained.
 */
@property (nonatomic, weak) id<UDIBeaconComponentDelegate> delegate;

/**
 * Configures the default Udini Beacon Component with the provided options.
 * Raises an exception if any configuration step fails.
 * This method is thread safe.
 *
 * @param options The Udini Beacon Component options used to configure the service.
 */
- (void) configureWithOptions:(NSDictionary *)options;

/**
 * This will start to monitor for regions specified in `scannableRegions`
 */
- (void) startMonitoringRegions;

/**
 * This will stop monitoring for regions specified in `scannableRegions` when `startMonitoringRegions` occurred.
 */
- (void) stopMonitoringRegions;

/**
 * This will initiate the location service always authorization request.
 * If the status is undertermined
 * @return BOOL returns YES if the request was initiated, returns NO if the status was already determined.
 */
- (BOOL) requestAuthorization;

@end

NS_ASSUME_NONNULL_END
