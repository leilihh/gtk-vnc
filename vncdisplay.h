#ifndef _VNC_DISPLAY_H_
#define _VNC_DISPLAY_H_

typedef struct _VncDisplay VncDisplay;
typedef struct _VncDisplayClass VncDisplayClass;
typedef struct _VncDisplayPrivate VncDisplayPrivate;

#include <gtk/gtkdrawingarea.h>
#include <glib.h>

#define VNC_TYPE_DISPLAY (vnc_display_get_type())

#define VNC_DISPLAY(obj) \
        (G_TYPE_CHECK_INSTANCE_CAST((obj), VNC_TYPE_DISPLAY, VncDisplay))

#define VNC_DISPLAY_CLASS(klass) \
        (G_TYPE_CHECK_CLASS_CAST((klass), VNC_TYPE_DISPLAY, VncDisplayClass))

#define VNC_IS_DISPLAY(obj) \
        (G_TYPE_CHECK_INSTANCE_TYPE((obj), VNC_TYPE_DISPLAY))

#define VNC_IS_DISPLAY_CLASS(klass) \
        (G_TYPE_CHECK_CLASS_TYPE((klass), VNC_TYPE_DISPLAY))

#define VNC_DISPLAY_GET_CLASS(obj) \
        (G_TYPE_INSTANCE_GET_CLASS((obj), VNC_TYPE_DISPLAY, VncDisplayClass))

struct _VncDisplay
{
	GtkDrawingArea parent;

	VncDisplayPrivate *priv;
};

struct _VncDisplayClass
{
	GtkDrawingAreaClass parent;

	void (*kvm_switched)(VncDisplayClass *obj, const gchar *string);
};

G_BEGIN_DECLS

GType		vnc_display_get_type(void);
GtkWidget *	vnc_display_new(void);

void		vnc_display_open(VncDisplay *obj, int fd);

void		vnc_display_set_password(VncDisplay *obj, const gchar *password);

G_END_DECLS

#endif