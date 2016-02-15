# Toggle the DTR pin of a Linux Serial Port (such as /dev/ttyUSB0)

This code toggles the DTR pin of a Linux serial port (such as /dev/ttyUSB0).

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

```

# Photos

![Blinking a big LED with a CP2102 usb-serial converter with its DTR pin](https://raw.githubusercontent.com/zoobab/toggledtr/master/usb-serial-toggle-dtr-pin.jpg)

# Credits

This is a fork of the well documented code of Xanthium:

https://github.com/xanthium-enterprises/RTS-DTR-Pin-Control-Linux

However, I only needed to toggle the DTR pin of my USB-serial adaptor, so I
removed everything else (like toggling other pins such as DTS, etc...).

# Links

* https://github.com/zoobab/ch340g-bitbanging
* https://github.com/xanthium-enterprises/RTS-DTR-Pin-Control-Linux
