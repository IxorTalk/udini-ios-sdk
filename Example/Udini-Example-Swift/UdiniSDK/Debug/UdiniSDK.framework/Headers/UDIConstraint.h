//
//  UDIBadgeConstraint.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 07/03/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniConstraint)
@interface UDIConstraint : NSObject

@property (nonatomic, strong, nullable) NSDate *fromTimestamp;
@property (nonatomic, strong, nullable) NSDate *toTimestamp;
@property (nonatomic, assign) BOOL proximityRequired;

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary<NSString *, id> *) toDictionary;

@end

NS_ASSUME_NONNULL_END
