/* libtinynotify
 * (c) 2011 Michał Górny
 * 2-clause BSD-licensed
 */

#include "config.h"

#include "tinynotify.h"
#include "tinynotify-cli.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
	NotifySession s;
	Notification n;

	n = notification_new_from_cmdline(argc, argv,
			"tinynotify-send " PACKAGE_VERSION);
	if (!n)
		return 1;

	s = notify_session_new("tinynotify-send", NOTIFY_SESSION_NO_APP_ICON);
	if (notification_send(n, s))
		fprintf(stderr, "%s\n", notify_session_get_error_message(s));

	notify_session_free(s);
	notification_free(n);

	return 0;
}
