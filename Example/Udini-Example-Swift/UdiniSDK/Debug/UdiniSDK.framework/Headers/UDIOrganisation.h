//
//  UDIOrganisation.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 07/03/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniOrganisation)
@interface UDIOrganisation : NSObject

@property (nonatomic, assign) NSInteger nid;
@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSString *fullAddress;
@property (nonatomic, strong, nullable) NSString *image;
@property (nonatomic, strong, nullable) NSString *streetAndNumber;
@property (nonatomic, strong, nullable) NSString *postalCode;
@property (nonatomic, strong, nullable) NSString *city;
@property (nonatomic, strong, nullable) NSString *country;

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary<NSString *, id> *) toDictionary;

@end

NS_ASSUME_NONNULL_END
