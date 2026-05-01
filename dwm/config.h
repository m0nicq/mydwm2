/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */

static const unsigned int gappih    = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;  /* vert inner gap between windows */
static const unsigned int gappoh    = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        // 1 — удалять внешние отступы при 1 окне
static int enablegaps               = 1;        // 0 — выключить gaps, 1 — включить

static const int horizpadbar        = 10;       /* отступы по горизонтали */
static const int vertpadbar         = 5;        /* отступы по вертикали */

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[]          = { "JetBrainsMonoNL NFP:size=11:style=bold" };
static const char dmenufont[]       = "JetBrainsMonoNL NFP:size=11:style=bold";

static const char col_gray1[]       = "#222222";
// static const char col_gray1[]       = "#0c0b09"; gruvbox
static const char col_gray2[]       = "#444444";
// static const char col_gray3[]       = "#ebdbb2"; /* gruvbox */
// static const char col_gray3[]       = "#b2bfeb"; /* custom_blue */
static const char col_gray3[]       = "#e3aac5"; /* custom_pink */
static const char col_gray4[]       = "#eeeeee";
// static const char col_cyan[]        = "#d65d0e"; /* gruvbox */
// static const char col_cyan[]        = "#0e68d6"; /* custom_blue */
static const char col_cyan[]        = "#c4246f"; /* custom_pink */
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
	/* class               instance    title       tags mask     isfloating   monitor */
    { "Thunar",                NULL,       NULL,       0,            1,           -1 },
    { "VirtualBox Manager",    NULL,       NULL,       0,            1,           -1 },
    { "TelegramDesktop",       NULL,       NULL,       0,            1,           -1 },
    { "gnome-calculator",      NULL,       NULL,       0,            1,           -1 },
    { "burp-StartBurp",        NULL,       NULL,       0,            1,           -1 },
    { "Wireshark",             NULL,       NULL,       0,            1,           -1 },
    { "com.mitchellh.ghostty", NULL,       NULL,       0,            1,           -1 },
    { "obsidian",              NULL,       NULL,       0,            1,           -1 },
    { "Calculator.Skia.Gtk",   NULL,       NULL,       0,            1,           -1 },
    { "Anki",                  NULL,       NULL,       0,            1,           -1 },
    { "edb",                   NULL,       NULL,       0,            1,           -1 },
    { "org.gnome.FileRoller",  NULL,       NULL,       0,            1,           -1 },
    { "Galculator",            NULL,       NULL,       0,            1,           -1 },
    { "kolourpaint",           NULL,       NULL,       0,            1,           -1 },
    { "mpv",                   NULL,       NULL,       0,            1,           -1 },
    { "Blueman-manager",       NULL,       NULL,       0,            1,           -1 },
	{ "Code",                  NULL,       NULL,       0,            1,           -1 },
	{ "Notepadqq",             NULL,       NULL,       0,            1,           -1 },
	{ "Sublime_text",          NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 165;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define MODKEY2 Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *brup[]      = { "brightnessctl", "set", "+5%", NULL };
static const char *brdown[]    = { "brightnessctl", "set", "5%-", NULL };
static const char *firefox[]   = { "firefox", NULL };
static const char *thunar[]    = { "thunar", NULL };
static const char *telegram[]  = { "Telegram", NULL };
static const char *flameshot[] = { "flameshot", "gui", NULL };
static const char *lockcmd[]   = { "betterlockscreen", "-l", NULL };
static const char *code[]      = { "code", NULL };
static const char *subl[]      = { "subl", NULL };
static const char *blue[]      = { "blueman-manager", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_q,      spawn,          {.v = termcmd } },
	{ MODKEY2,                      XK_f,      spawn,          {.v = firefox } },
	{ MODKEY2,                      XK_c,      spawn,          {.v = code } },
	{ MODKEY2,                      XK_s,      spawn,          {.v = subl } },
	{ MODKEY2,                      XK_k,      spawn,          {.v = blue } },
    { MODKEY,                       XK_e,      spawn,          {.v = thunar } },
    { MODKEY2,                      XK_t,      spawn,          {.v = telegram } },
    { 0,                            XK_Print,  spawn,          {.v = flameshot } },
    { MODKEY,               XK_semicolon,      spawn,          {.v = lockcmd } },
    { 0,             XF86XK_MonBrightnessUp,   spawn,          {.v = brup } },
    { 0,             XF86XK_MonBrightnessDown, spawn,          {.v = brdown } },
    { 0,              XF86XK_AudioRaiseVolume, spawn,          SHCMD("pamixer -i 5; pkill -RTMIN+10 dwmblocks") },
    { 0,              XF86XK_AudioLowerVolume, spawn,          SHCMD("pamixer -d 5; pkill -RTMIN+10 dwmblocks") },
    { 0,              XF86XK_AudioMute,        spawn,          SHCMD("pamixer -t 5; pkill -RTMIN+10 dwmblocks") },
    { MODKEY,                       XK_n,      spawn,          SHCMD("systemctl poweroff") },
    { MODKEY,                       XK_u,      spawn,          SHCMD("systemctl reboot") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_v,      togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
