/*
 * WPA Supplicant/hostapd / Shared EAP definitions
 * Copyright (c) 2004-2005, Jouni Malinen <jkmaline@cc.hut.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef EAP_DEFS_H
#define EAP_DEFS_H

/* RFC 3748 - Extensible Authentication Protocol (EAP) */

struct eap_hdr {
	u8 code;
	u8 identifier;
	u16 length; /* including code and identifier; network byte order */
	/* followed by length-4 octets of data */
} __attribute__ ((packed));

enum { EAP_CODE_REQUEST = 1, EAP_CODE_RESPONSE = 2, EAP_CODE_SUCCESS = 3,
       EAP_CODE_FAILURE = 4 };

/* EAP Request and Response data begins with one octet Type. Success and
 * Failure do not have additional data. */

typedef enum {
	EAP_TYPE_NONE = 0,
	EAP_TYPE_IDENTITY = 1 /* RFC 3748 */,
	EAP_TYPE_NOTIFICATION = 2 /* RFC 3748 */,
	EAP_TYPE_NAK = 3 /* Response only, RFC 3748 */,
	EAP_TYPE_MD5 = 4, /* RFC 3748 */
	EAP_TYPE_OTP = 5 /* RFC 3748 */,
	EAP_TYPE_GTC = 6, /* RFC 3748 */
	EAP_TYPE_TLS = 13 /* RFC 2716 */,
	EAP_TYPE_LEAP = 17 /* Cisco proprietary */,
	EAP_TYPE_SIM = 18 /* draft-haverinen-pppext-eap-sim-12.txt */,
	EAP_TYPE_TTLS = 21 /* draft-ietf-pppext-eap-ttls-02.txt */,
	EAP_TYPE_AKA = 23 /* draft-arkko-pppext-eap-aka-12.txt */,
	EAP_TYPE_PEAP = 25 /* draft-josefsson-pppext-eap-tls-eap-06.txt */,
	EAP_TYPE_MSCHAPV2 = 26 /* draft-kamath-pppext-eap-mschapv2-00.txt */,
	EAP_TYPE_TLV = 33 /* draft-josefsson-pppext-eap-tls-eap-07.txt */,
	EAP_TYPE_FAST = 43 /* draft-cam-winget-eap-fast-00.txt */,
	EAP_TYPE_PAX = 46, /* draft-clancy-eap-pax-04.txt */
	EAP_TYPE_EXPANDED_NAK = 253 /* RFC 3748 */,
	EAP_TYPE_WSC = 254 /*Wireless Simple Config*/,
	EAP_TYPE_PSK = 255 /* EXPERIMENTAL - type not yet allocated
			    * draft-bersani-eap-psk-09 */
} EapType;

#endif /* EAP_DEFS_H */
