//
//  UDICrypto.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 14/04/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface UDICrypto : NSObject

+ (NSString *) generateKeyPair;
+ (void) removeKeyPair;

+ (NSString *) publicKeyPem;

+ (SecKeyRef) privateKey;
+ (SecKeyRef) publicKey;
+ (SecKeyRef) peerPublicKeyForEnvironment:(NSString *)environment;

+ (NSError *) addPublicKey:(NSData *)data
            forEnvironment:(NSString *)environment;

+ (BOOL) validateChallange:(NSString *)challange
              andSignature:(NSString *)signature
            forEnvironment:(NSString *)environment;

+ (NSDictionary<NSString *, NSString *> *) challangeForPayload:(NSString *)payload
                                                forEnvironment:(NSString *)environment;

@end

NS_ASSUME_NONNULL_END
