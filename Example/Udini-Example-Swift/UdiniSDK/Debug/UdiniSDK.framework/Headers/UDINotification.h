//
//  UDINotification.h
//  udini
//
//  Created by Andy Jacobs on 12/02/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UserNotifications/UserNotifications.h>
NS_ASSUME_NONNULL_BEGIN

@interface UDINotification : NSObject

@property (nonatomic, strong) NSString *identifier;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *message;

@property (nonatomic, strong) NSArray<UNNotificationAction *> *actions;

@property (nonatomic, strong) NSDictionary *userInfo;

@property (nonatomic, strong) NSArray<NSString *> *removableNotificationIdentifiers;

- (instancetype) initWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
