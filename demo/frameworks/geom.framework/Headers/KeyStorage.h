//
//  KeyStorage.h
//  auth
//
//  Created by moon on 2017. 11. 24..
//  Copyright © 2017년 moon. All rights reserved.
//

#ifndef KeyStorage_h
#define KeyStorage_h

typedef NS_ENUM(NSInteger, AuthErrorCode) {
    /// API key bundle verify fail
    AuthErrorCodeKeyLoadFail = 11,
    /// API key is not exist
    AuthErrorCodeEmptyKey,
    /// invalid API key type
    AuthErrorCodeInvalidKey,
    /// API key server auth fail
    AuthErrorCodeUnauthorizedKey
};

//extern NSString *_Nonnull const AuthErrorDomain;

@interface KeyStorage : NSObject

@property (readonly, nonatomic) NSString * _Nonnull key;
@property (class, readonly, nonatomic)  NSString * _Nonnull authErrorDomain;

+ (KeyStorage * _Nonnull)instance;
- (NSError * _Nullable)setKey:(NSString * _Nonnull)key;

@end

#endif /* KeyStorage_h */
