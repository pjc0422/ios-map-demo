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
#import <CoreGraphics/CGGeometry.h>

@protocol GCoord;
@protocol GBounds;
@class GViewpoint;
@class GViewpointChangeBuilder;
@class NativeManager;

// internal use only
@protocol GViewpointChangeCommand

@required
- (void)execute:(NativeManager*)nativeMgr;

@end

/**
    지도를 바라보는 시점(viewpoint) 변경을 정의한다.
 */
@interface GViewpointChange : NSObject

@property (nonatomic, readonly) id<GViewpointChangeCommand> pivotCommand;
@property (nonatomic, readonly) NSArray* commands;

- (id)initWithCommand:(id<GViewpointChangeCommand>)command;
- (id)initWithPivot:(id<GViewpointChangeCommand>)pivotCommand commands:(NSArray*)commands;

/**
    명시된 값으로 지도의 시점을 즉시 변경하는 GViewpointChange 객체를 반환한다.
 
   @param viewpoint 지도시점
   @return GViewpointChange 객체
 */
+ (GViewpointChange*)moveTo:(GViewpoint*)viewpoint;

/**
    명시된 값으로 지도의 시점을 변경시키는 GViewpointChange 객체를 반환한다.
 
   @param center 중심 좌표
   @param zoom zoom
   @param rotation 회전각
   @param tilt 기울기
   @return GViewpointChange 객체
 */
+ (GViewpointChange*)moveTo:(id<GCoord>)center
                      zoom:(float)zoom
                  rotation:(float)rotation
                      tilt:(float)tilt;

/**
    zoom 을 한단계 확대하는 GViewpointChange 객체를 반환한다.
 
   @return GViewpointChange 객체
 */
+ (GViewpointChange*)zoomIn;

/**
    zoom 을 한단계 축소하는 GViewpointChange 객체를 반환한다.
 
   @return GViewpointChange 객체
 */
+ (GViewpointChange*)zoomOut;

/**
  현재 줌레벨을 명시된 값으로로 변경하는 ViewpointChange 객체를 생성하여 반환한다.
 
 @param zoom 줌레벨
 @return GViewpointChnage 객체
 */
+ (GViewpointChange*)zoomTo:(float)zoom;

/**
  줌레벨을 amount 만큼 확대 또는 축소 시키는 ViewpointChange 객체를 생성하여 반환한다.
 
 @param amount 줌레벨 변화값
 @return GViewpointChange 객체
 */
+ (GViewpointChange*)zoomBy:(float)amount;

/**
  현재 위치에서 파라미터로 지정된 상대적 좌표만큼 지도를 이동시키는 ViewpointChange 객체를 생성하여 반환한다.

 @param dx 이동하고자 하는 상대적 x좌표. point 단위
 @param dy 이동하고자 하는 상대적 y좌표. point 단위
 @return GViewpointChange 객체
 */
+ (GViewpointChange*)panByX:(double)dx y:(double)dy;

/**
  명시된 center 로 지도의 중심점을 이동하는 GViewpointChange 객체를 반환한다.
 
 @param coord 이동하고자 하는 절대 좌표
 @return GViewpointChange 객체
 */
+ (GViewpointChange*)panTo: (id<GCoord>) center;

/**
  현재 rotation 기준으로 amount 만큼 지도를 회전시키는 ViewpointChange 객체를 생성하여 반환한다.
 
 @param amount rotation 변화량 (degree)
 @return GViewpointChange 객체
 */
+ (GViewpointChange*)rotateBy:(float)amount;

/**
  현재 rotation 값을 명시된 값으로 변경하는 ViewpointChange 객체를 생성하여 반환한다.
 
 @param rotation 변경하고자 하는 rotation 값 (degree)
 @return GViewpointChange 객체
 */
+ (GViewpointChange*)rotateTo:(float)rotation;

/**
  지도의 tilt 를 파라미터로 지정된 값만큼 변화시키는 ViewpointChange 객체를 생성하여 반환한다.
 
 @param amount tilt 변화값 (degree)
 @return GViewpointChange 객체
 */
+ (GViewpointChange*)tiltBy:(float)amount;

/**
  지도의 tilt 를 파라미터로 지정된 값으로 변경하는 ViewpointChange 객체를 생성하여 반환한다.
 
 @param tilt tilt 값 (degree)
 @return OMsViewpointChange 객체
 */
+ (GViewpointChange*)tiltTo:(float)tilt;

/**
  bounds 영역이 화면전체를 차지하도록 zoom 과 center 를 변경한다.
 
 @param bounds 지도영역
 @return GViewpointChange 객체
 */
+ (GViewpointChange*)fitBounds:(id<GBounds>)bounds;

/**
  bounds 영역이 화면전체 영역에서 지정된 padding 안쪽으로 차지하도록 zoom과 center 를 변경한다.
 
 @param bounds 지도영역
 @param padding 화면 point
 @return GViewpointChange 객체
 */
+ (GViewpointChange*)fitBounds:(id<GBounds>)bounds padding:(int)padding;

/**
    새로운 VeiewpointChangeBuilder 객체를 반환한다.
 
   @return ViewpointChangeBuilder 객체
 */
+ (GViewpointChangeBuilder*)builder;

@end

/**
  ViewpointChangeBuilder 에는 복잡한 GViewpointChange 를 생성하기 위한 다양한 함수들이 정의되어 있다.
 
 생성된 GViewpointChange 는 GMapView 의 animateViewpoint: 의 파라미터로 사용되어 지도의 시점을 변경할 수 있다.
 예를들어 다음은 지도의 zoom 을 한단계 확대하는 코드이다.
 @code
 GViewpointChange* change = [[ViewpointChangeBuilder zoomIn] build];
 [omsMapView animateViewpoint:change];
 @endcode
 */
@interface GViewpointChangeBuilder : NSObject

/**
    pivot 은 GViewpointChange 가 적용될때의 중심점으로 작동한다.
 
   @param pivot pivot 좌표
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)pivot:(CGPoint)pivot;

/**
    zoom 을 한단계 축소한다.
 
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)zoomIn;

/**
    zoom 을 한단계 확대한다.
 
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)zoomOut;

/**
    delta 만큼 줌을 확대 또는 축소한다.
 
   @param delta zoom 변화량
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)zoomBy:(float)delta;

/**
    명시된 값으로 줌을 변경한다.
   
   @param zoom 값
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)zoomTo:(float)zoom;

/**
    delta 만큼 회전각을 변경한다.
 
   @param delta 회전각 변화량
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)rotateBy:(float)delta;

/**
    명시된 값으로 회전각을 변경한다.

   @param rotation 회전각
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)rotateTo:(float)rotation;

/**
    delta 만큼 지도의 tilt 를 변화시킨다.
 
   @param delta tilt 변화량
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)tiltBy:(float)delta;

/**
    명시된 값으로 tilt 를 변경한다.
 
   @param tilt 변경하고자 하는 tilt 값
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)tiltTo:(float)tilt;

/**
    현재 지도 중심점을 지정된 화면 좌표만큼 이동시킨다.
 
   @param dx 화면상 x 좌표 변화값. point 단위
   @param dy 화면상 y 좌표 변화값. point 단위
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)panByX:(double)dx y:(double)dy;

/**
    지정된 center 로 지도의 중심점을 이동시킨다.
 
   @param center 지도 좌표
   @return ViewpointChangeBuilder 객체
 */
- (GViewpointChangeBuilder*)panTo:(id<GCoord>)center;

/**
    ViewpointChangeBuilder 에 설정된 값들을 반영한 GViewpointChange 객체를 생성하여 반환한다.
 
   @return GViewpointChange 객체
 */
- (GViewpointChange*)build;


@end


