//
//  UDIBadge.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 01/03/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDIDevice.h"
#import "UDIOrganisation.h"
#import "UDIConstraint.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniBadge)
@interface UDIBadge : NSObject <NSCopying>

@property (nonatomic, strong, nullable) NSArray<UDIDevice *> *devices;
@property (nonatomic, strong, nullable) UDIOrganisation *organisation;

@property (nonatomic, assign) NSInteger nid;
@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) UDIConstraint *constraint;
@property (nonatomic, strong, nullable) NSArray<NSString *> *userIds;

@property (nonatomic, readonly) BOOL isValid;

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary<NSString *, id> *) toDictionary;

@end

NS_ASSUME_NONNULL_END
