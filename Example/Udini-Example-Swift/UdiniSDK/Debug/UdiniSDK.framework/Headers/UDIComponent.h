//
//  UDIComponent.h
//  udini
//
//  Created by Andy Jacobs on 28/11/2018.
//  Copyright © 2018 ixor. All rights reserved.
//

#ifndef UDIComponent_h
#define UDIComponent_h

/**
 * Udini Component interface
 */
@protocol UDIComponent <NSObject>

/**
 * Configures the Udini component with the provided options.
 *
 * @param options The Udini component options used to configure the service.
 */
- (void) configureWithOptions:(NSDictionary *)options;

@end

#endif /* UDIComponent_h */
