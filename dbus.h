/* copyright 2013 Sascha Kruse and contributors (see LICENSE for licensing information) */

#ifndef _DUNST_DBUS_H
#define _DUNST_DBUS_H

#include <dbus/dbus.h>

#include "notification.h"

int initdbus(void);
void dbus_tear_down(int id);
/* void dbus_poll(int timeout); */
void notificationClosed(notification * n, int reason);
void actionInvoked(notification * n, const char *identifier);

#endif //_DUNST_DBUS_H

/* vim: set ts=8 sw=8 tw=0: */
