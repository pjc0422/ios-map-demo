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

@class GMapView;
@class GOverlay;

@protocol GOverlayTapInterceptor
-(bool) onTapOverlay:(GMapView*) mapView overlay:(GOverlay*) overlay;
@end

/**
 * @class GOverlay
 *  GOverlay는 ollehMapView에 추가될 수 있는 오버레이들의 super class이다.
 * GOverlay의 인스턴스를 직접 생성할 수는 없고 GMarker, GGroundOverlay 등의 특정한 오버레이 타입의 인스턴스를 생성해야한다.
 */
@interface GOverlay : NSObject {
@protected
    void* _nOverlay;
    __weak GMapView* _mapView;
}

/// Overlay 생성 옵션
@property (nonatomic, copy) NSDictionary *options;

/// 오버레이 고유 아이디
@property (nonatomic, readonly, assign) unsigned int uuid;
// @property (nonatomic, readonly, assign) bool added;

/// 화면 표출 여부
@property (nonatomic, readwrite, assign) bool visible;
// @property (nonatomic, readwrite, assign) int zIndex;
// @property (nonatomic, readwrite, assign) NSUInteger minZoom;
// @property (nonatomic, readonly) void * overlay;
// @property (nonatomic, readonly) id * overlay;

/// overlay 부가 정보 설정 tag(App에서 설정하여 사용한다.)
/// default is -1
@property (nonatomic) int tagInfo;
@property (nonatomic) id<GOverlayTapInterceptor> interceptor;

/**
 *  오버레이에 지정된 모든 옵션을 적용한다.
 * @param options 설정한 내용.
 * @see \ref GMarker.markerWithOptions:
 * @see \ref GGroundOverlay.groundOverlayWithOptions:
 */
- (void)setOptions:(NSDictionary *)options;

/**
 *  화면 표출 여부를 지정한다.
 * @param visible 표출할 경우 true, 그렇지 않을 경우 false.
 */
- (void)setVisible:(bool)visible;

/**
 *  필수 옵션이 모두 설정되어 오버레이가 지도에 추가될 수 있는 상태인지 여부를 리턴한다.
 * @return 추가될 수 있는 상태인 경우 true, 그렇지 않을 경우 false.
 */
- (bool)isPrepared;

/**
 *  지도에 오버레이가 추가되어있는지 여부를 리턴한다.
 * @return 추가된 상태인 상태인 경우 true, 그렇지 않을 경우 false.
 */
- (bool)isAdded;

/**
 *  overlay의 우선순위를 강제적으로 조정 할 수 있는 기능
 */
- (void)setZIndex:(int)zIndex;

// 시스템 내부적으로 사용
- (void *)getNativeOverlay;

// 시스템 내부적으로 사용
- (void) setMap:(GMapView *)mapView;

// 시스템 내부적으로 사용
- (GMapView *)getMap;

@end
