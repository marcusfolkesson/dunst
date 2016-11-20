/* copyright 2013 Sascha Kruse and contributors (see LICENSE for licensing information) */

#ifndef _MENU_H
#define _MENU_H

#include "dunst.h"
#include <regex.h>

char *extract_urls(const char *to_match);
void open_browser(const char *url);
void invoke_action(const char *action);

#endif //_MENU_H
