//
//  BXBarcodeInfo.h
//  BXSDK
//
//  Created by Savin on 3/20/12.
//  Copyright (c) 2012 ZEBRA. All rights reserved.
//


#import <Foundation/Foundation.h>
@interface BXBarcode:NSObject
{
    
}


@property (assign)  int             barNumber;
@property (assign)	NSString		*name;
@property (assign)	BOOL            support;


- (id)initWithBarNumber:(int)barNum
                   name:(NSString*)barName
                support:(BOOL)isSupport;


@end




@interface BXBarcodeInfo: NSObject
{
    NSMutableArray*                 _pBars;
    
	
}

- (NSMutableArray*) getSuppotList;

- (BOOL) clearObject;
- (BOOL) addObjectWithBarcode:(int)barNum
                         name:(NSString*)barName
                      support:(BOOL)isSupport;
@end
