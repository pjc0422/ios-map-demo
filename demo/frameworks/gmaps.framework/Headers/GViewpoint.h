/*
 * Copyright (c) 2015 kt corp. All rights reserved.
 *
 * This is a proprietary software of kt corp, and you may not use this file
 * except in compliance with license agreement with kt corp. Any redistribution
 * or use of this software, with or without modification shall be strictly
 * prohibited without prior written approval of kt corp, and the copyright
 * notice above does not evidence any actual or intended publication of such
 * software.
 */

#import <Foundation/Foundation.h>

@protocol GCoord;

/**
   @class GViewpoint
    지도상의 특정시점(viewpoint)을 나타내는 클래스. 중심좌표(center),zoom,회전각(rotation),기울기(tilt) 로 구성된다.
 */
@interface GViewpoint : NSObject

/**
    지도의 중심좌표
 */
@property (nonatomic, readonly, copy) id<GCoord> center;

/**
    지도의 zoom
 */
@property (nonatomic, readonly) float zoom;

/**
    지도의 회전각
 */
@property (nonatomic, readonly) float rotation;

/**
    지도의 기울기
 */
@property (nonatomic, readonly) float tilt;

/**
    주어진 값으로 GViewpoint 객체를 초기화한다.
 */
- (id)initWithCenter:(id<GCoord>)center
                zoom:(float)zoom
            rotation:(float)rotation
                tilt:(float)tilt;
@end
