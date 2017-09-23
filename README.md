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
  The following are examples, not endorsements - [Adaptor][5], [Cable][6]

### Software needed

I recommend using and installing the [Mutable Instruments Vagrant Dev Environment][1] to Flash the Braids aspect of this with any firmware you like. Flash as you would any normal DIY Mutable Instrument build.

You will then need to install the [Arduino app][2] to upload the Display Code. The `elapsedMillis`, `Adafruit SSD 1306` and `Adafruit GFX Library` are included in the Sketch folder so you can just upload it with your FTDI Programmer.

> Note: If you don't use the library included in this repo you will need to specify screen size in the header file (`Adafruit_SSD1306.h`) of the `Adafruit SSD 1306` library. This is a 128x32 SPI OLED.

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
 
