//
//  BXPrinter.h
//  Demo
//
//  Created on 11. 3. 14..
//  Copyright 2011 Zebra. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDPServerDelegate.h"
#import "BXPrinterControlDelegate.h"
#import "InterfaceFunctionsDelegate.h"
//#import "NetFunctionsDelegate.h"
#import "iControllerDelegate.h"
#import "BXCode.h"

//#import "iController.h"

#define __message(fmt, ...)		/*_log(fmt, ##__VA_ARGS__);	\*/\
if( [self.delegate respondsToSelector:@selector(message:text:)] ) \
[Common dispatchSelector:@selector(message:text:) \
target:self.delegate \
objects:[NSArray arrayWithObjects:self,[NSString stringWithFormat:(fmt), ##__VA_ARGS__],nil] \
onMainThread:YES]

@class	UDPServer;
//@class	NetFunctions;
//@class	BTFunctions;
@class interfaceFunctions;
@class  BXPrinter;
@class	Section;

@interface BXPrinterController : NSObject <UDPServerDelegate, InterfaceFunctionsDelegate, iControllerDelegate>
{
}

@property (retain, readonly)                NSString        *version;
@property (retain, readonly)                NSString        *releaseDate;
@property (retain, readonly)                NSString        *manufacturer;
@property (assign, nonatomic)				int				configPassword;
@property (assign, nonatomic)				int				AutoConnection;
@property (assign, nonatomic)				int				barcodeSupportRange;


@property (assign, nonatomic)				id<BXPrinterControlDelegate>	delegate;
@property (assign, nonatomic)               BXPrinter       *target;

@property (assign, nonatomic)				CGFloat			lookupDuration;
@property (assign, nonatomic, readonly)     unsigned		lookupRemotePort;
@property (assign, nonatomic, readonly)     unsigned		lookupLocalPort;
@property (assign, nonatomic, readonly)     unsigned		lookupRemotePortEthernet;
@property (assign, nonatomic, readonly)     unsigned		lookupLocalPortEthernet;
@property (assign, nonatomic)				unsigned		lookupCount;


@property (assign, nonatomic)				int				alignment;
@property (assign, nonatomic)				int				attribute;
@property (assign, nonatomic)				int				textSize;
@property (assign, nonatomic)				char			characterSet;       // Codepage
@property (assign, nonatomic)				char			textPosition;
@property (assign, nonatomic)				char			internationalCharacterSet;
@property (assign, nonatomic)               long            textEncoding;



@property (assign, nonatomic)				int				drawerPin;
@property (assign, nonatomic)				int				drawerOpenLevel;

@property (assign, nonatomic, readonly)     long			state;
@property (assign, nonatomic, readonly)     long			power;

@property (assign, nonatomic)				BOOL			loadConfigurationOnConnect;
@property (assign, nonatomic)				_BXPrinterConfigrationStruct        *config;
@property (assign, nonatomic)				_BXPrinterSettingConfigrationStruct	*settingConfig;
@property (assign, nonatomic)				CGFloat			pendingWaitTime;

+ (BXPrinterController *)getInstance;

- (void)open;
- (void)close;

- (void)lookup;


- (long) selectTarget;
- (long) selectTarget:(int)modelID;

- (long)initializePrinter;

- (long)checkPrinter;


- (long)checkPrinter:(int)mask;


- (BOOL)connect;
- (void)disconnect;
- (long)disconnectWithTimeout:(int)timeout;

- (long)disconnectWithTimeout:(int)timeout
                   afterSleep:(int)afterSleep;

- (BOOL)isConnected;

- (int)recvValue:(void *)bytes size:(int)size;

- (long)printText:(NSString *)string;
- (long)printBox:(int)width height:(int)height;
- (long)lineFeed:(int)lines;
- (long)nextPrintPos;

- (long)printBarcode:(char *)bytes
		   symbology:(long)symbology
			   width:(long)width
			  height:(long)height;


- (long)printBarcode:(char *)bytes
           symbology:(long)symbology
               width:(long)width
              height:(long)height
   heightOfSeparator:(long)heightOfSeparator;

- (long)printBitmap:(NSString *)path
			  width:(long)width
			  level:(long)level;

- (long)printBitmapWithImage:(UIImage *)image
                       width:(long)width
                       level:(long)level;

- (long)removeNVImage:(int)address;
- (long)removeAllNVImages;
- (long)nvImageList:(NSArray **)images;
- (long)downloadNVImage:(int)address withImage:(UIImage *)image;
- (long)downloadNVImage:(int)address withImage:(UIImage *)image
				  width:(long)width
				  level:(long)level;
- (long)printNVImage:(int)address;


- (long)msrReadReady;
- (long)msrReadCancel;
- (long)msrReadCancelEx;
- (BOOL)msrIsReady;
- (long)msrReadTrack:(NSData **)data1 data2:(NSData **)data2 data3:(NSData **)data3;
- (long)msrGetTrack:(int)track response:(NSData **)response;
- (long)msrReadFullTrack:(NSData **)response;


- (long)directIO:(NSData *)request
	requiredSize:(int)requiredSize
		response:(NSData **)response;


- (long)openDrawer;

// Configuration
- (long)loadConfiguration;
- (long)saveConfiguration;

// COnfiguration
- (long)loadPrinterConfiguration;
- (long)savePrinterConfiguration;

- (long)enableLSB:(BOOL)bEnable;
- (long)enableUpsideDownMode:(BOOL)bEnable;


- (BOOL) isSupport_Barcode;
- (BOOL) isSupport_MSR;
- (BOOL) isSupport_LSB;
- (BOOL) isSupport_PrinterConfig;
- (NSMutableArray*)  getBarcodeSupportTable;



// SetObject;

- (void) setConfigPassword:(int)pw;
- (void) setLookupDuration:(CGFloat)duration;
- (void) setLookupCount:(unsigned)count;
- (void) setAlignment:(int)set;
- (void) setAttribute:(int)set;
- (void) setTextSize:(int)size;
- (void) setCharacterSet:(char)set;
- (void) setTextPosition:(char)position;
- (void) setInternationalCharacterSet:(char)set;
- (void) setLoadConfigurationOnConnect:(BOOL)set;
- (void) setPendingWaitTime:(CGFloat)time;
//- (void) setDelegate:(id <BXPrinterControlDelegate>)_delegate;
//- (void) setTarget:(BXPrinter *)_target;

@end
