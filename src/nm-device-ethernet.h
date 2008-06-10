/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */

/* NetworkManager -- Network link manager
 *
 * Dan Williams <dcbw@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * (C) Copyright 2005 Red Hat, Inc.
 */

#ifndef NM_DEVICE_ETHERNET_H
#define NM_DEVICE_ETHERNET_H

#include <glib-object.h>
#include <net/ethernet.h>

#include "nm-device.h"

G_BEGIN_DECLS

#define NM_TYPE_DEVICE_ETHERNET			(nm_device_ethernet_get_type ())
#define NM_DEVICE_ETHERNET(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), NM_TYPE_DEVICE_ETHERNET, NMDeviceEthernet))
#define NM_DEVICE_ETHERNET_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass),  NM_TYPE_DEVICE_ETHERNET, NMDeviceEthernetClass))
#define NM_IS_DEVICE_ETHERNET(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), NM_TYPE_DEVICE_ETHERNET))
#define NM_IS_DEVICE_ETHERNET_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass),  NM_TYPE_DEVICE_ETHERNET))
#define NM_DEVICE_ETHERNET_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj),  NM_TYPE_DEVICE_ETHERNET, NMDeviceEthernetClass))

#define NM_DEVICE_ETHERNET_HW_ADDRESS "hw-address"
#define NM_DEVICE_ETHERNET_SPEED "speed"
#define NM_DEVICE_ETHERNET_CARRIER "carrier"

typedef struct {
	NMDevice parent;
} NMDeviceEthernet;

typedef struct {
	NMDeviceClass parent;

	/* Signals */
	void (*properties_changed) (NMDeviceEthernet *device, GHashTable *properties);
} NMDeviceEthernetClass;


GType nm_device_ethernet_get_type (void);


NMDeviceEthernet *nm_device_ethernet_new (const char *udi,
										  const char *iface,
										  const char *driver,
										  gboolean managed);

void nm_device_ethernet_get_address (NMDeviceEthernet *dev,
								   struct ether_addr *addr);

gboolean nm_device_ethernet_get_carrier (NMDeviceEthernet *dev);

G_END_DECLS

#endif	/* NM_DEVICE_ETHERNET_H */
