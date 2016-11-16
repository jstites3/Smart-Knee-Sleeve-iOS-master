//
//  BEFoldMenuViewController.h
//  vozForums
//
//  Created by Vũ Trường Giang on 7/21/16.
//  Copyright © 2016 Vũ Trường Giang. All rights reserved.
//

#import <UIKit/UIKit.h>
@import CoreBluetooth;

#define DEFAULT_MAIN_SEGUE_IDENTIFIER @"mainSegueIdentifier"
#define DEFAULT_LEFT_SEGUE_IDENTIFIER @"leftSegueIdentifier"
#define DEFAULT_RIGHT_SEGUE_IDENTIFIER @"rightSegueIdentifier"
#define NRF52_DEVICE_INFO_UUID @"180A"
#define NFR52_ANGLE_MEASUREMENTS_UUID @""


typedef NS_ENUM(NSUInteger, BSMenuState) {
    BSMenuStateLeftOpen,
    BSMenuStateRightOpen,
    BSMenuStateCenterOpen,
};

@protocol BEFoldMenuDelegate;

@interface BEFoldMenuViewController : UIViewController<UIScrollViewDelegate, CBCentralManagerDelegate, CBPeripheralDelegate>

@property (nonatomic, strong) UIViewController *mainViewController;

@property (nonatomic, strong) UIViewController *leftViewController;
@property (nonatomic, assign) BOOL leftMenuEnabled;
@property (nonatomic, assign) BOOL foldEffeectEnabled;
@property (nonatomic, assign) CGFloat leftMenuWidth;

@property (nonatomic, strong) UIViewController *rightViewController;
@property (nonatomic, assign) BOOL rightMenuEnabled;
@property (nonatomic, assign) CGFloat rightMenuWidth;

@property (nonatomic, weak) id<BEFoldMenuDelegate> delegate;

@property (nonatomic, assign, readonly ) BSMenuState menuState;
@property (nonatomic, assign, readonly) BOOL isDragging;

@property (nonatomic, strong) UIColor *topShadowColor;
@property (nonatomic, assign) CGFloat topShadowWidth;
@property (nonatomic, assign) CGFloat topShadowOpacity;

@property (nonatomic, assign) CGFloat animationDuration;


//Properties for support Storyboard
@property (nonatomic,copy) NSString *mainSegueIdentifier;
@property (nonatomic,copy) NSString *leftSegueIdentifier;
@property (nonatomic,copy) NSString *rightSegueIdentifier;

//Properties for bluetooth
@property (nonatomic, strong) CBCentralManager *centralManager;
@property (nonatomic, strong) CBPeripheral     *PCBPeripheral;

// Properties for your Object controls
@property (nonatomic, strong) IBOutlet UIImageView *heartImage;
@property (nonatomic, strong) IBOutlet UITextView  *deviceInfo;

// Properties to hold data characteristics for the peripheral device
@property (nonatomic, strong) NSString   *connected;
@property (nonatomic, strong) NSString   *bodyData;
@property (nonatomic, strong) NSString   *manufacturer;
@property (nonatomic, strong) NSString   *NRFDeviceData;
@property (assign) uint16_t kneeAngleData;

// Properties to handle storing the BPM and heart beat
@property (nonatomic, strong) UILabel    *kneeAngle;
@property (nonatomic, retain) NSTimer    *pulseTimer;

// Instance method to get the heart rate BPM information
- (void) getKneeAngleData:(CBCharacteristic *)characteristic error:(NSError *)error;

// Instance methods to grab device Manufacturer Name, Body Location
- (void) getManufacturerName:(CBCharacteristic *)characteristic;
//- (void) getBodyLocation:(CBCharacteristic *)characteristic;

// Instance method to perform heart beat animations
- (void) doHeartBeat;


-(void)leftMenuAction;
-(void)rightMenuAction;

@end

#pragma mark - BEFoldMenuDelegate
@protocol BEFoldMenuDelegate <NSObject>
//
-(void)foldMenuControllerWillBeginDragging:(UIViewController*) foldMenuController;
-(void)foldMenuControllerWillEndDragging:(UIViewController*) foldMenuController;
-(void)foldMenuControllerDidEndDragging:(UIViewController*) foldMenuController;
-(void)foldMenuControllerWillStartAnimation:(UIViewController*) foldMenuController duration:(CGFloat) duration;
-(void)foldMenuControllerDidEndAnimation:(UIViewController*) foldMenuController;


//Left
-(void)foldMenuController:(UIViewController*) foldMenuController didShowLeftMenu:(UIViewController*) leftMenuController;
//Right
-(void)foldMenuController:(UIViewController*) foldMenuController didShowRighMenu:(UIViewController*) leftMenuController;
//Hide
-(void)foldMenuControllerDidHideMenu:(UIViewController*) foldMenuController;
@end

#pragma mark - UIViewController Extension
@interface UIViewController (FoldMenuController)

-(BEFoldMenuViewController*)foldMenuController;

@end
