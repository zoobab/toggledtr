# Blink a LED lamp (toggle) with the DTR pin of a Linux Serial Port (such as /dev/ttyUSB0)

This code toggles the DTR pin of a Linux serial port (such as /dev/ttyUSB0).

It blinks a cheap LED lamp usually powered by 3xAAA 1.5V batteries, so it could be powered over USB 5V.

# Compile

```
zoobab@sabayonx86-64 /home/zoobab/soft/toggledtr [55]$ make clean
rm -v toggledtr
removed ‘toggledtr’
zoobab@sabayonx86-64 /home/zoobab/soft/toggledtr [56]$ make
gcc -o toggledtr toggledtr.c
zoobab@sabayonx86-64 /home/zoobab/soft/toggledtr [57]$ 
```

# Run

```
zoobab@sabayonx86-64 /home/zoobab/soft/toggledtr [323]$ sudo ./toggledtr 
ttyUSB0 opened successfully
DTR = 1
DTR = 0
DTR = 1
DTR = 0
DTR = 1
DTR = 0
DTR = 1
DTR = 0
^C
zoobab@sabayonx86-64 /home/zoobab/soft/toggledtr [324]$ 

```

Note the CTRL-C at the end to quit the program loop.

# Photos

![Blinking a big LED with a CP2102 usb-serial converter with its DTR pin](https://raw.githubusercontent.com/zoobab/toggledtr/master/usb-serial-toggle-dtr-pin.jpg)

The Minus sign of your batteries (-) is connected to GND, and the Plus sign of the batteries (+) is connected to the DTR pin. When the DTR pin is HIGH, there is current on the lamp, when DTR pin is LOW, there is no current flowing.

# About the lamp

The LED lamp "Lampe retro LED sur tirette" was bought for 2EUR on the 13 February 2016 at Action.be in Brussels.

Product page is here:

http://www.action.be/fr/lampe-r-tro-led-sur-tirette-div-couleurs


# About the USB serial adaptor

The CP2102 adaptor has the DTR pin exposed on the last pin of its header, NoSolderingRequired(tm):

![DTR pin (the last one on the header) on the CP2102 usb-serial converter](https://raw.githubusercontent.com/zoobab/toggledtr/master/cp2102-usb-serial.jpg)

# Credits

This is a fork of the well documented code of Xanthium:

https://github.com/xanthium-enterprises/RTS-DTR-Pin-Control-Linux

However, I only needed to toggle the DTR pin of my USB-serial adaptor, so I
removed everything else (like toggling other pins such as DTS, etc...).

# Links

* https://github.com/zoobab/ch340g-bitbanging
* https://github.com/xanthium-enterprises/RTS-DTR-Pin-Control-Linux
* http://www.linuxtv.org/mailinglists/vdr/2003/02-2003/msg00543.html
* http://www.action.be/fr/lampe-r-tro-led-sur-tirette-div-couleurs
