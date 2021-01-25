//
//  GVisibleRegion.h
//  OllehMapSDK
//
//  Created by ik on 2015. 1. 5..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GCoord;
@protocol GBounds;
@class GBounds;

/**
  화면상에 보여지는 지도영역을 4개의 좌표로 나타낸다.
 */
@interface GVisibleRegion : NSObject

/**
  화면의 좌측하단 좌표
 */
@property (nonatomic, readonly) id<GCoord> nearLeft;

/**
  화면의 우측하단 좌표
 */
@property (nonatomic, readonly) id<GCoord> nearRight;

/**
  화면의 좌측상단 좌표
 */
@property (nonatomic, readonly) id<GCoord> farLeft;

/**
  화면의 우측상단 좌표
 */
@property (nonatomic, readonly) id<GCoord> farRight;

/**
  GVisibleRegion 을 포함하는 가장작은 GBounds 를 나타낸다.
 */
@property (nonatomic, readonly, getter=getBounds) id<GBounds> bounds;

/**
  주어진 좌표들로 GVisibleRegion 을 초기화한다.
 
 @param nearLeft 좌측하단 좌표
 @param nearRight 우측하단 좌표
 @param farLeft 좌측상단 좌표
 @param farRight 우측상단 좌표
 */
- (instancetype)initWithNearLeft:(id<GCoord>)nearLeft
                      nearRight:(id<GCoord>)nearRight
                        farLeft:(id<GCoord>)farLeft
                       farRight:(id<GCoord>)farRight;

@end
