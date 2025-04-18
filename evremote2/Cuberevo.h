#ifndef _cuberevo_
#define _cuberevo_

/* ioctl numbers ->hacky */
#define VFDBRIGHTNESS         0xc0425a03
#define VFDPWRLED             0xc0425a04
#define VFDDRIVERINIT         0xc0425a08
#define VFDICONDISPLAYONOFF   0xc0425a0a
#define VFDDISPLAYWRITEONOFF  0xc0425a05
#define VFDDISPLAYCHARS       0xc0425a00

#define VFDCLEARICONS         0xc0425af6
#define VFDSETRF              0xc0425af7
#define VFDSETFAN             0xc0425af8
#define VFDGETWAKEUPMODE      0xc0425af9
#define VFDGETTIME            0xc0425afa
#define VFDSETTIME            0xc0425afb
#define VFDSTANDBY            0xc0425afc
#define VFDREBOOT             0xc0425afd
#define VFDSETLED             0xc0425afe
#define VFDSETMODE            0xc0425aff

#define VFDGETWAKEUPTIME      0xc0425b00
#define VFDGETVERSION         0xc0425b01

struct set_brightness_s
{
	int level;
};

struct set_led_s
{
	int led_nr;
	int on;
};

struct set_fan_s
{
	int on;
};

struct set_rf_s
{
	int on;
};

struct set_icon_s
{
	int icon_nr;
	int on;
};

/* YYMMDDhhmm */
struct set_standby_s
{
	char time[10];
};

/* YYMMDDhhmmss */
struct set_time_s
{
	char time[12];
};

/* YYMMDDhhmmss */
struct get_time_s
{
	char time[12];
};

struct get_wakeupstatus
{
	char status;
};

/* YYMMDDhhmmss */
struct get_wakeuptime
{
	char time[12];
};

/* this setups the mode temporarily (for one ioctl)
 * to the desired mode. currently the "normal" mode
 * is the compatible vfd mode
 */
struct set_mode_s
{
	int compat; /* 0 = compatibility mode to vfd driver; 1 = micom mode */
};

/* 0 = 12dot 12seg, 1 = 13grid, 2 = 12 dot 14seg, 3 = 7seg */
struct get_version_s
{
	int version;
};

struct micom_ioctl_data
{
	union
	{
		struct set_icon_s icon;
		struct set_led_s led;
		struct set_fan_s fan;
		struct set_rf_s rf;
		struct set_brightness_s brightness;
		struct set_mode_s mode;
		struct set_standby_s standby;
		struct set_time_s time;
		struct get_time_s get_time;
		struct get_wakeupstatus status;
		struct get_wakeuptime wakeup_time;
		struct get_version_s version;
	} u;
};

#endif
