//
//  GBounds.h
//  geom
//
//  Created by gisdev on 2015. 1. 29..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GCoord;

/**
 지도상의 사각형 영역을 나타내는 protocol.
 좌측하단을 나타내는 min 과 우측상단을 나타내는 max 의 2 property 로 이루어진다.
 */
@protocol GBounds<NSObject>

/**
 bounds 를 정의하는 좌측하단 좌표
 */
@property (readonly, getter=getMin) id<GCoord> min;

/**
 bounds 를 정의하는 우측상단 좌표
 */
@property (readonly, getter=getMax) id<GCoord> max;

@end
