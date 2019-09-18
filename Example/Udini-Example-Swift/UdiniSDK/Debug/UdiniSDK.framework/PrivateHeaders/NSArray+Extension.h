//
//  NSArray+Extension.h
//  udini
//
//  Created by Andy Jacobs on 29/11/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

// Shorthand for simple blocks
#define λ(decl, expr) (^(decl) { return (expr); })

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (Extension)

- (NSArray *)map:(id (^)(id obj))block;

- (NSArray *)filter:(BOOL (^)(id obj))block;

- (id)reduce:(id)initial
       block:(id (^)(id obj1, id obj2))block;

- (NSArray *)flatMap:(id (^)(id obj))block;

- (NSString* _Nullable) jsonString;


@end

// nil → NSNull conversion for JSON dictionaries
static id NSNullify(id _Nullable x) {
    return (x == nil || x == NSNull.null) ? NSNull.null : x;
}

static id map(id collection, id (^f)(id value)) {
    id result = nil;
    if ([collection isKindOfClass:NSArray.class]) {
        result = [NSMutableArray arrayWithCapacity:[collection count]];
        for (id x in collection) [result addObject:f(x)];
    } else if ([collection isKindOfClass:NSDictionary.class]) {
        result = [NSMutableDictionary dictionaryWithCapacity:[collection count]];
        for (id key in collection) [result setObject:f([collection objectForKey:key]) forKey:key];
    }
    return result;
}

NS_ASSUME_NONNULL_END
