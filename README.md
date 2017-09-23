# microBraids
μBraids in 8HP.

Braids is an amazing module. μBraids is half the space, so twice as amazing.

## Requirements
This is an advanced build. After you follow the basic build guide and solder in the 0603 & TSSOP components and you will have to flash two microprocessors with two different programmers... It is not insurmountable but if you haven't done a microprocessor based build I would recommend something simpler to start.

Nothing has been altered component-wise from v5 of Braids. Some ICs were shrunk down to TSSOP packages in order to create more space. This means that any future firmware upgrade on Braids or alternate firmware such as Tim Churches' Bees in the Trees should load and work fine.

### Hardware needed

- ISP/AVR Programmer (for the ATMEGA328P display code)
- FTDI or JTAG (ST-Linkv2) Programmer (for the main STM32 processor)
  
Note: for JTAG/ST-Linkv2, you will need a JTAG to SWD 10-pin adaptor.
The following are examples of the adaptors needed to use the mini-JTAG (SWD) connector on
the v2 board, not endorsements - [Adaptor][5], [Cable][6]

Further note: If you have a v1 board, you will only be able to use FTDI to program the
STM32 processor.

### Software needed

For flashing the main Braids firmware to this module - the microBraids firmware, using the [Mutable Instruments Vagrant Dev Environment][1] will provide the needed compilers, code and tools in a virtual machine to make the process easier. 
The μBraids can be programmed with any standard Braids firmware without modification, using the same process as the original Braids module.

For the display code - You will then need to install the [Arduino app][2] in order to programm the ATMEGA328P running the display. 
The `elapsedMillis`, `Adafruit SSD 1306` and `Adafruit GFX Library` are included in this repository folder, so they do not need to be installed using the Arduino Library Manager.
Load the Ardunio sketch for the display code in the [Display Code/mbraidsv3](Display Code/mbraidsv3) folder, and use the program button in the Ardunio IDE to upload the code.
Make sure you set the board type in the Ardunio IDE `Ardunio Genuino/Uno`, and ensure the correct port and programmer type is set, based on the AVR/ISP programmer you have connected to the ISP port on microBraids.

> Note: The microBraids is designed for use with an 128x32 SPI OLED. If you manually
> install or update the libraries needed by this project, please ensure that the SSD1306
> library is correctly configured for a display size of 128x32.

## Please be advised

This board is 0603 SMT components and thus not suitable for beginners. If you would like a good introduction to the sDIY world, we recommend building a simpler through-hole kit such as the Mikrophonie and then working up in complexity from there.
There are a number of simpler SMD-based modules, and SMD practice boards can be had cheaply to practice your surface-mount soldering before attempting uBraids.

Since the layout has been altered to shrink the board down, the smaller PCB does not have all component designations marked. Instead, you can use the component overlay in the [build guide][0], or open the board layout in Diptrace to view component placements whilst building.

Before purchasing a PCB, please ensure you are comfortable with setting up the development environment needed to compile the firmware and flash these units, and understand the basic flow of working on microprocessor based builds. That said: The point of providing these boards is that learning to work SMT is not an insurmountable task and with proper research, practice and steady hands you might actually prefer it. (or not)

We are a small 2 person shop and unfortunately do not have time to be able to offer any build support or answer any questions about or troubleshoot your DIY builds.

## Want to contribute?

This is Open Source Project and could benefit from the following:

- OLED reprogramming to show the full name of the parameter and what the timbre & color adjust. There may be space for a 128x64 OLED so there is potential for this to display for more information than the regular 14 segment LEDs braids has.
- Contributions to our GitHub repositories in the form of PRs and/or filing issues if you
  find them.
- Muffwiggler project thread maintainence, feel free to chime in and support your fellow
  builders!

Please contact us if you are interested in contributing to any of the above.

  This is an at your own risk project. For the most part you can safely consider this identical to a regular braids with a few chips reduced in size and an additional atmega chip & circuit to handle the OLED display.

## Support
Support is not available through us nor Mutable Instruments nor the Mutable Instruments forums, please respect their wishes to not want to answer any questions regarding DIY builds and leave them to continue doing what they do best.

## Licence (cc-by-sa-3.0)
Original CAD file, PCB & Schematic and original design elements provided by [Mutable Instruments][3] under creative commons CC-BY-SA-3.0 license. 

This microBraids (uBraids) project is provided by [Magpie Modular][4] under Creative Commons CC-BY-SA-3.0 license.


[0]: http://github.com/MagpieModular/microBraids/blob/master/Build%20Guide/MicroBraids%20Build.pdf
[1]: http://github.com/pichenettes/mutable-dev-environment 
[2]: http://www.arduino.cc/en/Main/Software
[3]: http://mutable-instruments.net
[4]: http://magpie-modular.myshopify.com
[5]: https://www.adafruit.com/product/2094
[6]: https://www.adafruit.com/product/1675
 
