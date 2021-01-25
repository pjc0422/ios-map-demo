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

#import <UIKit/UIKit.h>

/**
 기본 지도 스타일. `[GMapView setStyle:]` 의 파라미터로 사용된다.
 */
extern NSString* DEFAULT_MAP_STYLE;

/**
  기본 지도 이미지 파일. `[GMapView setImage:]` 의 파라미터로 사용된다.
 */
extern NSString* DEFAULT_IMAGE;

/**
  기본 지도 이미지 정보파일. `[GMapView setImage:]` 의 파라미터로 사용된다.
 */
extern NSString* DEFAULT_IMAGE_INFO;


@protocol GCoord;
@protocol GBounds;
@protocol GMapViewDelegate;
@protocol GTrafficLayerAdaptor;

@class GViewpoint;
@class GViewpointChange;
@class GVisibleRegion;
@class GOverlay;
@class GMapOptions;
@class GInfoWindow;
@class GMapLabelInfo;
@class GMapLabelOption;


typedef NS_ENUM(NSUInteger, GLanguage) {
    GKorean = 4,
    GEnglish,
    GChinese,
};

// -1 : 작은 폰트 , 0 : 기본 폰트, 1 : 큰글씨
typedef NS_ENUM(NSInteger, GFontMode) {
    GUndefined=-2,
    GSmall=-1,
    GNormal,
    GLarge,
    GLarge2,
    GLarge3
};

//0=정보없음, 1=원활, 2=서행, 3=지체, 4=정체
typedef NS_ENUM (NSUInteger, GTrafficState) {
    GTrafficUnknown = 0,
    GTrafficLight,
    GTrafficSlow,
    GTrafficDelay,
    GTrafficCongested
};

//61=상세도로/단지내도로, 62=소로, 63=중로 64=대로, 65=국가지원지방도/지방도, 66=국도, 67=도시고속도로, 68=고속도로
typedef NS_ENUM (NSInteger, GRoadType) {
    GUNKNOWN_ROAD = -1,
    GDETAILED_ROAD = 61,
    GSMALL_ROAD,
    GMIDDLE_ROAD,
    GBIG_ROAD,
    GPROVINCIAL_ROAD,
    GNATIONAL_ROAD,
    GCITY_HIGHWAY,
    GHIGHWAY
};

//제한속도, 도로종별
typedef NS_ENUM(NSUInteger, GTrafficStateRequestType) {
    GMAX = 0,
    GPANE
};
#define gTrafficStateRequestTypeToString(enum) [@[@"max",@"pane"] objectAtIndex:enum]


/**
 @breif 애니메이션을 적용할때 사용할 타이밍 펑션을 정의한다.
   타이밍 펑션에 대해서는 다음 사이트를 참고 http://cubic-bezier.com/
 */
typedef NS_ENUM(NSUInteger, GAnimationTiming) {
    GAnimationTimingLinear,
    GAnimationTimingEaseIn,
    GAnimationTimingEaseOut,
    GAnimationTimingEaseInOut,
    GAnimationTimingSin,
    GAnimationTimingDrop,
    GAnimationTimingDefault
};

typedef NS_ENUM(NSUInteger, GAnimationState) {
    GAnimationStateComplete,
    GAnimationStateCancel
};
/**
 @brief animation state의 변경을 callback 받는 block
 */
typedef void(^GAnimationCompletionBlock)(GAnimationState state);

typedef NS_ENUM(NSInteger, GMapLoadResult) {
    GMapLoadSuccess,
    GMapLoadFail,
    GMapLoadEmpty,
    GMapLoadInvalid,
    GMapKeyExpired
};

/**
    GMapView 클래스는 벡터맵 SDK 의 기능들을 사용하기 위한 시작점(Entry Point)이 된다.
   GMapView 객체는 [GMapView initWithFrame:mapOptions:] 생성자를 사용해서 생성할 수 있다.
 */
IB_DESIGNABLE
@interface GMapView : UIView
/**
 지도의 minZoom xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGFloat minimumZoom;
/**
 지도의 maxZoom xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGFloat maximumZoom;
/**
 지도의 초기 rotation xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGFloat rotation;
/**
 지도의 초기 확대 정도 rotation xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGFloat defaultZoom;
/**
 지도의 초기 기울기 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGFloat defaultTilt;
/**
 지도의 초기 위치 좌표값 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGPoint centerLocationLngLat;
/**
 지도의 최대 확장 하단 지점 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGPoint maxEntendsMinPoint;
/**
 지도의 최대 확장 상단 지점 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGPoint maxEntendsMaxPoint;
/**
 지도의 최대 기울기 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable NSString* maximumTilt;
/**
 지도의 pan 제스쳐 사용여부 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable BOOL panGesture;
/**
 지도의 확대/축소 제스쳐 사용여부 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable BOOL zoomGesture;
/**
 지도의 회전 제스쳐 사용여부 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable BOOL rotateGesture;
/**
 지도의 기울임 제스쳐 사용여부 xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable BOOL tiltGesture;
/**
 렌더링 틱 기본값 : 20fps xib,Storyboard에서 생성
 */
@property (nonatomic) IBInspectable CGFloat renderFps;
/**
    GMapViewDelegate
 */
@property (nonatomic, weak) id<GMapViewDelegate> delegate;

/**
    지도의 시점 (Viewpoint) 을 나타낸다.
 */
@property (nonatomic, readonly) GViewpoint* viewpoint;

/**
    지도 애니메이션이 진행중인지 여부를 나타낸다.
 */
@property (nonatomic, readonly) BOOL animationInProgress;

/**
    지도의 가시영역 (GVisibleRegion) 을 나타낸다.
 */
@property (nonatomic, readonly) GVisibleRegion* visibleRegion;

//@property (nonatomic, weak) id<GImportStateDelegate> importDelegate;

- (void) setTrafficAdaptor:(id<GTrafficLayerAdaptor>) trafficAdaptor;

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
    저레벨 배경 레이어의 화면 출력 여부를 지정한다.
 */
@property (nonatomic) BOOL lowLevelBackgroundLayerVisible;

/**
    배경 레이어 화면 출력 여부를 지정한다.
 */
@property (nonatomic) BOOL backgroundLayerVisible;

/**
  도로 레이어 화면 출력 여부를 지정한다.
 */
@property (nonatomic) BOOL roadLayerVisible;


/**
    빌딩 레이어 화면 출력 여부를 지정한다.
 */
@property (nonatomic) BOOL buildingLayerVisible;

/**
    오버레이 레이어 화면 출력 여부를 지정한다.
 */
@property (nonatomic) BOOL overlayLayerVisible;

/**
    주기 레이어 화면 출력 여부를 지정한다.
 */
@property (nonatomic) BOOL labelLayerVisible;

/**
    저레벨 주기 레이어 화면 출력 여부를 지정한다.
 */
@property (nonatomic) BOOL lowLevelLabelLayerVisible;

/**
    네트워크 레이어의 화면 출력 여부를 지정한다.
 */
@property (nonatomic) BOOL networkLayerVisible;

/**
    화면에 보여지는 오버레이 객체들로 이루어진 배열
 */
@property (nonatomic, readonly) NSArray* visibleOverlays;

/**
    화면에 보여지는 주기(POI)의 사이즈
 */
@property (nonatomic) GFontMode fontMode;

/**
    화면에 표현되는 건물의 갯수를 줄여줌.
 */
@property (nonatomic) BOOL driveMode;


/**
 네트워크레이어 타입
 */
@property (nonatomic) int networkLayerType;

/**
    주어진 frame 과 옵션으로 지도객체를 초기화한다.

   @param frame Frame 객체
   @param mapOptions 옵션
   @return 지도객체
 */
- (instancetype)initWithFrame:(CGRect)frame mapOptions:(GMapOptions *)mapOptions;

/**
 *  네트워크 링크 데이터 업데이트
 * {@link GMapView#updateNetworkLink:true}
 * default : true
 */
- (void)updateNetworkLink;

/**
 *  네트워크 링크 데이터 업데이트
 * @param BOOL 케쉬 clear 여부
 */
- (void)updateNetworkLink:(BOOL) isCacheClear;

/**
 3D 모드에서 화면의 소실점을 설정하는 값으로
 0~1 로 값을 정의한다.
 default : 0.5
 */
-(void) setVanishingPointX:(float) vanishingPointX;
/**
  지도의 최대 영역을 정의한다.
 @param 지도의 최대 영역
 */
- (void)setMaxExtent:(id<GBounds>) maxExtent;

/**
  최소 줌 레벨을 설정한다.
 @param 최소 줌 레벨
 */
- (void)setMinZoom:(float)minZoom;

/**
  최대 줌 레벨을 설정한다.
 @param 최대 줌 레벨
 */
- (void)setMaxZoom:(float)maxZoom;

/**
  줌별 최대 tilt 값을 설정한다.
 @param 줌별 최대 tilt. key: (NSNumber) 줌. value: (NSNumber) tilt
 */
- (void)setMaxTilt:(NSDictionary *) maxTilt;

/**
    지도의 viewpoint 를 지정된 값으로 애니메이션없이 변경한다.

   @param viewpoint Viewpoint값
 */
- (void)moveTo:(GViewpoint *) viewpoint;

/**
    현재 Viewpoint를 viewpointChange 에서 정의하는 상태로
   애니메이션 효과 없이 변경한다.

   @param viewpointChange Viewpoint 변경
 */
- (void)changeViewpoint:(GViewpointChange *)viewpointChange;

/**
 현재 Viewpoint를 viewpointChange 에서 정의하는 상태로
 애니메이션 효과와 함께 변경한다. 애니메이션 지속시간은 duration 으로 지정할 수 있다.
 
 @param viewpointChange Viewpoint 변경
 @param duration millisecond 단위의 애니메이션 지속 시간.
 @param timingFuction 애니메이션에 적용할 타이밍펑션
 @param fps 애니메이션에 적용할 fps.
 @param complete 요청한 애니매이션의 수행 결과값.
 */
-(void) animateViewpoint:(GViewpointChange *)viewpointChange
                duration:(int)duration
         animationTiming:(GAnimationTiming)animationTiming
                     fps:(float)fps
                complete:(GAnimationCompletionBlock)complete;
/**
  현재 Viewpoint를 viewpointChange 에서 정의하는 상태로
 애니메이션 효과와 함께 변경한다. 애니메이션 지속시간은 duration 으로 지정할 수 있다.
 
 @param viewpointChange Viewpoint 변경
 @param duration millisecond 단위의 애니메이션 지속 시간.
 @param timingFuction 애니메이션에 적용할 타이밍펑션
 @param fps 애니메이션에 적용할 fps.
 */
- (void)animateViewpoint:(GViewpointChange *)viewpointChange
                duration:(int)duration
         animationTiming:(GAnimationTiming)animationTiming
                     fps:(float)fps;

/**
  현재 Viewpoint를 viewpointChange 에서 정의하는 상태로
 애니메이션 효과와 함께 변경한다. 애니메이션 지속시간은 duration 으로 지정할 수 있다.

 @param viewpointChange Viewpoint 변경
 @param duration millisecond 단위의 애니메이션 지속 시간.
 @param timingFuction 애니메이션에 적용할 타이밍펑션
 */
- (void)animateViewpoint:(GViewpointChange *)viewpointChange
                duration:(int)duration
         animationTiming:(GAnimationTiming)animationTiming;

/**
    현재 Viewpoint를 viewpointChange 에서 정의하는 상태로
   애니메이션 효과와 함께 변경한다. 애니메이션 지속시간은 duration 으로 지정할 수 있다.

   @param viewpointChange Viewpoint 변경
   @param duration millisecond 단위의 애니메이션 지속 시간.
  @param fps 애니메이션에 적용할 fps.
 */
- (void)animateViewpoint:(GViewpointChange *)viewpointChange
                duration:(int)duration
                     fps:(float)fps;

/**
  현재 Viewpoint를 viewpointChange 에서 정의하는 상태로
 애니메이션 효과와 함께 변경한다. 애니메이션 지속시간은 duration 으로 지정할 수 있다.

 @param viewpointChange Viewpoint 변경
 @param duration millisecond 단위의 애니메이션 지속 시간.
 */
- (void)animateViewpoint:(GViewpointChange *)viewpointChange
                duration:(int)duration;

/**
    현재 Viewpoint를 viewpointChange 에서 정의하는 상태로
   애니메이션 효과와 함께 변경한다.

   @param viewpointChange Viewpoint 변경
 */
- (void)animateViewpoint:(GViewpointChange *)viewpointChange;

/**
    애니메이션이 진행중이면 애니메이션을 중단한다.
 */
- (void)stopAnimation;

/**
    지도에 오버레이를 추가한다.

   @param overlay 지도에 추가할 오버레이 객체
   @throws NSObjectNotAvailableException 오버레이가 지도에 추가 가능한 상태가 아닌 경우 exception을 발생시킨다.
 */
- (void)addOverlay:(GOverlay *)overlay;

/**
    지도에서 오버레이를 제거한다.

   @param overlay overlay 지도에서 제거할 오버레이 객체
 */
- (void)removeOverlay:(GOverlay *)overlay;

/**
    지도에 추가된 오버레이들을 제거한다.
 */
- (void)clearOverlays;
/**
  화면좌표를 지도좌표로 변환한다.
 
 @param point 화면좌표
 @return 지도좌표
 */
- (id<GCoord>)coordFromViewportPoint:(CGPoint)point;

/**
  지도좌표를 화면좌표로 변환한다.
 
 @param coord 지도좌표
 @return 화면좌표
 */
- (CGPoint)viewportPointFromCoord:(id<GCoord>)coord;

/**
 @breif 현재 줌레벨에서의 화면상 1point에 해당하는 지도상의 거리를 미터단위로 반환한다.
 
 @return resolution in meter per point
 */
- (float)getResolution;

/**
 @breif 입력된 줌레벨에서의 화면상 1point에 해당하는 지도상의 거리를 미터단위로 반환한다.
 
 @param zoom 줌레벨
 @return resolution in meter per point
 */
- (float)getResolutionOfZoom:(float)zoom;

/**
 * @breif 지도의 기본 언어를 설정한다.
 */
- (void)setLanguage:(GLanguage)language;

/**
  지도 스타일을 동적으로 변경한다.
 
 파라미터로 사용자 정의 스타일 파일에 대한 완전한 경로를 지정한다. 예를 들어 style.json 을 지도 현재 스타일로 적용하는 예제는 다음과 같다.
 @code 
    NSString* stylePath = [[NSBundle mainBundle] pathForResource:@"style.json" ofType:nil];
    [self.mapView setStyle:stylePath];
 @endcode
 올레맵 기본 스타일은 DEFAULT_MAP_STYLE 로 정의된다.
 @code
    [self.mapView setStyle:DEFAULT_MAP_STYLE];
 @endcode
 @param stylePath 스타일 파일 경로
 */
- (void)setStyle:(NSString *)stylePath;

- (void)animateStyle:(NSString *)stylePath duration:(NSInteger) duration;

- (void)animateStyle:(NSString *)stylePath;

- (void)setDefaultMapStyle;
/**
  지도 스타일을 동적으로 변경한다.
  변경후에 현재보여지는 빌딩레이어를 강제 업데이트 한다.

 파라미터로 사용자 정의 스타일 파일에 대한 완전한 경로를 지정한다. 예를 들어 style.json 을 지도 현재 스타일로 적용하는 예제는 다음과 같다.
 @code
    NSString* stylePath = [[NSBundle mainBundle] pathForResource:@"style.json" ofType:nil];
    [self.mapView setStyle:stylePath];
 @endcode
 올레맵 기본 스타일은 DEFAULT_MAP_STYLE 로 정의된다.
 @code
    [self.mapView setStyle:DEFAULT_MAP_STYLE];
 @endcode
 @param stylePath 스타일 파일 경로
 */
- (void)setStyleAndUpdateCurrentLayer:(NSString *)stylePath;

/**
  지도 Texture atlas 이미지(POI 아이콘, 패스 이미지등)를 동적으로 변경한다.

 파라미터로 사용자 정의 파일에 대한 완전한 경로를 지정한다. 예를 들어 image.png, imageInfo.txt 을 지도에 적용하는 예제는 다음과 같다.

     NSString* imagePath = [[NSBundle mainBundle] pathForResource:@"image.png" ofType:nil];
     NSString* imageInfoPath = [[NSBundle mainBundle] pathForResource:@"imageInfo.txt" ofType:nil];
     [self.mapView setImage:imagePath imageInfoPath:imageInfoPath];

 올레맵 기본 Texture altas 이미지는 DEFAULT_IMAGE, DEFAULT_IMAGE_INFO로 정의된다.

     [self.mapView setImage:DEFAULT_IMAGE imageInfoPath:DEFAULT_IMAGE_INFO];

 @param imagePath imagePath 이미지 파일 경로
 @param imageInfoPath imageInfoPath 이미지정보 파일 경로
 */
- (void)setSystemImage:(NSString *)imagePath imageInfoPath:(NSString *)imageInfoPath;

- (GInfoWindow  *)getInfoWindow;

- (GMapLoadResult) getLoadResult ;

/**
  기본 InfoWindow의 UIView를 반환한다.

 @param infoWindow `GInfoWindow`
 */
- (UIView  *)didShowDefaultInfoWindow:(GInfoWindow *)infoWindow;

/**
 * 특정 지도좌표를 포함하는 빌딩을 하이라이트 한다.
 *
 * @param coord 지도좌표
 */
- (void)addBuildingFocus:(id<GCoord>)coord;

/**
 * 특정 지도좌표를 포함하는 여러개의 빌딩을 하이라이트 한다.
 *
 * @param coordList 지도좌표 리스트
 */
- (void)addBuildingFocuses:(NSArray *)coordArr;

/**
 특정 지도좌표를 포함하는 빌딩 폴리곤의 하이라이트 효과를 제거한다.

 @param coord 지도좌표
 */
- (void)removeBuildingFocus:(id<GCoord>)coord;

/**
 * 특정 지도좌표를 포함하는 빌딩 폴리곤의 하이라이트 효과를 제거한다.
 * @param coordList 지도좌표 리스트
 */
- (void)removeBuildingFocuses:(NSArray *)coordArr;

/**
 * 모든 빌딩 하이라이트 효과를 제거한다.
 */
- (void)clearBuildingFocuses;

/**
 지도위의 label image 탭(tap) 이벤트가 발생될 때 해당 image를 어떤 조건으로 focus줄 지 정하는 option
 */
-(void) setGMapLabelFocusOption:(GMapLabelOption*) option;

/**
 지도 위에 선택된 label의 focus effect를 제거하여 선택되기 전으로 되돌림.
 */
-(void) releaseLabelFocus;
/**
 해당 카테고리 아이디의 Label tap event를 제공 하지 않는다.
 @param categoryId label의 카테고리 아이디
 */
-(void) addIgnoreLabelFocus:(NSInteger) categoryId;
/**
 해당 카테고리 아이디의 Label tap event를 제공함.
 @param categoryId label의 카테고리 아이디
 */
-(void) removeIgnoreLabelFocus:(NSInteger) categoryId;

/**
 * UV 통계를 위한 unique client id 를 설정한다.
 * @param id 설정할 client id
 */
- (void)setClientId:(NSString *)idString;

/**
 * 경로 근처의 POI만 보여준다.
 * 단, 중요도도 높은 POI의 경우는 예외임.
 * @param points 경로. 출발지좌표, 경로, 목적지좌표를 포함한다.
 * @param bufferWidth 버퍼 너비(미터 단위).
 * @param minZoom 최소 줌
 * @param maxZoom 최대 줌
 * @note throw NSInvalidArgumentException: bufferWidth 0 이하인 경우, points의 점의 갯수가 2 미만인 경우, points에 `GCoord` 이외의 오브젝트가 포함 된 경우.
 */
- (void)applyPoiPath:(NSArray *) points
         bufferWidth:(float) bufferWidth
             minZoom:(float) minZoom
             maxZoom:(float) maxZoom;


/**
 * 경로 반경만 POI표출했던 것을 취소한다.
 */
-(void)cancelPoiPath;

/**
 * 빌딩의 3d 표현 여부를 설정한다.
 * 기본값은 `true` 이다.
 *
 * @param enable 빌딩의 3d 표현 여부
 */
- (void)setBuilding3dEnabled:(bool)enable;

/**
 * 빌딩을 3d 로 표현할 최소 줌레벨 값을 지정한다.
 * 기본값은 13 이다.
 *
 * @param zoom 설정할 줌레벨 값.
 *
 * */
- (void)setBuilding3dMinZoom:(int)zoom;


/**
 * 네트워크 레이어 링크들의 상태를 지정한다.
 * @param linkStates 
 *        - key=(NSNumber): 상태값 0=정보없음, 1=원활, 2=서행, 3=지체, 4=정체
 *        - value=(NSArray): 링크아이디로 이루어진 NSArray
 */
-(void)setNetworkLayerLinkStates:(NSDictionary *) linkStates;

/**
 주요도로 교통정보.
 */
-(void) setMainTrafficID:(NSString*) contentID;

/**
 infowindow, marker등을 화면에 add하는 순서가 아닌 화면의 상단을 기준으로 가까운 순서로
 화면에 렌더링함.
 */
-(void) applyOverlayLayerBirdView:(BOOL) useBirdView;

/**
 internal function
 */
-(void) animationComplete:(int) completeId state:(GAnimationState) state;

/**
 폰트 스타일의 특정 속성을 변경
 */
-(void) applyFontStyleElement:(int) paneId
                      strokeR:(int) strokeR strokeG:(int) strokeG strokeB:(int) strokeB strokeA:(float) strokeA
                  strokeWidth:(float) strokeWidth
                        fillR:(int) fiilR fillG:(int) fillG fillB:(int) fillB fillA:(float) fillA
                     fontSize:(int) fontSize
                       dpType:(int) dpType
                      visible:(bool) visible;
/**
 폴리곤 속성의 스타일을 변경
 */
-(void) applyPolygonStyleElement: (int) layerId paneId: (int) paneId
                           fillR: (int) fiilR fillG:(int) fillG fillB:(int) fillB fillA:(float) fillA
                         visible:(bool) visible;
/**
 라인 속성의 스타일을 변경
 */
-(void) applyLineStyleElement:(int) layerId paneId:(int) paneId
                      strokeR:(int) strokeR strokeG:(int) strokeG strokeB:(int) strokeB strokeA:(float) strokeA
                  strokeWidth:(float) strokeWidth
                      visible:(bool) visible;

-(void) resetStyleElement:(NSString *)stylePath;

-(void) setUnDefineTypeFont:(NSInteger )addSize;
@end


/**
  GMapView 이벤트에 대한 delegate
 */
@protocol GMapViewDelegate <NSObject>

@optional
/**
  Viewpoint 가 변경될때 호출된다.
 
 @param mapView 이벤트가 발생된 GMapView 객체
 @param viewpoint 변경된 viewpoint
 @param gesture 제스쳐 발생 여부
 */
- (void)mapView:(GMapView *)mapView didChangeViewpoint:(GViewpoint *)viewpoint withGesture:(BOOL)gesture;

/**
  idle 이벤트 발생시 호출된다.
 
 Viewpoint 변경 이벤트가 발생한 후 일정시간 delay 가 진후 idle 이벤트가 발생한다.
 연속적인 viewpoint 변경 이벤트가 일정시간 delay 이내에 발생하는 경우
 마지막 viewpoint 변경 이벤트에 대해서만 idle 이벤트가 발생된다.
 @param mapView 이벤트가 발생된 GMapView 객체
 @param viewpoint 변경된 viewpoint
 */
- (void)mapView:(GMapView *)mapView didIdleAtViewpoint:(GViewpoint *)viewpoint;

/**
  지도 애니메이션 종료시 호출된다.
 @param 지도 애니메이션 종료 상태. 정상종료시 GAnimationStateEnd 가 전달되고 취소될경우 GAnimationStateCancel 이 전달된다.
 */
- (void)mapView: (GMapView *)mapView didAnimationEnd:(GAnimationState)animationState;

/**
  사용자가 지도를 long press 하는 경우 호출된다.
 
 @param mapView 이벤트가 발생된 GMapView 객체
 @param coord long press 이벤트 좌표
 */
- (void)mapView:(GMapView *)mapView didLongPressAtCoord:(id<GCoord>)coord;

/**
  사용자가 지도를 tap 하는 경우 호출된다.
 
 @param mapView 이벤트가 발생된 GMapView 객체
 @param coord tap 이벤트 좌표
 */
- (void)mapView:(GMapView *)mapView didTapAtCoord:(id<GCoord>)coord;

/**
  사용자가 Overlay 를 tap 하는 경우 호출된다.
 
 반환값이 true인 경우 지도의 기본 동작을 수행하지 않는다.
 예를 들어 마커를 탭했을 때 인포윈도우가 지도에 추가되는 것이 기본 동작인데, 인포윈도우가 지도에 추가되는 것을 수행하지 않도록 한다.
 
 @param mapView 이벤트가 발생된 GMapView 객체
 @param overlay tap 이벤트가 발생한 Overlay 객체
 @return 지도의 기본 동작을 해지하려면 true, 그렇지 않을 경우 false.
 */
- (BOOL)mapView:(GMapView *)mapView didTapOverlay:(GOverlay *)overlay;

/**
  Overlay drag start 이벤트 발생시 호출된다.
 
 @param mapView 이벤트가 발생된 GMapView 객체
 @param overlay Overlay 객체
 */
- (void)mapView:(GMapView *)mapView didStartDraggingOverlay:(GOverlay *)overlay;

/**
  Overlay drag 이벤트 발생시 호출된다.

 @param mapView 이벤트가 발생된 GMapView 객체
 @param overlay Overlay 객체
 */
- (void)mapView:(GMapView *)mapView didDragOverlay:(GOverlay *)overlay;

/**
  Overlay drag end 이벤트 발생시 호출된다.
 
 @param mapView 이벤트가 발생된 GMapView 객체
 @param overlay Overlay 객체
 */
- (void)mapView:(GMapView *)mapView didEndDraggingOverlay:(GOverlay *)overlay;

/**
  InfoWindow 가 화면에 표시될 때 호출된다. 화면에 어떻게 그려질지 구성한다.

 @param mapView 이벤트가 발생된 GMapView 객체
 @param infoWindow infoWindow 객체
 */
- (UIView  *)mapView:(GMapView *)mapView didShowInfoWindow:(GInfoWindow *)infoWindow;

/**
 지도 화면에 touch event발생시 해당 위치의 label이 있는지 여부 체크

 @param mapView 이벤트가 발생된 GMapView 객체
 @param coord   poi의 좌표
 @param label   poi의 이름
 */
- (BOOL)mapView:(GMapView *)mapView didTapLabelInfo:(GMapLabelInfo*) info;

/**
 지도 화면에 LongPressed event발생시 해당 위치의 label이 있는지 여부 체크

 @param mapView 이벤트가 발생된 GMapView 객체
 @param coord   poi의 좌표
 @param label   poi의 이름
 */
- (BOOL)mapView:(GMapView *)mapView didLongPressLabelInfo:(GMapLabelInfo*) info;
//TODO:- OnMapReady

@end

/**
 *  네트워크 레이어가 로딩될때 발생하는 이벤트를 처리하는 delegate 프로토콜
 */
@protocol GTrafficLayerAdaptor
/**
  도로의 속도에 따른 도로 상태처리 정보를 요청하기위해 도로 타입을 세팅하는 로직
 @return GTrafficStateRequestType 으로 요청 타입 반환
 */
@required
-(GTrafficStateRequestType) setTypeForRequestSpeedToState;
/**
  도로의 속도에 따른 도로 상태를 처리하는 로직부분.
 @param roadType 도로의 타입
 @param speed 도로의 속도
 @return GTrafficState 속도에 따른 도로 상태
 */
@required
-(GTrafficState) speedToState:(NSNumber *)typeValue speed:(NSNumber*) speed;


@end
