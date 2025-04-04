/usr/local/dwmScript/autoChangeWallpaper.sh &
alacritty --working-directory ~/ &
redshift &
#picom -o 0.95 -i 0.88 --detect-rounded-corners --vsync --blur-background-fixed -f -D 5 -c -b
compton -b --config ~/.config/compton-config/compton.conf &
ibus-daemon -d -x -r &
firefox &
#while false; do
#	/usr/local/dwmScript/bar-message.sh
#	sleep 1m
#done &
#st -d ~/ -e bash -c "ranger --choosedir=$HOME/.config/ranger/.rangerdir;exec bash";
#xsetroot -name "Wifi:$(cat /sys/class/net/<你的无线网卡名>/operstate)|Ethernet:$(cat /sys/class/net/<你的有线网卡名>/operstate)|Battery:$(acpi -b | awk '{print $4}' | cut -d"," -f1)|Volume:$(amixer get Master | awk -F'[][]' 'END{ print $4":"$2 }')|$(LC_ALL='C' date +'%F[%b %a] %R')" %#在dwm的菜单栏里显示一个简易的系统状态栏，包括wifi、有线网、电池电量、音量、日期和时间(24小时制)。喜欢功能丰富的同学可以自己去安装配置polybar、conky、i3status、slstatus等，从中选一个。
#xset dpms 1800 0
/usr/local/dwmScript/touchpad-switch.sh
/usr/local/dwmScript/sound-init.sh &

# === orc ===
mkdir /tmp/dwm_tesseract_ocr/

# === screenshot tmp ===
mkdir -p /tmp/screenshot_tmp

# === clash ===
# cd ~/.config/clash/
# cat ~/.config/clash/mySubscription | xargs  ConvertSubscription
# sed -i "/port\s*:\s*7890\s*$/d" ~/.config/clash/config.yaml
# sed -i "/external-controller:/d" ~/.config/clash/config.yaml
# sed -i "/mixed-port:/d" ~/.config/clash/config.yaml
# sed -i "1i mixed-port: 7890" ~/.config/clash/config.yaml
#clash > /var/log/clash/clash.log &
