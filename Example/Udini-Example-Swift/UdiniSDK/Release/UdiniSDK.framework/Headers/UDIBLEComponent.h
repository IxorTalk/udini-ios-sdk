//
//  BLEComponent.h
//  udini
//
//  Created by Andy Jacobs on 28/11/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "UDIComponent.h"
#import "UDIBadge.h"
#import "UDIDevice.h"
#import "UDIChallangeValidator.h"

NS_ASSUME_NONNULL_BEGIN

// forwards required by this header
@class UDIBLEComponent;
@class UDIBLEDevicePeripheral;
/**
 * The inputsource of a UDIBLEComponent object must adopt the UDIBLEComponentInputSource protocol.
 * Required methods of the protocol allow the inputsource to make necessary decisions on actions taken by BLE Component.
 * As well as provide a data requested by the BLE Component.
 */
@protocol UDIBLEComponentInputSource <NSObject>
@required

/**
 * Asks the input source if it should connect to a BLE device.
 *
 * @param component The Udini BLE Component object requesting this information.
 * @param device The device that describes the BLE device.
 *
 * @return YES if the it should connect to the BLE device or NO if it does not have to connect.
 */
- (BOOL) component:(UDIBLEComponent * _Nonnull)component shouldConnectToDeviceOnProximity:(UDIDevice * _Nonnull)device forBadge:(UDIBadge *)badge;

/**
 * Asks the input source if it should write to a BLE device.
 *
 * @param component The Udini BLE Component object requesting this information.
 * @param device The device that describes the BLE device.
 *
 * @return YES if the it should write to the BLE device or NO if it does not have to write.
 */
- (BOOL) component:(UDIBLEComponent * _Nonnull)component shouldWriteUserTokenToDevice:(UDIDevice * _Nonnull)device;

/**
 * Asks the input source to provide a token generator.
 *
 * @param component The Udini BLE Component object requesting this information.
 * @param device The device that describes the BLE device.
 *
 * @return A UDIChallangeValidator which can be used to validate a challenge from a BLE device.
 */
- (UDIChallangeValidator *) component:(UDIBLEComponent * _Nonnull)component validatorForDevice:(UDIDevice * _Nonnull)device;

@end

/**
 * The delegate of a UDIBLEComponent object must adopt the UDIBLEComponentDelegate protocol.
 * Optional methods of the protocol allow the delegate to receive feedback of ongoing actions being taken in the BLE component.
 */
@protocol UDIBLEComponentDelegate <NSObject>
@optional
/**
 * Tells the delegate that the Udini BLE Component has been succesfully configured.
 *
 * @param component The Udini BLE Component object providing this information.
 */
- (void) componentConfigurationSuccess:(UDIBLEComponent * _Nonnull)component;

/**
 * Tells the delegate that the Udini BLE Component configuration has failed.
 *
 * @param component The Udini BLE Component object providing this information.
 * @param state The CBManagerState describing the reason of configuration failure
 */
- (void) component:(UDIBLEComponent * _Nonnull)component configurationFailed:(CBManagerState)state;

/**
 * Tells the delegate that the Udini BLE Component has started scanning a set of devices.
 *
 * @param component The Udini BLE Component object providing this information.
 * @param scannabledevices An array of all devices that are included in the BLE scanning
 */
- (void) component:(UDIBLEComponent * _Nonnull)component didStartScanningDevices:(NSArray<UDIDevice *> * _Nonnull)scannabledevices;

/**
 * Tells the delegate that the Udini BLE Component has stopped scanning a set of devices.
 *
 * @param component The Udini BLE Component object providing this information.
 * @param scannabledevices An array of all devices that were included in the BLE scanning
 */
- (void) component:(UDIBLEComponent * _Nonnull)component didStopScanningDevices:(NSArray<UDIDevice *> * _Nonnull)scannabledevices;

/**
 * Tells the delegate that the Udini BLE Component did discover a BLE device.
 *
 * @param component The Udini BLE Component object providing this information.
 * @param device The device that describes the BLE device that has been discovered.
 */
- (void) component:(UDIBLEComponent * _Nonnull)component didDiscoverDevices:(NSArray<UDIDevice *> * _Nonnull)device;
- (void) component:(UDIBLEComponent * _Nonnull)component didDiscoverDevice:(UDIDevice * _Nonnull)device forBadge:(UDIBadge *)badge;

/**
 * Tells the delegate that the Udini BLE Component did connect to a BLE device.
 *
 * @param component The Udini BLE Component object providing this information.
 * @param device The device that describes the BLE device that has been connected to.
 */
- (void) component:(UDIBLEComponent * _Nonnull)component didConnectToDevice:(UDIDevice * _Nonnull)device;

/**
 * Tells the delegate that the Udini BLE Component did disconnect to a BLE device.
 *
 * @param component The Udini BLE Component object providing this information.
 * @param device The device that describes the BLE device that it has been disconnected to.
 */
- (void) component:(UDIBLEComponent * _Nonnull)component didDisconnectToDevice:(UDIDevice * _Nonnull)device;

/**
 * Tells the delegate that the Udini BLE Component did write to a BLE device.
 *
 * @param component The Udini BLE Component object providing this information.
 * @param device The device that describes the BLE device that has been written to.
 */
- (void) component:(UDIBLEComponent * _Nonnull)component didWriteToDevice:(UDIDevice * _Nonnull)device;

/**
 * Tells the delegate that an error occured inside Udini BLE Component for a specific device
 *
 * @param component The Udini BLE Component object providing this information.
 * @param device The device that describes the BLE device that has been written to.
 * @param error The error that occured.
 */
- (void) component:(UDIBLEComponent * _Nonnull)component forDevice:(UDIDevice * _Nonnull)device didFailWithError:(NSError *)error;

/**
 * Tells the delegate that the state has changed for a specific device
 *
 */
- (void) component:(UDIBLEComponent * _Nonnull)component forDevice:(UDIDevice * _Nonnull)device stateChange:(UDIDeviceState)state;

/**
 * Tells the delegate that the state has changed for a specific device
 *
 */
- (void) component:(UDIBLEComponent * _Nonnull)component invokeOnProximityWillStartForDevice:(UDIDevice * _Nonnull)device;

@end


/**
 * The Udini BLE Component is responsible for all communications between
 * the SDK and the BLE device
 * It is responsible for scanning for peripherals (BLE devices) with specified services
 * Connecting to discovered peripherals
 * Discovering services & characteristics of those peripherals
 * Writing data to specified characteristics
 */
NS_SWIFT_NAME(UdiniBLEComponent)
@interface UDIBLEComponent : NSObject <UDIComponent>

@property (nonatomic, assign) CBManagerState currentState;
@property (nonatomic, assign) BOOL isScanning;

/**
 * All devices that will be scanned upon `startScanningdevices`
 */
@property (nonatomic, nullable, strong) NSArray<UDIBadge *> *badges;
@property (nonatomic, nullable, strong) UDIBLEDevicePeripheral *connectedDevice;


/**
 * The object that acts as the input source of the Udini BLE Component.
 * The input source must adopt the UDIBLEComponentInputSource protocol.
 * The input source is not retained.
 */
@property (nonatomic, weak) id<UDIBLEComponentInputSource> inputSource;

///**
// * The object that acts as the delegate of the Udini BLE Component.
// * The input source must adopt the UDIBLEComponentDelegate protocol.`
// * The delegate is not retained.
// */
//@property (nonatomic, weak) id<UDIBLEComponentDelegate> delegate;

/**
 * Configures the default Udini BLE Component with the provided options.
 * Raises an exception if any configuration step fails.
 * This method is thread safe.
 *
 * @param options The Udini BLE Component options used to configure the service.
 */
- (void) configureWithOptions:(NSDictionary *)options;

/**
 * This will start scanning for devices specified in `scannableDevices`
 */
- (void) startScanning;

/**
 * This will stop scanning for devices specified in `scannabledevices` when `startScanning` occurred.
 */
- (void) stopScanning;

/**
 * Connect to a specific BLE device
 *
 * @param asset The Udini BLE device that you want to connect to
 */
//- (void) connectToAsset:(UDIDevice *)asset;

/**
 * Instruct the BLE Component to invoke a specified action on the BLE Device.
 *
 * @param action The specified action you want to invoke on the asset
 * @param device The Udini BLE device you want to invoke the action
 * @param completionHandler feedback when the acction was succcessful or not
 */
- (void) invokeAction:(UDIDeviceAction *)action
             onDevice:(UDIDevice *)device
withCompletionHandler:(void (^)(NSError * _Nullable error))completionHandler;

- (void) cancelAction:(UDIDeviceAction *)action
             onDevice:(UDIDevice *)device;

- (void)addDelegate:(id<UDIBLEComponentDelegate>)delegate;
- (void)removeDelegate:(id<UDIBLEComponentDelegate>)delegate;

- (void) stateChanged:(UDIDeviceState)state forAsset:(UDIBLEDevicePeripheral *)asset;

@end

NS_ASSUME_NONNULL_END
