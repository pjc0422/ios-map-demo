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

@class GOverlay;
@class GMarker;
@protocol GCoord;

/**
 * @class GInfoWindow
 *  GInfoWindow는 지도 위에 특정 지점의 정보를 표시하기 위해 제목, 부제목 요소를 가지고 있다.
 *
 * GOverlay
 *   기본 오버레이와 동일하게 개별적으로 지도에 추가, 삭제 가능한다.
 *
 * GMarker 연동
 *   기본 동작
 *     마커에 제목, 부제목이 있는 경우 마커를 탭하면 기본적으로 인포윈도우가 지도에 추가되어 보여지고,
 *     지도를 탭하면 기본적으로 인포윈도우가 지도에서 삭제된다.
 *   기본 동작 해제
 *     GMapViewDelegate.didTapOverlay를 구현해서 TRUE 반환한다.
 *   직접 추가, 삭제
 *     GMarker.showInfoWindow, GMarker.hideInfoWindow
 *
 * UI 변경
 *  GMapViewDelegate.didShowInfoWindow를 구현한다. 구현내에서 조건에 따라 기존 UI를 사용하려면
 *  GMapView.didShowDefaultInfoWindow를 호출한다.
 *
 * @see \ref GOverlay
 * @see \ref GMarker.showInfoWindow
 * @see \ref GMarker.hideInfoWindow
 * @see \ref GMapViewDelegate.didTapOverlay
 * @see \ref GMapViewDelegate.didShowInfoWindow
 * @see \ref GMapView.didShowDefaultInfoWindow
 */
@interface GInfoWindow : GOverlay

/// 위치
@property (nonatomic, copy) id<GCoord> position;

/// 제목 텍스트
@property (nonatomic, copy) NSString *title;

/// 부제목 텍스트
@property (nonatomic, copy) NSString *subTitle;

/// anchor위치 (이미지 크기 대비 백분율 값). 기본값은 (0.5, 1.0)
@property (nonatomic) CGPoint anchor;


/// marker
@property (nonatomic, readonly) GMarker *marker;


/**
 *  인포윈도우의 생성옵션을 이용한 기본 생성자
 * @param options 인포윈도우 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * position         |   (GCoord *)
 * anchor           |   (CGPoint)
 * title            |   (NSString *)
 * subTitle         |   (NSString *)
 * @return 생성된 InfoWindow 객체
 *
 * @code
 * @endcode
 */
+ (instancetype)infowWindowWithOptions:(NSDictionary *)options;


- (void)openWithMarker:(GMarker *)marker;

@end
