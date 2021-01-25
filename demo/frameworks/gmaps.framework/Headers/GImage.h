/*
 * Copyright (c) 2014 kt corp. All rights reserved.
 *
 * This is a proprietary software of kt corp, and you may not use this file
 * except in compliance with license agreement with kt corp. Any redistribution
 * or use of this software, with or without modification shall be strictly
 * prohibited without prior written approval of kt corp, and the copyright
 * notice above does not evidence any actual or intended publication of such
 * software.
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface GImage : NSObject

@property (nonatomic, copy, readonly) NSString *fileName;
@property (nonatomic, copy, readonly) NSString *customView;
@property (nonatomic, readonly) UIImage *image;

/**
 *  이미지 파일명을 이용하여 Map이미지 객체 생성 (권장)
 * @return 생성된 이미지 객체
 *
 * @code
 * GImage *img = [GImage imageWithFileName:@"img.png"]
 * @endcode
 */
+ (instancetype)imageWithFileName:(NSString *)fileName;

/**
 *  UIImage를 이용하여 Map이미지 객체 생성. <code>imageWithFileName</code>를 권장함
 * @return 생성된 이미지 객체
 *
 * @code
 * UIImage *uiImg = [UIImage imageNamed:@"img.png"];
 * GImage *img = [GImage imageWithUIImage:uiImg];
 * @endcode
 */
+ (instancetype)imageWithUIImage:(UIImage *)image;


+ (instancetype) imageWithView:(UIView*) view;

#pragma mark - internal use only
/**
 * image의 reference를 반환
 */
-(long) getImageRef;
///**
// * 다 사용된 후 해당 reference 해제
// */
//-(void) releaseReference;
@end
