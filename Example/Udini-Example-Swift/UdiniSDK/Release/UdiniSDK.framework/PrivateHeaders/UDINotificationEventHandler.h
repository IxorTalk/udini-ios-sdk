//
//  UDINotificationEventHandler.h
//  udini
//
//  Created by Andy Jacobs on 14/02/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDIBLEComponent.h"
#import "UDINotificationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface UDINotificationEventHandler : NSObject <UDIBLEComponentDelegate>

- (instancetype) initWithNotificationComponent:(UDINotificationComponent *)notificationComponent;

@end

NS_ASSUME_NONNULL_END
