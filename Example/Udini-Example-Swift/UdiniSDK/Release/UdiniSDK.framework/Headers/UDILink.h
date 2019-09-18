//
//  UDILink.h
//  udini
//
//  Created by Andy Jacobs on 11/12/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UDILink : NSObject

@property (nonatomic, strong) NSString *href;
@property (nonatomic, strong) NSString *title;

- (instancetype) initWithHref:(NSString *)href
                        title:(NSString *)title;

- (instancetype) initWithDictionary:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
