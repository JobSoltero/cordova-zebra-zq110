//
//  UDPServerDelegate.h
//  Demo
//
//  Created by Beomjin Kim on 11. 3. 14..
//  Copyright 2011 ZEBRA. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Defines.h"

@interface UDPPacket : NSObject
{
	
}

@property (assign)	SOCKADDR_IN		*addr;
@property (assign)	char			*data;
@property (assign)	int				size;


@end

@protocol UDPServerDelegate <NSObject>

@required
- (void)didUDPReceive:(UDPPacket *)packet;

@optional

- (void)didUDPServiceStart;
- (void)didUDPServiceStop;


@end

