//
//  UDIPersistenceComponent.h
//  udini
//
//  Created by Andy Jacobs on 04/12/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDIBadge.h"
#import "UDIUser.h"
#import "AppAuth.h"
#import "UDIComponent.h"
NS_ASSUME_NONNULL_BEGIN
/**
 * The Udini Persistence Component is responsible for data persistence on disk and in memory
 * It will make sure data is stored secure in the keychain
 */
NS_SWIFT_NAME(UdiniPersistenceComponent)
@interface UDIPersistenceComponent : NSObject <UDIComponent>

@property (nonatomic, strong, nullable) NSArray<UDIBadge *> *cachedBadges;
@property (nonatomic, strong, nullable) UDIUser *user;
@property (nonatomic, strong, nullable) OIDAuthState *authState;
@property (nonatomic, strong, readonly) NSUUID *deviceId;


- (void) configureWithOptions:(NSDictionary *)options;
- (void) setAuthToken:(NSString *)token;
- (NSString *) authToken;

- (void) clearCache;

@end

NS_ASSUME_NONNULL_END
