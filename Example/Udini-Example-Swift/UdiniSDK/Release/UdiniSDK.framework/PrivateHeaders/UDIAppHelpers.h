//
//  UdiniAppHelpers.h
//  udini
//
//  Created by Andy Jacobs on 28/11/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

#define weakify(var) __weak typeof(var) AHKWeak_##var = var;

#define strongify(var) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
__strong typeof(var) var = AHKWeak_##var; \
_Pragma("clang diagnostic pop")

static id ObjectOrNull(id object)
{
    return object ?: [NSNull null];
}

NS_ASSUME_NONNULL_BEGIN

@interface UDIAppHelpers : NSObject

+ (NSString * _Nonnull) formatUUIDString:(NSString * _Nonnull)uuid;
+ (NSUUID * _Nullable) UUIDFromUUIDString:(NSString * _Nonnull)uuid;

@end

@interface NSDictionary (Safe)
- (NSDictionary *) removeNullValues;
@end

NS_ASSUME_NONNULL_END
