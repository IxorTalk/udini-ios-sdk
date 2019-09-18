//
//  UDIDeviceAction.h
//  udini
//
//  Created by Andy Jacobs on 11/12/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDIConstraint.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UdiniDeviceAction)
@interface UDIDeviceAction : NSObject

@property (nonatomic, assign) NSInteger nid;
@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSString *label;
@property (nonatomic, strong, nullable) UDIConstraint *constraint;
@property (nonatomic, strong, nullable) NSString *icon;

@property (nonatomic, assign) BOOL invokeOnProximity;


+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary<NSString *, id> *) toDictionary;

@end

NS_ASSUME_NONNULL_END

//"name" : "open",
//"constraint" : {
//    "timeWindow" : null,
//    "proximityRequired" : false,
//    "links" : [ ]
//},
//"invokeOnProximity" : true,
//"icon" : "lock-open",
//"links" : [ ],
//"_links" : {
//    "self" : {
//        "href" : "https://www-stg.udini.eu/api/actions/1010",
//        "title" : null
//    },
//    "action" : {
//        "href" : "https://www-stg.udini.eu/api/actions/1010",
//        "title" : null
//    },
//    "invoke" : {
//        "href" : "https://www-stg.udini.eu/api/action/1010/invoke",
//        "title" : null
//    }
//}
//}
