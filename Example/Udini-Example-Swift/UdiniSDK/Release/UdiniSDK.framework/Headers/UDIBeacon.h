//
//  UDIBeacon.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 08/03/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniBeacon)
@interface UDIBeacon : NSObject

@property (nonatomic, strong, nullable) NSUUID *serviceUuid;
@property (nonatomic, assign) NSInteger major;
@property (nonatomic, assign) NSInteger minor;


+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary<NSString *, id> *) toDictionary;

@end

NS_ASSUME_NONNULL_END
