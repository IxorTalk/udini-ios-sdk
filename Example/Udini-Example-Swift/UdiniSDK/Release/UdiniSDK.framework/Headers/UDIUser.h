//
//  UDIUserInfo.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 21/02/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniUser)
@interface UDIUser : NSObject

@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *fullName;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSNumber *userId;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong, nullable) NSString *profilePictureUrl;
@property (nonatomic, strong) NSString *langKey;



@property (nonatomic, strong) NSString *loginProvider;

- (instancetype) initWithDictionary:(NSDictionary<NSString *, id> *)dict;
- (NSDictionary *)JSONDictionary;

@end

NS_ASSUME_NONNULL_END
