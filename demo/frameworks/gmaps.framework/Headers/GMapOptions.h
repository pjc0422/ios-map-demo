//
//  GMapOptions.h
//  OllehMapSDK
//
//  Created by gisdev on 2015. 1. 30..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GViewpoint.h"
#import <geom/geom.h>

/**
 @class GMapOptions
  지도 생성시 초기옵션을 정의한다. [GMapView initWithFrame:mapOptions:] 의 파라미터로 사용된다.
 */
@interface GMapOptions : NSObject

/**
  초기 viewpoint 를 설정한다.
 */
@property GViewpoint* viewpoint;

/**
  지도의 최대 영역을 정의한다.
 */
@property id<GBounds> maxExtent;

/**
  최소 줌 레벨을 설정한다.
 */
@property float minZoom;

/**
  최대 줌 레벨을 설정한다.
 */
@property float maxZoom;

/**
  줌별 최대 tilt 값을 설정한다.
 key: (NSNumber) 줌
 value: (NSNumber) tilt
 */
@property NSDictionary *maxTilt;

/**
  팬 제스쳐 활성화 여부를 지정한다. 팬 제스쳐 활성화 여부와는 별개로 API 를 통한 패닝은 항상 허용된다.
 */
@property (nonatomic) BOOL panGesturesEnabled;

/**
  줌 제스쳐 활성화 여부를 지정한다. 줌 제스쳐 활성화 여부와는 별개로 API 를 통한 줌은 항상 허용된다.
 */
@property (nonatomic) BOOL zoomGesturesEnabled;

/**
  로테이트 제스쳐 활성화 여부를 지정한다. 로테이트 제스쳐 활성화 여부와는 별개로 API 를 통한 로테이트는 항상 허용된다.
 */
@property (nonatomic) BOOL rotateGesturesEnabled;

/**
  틸트 제스쳐 활성화 여부를 지정한다. 틸트 제스쳐 활성화 여부와는 별개로 API 를 통한 틸트는 항상 허용된다.
 */
@property (nonatomic) BOOL tiltGesturesEnabled;

/**
 렌더링 fps
 */
@property (nonatomic) float renderFps;

@end
