//
//  UDICompany.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 08/03/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniCompany)
@interface UDICompany : NSObject

@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSString *logo;
@property (nonatomic, strong, nullable) NSString *color;

@end

NS_ASSUME_NONNULL_END
