//
//  UDIDataProvider.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 02/05/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDIBadge.h"
#import "UDIUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface UDIDataProvider : NSObject

- (void) getBadgesWithCompletionHandler:(void (^)(NSArray<UDIBadge *> * _Nullable assets, NSError * _Nullable error))completionHandler;

- (void) getUserProfileWithCompletionHandler:(void (^)(UDIUser * _Nullable user, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
