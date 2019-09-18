//
//  UDIAuthorizationComponent.h
//  UdiniSDK
//
//  Created by Andy Jacobs on 21/02/2019.
//  Copyright © 2019 ixor. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppAuth.h"
#import "UDIComponent.h"
#import "FBLPromises.h"
NS_ASSUME_NONNULL_BEGIN

@interface UDIAuthorizationComponent : NSObject <UDIComponent>

@property(nonatomic, strong, nullable) OIDAuthState *authState;

- (void) configureWithRedirectURL:(NSURL *)redirectURL;
- (void) configureWithOptions:(NSDictionary *)options;

- (void) authorizeFromPresentingController:(UIViewController *)viewController
                     withCompletionHandler:(void (^)(OIDAuthState * _Nullable authState, NSError * _Nullable error))completionHandler;

- (void) authorizeWithUserName:(NSString *)username andPassword:(NSString *)password withCompletionHandler:(void (^)(NSString * _Nullable accessToken, NSError * _Nullable error))completionHandler;

- (void) performAction:(void (^)(NSString *_Nonnull accessToken,
                                 NSError *_Nullable error))action;

- (void) authStateDidChange:(void (^)(OIDAuthState * _Nullable authState, NSError * _Nullable error))changeHandler;

- (FBLPromise<NSString *> *) performAction;

- (void) logoutFromPresentingController:(UIViewController *)viewController
                  withCompletionHandler:(void (^)(NSError * _Nullable error))completionHandler;

- (void) logoutRedirectReceived;

- (BOOL) resumeExternalUserAgentFlowWithURL:(NSURL *)URL;

@end

NS_ASSUME_NONNULL_END
