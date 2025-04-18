/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Source code pro:size=20" };
static const char dmenufont[]       = "Source code pro:size=22";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#a8a8a8";
static const char col_gray4[]       = "#dadada";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
    /*
     * Go will match google-chrome
     */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "feh",      NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[M]",      monocle },    /* []=first entry is default */
	{ "[T]",      tile }, /* one window */
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid }, /* table */
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "[F]",      NULL },    /* ><>no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY ControlMask
#define TAGKEYS(KEY,TAG) \
	{ KeyPress,	Mod1Mask,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ KeyPress,	Mod1Mask|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ KeyPress,	Mod1Mask|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ KeyPress,	Mod1Mask|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "50x15", NULL };
static const char *slockscreen[]  = { "slock", NULL };
// static const char *systempoweroff[]  = { "poweroff", NULL };
// static const char *systemreboot[]  = { "reboot", NULL };
// static const char *lightup[] = {"/usr/local/dwmScript/light-up.sh", NULL};
// static const char *lightdown[] = {"/usr/local/dwmScript/light-down.sh", NULL};
// static const char *soundup[] = {"/usr/local/dwmScript/sound-up.sh", NULL};
// static const char *sounddown[] = {"/usr/local/dwmScript/sound-down.sh", NULL};
// static const char *soundmute[] = {"/usr/local/dwmScript/sound-mute.sh", NULL};
// static const char *touchpadswitch[] = { "/usr/local/dwmScript/touchpad-switch.sh", NULL};
// static const char *barmessage[] = {"/usr/local/dwmScript/bar-message.sh", NULL};
static const char *screenshotpart[] = {"/usr/local/dwmScript/screenshot-part.sh", NULL};
static const char *screenshotwindow[] = {"/usr/local/dwmScript/screenshot-window.sh", NULL};
static const char *screenshotfull[] = {"/usr/local/dwmScript/screenshot-full.sh", NULL};
static const char *screenshotrefer[] = {"/usr/local/dwmScript/screenshot-refer.sh", NULL};
static const char *screenshotocr[] = {"/usr/local/dwmScript/tesseractSimEng.sh", NULL};
static const char *emptydo[]  = { "/usr/bin/echo", NULL };
static const char *hotcmdh[] = {"/usr/local/dwmScript/hotcmd-h.sh", NULL};
static const char *hotcmdj[] = {"/usr/local/dwmScript/hotcmd-j.sh", NULL};
static const char *hotcmdk[] = {"/usr/local/dwmScript/hotcmd-k.sh", NULL};
static const char *hotcmdl[] = {"/usr/local/dwmScript/hotcmd-l.sh", NULL};

static Key keys[] = {
	/* type		modifier                     key        function        argument */
	{ KeyPress,	MODKEY,                       0x3b,      spawn,          {.v = emptydo } },
	{ KeyPress,	MODKEY,                       0x2e,      spawn,          {.v = emptydo } },
	{ KeyPress,	MODKEY|Mod1Mask,              XK_p,      spawn,          {.v = dmenucmd } },
	{ KeyPress,	MODKEY|Mod1Mask,              XK_Return, spawn,          {.v = termcmd } },
	{ KeyPress,	MODKEY|Mod1Mask,              XK_n,      togglescratch,  {.v = scratchpadcmd } },
	/* { KeyPress,	MODKEY|Mod1Mask,              XK_b,      togglebar,      {0} }, */
	// { KeyPress,	MODKEY|Mod1Mask,              XK_b,      spawn,     	 {.v = barmessage } },

	// 系统操作
	// { KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_p,      spawn,          {.v = systempoweroff } },
	// { KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_r,      spawn,          {.v = systemreboot } },
	{ KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_l,      spawn,          {.v = slockscreen } },
	// { KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_Right,  spawn,          {.v = lightup } },
	// { KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_Left,   spawn,          {.v = lightdown } },
	// { KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_Up,     spawn,          {.v = soundup } },
	// { KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_Down,   spawn,          {.v = sounddown } },
	// { KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_space,  spawn,          {.v = soundmute } },
	// { KeyPress,	MODKEY|Mod1Mask|ShiftMask,    XK_t,		 spawn,          {.v = touchpadswitch } },

	// 截图
	{ KeyRelease,	ShiftMask,		      XK_Print,  spawn,          {.v = screenshotpart } },
	/* { KeyPress,	MODKEY,			      XK_Print,  spawn,          {.v = screenshotwindow } }, */
	{ KeyPress,	    Mod1Mask,		      XK_Print,  spawn,          {.v = screenshotfull } },
	{ KeyRelease,	Mod4Mask,		      XK_Print,  spawn,          {.v = screenshotocr } },
	/* { KeyRelease,	MODKEY|Mod1Mask,	      XK_Print,  spawn,          {.v = screenshotrefer } }, */
	{ KeyPress,	    MODKEY,               XK_Print,  spawn,          {.v = screenshotrefer } },

	// 聚焦窗口
	// { KeyPress,	Mod1Mask,                       XK_j,      focusstack,     {.i = +1 } },
	// { KeyPress,	Mod1Mask,                       XK_k,      focusstack,     {.i = -1 } },
	// { KeyPress,	Mod1Mask,                       XK_l,      focusstack,     {.i = +1 } },
	// { KeyPress,	Mod1Mask,                       XK_h,      focusstack,     {.i = -1 } },
	// { KeyPress,	Mod1Mask,			            XK_m,      focusmaster,    {.i = +1} },

	// 排列窗口
	{ KeyPress,	ShiftMask|Mod1Mask,	      XK_j,      inplacerotate,  {.i = +1} },
	{ KeyPress,	ShiftMask|Mod1Mask,	      XK_k,      inplacerotate,  {.i = -1} },
	{ KeyPress,	ShiftMask|Mod1Mask,	      XK_h,      inplacerotate,  {.i = -2} },
	{ KeyPress,	ShiftMask|Mod1Mask,	      XK_l,      inplacerotate,  {.i = +2} },

	// 热功能按键，需要注意按键释放和触发的链接性问题
	{ KeyRelease,	MODKEY|Mod1Mask,	      XK_h,      spawn,  {.v = hotcmdh } },
	{ KeyRelease,	MODKEY|Mod1Mask,	      XK_j,      spawn,  {.v = hotcmdj } },
	{ KeyRelease,	MODKEY|Mod1Mask,	      XK_k,      spawn,  {.v = hotcmdk } },
	{ KeyRelease,	MODKEY|Mod1Mask,	      XK_l,      spawn,  {.v = hotcmdl } },

	// { KeyPress,	MODKEY|Mod1Mask,              XK_i,      incnmaster,     {.i = +1 } },
	// { KeyPress,	MODKEY|Mod1Mask,              XK_d,      incnmaster,     {.i = -1 } },

	// 放大窗口
	{ KeyPress,	MODKEY|Mod1Mask,              0x5b,      setmfact,       {.f = -0.05} },
	{ KeyPress,	MODKEY|Mod1Mask,              0x5d,      setmfact,       {.f = +0.05} },
	// { KeyPress,	MODKEY|Mod1Mask,              XK_y, 	 zoom,           {0} },

	// 窗口间隔
	// { KeyPress,	MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
	// { KeyPress,	MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	// { KeyPress,	MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
	// { KeyPress,	MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	// { KeyPress,	MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
	// { KeyPress,	MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	// { KeyPress,	MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	// { KeyPress,	MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	// { KeyPress,	MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	// { KeyPress,	MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	// { KeyPress,	MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	// { KeyPress,	MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	// { KeyPress,	MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	// { KeyPress,	MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	// { KeyPress,	MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	// { KeyPress,	MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

	{ KeyPress,	Mod1Mask,                     XK_Tab,    view,           {0} },
	{ KeyPress,	MODKEY|Mod1Mask,              XK_z,      killclient,     {0} },

	// 窗口排列方式
	{ KeyPress,	MODKEY|Mod1Mask,              XK_t,      setlayout,      {.v = &layouts[1]} },
	// { KeyPress,	MODKEY|Mod1Mask,              XK_f,      setlayout,      {.v = &layouts[13]} },
	{ KeyPress,	MODKEY|Mod1Mask,              XK_m,      setlayout,      {.v = &layouts[0]} },
	// { KeyPress,	MODKEY|Mod1Mask,              XK_space,  setlayout,      {0} },

	// { KeyPress,	MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },

	{ KeyPress,	Mod1Mask,                     XK_0,      view,           {.ui = ~0 } },
	{ KeyPress,	Mod1Mask|ShiftMask,           XK_0,      tag,            {.ui = ~0 } },

	// 分屏
	// { KeyPress,	Mod4Mask,                     XK_comma,  focusmon,       {.i = -1 } },
	// { KeyPress,	Mod4Mask,                     XK_period, focusmon,       {.i = +1 } },
	// { KeyPress,	Mod4Mask|ShiftMask,           XK_comma,  tagmon,         {.i = -1 } },
	// { KeyPress,	Mod4Mask|ShiftMask,           XK_period, tagmon,         {.i = +1 } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ KeyPress,	Mod1Mask|MODKEY|ShiftMask,    XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	/* { ClkLtSymbol,          0,              Button1,        setlayout,      {0} }, */
	/* { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} }, */
	/* { ClkWinTitle,          0,              Button2,        zoom,           {0} }, */
	/* { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } }, */
	{ ClkClientWin,         MODKEY|Mod1Mask,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY|Mod1Mask,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY|Mod1Mask,         Button3,        resizemouse,    {0} },
	/* { ClkTagBar,            0,              Button1,        view,           {0} }, */
	/* { ClkTagBar,            0,              Button3,        toggleview,     {0} }, */
	/* { ClkTagBar,            MODKEY,         Button1,        tag,            {0} }, */
	/* { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} }, */
};

