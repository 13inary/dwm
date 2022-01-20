##  condition
```shell
sudo apt install libxinerama-dev
sudo apt install libcanberra-gtk-module

sudo apt install brightnessctl
sudo apt install alsa-utils
sudo apt install redshift
sudo apt install acpi

sudo apt install compton
```

##  configuration
###   file
edit `config.mk` 
```shell
X11INC=/usr/include/X11
X11LIB=/usr/include/X11
FREETYPEINC = /usr/include/freetype2
```

###   input method
`ibus` 
```shell
sudo apt install ibus
sudo apt install ibus-data
sudo apt install ibus-gtk
sudo apt install ibus-gtk3
sudo apt install ibus-libpinyin
sudo apt install ibus-pinyin
```
process serve:
```shell
ibus-daemon
ibus-memconf
ibus-ui-gtk3
ibus-extension-
ibus-X11
ibus-portal
ibus-engine-sim
ibus-engine-pin
```

###   system
```shell
#export GTK_IM_MODULE=xim # 使用fictx时，可能chromium、vscode等软件无法使用输入法，故改用为xim
#export QT_IM_MODULE=xim
#export XMODIFIERS="@im=fcitx"
#export LC_ALL="zh_CN.UTF-8"
#fcitx &

# input method
export GTK_IM_MODULE=ibus
export QT_IM_MODULE=ibus
export XMODIFIERS="@im=ibus"

# JAVA aplication
export _JAVA_AWT_WM_NONREPARENTING=1
export AWT_TOOLKIT=MToolkit
```

```shell
vim /etc/X11/xinit/xinitrc
	wmname LG3D
	exec dwm
sudo ln -s /xxx/.../source-code-pro /use/share/fonts/opentype/
ln -s .../shell/...   ~/.dwm
```

Auto start ranger, when open system
```shell
//st -e bash -c "ranger --choosedir=$HOME/.config/ranger/.rangerdir;RANGERLASTDIR=`cat $HOME/.config/ranger/.rangerdir`;echo "$RANGERLASTDIR";cd "$RANGERLASTDIR" ;exec bash";
st -d ~/  
```

###   bright
```shell
//sudo chmod 666 /sys/class/backlight/intel_backlight/brightness
sudo usermod -a -G video <user name>
//sudo visudo
//<user name> ALL=NOPASSWD:/usr/bin/brightnessctl

# set standby suspend off (0: close) 1800秒后关闭屏幕，不执行挂起和关机
# xset dpms 1800 0 0
```

###   key set
```shell
xev
```

###   bar
```shell
xsetroot
```

###   name of `wm` 
Because some java app have error
```shell
sudo apt install wmname
wmname <name>
```

### 3  desktop
```shell
/usr/share/xsession/dwm.Desktop
```

### 3  `xsession`
```shell
#/usr/share/lightdm/lightdm.conf.d/50-ubuntu.conf
dwm
```

### 3  `xinitrc`
```shell
/etc/X11/xinit/xinitrc
#_JAVA_OPTIONS='-Dawt.useSystemAAFontSettings=lcd'
#_JAVA_OPTIONS='-Dswing.defaultlaf=com.sun.java.swing.plaf.gtk.GTKLookAndFeel'
export _JAVA_AWT_WM_NONREPARENTING=1
export AWT_TOOLKIT=MToolkit
wmname LG3D
exec dwm
```



### 3  console
when open computer, set console font size
```shell
sudo vim /etc/default/console-setup
FONTSIZE="16x32"
#FONTFACE="Fixed"
```

### 3  `xdotool` 
```shell
模拟回车                      ： $ xdotool key KP_Enter
模拟按下左侧shift键(不弹起)   ： $ xdotool keydown Shift_L
模拟弹起shift                 ： $ xdotool keyup Shift_L
模拟按下A并弹起               ： $ xdotool key a
模拟ctrl+a                    ： $ xdotool key Ctrl+a
模拟按下向上方向键            ： $ xdotool key Up
获取鼠标位置                  ： $ xdotool getmouselocation
模拟鼠标移动                  ： $ xdotool mousemove X坐标值 Y坐标值
模拟鼠标左键点击1次           ： $ xdotool click 1
模拟鼠标中键（滚轮键）点击1次 ： $ xdotool click 2
模拟鼠标右键点击1次           ： $ xdotool click 3
模拟选择并复制文本            ： 模拟鼠标点击起始位置 -> 模拟鼠标移动到末端位置 -> 模拟按下左shift键(不弹起) -> 模拟鼠标左键点击 -> 模拟弹起左shift -> 模拟Ctrl+c
```

### 3  more monitor
```shell
修改dwm、dmenu、slock的USE flags

sudo vim /etc/portage/package.use/suckless：
x11-wm/dwm -savedconfig -xinerama
x11-misc/dmenu -savedconfig -xinerama
x11-misc/slock -savedconfig -xinerama

#"xinerama"仅在你拥有2个及以上显示器的时候才开启，一般人的电脑只用一个显示器，所以不开启这项USE flag。
```

### 3  only play game
```shell
vim ~/.xinitrc：    #不要sudo！！
......
if [ -n "$failsafe" ]; then
#将之前关于dwm的相关配置全部注释掉
xrandr --setprovideroutputsource modesetting NVIDIA-0     #关于xrandr的这两行配置，每一行后面都不要加上"&"，否则nvidia驱动不能正常加载，会导致黑屏
xrandr --auto               #关于xrandr的这两行配置必须保留，否则你的intel&nvidia双显卡是无法进入X11图形环境的！！
exec <你想运行的图形程序/游戏>    #让X11(xorg)只运行一个图形程序
# exec sleep 99999999999999999999999
else
 exec $command
fi

startx
```

### 3  close `垂直同步Vsync` 
```shell
vim ~/.xinitrc：    #不要sudo！！
......
if [ -n "$failsafe" ]; then
......
xrandr --setprovideroutputsource modesetting NVIDIA-0    #关于xrandr的这三行配置，每一行后面都不要加上"&"，否则nvidia驱动不能正常加载，会导致黑屏
xrandr --auto               #关于xrandr的这两行配置必须保留，否则你的intel&nvidia双显卡是无法进入X11图形环境的！！
xrandr --output <output> --set "PRIME Synchronization" 0    #关闭垂直同步。<output>替换为你的显示器名称，可以通过执行xrandr命令查看输出结果，会列出电脑支持的所有显示器名称，如DP-0、DP-1、eDP-1-1、HDMI-1-1等；找出后面跟有“connected“字样的显示器名称，我们需要的就是这个，用它替换<output>。若想再次开启垂直同步，只需把参数从0改为1即可。
......
else
 exec $command
fi
```
and
```shell
sudo vim /etc/X11/xorg.conf:
......
Section "Device"
    Identifier     "Device0"
    Driver         "nvidia"
    VendorName     "NVIDIA Corporation"
    BusID          "PCI:1:0:0"
...
    Option         "ForceCompositionPipeline" "false"
    Option         "ForceFullCompositionPipeline" "false"    #关闭强制交错，提高渲染性能
    Option         "TripleBuffer" "false"    #关闭三重缓冲；三重缓冲只有在开启垂直同步时才有意义，由于我们不需要垂直同步了，所以关掉
    Option         "DPI" "96x96"    #将显示器的dpi设置为96,可以得到一个相对合适的字体大小界面，看上去字体没那么小了，视觉上舒服了不少
...
EndSection
......
```


### 3  backlight
```shell
背光灯调整工具

$ sudo apt install light

为背光灯调整工具设置sudo免密码

$ sudo visudo

然后在文本最后加入如下代码

{登录系统的用户名} ALL=NOPASSWD:/usr/bin/light

```

### 3  replace logo of computer by text
```shell
vim /etc/default/grub
#GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
GRUB_CMDLINE_LINUX_DEFAULT="text"
```



### 3  point place of software
```shell
为软件指定打开标签

xprop | grep WM_CLASS

鼠标会变为十字架,用十字架点击想要被指定的软件的打开窗口，terminal就会显示该软件的instance和class:

WM_CLASS(STRING) = instance, class

将信息填入config.h的下列位置: 
```

### 3  `startx`
```shell
开机启动时自动运行程序

Linux加载后, 它将初始化硬件和设备驱动, 然后运行第一个进程init。init根据配置文件继续引导过程，启动其它进程。通常情况下，修改放置在 /etc/rc或 /etc/rc.d 或 /etc/rc?.d 目录下的脚本文件，可以使init自动启动其它程序。例如：编辑 /etc/rc.d/rc.local 文件，在文件最末加上一行"xinit"或"startx"，可以在开机启动后直接进入X－Window。
登录时自动运行程序

用户登录时，bash首先自动执行系统管理员建立的全局登录script ：/etc/profile。然后bash在用户起始目录下按顺序查找三个特殊文件中的一个：/.bash_profile、/.bash_login、 /.profile，但只执行最先找到的一个。
因此，只需根据实际需要在上述文件中加入命令就可以实现用户登录时自动运行某些程序（类似于DOS下的Autoexec.bat）。
退出登录时自动运行程序

退出登录时，bash自动执行个人的退出登录脚本/.bash_logout。例如，在/.bash_logout中加入命令"tar －cvzf c.source.tgz ＊.c"，则在每次退出登录时自动执行 "tar" 命令备份 ＊.c 文件。
定期自动运行程序

Linux有一个称为crond的守护程序，主要功能是周期性地检查 /var/spool/cron目录下的一组命令文件的内容，并在设定的时间执行这些文件中的命令。用户可以通过crontab 命令来建立、修改、删除这些命令文件。
例如，建立文件crondFile，内容为"00 9 23 Jan ＊ HappyBirthday"，运行"crontab cronFile"命令后，每当元月23日上午9:00系统自动执行"HappyBirthday"的程序（"＊"表示不管当天是星期几）。
定时自动运行程序一次

定时执行命令at 与crond 类似（但它只执行一次）：命令在给定的时间执行，但不自动重复。at命令的一般格式为：at [ －f file ] time ，在指定的时间执行file文件中所给出的所有命令。也可直接从键盘输入命令：

＄ at 12:00
at>mailto Roger －s ″Have a lunch″ < plan.txt
at>Ctr－D
Job 1 at 2000－11－09 12:00

2000－11－09 12:00时候自动发一标题为"Have a lunch"，内容为plan.txt文件内容的邮件给Roger。
```


### 3  fix border of `alacritty` 
```shell
Transparent border in dwm

With dwm, alacritty's borders become transparent. Adding this line to drw.c in the dwm source directory and recompiling fixes the issue:

if (!XftColorAllocName(...))
    die("error, cannot allocate color '%s'", clrname); /* Find this line */
dest->pixel |= 0xff << 24; /* Add this line */
```


### 3  bug
```shell
Open window in other tag

Transmit file to phone and ftp and samba and scrcpy

`feem` font

`startx`

Focus on tag which open app

`mount` `usb` device

`screenshot-part.sh`

`xsetroot` set color

When open computer, set the `Speaker` and `Headphone`

When open st, automatic open `ranger` or `yd` 

When open `wps` , move it to tag 3

When focus A tag, move B tag

When close one window, other window display is not total

Voice in more monitor

When add other monitor , mouse can't move to other monitor

```

## 2 certification
```shell
0x02 导入系统证书

参考：

https://www.archlinux.org/news/ca-certificates-update/

这一步很重要，在archlinux中最好的证书导入方式就是把证书直接导入系统当中，不论是burpsuite或是xray或是一些vpn证书，导入系统的效果最好，三条命令完成。

sudo cp xxx.crt /etc/ssl/certs/
sudo cp xxx.crt /etc/ca-certificates/trust-source/anchors/
sudo trust extract-compat
```


## 2 blue
```shell
0x03 可视化蓝牙配置

参考：

https://wiki.archlinux.org/index.php/Bluetooth

安装蓝牙、蓝牙音频及可视化管理工具：

yay -S bluez bluez-utils pulseaudio-bluetooth blueman

在/etc/pulse/system.pa 增加下面内容：

load-module module-bluetooth-policy
load-module module-bluetooth-discover

启动蓝牙服务：

systemctl start bluetooth.service

启动blueman管理工具，当然你可以把它设为开机自启：

blueman-applet &
```

## 2 `tim` 
```shell
0x04 TIM解决方案

当然archlinuxcn源里有qq-linux,但是这个谁用谁知道,反正我不喜欢用,其次可以选择deepin-qq,可用archlinuxcn源的deepin.com.qq.office,但是该版本较旧,推荐aur源的deepin-wine-tim,直接下载编译,随时保持最新版,deepin-qq在非gnome环境下主要存在3个问题.

其一:

dwm每次重启后tim都无法开启,修改wine版本可解决,将/opt/deepinwine/apps/Deepin-TIM/run.sh和/opt/deepinwine/tools/run.sh的WINE_CMD一项都修改为wine,这也可以解决使用deepin-wine时的字体显示问题.

WINE_CMD="wine"

其二:

需提前运行gnome-settings-daemon依赖,但是运行后会导致gkt主题遭到破坏,运行以下两条命令重新设置主题:

gsettings set org.gnome.desktop.interface gtk-theme Adapta-Eta
gsettings set org.gnome.desktop.interface icon-theme Arc

当然我都是开机自启的包括运行gnome-settings-daemon

nohup /usr/lib/gsd-xsettings > /dev/null 2>&1 

其三:

TIM无法显示图片,包括用户头像等,原因在于deepin-qq走的是ipv6的线路,解决方案是禁用本机ipv6,但我不推荐,推荐使用代理,但是tim登录显示原因linux上设置不了,所以在windows上设置后将配置文件复制过来即可

C:\Users\Administrator\Documents\Tencent Files\All Users\TIM

替换

~/Documents/Tencent Files/All Users/TIM
```


## 2 `net music` 
```shell
0x05 linux 网易云音乐无法输入中文

linux上网易云音乐使用其自己的qt框架,无法共用系统环境配置,所以单独为其配置一下环境变量即可,修改/opt/netease/netease-cloud-music/netease-cloud-music.bash

先注释三行

#export LD_LIBRARY_PATH="${HERE}"/libs
#export QT_PLUGIN_PATH="${HERE}"/plugins 
#export QT_QPA_PLATFORM_PLUGIN_PATH="${HERE}"/plugins/platforms

再添加两行,完美解决

export LD_LIBRARY_PATH=/usr/lib
export XDG_CURRENT_DESKTOP=DDE
```


