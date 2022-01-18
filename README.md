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

### 3  xsession
```shell
#/usr/share/lightdm/lightdm.conf.d/50-ubuntu.conf
dwm
```

### 3  xinitrc
```shell
/etc/X11/xinit/xinitrc
export _JAVA_AWT_WM_NONREPARENTING=1
export AWT_TOOLKIT=MToolkit
wmname LG3D
```



### 3  console
when open computer, set console font size
```shell
sudo vim /etc/default/console-setup
FONTSIZE
FONTFACE
```





