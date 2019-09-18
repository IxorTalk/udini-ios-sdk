//
//  UDIChallangeValidator.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 15/04/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UDIChallangeValidator : NSObject

- (instancetype) initWithUsername:(NSString *)username
                         deviceId:(NSString *)deviceId
                      environment:(NSString *)environment;

- (void) validateChallange:(NSArray<NSString *> *)challange
     withCompletionHandler:(void (^)(NSArray * _Nullable response, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END

